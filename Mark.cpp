  // Copyright 2015 <Copyright Owner>
#include "Mark.h"

#include <iomanip>

void Mark::init(const Student& student, const Discipline& discipline,
                double mark) {
    this->student = Student(student);
    this->discipline = Discipline(discipline);
    this->mark = mark;
}

Mark::Mark() {
    this->init(Student(), Discipline(), 10.0);
}

Mark::Mark(const Student &student, const Discipline &discipline)
    : EqualsAbstr() {
    this->init(student, discipline, discipline.GetMinMark());
}

Mark::Mark(const Student &student, const Discipline &discipline, double mark)
    : EqualsAbstr() {
    this->init(student, discipline, mark);
}

Mark::Mark(const Mark &mark)
    : EqualsAbstr(mark) {
    this->init(mark.GetStudent(), mark.GetDiscipline(), mark.GetMark());
}

Mark::~Mark() {
    this->mark = 0;
}

const Student Mark::GetStudent() const {
    return this->student;
}

const Discipline Mark::GetDiscipline() const {
    return this->discipline;
}

double Mark::GetMark() const {
    return this->mark;
}

void Mark::SetMark(const double mark) {
    this->mark = mark;
}

// Достаточно ли для зачета
bool Mark::Enought() const {
    return GetMark() >= GetDiscipline().GetMinMark();
}

// Достаточно ли для отличной оценки
bool Mark::Excelent() const {
    return GetMark() >= GetDiscipline().GetExcelentMark();
}

bool Mark::Equals(const EqualsAbstr& obj) const {
    if (!EqualsAbstr::Equals((EqualsAbstr&)obj)) { return false; }
    Mark &o = (Mark&)obj;

    return (o.GetStudent() == this->GetStudent()) &&
           (o.GetDiscipline() == this->GetDiscipline());
}

int Mark::ClassType() const {
    return TypeMark;
}

ostream& operator<<(ostream& os, const Mark& mark) {
    os << "Оценка: " << endl;
    os << "Студент: " << mark.GetStudent().GetName() << endl;
    os << "Дисциплина: " << mark.GetDiscipline().GetName() << endl;
    os << "Баллов: " << fixed << std::setprecision(3) << mark.GetMark() << endl;
    os << "Хватает на зачет " << (mark.Enought() ? "Да" : "Нет") << endl;
    os << "Хватает на отлично " << (mark.Excelent() ? "Да" : "Нет") << endl;

    return os;
}

//Оператор =
Mark& Mark::operator=(const Mark& right) {
    if (this == &right) {
        return *this;
    }

    this->init(right.GetStudent(), right.GetDiscipline(), right.GetMark());
    return *this;
}

//Оператор ==
bool operator==(const Mark& left, const Mark& right) {
    return left.Equals(right);
}
