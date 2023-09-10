#include <iostream>
#include "Employee.h"
#include <vector>
#include <sstream>
#include <bits/stdc++.h>  // For std::sort

class NodeTemp{
public:
    Employee info;
    Employee next;
};

class NodePer{
public:
    Employee info;
    NodePer* next;
    NodePer* previous;
};

class doubleLinkedList{
public:
    void add(NodePer** head, Employee employee){
        NodePer* newNode = new NodePer();
        newNode->info = employee;
        if (*head == nullptr){
            *head = newNode;
            return;
        }
        NodePer* temp = *head;

        NodePer*last = *head;

        while (last->next != nullptr){
            last = last->next;
        }
        last->next = newNode;
        NodePer*previous = *head;
        while (previous->next != newNode){
            previous = previous->next;
        }
        newNode->previous = previous;
    }

    void print(NodePer**head){
        NodePer*last = *head;
        while (last != nullptr){
            std::cout << last->info.employeeNumber <<std::endl;
            last = last->next;
        }
    }

    bool findEmployee(NodePer**head, int employeeNumber){
        NodePer* search = *head;
        while (search != nullptr){
            if (search->info.employeeNumber == employeeNumber){
                return true;
            }
            search = search->next;
        }
        return false;
    }

    bool contains(NodePer**head, int employeeNumber) {
        bool container = false;
        if (*head != nullptr) {
            NodePer *last = *head;
            while (last != nullptr) {
                if (last->info.employeeNumber == employeeNumber) {
                    container = true;
                    break;
                }
                last = last->next;
            }
        }
        return container;
    }

    void deleteNode(NodePer**head, NodePer* theEmployee){
        if (*head == theEmployee){
            NodePer* nextTheEmployee = theEmployee->next;
            *head = nextTheEmployee;
            return;
        }
        NodePer* previousTheEmployee = theEmployee->previous;
        NodePer* nextTheEmployee = theEmployee->next;
        previousTheEmployee->next = nextTheEmployee;
    }
};

class singleLinkedList{
public:
    int size = -1;
    Employee list[20];
    NodeTemp node;
    void add(Employee employee){
        if (size >= 20){
            return;
        }
        size ++;
        list[size] = employee;
        node.next = list[0];
    }
    bool contains(int employeeNumber){
        bool container = false;
        if (size != -1) {
            for (int i = 0; i <= size; i++) {
                if (list[i].employeeNumber == employeeNumber) {
                    container = true;
                    break;
                }
            }
        }
        return container;
    }
    void deleteNode(int deleten){
        if (deleten == -4){
            return;
        }
        for (int i = deleten; i < size+1; i++){
            if (i == size){
                break;
            }
            list[i] = list[i + 1];
        }
        size --;
    }
    void print(){
        for (int i = 0; i <= size; ++i) {
            std::cout << list[i].employeeNumber << std::endl;
        }
    }

};

std::vector<int> split(std::string strReal, char splitter){
    std::vector<int> result;
    std::stringstream data(strReal);
    std::string value;
    while (getline(data, value, splitter)){
        std::stringstream get(value);
        int x;
        get >> x;
        result.push_back(x);
    }

    return result;
}

struct employeeNumberOrder
{
    inline bool operator() (const Employee& employee1, const Employee& employee2)
    {
        return (employee1.employeeNumber < employee2.employeeNumber);
    }
};

struct timeOrder
{
    inline bool operator() (const Employee& employee1, const Employee& employee2)
    {
        if (employee1.appointmentDate.year < employee2.appointmentDate.year){
            return (employee1.appointmentDate.year < employee2.appointmentDate.year);
        } else if (employee1.appointmentDate.year == employee2.appointmentDate.year){
            if (employee1.appointmentDate.month < employee2.appointmentDate.month){
                return (employee1.appointmentDate.month < employee2.appointmentDate.month);
            } else if (employee1.appointmentDate.month == employee2.appointmentDate.month){
                if (employee1.appointmentDate.day < employee2.appointmentDate.day){
                    return employee1.appointmentDate.day < employee2.appointmentDate.day;
                }
            }
        }
        return employee2.appointmentDate.year < employee1.appointmentDate.year;
    }
};

