  // Copyright 2015 <Copyright Owner>
#pragma once

#include <iostream>
#include <list>
using std::ostream;

#include "Mark.h"
#include "ListBase.h"

#include "Student.h"
#include "Students.h"

#include "Discipline.h"
#include "Disciplines.h"

#include "Exceptions.h"

typedef ExceptionObjectExist<Mark> ExceptionMarkExist;
typedef ExceptionObjectNotFound<Mark> ExceptionMarkNotFound;

const int TypeMarkList = TypeMark * 1000;

class MarkList : public ListBase<Mark> {
 public:
    MarkList();
    MarkList(const MarkList& marks);

    virtual ~MarkList();

    virtual void Add(const Mark& element);
    virtual void Add(const ListBase<Mark>& l);
    virtual void Add(const Student& student, const Discipline& discipline,
        double mark);

    virtual void Remove(const Mark& eleemnt);
    virtual void Remove(const ListBase<Mark>& l);

    // Удаление всех отметок для заданного студента
    virtual void Remove(const Student& student);
    virtual void Remove(const Students& students);

    // Удаление всех отметок для заданной дисциплины
    virtual void Remove(const Discipline& discipline);
    virtual void Remove(const Disciplines& disciplines);

    // Оператор <<
    friend ostream& operator<<(ostream& os, const MarkList& marks);
};

ostream& operator<<(ostream& os, const MarkList& marks);
