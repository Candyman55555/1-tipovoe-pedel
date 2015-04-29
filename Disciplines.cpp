  // Copyright 2015 <Copyright Owner>
#include "Disciplines.h"

#include <algorithm>

Disciplines::Disciplines()
    : ListBase<Discipline>() {
}

Disciplines::Disciplines(const Disciplines& disciplines)
    : ListBase<Discipline>(disciplines) {
}

Disciplines::~Disciplines() {
}

bool Disciplines::Equals(const EqualsAbstr& obj) const {
    if (!EqualsAbstr::Equals((EqualsAbstr&)obj)) { return false; }

    Disciplines& o = (Disciplines&)obj;
    if (o.size() != this->size()) return false;

    bool equals = true;

    std::for_each(this->begin(), this->end(),
            [o, &equals](const Discipline& d) {
                    equals &= equals & o.Contains(d);
                });

    return equals;
}

int Disciplines::ClassType() const {
    return TypeDisciplines;
}


//Оператор <<
ostream& operator<<(ostream& os, const Disciplines& disciplines) {
    os << "Дисциплины: " << endl;
    os << (ListBase<Discipline>&)disciplines << endl;

    return os;
}
