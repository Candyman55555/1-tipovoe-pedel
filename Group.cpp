  // Copyright 2015 <Copyright Owner>
#include "Group.h"

#include <iomanip>
#include <algorithm>
#include <string>

using std::cout;

void Group::init(const Students& students, const Disciplines& disciplines,
                 const MarkList& marks) {
    this->students = students;
    this->disciplines = disciplines;
    this->marks = marks;
}

Group::Group()
    : ObjectNumName() {
    init(Students(), Disciplines(), MarkList());
}

Group::Group(int num, const string& name)
    : ObjectNumName(num, name) {
    init(Students(), Disciplines(), MarkList());
}

Group::Group(const Group& group)
    : ObjectNumName((ObjectNumName&)group) {
    init(Students(group.students),
         Disciplines(group.disciplines),
         MarkList(group.marks));
}

Group::~Group() {
}


void Group::AddStudent(const Student& student) {
    if (this->students.Contains(student)) {
        throw ExceptionStudentExist(student);
    }

    this->students.Add(student);

    std::for_each(this->disciplines.begin(), this->disciplines.end(),
            [this, student](const Discipline& d) {
                    try {
                        this->marks.Add(Mark(student, d, 0));
                    } catch(...) {}
                });
}

void Group::AddStudents(const Students& students) {
    std::for_each(students.begin(), students.end(),
            [this](const Student& s) {
                    try {
                        this->AddStudent(s);
                    } catch(...) {}
                });
}

void Group::AddDicipline(const Discipline& discipline) {
    if (this->disciplines.Contains(discipline)) {
        throw ExceptionDisciplineExist(discipline);
    }

    this->disciplines.Add(discipline);

    std::for_each(this->students.begin(), this->students.end(),
            [this, discipline](const Student& s) {
                    try {
                        this->marks.Add(Mark(s, discipline, 0));
                    } catch(...) {}
                });
}

void Group::AddDiciplines(const Disciplines& disciplines) {
        std::for_each(disciplines.begin(), disciplines.end(),
            [this](const Discipline& d) {
                    try {
                        this->AddDicipline(d);
                    } catch(...) {}
                });
}


void Group::SetMark(const Student& student, const Discipline& discipline,
                    double mark) {
    this->SetMark(Mark(student, discipline, mark));
}

void Group::SetMark(const Mark& mark) {
    if (!this->students.Contains(mark.GetStudent())) {
        throw ExceptionStudentNotFound(mark.GetStudent());
    }

    if (!this->disciplines.Contains(mark.GetDiscipline())) {
        throw ExceptionDisciplineNotFound(mark.GetDiscipline());
    }

    try {
        this->marks.Remove(mark);
    } catch(...) {}

    this->marks.Add(mark);
}

void Group::SetMarks(const MarkList& markList) {
    std::for_each(markList.begin(), markList.end(),
        [this](const Mark& m) {
                try {
                    this->SetMark(Mark(m));
                } catch(...) {}
            });
}

Mark Group::GetAvgMarkByDicipline(const Discipline& discipline) const {
    //Сумма оценок по дисциплине
    Mark mark(Student(), discipline, 0);
    int count = 0;

    std::for_each(this->marks.begin(), this->marks.end(),
        [this, &mark, &count](const Mark& m) {
                if (m.GetDiscipline().Equals(mark.GetDiscipline())) {
                    mark.SetMark(mark.GetMark() + m.GetMark());
                    count++;
                }
            });

    Mark result(mark);

    if (count > 0) {
        result.SetMark(mark.GetMark() / count);
    } else {
        result.SetMark(0);
    }

    return result;
}


MarkList Group::GetAvgMarkByDiciplines() const {
    MarkList temp;

    std::for_each(this->disciplines.begin(), this->disciplines.end(),
        [this, &temp](const Discipline& d) {
                Mark davg = this->GetAvgMarkByDicipline(d);
                temp.Add(davg);
            });

    return temp;
}


