  // Copyright 2015 <Copyright Owner>
#pragma once

#include <iostream>
#include <string>
using std::string;
using std::ostream;

#include "ObjectNumName.h"

const int TypeStudent = 2;

class Student : public ObjectNumName {
 private:
    string info;  // Номер зачетной книжки
    int year;  // Курс

    void init(int year, const string& info);

 public:
    // Конструкторы
    Student();
    Student(int num, const string& name, int year);
    Student(int num, const string& name, int year, const string& info);
    Student(const Student& student);

    ~Student();

    string GetInfo() const;
    void SetInfo(const string& info);

    int GetYear() const;
    void SetYear(int year);

    int ClassType() const;

    // Оператор <<
    friend ostream& operator<<(ostream& os, const Student& student);

    // Оператор =
    Student& operator=(const Student& right);

    // Оператор ==
    friend bool operator==(const Student& left, const Student& right);
};

// Оператор <<
ostream& operator<<(ostream& os, const Student& student);
