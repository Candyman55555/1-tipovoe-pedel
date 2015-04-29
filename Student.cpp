  // Copyright 2015 <Copyright Owner>
#include "Student.h"

#include <string>
#include <iomanip>

using std::endl;
using std::fixed;

void Student::init(int year, const string& info) {
    this->SetYear(year);
    this->SetInfo(info);
}

Student::Student() : ObjectNumName() {
    this->init(1, "");
}

Student::Student(int num, const string& name, int year)
    : ObjectNumName(num, name) {
    this->init(year, "");
}

Student::Student(int num, const string& name, int year, const string& info)
    : ObjectNumName(num, name) {
    this->init(year, info);
}

Student::Student(const Student& student)
    : ObjectNumName((ObjectNumName&)student) {
    this->init(student.GetYear(),
               student.GetInfo());
}

Student::~Student() {
}

string Student::GetInfo() const {
    return this->info;
}

void Student::SetInfo(const string& info) {
    this->info = string(info);
}

int Student::GetYear() const {
    return this->year;
}

void Student::SetYear(const int year) {
    this->year = year;
}

int Student::ClassType() const {
    return TypeStudent;
}

ostream& operator<<(ostream& os, const Student& student) {
    os << "Студент: " << endl;
    os << "Номер зачетной книжки: " << fixed << student.GetNum() << endl;
    os << "Имя: " << student.GetName() << endl;
    os << "Информация: " << student.GetInfo() << endl;
    os << "Курс: " << fixed << student.GetYear() << endl;

    return os;
}

// =
Student& Student::operator=(const Student& right) {
    if (this == &right) {
        return *this;
    }

    ObjectNumName::operator=(right);
    this->init(right.GetYear(), right.GetInfo());
    return *this;
}

// Оператор ==
bool operator==(const Student& left, const Student& right) {
    return left.Equals(right);
}
