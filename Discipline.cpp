  // Copyright 2015 <Copyright Owner>
#include "Discipline.h"

#include <iomanip>
#include <string>

void Discipline::init(double minMark, double excelentMark) {
    this->SetMinMark(minMark);
    this->SetExcelentMark(excelentMark);
}

Discipline::Discipline() : ObjectNumName() {
    this->init(50.0, 100.0);
}

Discipline::Discipline(int num, const string& name)
    : ObjectNumName(num, name) {
    this->init(50.0, 100.0);
}

Discipline::Discipline(int num, const string& name,
            double minMark, double excelentMark)
    : ObjectNumName(num, name) {
    this->init(minMark, excelentMark);
}

Discipline::Discipline(const Discipline& d)
    : ObjectNumName((Discipline&)d) {
    this->init(d.GetMinMark(), d.GetExcelentMark());
}

Discipline::~Discipline() {
}

double Discipline::GetMinMark() const {
    return this->minMark;
}

void Discipline::SetMinMark(double mark) {
    this->minMark = mark;
}

double Discipline::GetExcelentMark() const {
    return this->excelentMark;
}

void Discipline::SetExcelentMark(double mark) {
    this->excelentMark = mark;
}

int Discipline::ClassType() const {
    return TypeDiscipline;
}


// Оператор <<
ostream& operator<<(ostream& os, const Discipline& d) {
    os << "Дисциплина: " << endl;
    os << "Номер: " << fixed << d.GetNum() << endl;
    os << "Наименование: " << d.GetName() << endl;
    os << "Балов для зачета: " << fixed << std::setprecision(3) <<
        d.GetMinMark() << endl;
    os << "Балов для отлично: " << fixed << std::setprecision(3) <<
        d.GetExcelentMark() << endl;

    return os;
}

// оператор =
Discipline& Discipline::operator=(const Discipline& right) {
    if (this == &right) {
        return *this;
    }

    ObjectNumName::operator=(right);
    this->SetMinMark(right.GetMinMark());
    this->SetExcelentMark(right.GetExcelentMark());

    return *this;
}

// Оператор ==
bool operator==(const Discipline& left, const Discipline& right) {
    return left.Equals(right);
}
