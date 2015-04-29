  // Copyright 2015 <Copyright Owner>
#pragma once

#include <iostream>
using std::ostream;

#include "Equals.h"

#include "Student.h"
#include "Discipline.h"

const int TypeMark = 4;

class Mark : EqualsAbstr {
 private:
    Student student;
    Discipline discipline;
    double mark;  // Количетво баллов

    void init(const Student& student, const Discipline& discipline,
        double mark);

 public:
    Mark();
    Mark(const Student& student, const Discipline& discipline);
    Mark(const Student& student, const Discipline& discipline, double mark);
    Mark(const Mark &mark);

    virtual ~Mark();

    const Student GetStudent() const;
    const Discipline GetDiscipline() const;

    double GetMark() const;
    void SetMark(double mark);

    bool Enought() const;  // Достаточно ли для зачета
    bool Excelent() const;  // Достаточно ли для отличной оценки

    // Сравнение с другим объектом
    bool Equals(const EqualsAbstr& obj) const;
    int ClassType() const;

    // Оператор <<
    friend ostream& operator<<(ostream& os, const Mark& mark);

    // Оператор =
    Mark& operator=(const Mark& right);

    // Оператор ==
    friend bool operator==(const Mark& left, const Mark& right);
};

// Оператор <<
ostream& operator<<(ostream& os, const Mark& mark);
bool operator==(const Mark& left, const Mark& right);