struct timeOrderReverse
{
    inline bool operator() (const Employee& employee1, const Employee& employee2)
    {
        if (employee1.appointmentDate.year < employee2.appointmentDate.year){
            return (employee1.appointmentDate.year > employee2.appointmentDate.year);
        } else if (employee1.appointmentDate.year == employee2.appointmentDate.year){
            if (employee1.appointmentDate.month < employee2.appointmentDate.month){
                return (employee1.appointmentDate.month > employee2.appointmentDate.month);
            } else if (employee1.appointmentDate.month == employee2.appointmentDate.month){
                if (employee1.appointmentDate.day < employee2.appointmentDate.day){
                    return employee1.appointmentDate.day > employee2.appointmentDate.day;
                }
            }
        }
        return employee2.appointmentDate.year > employee1.appointmentDate.year;
    }
};

struct timeOrderYear
{
    inline bool operator() (const Employee& employee1, const Employee& employee2)
    {
        if (employee1.appointmentDate.year < employee2.appointmentDate.year){
            return (employee1.appointmentDate.year < employee2.appointmentDate.year);
        }
        return employee2.appointmentDate.year < employee1.appointmentDate.year;
    }
};

bool passedDate(Employee employee, Date certainDate){
    if (employee.appointmentDate.year > certainDate.year){
        return true;
    } else if (employee.appointmentDate.year == certainDate.year){
        if (employee.appointmentDate.month > certainDate.month){
            return true;
        } else if (employee.appointmentDate.month == certainDate.month){
            if (employee.appointmentDate.day > certainDate.day){
                return true;
            }
        }
    }
    return false;
}

