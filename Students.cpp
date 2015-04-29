  // Copyright 2015 <Copyright Owner>
#include "Students.h"

#include <algorithm>

using std::endl;

Students::Students()
    : ListBase<Student>() {
}

Students::Students(const Students& students)
    : ListBase<Student>(students) {
}

Students::~Students() {
    this->clear();
}

bool Students::Equals(const EqualsAbstr& obj) const {
    if (!EqualsAbstr::Equals((EqualsAbstr&)obj)) { return false; }

    Students& o = (Students&)obj;
    if (o.size() != this->size()) return false;

    bool equals = true;

    std::for_each(this->begin(), this->end(),
            [o, &equals](const Student& s) {
                    equals &= equals & o.Contains(s);
                });

    return equals;
}

int Students::ClassType() const {
    return TypeStudents;
}

ostream& operator<<(ostream& os, const Students& students) {
    os << "Студенты: " << endl;
    os << (ListBase<Student>&)students << endl;
    return os;
}