Mark Group::GetAvgTotal() const {
    double sum;
    int count;

    sum = 0;
    count = 0;

    MarkList avglist = this->GetAvgMarkByDiciplines();
    std::for_each(avglist.begin(), avglist.end(),
        [&sum, &count](const Mark& m) {
                sum += m.GetMark();
                count++;
            });

    double avg = count > 0 ? sum/count : 0;

    return Mark(Student(), Discipline(), avg);
}

MarkList Group::GetStudentMarks(const Student& student) const {
    if (!this->students.Contains(student)) {
        throw ExceptionStudentNotFound(student);
    }

    MarkList temp;

    std::for_each(this->marks.begin(), this->marks.end(),
        [this, &temp, &student](const Mark& m) {
                if (student.Equals(m.GetStudent()))
                    temp.Add(m);
            });

    return temp;
}

bool Group::StudentIsPoor(const Student& student) const {
    MarkList markList = GetStudentMarks(student);
    bool temp = false;

    std::for_each(markList.begin(), markList.end(),
        [&temp](const Mark& m) {
                if (!m.Enought()) temp = true;
            });

    return temp;
}

bool Group::StudentIsExcelent(const Student& student) const {
    MarkList markList = GetStudentMarks(student);
    bool temp = true;

    std::for_each(markList.begin(), markList.end(),
        [&temp](const Mark& m) {
                if (!m.Excelent()) temp = false;
            });

    return temp;
}

Students Group::GetPoorStudents() const {
    Students temp;

    std::for_each(this->students.begin(), this->students.end(),
        [this, &temp](const Student& s) {
                if (this->StudentIsPoor(s))
                    temp.Add(s);
            });

    return temp;
}

Students Group::GetExcelentStudents() const {
    Students temp;

    std::for_each(this->students.begin(), this->students.end(),
        [this, &temp](const Student& s) {
                if (this->StudentIsExcelent(s))
                    temp.Add(s);
            });

    return temp;
}





ostream& operator<<(ostream& os, const Group& group) {
    os << "Учебная группа: " << endl;
    os << "Номер: " << fixed << group.GetNum() << endl;
    os << "Наименование: " << group.GetName() << endl << endl;
    os << "Количетсво студентов: " << fixed << group.students.GetCount() <<
        endl;
    os << (group.students) << endl;
    os << "Количетсво Дисциплин: " << fixed << group.disciplines.GetCount() <<
        endl;
    os << (group.disciplines) << endl;

    MarkList avglist = group.GetAvgMarkByDiciplines();
    os << "Средние баллы по дисциплинам: " << endl;
    std::for_each(avglist.begin(), avglist.end(),
        [](const Mark& m) {
                cout << "Дисциплина: " << m.GetDiscipline().GetName()
                    << " Средний балл: " << fixed << std::setprecision(3) <<
                    m.GetMark() << endl;
            });

    os << endl;

    os << "Общий средний балл: " << fixed << std::setprecision(3) <<
        group.GetAvgTotal().GetMark() << endl;

    Students poorStudents = group.GetPoorStudents();
    os << "Студенты с долгами: " << endl << poorStudents << endl;

    Students excelentStudents = group.GetExcelentStudents();
    os << "Студенты отличники: " << endl << excelentStudents << endl;

    return os;
}


Group operator+(const Group& left, const Group& right) {
    Group result = Group(left);
    result.AddDiciplines(right.disciplines);
    result.AddStudents(right.students);

    result.SetMarks(right.marks);
    result.SetMarks(left.marks);

    return result;
}


  // Оператор =
Group& Group::operator=(const Group& right) {
    if (this == &right) {
        return *this;
    }

    ObjectNumName::operator=(right);
    init(Students(right.students),
         Disciplines(right.disciplines),
         MarkList(right.marks));

    return *this;
}

  // Оператор ==
bool operator==(const Group& left, const Group& right) {
    return left.Equals(right);
}
