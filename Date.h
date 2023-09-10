//
// Created by Can on 25.11.2021.
//

#ifndef ASSIGNMENT2_DATE_H
#define ASSIGNMENT2_DATE_H


#include <ostream>

class Date {
public:
    int day;
    int month;
    int year;

    friend std::ostream &operator<<(std::ostream &os, const Date &date) {
        os << date.year << "-" << date.month << "-" << date.day;
        return os;
    }

    void print(std::string type) const{
        std::cout << type << ": " << day << "-" << month << "-" << year << std::endl;
    }
};


#endif //ASSIGNMENT2_DATE_H
