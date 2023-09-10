//
// Created by Can on 25.11.2021.
//

#ifndef ASSIGNMENT2_EMPLOYEE_H
#define ASSIGNMENT2_EMPLOYEE_H

#include <ostream>
#include "Date.h"


class Employee{
public:
    int employeeNumber;
    short employeeType;
    std::string name; // 12 characters
    std::string surname; // 12
    std::string title;  // 12
    double salaryCoefficient;
    Date birthDay;
    Date appointmentDate;
    int lengthService;

    friend std::ostream &operator<<(std::ostream &os, const Employee &employee) {
        os << "Employee Number: " << employee.employeeNumber << std::endl<< "Employee Type: " << employee.employeeType << std::endl
        << "Name: " << employee.name << std::endl << "Surname: " << employee.surname << std::endl << "Title: " << employee.title << std::endl
        << "Salary Coefficient: " << employee.salaryCoefficient << "Birth Day: " << employee.birthDay << "Appointment Date: " << employee.appointmentDate
        << "Length of Service: " << employee.lengthService << std::endl;
        return os;
    }

    void showInformations(Employee e){
        std::cout << "Employee Number: " << employeeNumber << std::endl;
        std::cout << "Employee Type: " << e.employeeType << std::endl;
        std::cout << "Name: " << e.name << std::endl;
        std::cout << "Surname: " << e.surname << std::endl;
        std::cout << "Title: " << e.title << std::endl;
        std::cout << "Salary Coefficient: " << e.salaryCoefficient << std::endl;
        e.birthDay.print("Birth Day");
        e.appointmentDate.print("Appointment Date");
        std::cout << "Length of Service: " << e.lengthService << std::endl;
    }


};
class TemporaryEmployee : public Employee{

};
class PermanentEmployee : public Employee{

};

#endif //ASSIGNMENT2_EMPLOYEE_H
