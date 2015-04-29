  // Copyright 2015 <Copyright Owner>
#pragma once

#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::endl;
using std::fixed;

#include "ObjectNumName.h"

const int TypeDiscipline = 3;

class Discipline : public ObjectNumName {
 private:
    double minMark;  // Минимальный бал для зачета
    double excelentMark;  // Количество баллов для отличной оценки

    void init(double minMark, double excelentMark);

 public:
    Discipline();
    Discipline(int num, const string& name);
    Discipline(int num, const string& name,
               double minMark, double excelentMark);

    Discipline(const Discipline& d);

    ~Discipline();

    double GetMinMark() const;
    void SetMinMark(double mark);

    double GetExcelentMark() const;
    void SetExcelentMark(double mark);

    int ClassType() const;

    // Оператор <<
    friend ostream& operator<<(ostream& os, const Discipline& d);

    // оператор =
    Discipline& operator=(const Discipline& right);

    // Оператор ==
    friend bool operator==(const Discipline& left, const Discipline& right);
};

// Оператор <<
ostream& operator<<(ostream& os, const Discipline& d);