bool passedDateBorn(Employee employee, Date bornDate){
    if (employee.birthDay.year < bornDate.year){
        return true;
    } else if (employee.birthDay.year == bornDate.year){
        if (employee.birthDay.month < bornDate.month){
            return true;
        } else if (employee.birthDay.month == bornDate.month){
            if (employee.birthDay.day < bornDate.day){
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::string consoleMessage = "___ Employee Recording System ___\n"
                                 "1) Appointment of a new employee\n"
                                 "2) Appointment of a transferred employee\n"
                                 "3) Updating the the title and salary coefficient of an employee\n"
                                 "4) Deleting of an employee\n"
                                 "5) Listing the information of an employee\n"
                                 "6) Listing employees ordered by employee number\n"
                                 "7) Listing employees ordered by appointment date\n"
                                 "8) Listing employees appointed after a certain date\n"
                                 "9) Listing employees assigned in a given year\n"
                                 "10) Listing employees born before a certain date\n"
                                 "11) Listing employees born in a particular month\n"
                                 "12) Listing the information of the last assigned employee with a given title\n"
                                 ;


    int choice;
    singleLinkedList singleLinkedList; // For temp
    doubleLinkedList doubleLinkedList;  //For permanent
    NodePer*head = nullptr;
    std::vector<std::string> typeVector;
    while (true) {
        std::cout << consoleMessage;
        std::cin >> choice;
        int lengthService = 0;
        if (choice == 1) {
            std::cout << "Please type the employee number\n";
            int employeeNumber;
            std::cin >> employeeNumber;
            if (!(singleLinkedList.contains(employeeNumber)) && !(doubleLinkedList.contains(&head, employeeNumber))) {
                std::cout << "Type the employee type\n";
                short employeeType;
                std::cin >> employeeType;
                if (employeeType == 0) {
                    TemporaryEmployee temp;
                    temp.employeeNumber = employeeNumber;
                    temp.employeeType = employeeType;
                    std::string name, surname, title;
                    double salaryCoefficient;
                    Date birth;
                    Date appointment;
                    std::string complexDate;
                    std::cout << "Type the Name\n";
                    std::cin >> name;
                    temp.name = name;
                    std::cout << "Type surname\n";
                    std::cin >> surname;
                    temp.surname = surname;
                    std::cout << "Type title\n";
                    std::cin >> title;
                    temp.title = title;
                    std::cout << "Type salary coefficient\n";
                    std::cin >> salaryCoefficient;
                    temp.salaryCoefficient = salaryCoefficient;
                    std::cout << "Type birth date\n";
                    std::cin >> complexDate;
                    birth.day = split(complexDate, '-').at(0);
                    birth.month = split(complexDate, '-').at(1);
                    birth.year = split(complexDate, '-').at(2);
                    temp.birthDay = birth;
                    std::cout << "Type appointment date\n";
                    std::cin >> complexDate;
                    appointment.day = split(complexDate, '-').at(0);
                    appointment.month = split(complexDate, '-').at(1);
                    appointment.year = split(complexDate, '-').at(2);
                    temp.appointmentDate = appointment;
                    temp.lengthService = lengthService;
                    singleLinkedList.add(temp);
                } else if (employeeType == 1) {
                    PermanentEmployee perm;
                    perm.employeeNumber = employeeNumber;
                    perm.employeeType = employeeType;
                    std::string name, surname, title;
                    double salaryCoefficient;
                    Date birth;
                    Date appointment;
                    std::string complexDate;
                    std::cout << "Type the Name\n";
                    std::cin >> name;
                    perm.name = name;
                    std::cout << "Type surname\n";
                    std::cin >> surname;
                    perm.surname = surname;
                    std::cout << "Type title\n";
                    std::cin >> title;
                    perm.title = title;
                    std::cout << "Type salary coefficient\n";
                    std::cin >> salaryCoefficient;
                    perm.salaryCoefficient = salaryCoefficient;
                    std::cout << "Type birth date\n";
                    std::cin >> complexDate;
                    birth.day = split(complexDate, '-').at(0);
                    birth.month = split(complexDate, '-').at(1);
                    birth.year = split(complexDate, '-').at(2);
                    perm.birthDay = birth;
                    std::cout << "Type appointment date\n";
                    std::cin >> complexDate;
                    appointment.day = split(complexDate, '-').at(0);
                    appointment.month = split(complexDate, '-').at(1);
                    appointment.year = split(complexDate, '-').at(2);
                    perm.appointmentDate = appointment;
                    std::cout << "Type length of service days\n";
                    std::cin >> lengthService;
                    perm.lengthService = lengthService;
                    doubleLinkedList.add(&head, perm);
                }
            }
        } else if (choice == 2) {
            std::cout << "Please type the employee number\n";
            int employeeNumber;
            std::cin >> employeeNumber;
            if (!(singleLinkedList.contains(employeeNumber)) && !(doubleLinkedList.contains(&head, employeeNumber))) {
                std::cout << "Type the employee type\n";
                short employeeType;
                std::cin >> employeeType;
                if (employeeType == 0) {
                    TemporaryEmployee temp;
                    temp.employeeNumber = employeeNumber;
                    temp.employeeType = employeeType;
                    std::string name, surname, title;
                    double salaryCoefficient;
                    Date birth;
                    Date appointment;

                    std::string complexDate;
                    std::cout << "Type the Name\n";
                    std::cin >> name;
                    temp.name = name;
                    std::cout << "Type surname\n";
                    std::cin >> surname;
                    temp.surname = surname;
                    std::cout << "Type title\n";
                    std::cin >> title;
                    temp.title = title;
                    std::cout << "Type salary coefficient\n";
                    std::cin >> salaryCoefficient;
                    temp.salaryCoefficient = salaryCoefficient;
                    std::cout << "Type birth date\n";
                    std::cin >> complexDate;
                    birth.day = split(complexDate, '-').at(0);
                    birth.month = split(complexDate, '-').at(1);
                    birth.year = split(complexDate, '-').at(2);
                    temp.birthDay = birth;
                    std::cout << "Type appointment date\n";
                    std::cin >> complexDate;
                    appointment.day = split(complexDate, '-').at(0);
                    appointment.month = split(complexDate, '-').at(1);
                    appointment.year = split(complexDate, '-').at(2);
                    temp.appointmentDate = appointment;
                    std::cout << "Type length of service days\n";
                    std::cin >> lengthService;
                    temp.lengthService = lengthService;
                    singleLinkedList.add(temp);
                } else if (employeeType == 1) {
                    PermanentEmployee perm;
                    perm.employeeNumber = employeeNumber;
                    perm.employeeType = employeeType;
                    std::string name, surname, title;
                    double salaryCoefficient;
                    Date birth;
                    Date appointment;
                    std::string complexDate;
                    std::cout << "Type the Name\n";
                    std::cin >> name;
                    perm.name = name;
                    std::cout << "Type surname\n";
                    std::cin >> surname;
                    perm.surname = surname;
                    std::cout << "Type title\n";
                    std::cin >> title;
                    perm.title = title;
                    std::cout << "Type salary coefficient\n";
                    std::cin >> salaryCoefficient;
                    perm.salaryCoefficient = salaryCoefficient;
                    std::cout << "Type birth date\n";
                    std::cin >> complexDate;
                    birth.day = split(complexDate, '-').at(0);
                    birth.month = split(complexDate, '-').at(1);
                    birth.year = split(complexDate, '-').at(2);
                    perm.birthDay = birth;
                    std::cout << "Type appointment date\n";
                    std::cin >> complexDate;
                    appointment.day = split(complexDate, '-').at(0);
                    appointment.month = split(complexDate, '-').at(1);
                    appointment.year = split(complexDate, '-').at(2);
                    perm.appointmentDate = appointment;
                    std::cout << "Type length of service days\n";
                    std::cin >> lengthService;
                    perm.lengthService = lengthService;
                    doubleLinkedList.add(&head, perm);
                }
            }
        } else if (choice == 3){
            std::cout << "Please type the employee number\n";
            int employeeNumber;
            std::cin >> employeeNumber;
            if (doubleLinkedList.findEmployee(&head, employeeNumber)){
                NodePer* employee = head;
                while (employee != nullptr){
                    if (employee->info.employeeNumber == employeeNumber){
                        std::string newTitle;
                        double newCoefficient;
                        std::cout << "Type the new title\n";
                        std::cin >> newTitle;
                        std::cout << "Type the new salary coefficient\n";
                        std::cin >> newCoefficient;
                        employee->info.title = newTitle;
                        employee->info.salaryCoefficient = newCoefficient;
                        break;
                    }
                    employee = employee->next;
                }
            }
            for (Employee e : singleLinkedList.list){
                if (e.employeeNumber == employeeNumber){
                    std::string newTitle;
                    double newCoefficient;
                    std::cout << "Type the new title\n";
                    std::cin >> newTitle;
                    std::cout << "Type the new salary coefficient\n";
                    std::cin >> newCoefficient;
                    e.title = newTitle;
                    e.salaryCoefficient = newCoefficient;
                    break;
                }
            }
        } else if (choice == 4){
            std::cout << "Please type the employee number\n";
            int employeeNumber;
            std::cin >> employeeNumber;
            if (doubleLinkedList.findEmployee(&head, employeeNumber)){
                NodePer* theEmployee = head;
                while (true){
                    if (theEmployee->info.employeeNumber == employeeNumber){
                        break;
                    } else{
                        theEmployee = theEmployee->next;
                    }
                }
                doubleLinkedList.deleteNode(&head, theEmployee);
            }
            int deleten = -4; // a random value
            for (int i = 0; i < singleLinkedList.size + 1; i++){
                if (singleLinkedList.list[i].employeeNumber == employeeNumber){
                    deleten = i;
                    break;
                }
            }
            singleLinkedList.deleteNode(deleten);
        } else if (choice == 5){
            std::cout << "Please type the employee number\n";
            int employeeNumber;
            std::cin >> employeeNumber;
            if (doubleLinkedList.findEmployee(&head, employeeNumber)){
                NodePer* employee = head;
                while (employee != nullptr){
                    if (employee->info.employeeNumber == employeeNumber){
                        std::cout << "Employee Number: " << employeeNumber << std::endl;
                        std::cout << "Employee Type: " << employee->info.employeeType << std::endl;
                        std::cout << "Name: " << employee->info.name << std::endl;
                        std::cout << "Surname: " << employee->info.surname << std::endl;
                        std::cout << "Title: " << employee->info.title << std::endl;
                        std::cout << "Salary Coefficient: " << employee->info.salaryCoefficient << std::endl;
                        employee->info.birthDay.print("Birth Day");
                        employee->info.appointmentDate.print("Appointment Date");
                        std::cout << "Length of Service: : " << employee->info.lengthService << std::endl;
                        break;
                    }
                    employee = employee->next;
                }
            }
            for (Employee e : singleLinkedList.list){
                if (e.employeeNumber == employeeNumber){
                    std::cout << "Employee Number: " << employeeNumber << std::endl;
                    std::cout << "Employee Type: " << e.employeeType << std::endl;
                    std::cout << "Name: " << e.name << std::endl;
                    std::cout << "Surname: " << e.surname << std::endl;
                    std::cout << "Title: " << e.title << std::endl;
                    std::cout << "Salary Coefficient: " << e.salaryCoefficient << std::endl;
                    e.birthDay.print("Birth Day");
                    e.appointmentDate.print("Appointment Date");
                    std::cout << "Length of Service: : " << e.lengthService << std::endl;
                    break;
                }
            }
        } else if (choice == 6){
          std::vector<Employee> employees;
          for (int i = 0; i <= singleLinkedList.size; i++){
              employees.push_back(singleLinkedList.list[i]);
          }
          NodePer* last = head;
            while (last != nullptr){
                employees.push_back(last->info);
                last = last->next;
            }
            std::sort(employees.begin(), employees.end(), employeeNumberOrder());
            for (Employee e : employees)
            {
                e.showInformations(e);
            }
        } else if (choice == 7){
            std::vector<Employee> employees;
            for (int i = 0; i <= singleLinkedList.size; i++){
                employees.push_back(singleLinkedList.list[i]);
            }
            NodePer* last = head;
            while (last != nullptr){
                employees.push_back(last->info);
                last = last->next;
            }
            std::sort(employees.begin(), employees.end(), timeOrder());
            for (Employee e : employees){
                e.showInformations(e);
            }
        } else if (choice == 8){
            std::cout << "Please type the date\n";
            std::string strDate;
            Date certainDate;
            std::cin >> strDate;
            std::vector<int> certain = split(strDate, '-');
            certainDate.day =  certain.at(0);
            certainDate.month = certain.at(1);
            certainDate.year = certain.at(2);
            std::vector<Employee> employees;
            for (int i = 0; i <= singleLinkedList.size; i++){
                if (passedDate(singleLinkedList.list[i], certainDate)){
                    employees.push_back(singleLinkedList.list[i]);
                }
            }
            NodePer* last = head;
            while (last != nullptr){
                if (passedDate(last->info, certainDate)){
                    employees.push_back(last->info);
                }
                last = last->next;
            }
            std::sort(employees.begin(), employees.end(), timeOrderReverse());
            for (Employee e : employees){
                e.showInformations(e);
            }
        } else if (choice == 9){
            std::cout << "Type the year\n";
            int year;
            std::cin >> year;
            std::vector<Employee> employees;
            for (int i = 0; i <= singleLinkedList.size; i++){
                if (singleLinkedList.list[i].appointmentDate.year == year) {
                    employees.push_back(singleLinkedList.list[i]);
                }
            }
            NodePer* last = head;
            while (last != nullptr){
                if (last->info.appointmentDate.year == year) {
                    employees.push_back(last->info);
                }
                last = last->next;
            }
            std::sort(employees.begin(), employees.end(), timeOrderYear());
            for (Employee e : employees){
                e.showInformations(e);
            }
        } else if (choice == 10){
            std::cout << "Please type the date\n";
            std::string strDate;
            Date certainDate;
            std::cin >> strDate;
            std::vector<int> certain = split(strDate, '-');
            certainDate.day =  certain.at(0);
            certainDate.month = certain.at(1);
            certainDate.year = certain.at(2);
            std::vector<Employee> employees;
            for (int i = 0; i <= singleLinkedList.size; i++){
                if (passedDateBorn(singleLinkedList.list[i], certainDate)){
                    employees.push_back(singleLinkedList.list[i]);
                }
            }
            NodePer* last = head;
            while (last != nullptr){
                if (passedDateBorn(last->info, certainDate)){
                    employees.push_back(last->info);
                }
                last = last->next;
            }
            std::sort(employees.begin(), employees.end(), employeeNumberOrder());
            for (Employee e : employees){
                e.showInformations(e);
            }
        } else if (choice == 11){
            std::cout << "Type the month\n";
            int month;
            std::cin >> month;
            std::vector<Employee> employees;
            for (int i = 0; i <= singleLinkedList.size; i++){
                if (singleLinkedList.list[i].birthDay.month == month) {
                    employees.push_back(singleLinkedList.list[i]);
                }
            }
            NodePer* last = head;
            while (last != nullptr){
                if (last->info.birthDay.month == month) {
                    employees.push_back(last->info);
                }
                last = last->next;
            }
            std::sort(employees.begin(), employees.end(), employeeNumberOrder());
            for (Employee e : employees){
                e.showInformations(e);
            }
        } else if (choice == 12){
            std::cout << "Type the Title\n";
            std::string title;
            std::cin >> title;
            std::vector<Employee> employees;
            for (int i = 0; i <= singleLinkedList.size; i++){
                if (singleLinkedList.list[i].title == title) {
                    employees.push_back(singleLinkedList.list[i]);
                }
            }
            NodePer* last = head;
            while (last != nullptr){
                if (last->info.title == title) {
                    employees.push_back(last->info);
                }
                last = last->next;
            }
            if (!employees.empty()){
                std::sort(employees.begin(), employees.end(), timeOrder());
                Employee e = employees.at(employees.size() - 1);
                e.showInformations(e);
            }
        }
    }
    return 0;
}
