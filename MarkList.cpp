  // Copyright 2015 <Copyright Owner>
#include "MarkList.h"

#include <iomanip>

#include <algorithm>
using std::ostream;


MarkList::MarkList() : ListBase<Mark>() {
}

MarkList::MarkList(const MarkList& marks)
    : ListBase<Mark>(marks) {
}

MarkList::~MarkList() {
    this->clear();
}

void MarkList::Add(const Mark& element) {
    ListBase<Mark>::Add(element);
}

void MarkList::Add(const ListBase<Mark>& l) {
    ListBase<Mark>::Add(l);
}

void MarkList::Add(const Student& student, const Discipline& discipline,
                   double mark) {
    Add(Mark(student, discipline, mark));
}

void MarkList::Remove(const Mark& eleemnt) {
    ListBase<Mark>::Remove(eleemnt);
}

void MarkList::Remove(const ListBase<Mark>& l) {
    ListBase<Mark>::Remove(l);
}

void MarkList::Remove(const Student& student) {
    this->remove_if(
        [student](const Mark& m) -> bool {
                return student.Equals(m.GetStudent());
            });
}

void MarkList::Remove(const Students& students) {
    this->remove_if(
        [students](const Mark& m) -> bool {
                return students.Contains(m.GetStudent());
            });
}

void MarkList::Remove(const Discipline& discipline) {
    this->remove_if(
        [discipline](const Mark& m) -> bool {
                return discipline.Equals(m.GetDiscipline());
            });
}

void MarkList::Remove(const Disciplines& disciplines) {
    this->remove_if(
        [disciplines](const Mark& m) -> bool {
                return disciplines.Contains(m.GetDiscipline());
            });
}

ostream& operator<<(ostream& os, const MarkList& marks) {
    os << "Оценки: " << endl;
    os << (ListBase<Mark>&)marks << endl;

    return os;
}
