  // Copyright 2015 <Copyright Owner>
#pragma once

#include <iostream>
#include <list>
using std::ostream;

#include "Student.h"
#include "ListBase.h"

#include "Exceptions.h"

typedef ExceptionObjectExist<Student> ExceptionStudentExist;
typedef ExceptionObjectNotFound<Student> ExceptionStudentNotFound;

const int TypeStudents = TypeStudent * 1000;

class Students : public ListBase<Student> {
 public:
    Students();
    Students(const Students& students);

    ~Students();

    bool Equals(const EqualsAbstr& obj) const;
    int ClassType() const;

    // Оператор <<
    friend ostream& operator<<(ostream& os, const Students& students);
};

ostream& operator<<(ostream& os, const Students& students);
