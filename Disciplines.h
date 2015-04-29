  // Copyright 2015 <Copyright Owner>
#pragma once

#include <iostream>
#include <list>

#include "Discipline.h"
#include "ListBase.h"

#include "Exceptions.h"

typedef ExceptionObjectExist<Discipline> ExceptionDisciplineExist;
typedef ExceptionObjectNotFound<Discipline> ExceptionDisciplineNotFound;

const int TypeDisciplines = TypeDiscipline * 1000;

class Disciplines : public ListBase<Discipline> {
 public:
    Disciplines();
    Disciplines(const Disciplines& disciplines);

    ~Disciplines();

    bool Equals(const EqualsAbstr& obj) const;
    int ClassType() const;

    //Оператор <<
    friend ostream& operator<<(ostream& os, const Disciplines& disciplines);
};

ostream& operator<<(ostream& os, const Disciplines& disciplines);
