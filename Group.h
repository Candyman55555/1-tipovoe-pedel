  // Copyright 2015 <Copyright Owner>


#pragma once

#include <iostream>
#include <list>
#include <string>
using std::string;
using std::ostream;

#include "Student.h"
#include "Students.h"

#include "Discipline.h"
#include "Disciplines.h"

#include "Mark.h"
#include "MarkList.h"

class Group : public ObjectNumName {
 private:
    Students students;
    Disciplines disciplines;
    MarkList marks;

    void init(const Students& students, const Disciplines& disciplines,
        const MarkList& marks);

 public:
    Group();
    Group(int num, const string& name);
    Group(const Group& group);

    ~Group();

    void AddStudent(const Student& student);
    void AddStudents(const Students& students);

    void AddDicipline(const Discipline& discipline);
    void AddDiciplines(const Disciplines& disciplines);

    void SetMark(const Student& student, const Discipline& discipline,
        double mark);
    void SetMark(const Mark& mark);
    void SetMarks(const MarkList& markList);

    Mark GetAvgMarkByDicipline(const Discipline& discipline) const;
    MarkList GetAvgMarkByDiciplines() const;
    Mark GetAvgTotal() const;

    MarkList GetStudentMarks(const Student& student) const;

    bool StudentIsPoor(const Student& student) const;
    bool StudentIsExcelent(const Student& student) const;

    Students GetPoorStudents() const;
    Students GetExcelentStudents() const;

    // Оператор <<
    friend ostream& operator<<(ostream& os, const Group& group);

    // Оператор +
    friend Group operator+(const Group& left, const Group& right);

    // Оператор =
    Group& operator=(const Group& right);

    // Оператор ==
    friend bool operator==(const Group& left, const Group& right);
};

ostream& operator<<(ostream& os, const Group& group);
Group operator+(const Group& left, const Group& right);
