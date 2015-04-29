  // Copyright 2015 <Copyright Owner>
#define _CRT_RAND_S
#include <stdio.h>
#include <conio.h>

#include <cstdlib>

#include "Exceptions.h"

#include "ListBase.h"

#include "Student.h"
#include "Students.h"

#include "Discipline.h"
#include "Disciplines.h"

#include "Mark.h"
#include "MarkList.h"

#include "Group.h"

#include <sstream>
#include <iostream>
using std::cout;
using std::endl;
using std::stringstream;

  // Примеры для класса ListBase
void TestListBase() {
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "Примеры для класса ListBase: " << endl;
    cout << endl;

    ListBase<int> list1 = ListBase<int>();
    list1.Add(10);
    list1.Add(20);
    list1.Add(30);
    cout << list1 << endl;

    ListBase<int> list2 = list1;
    list2.RemoveByIndex(0);
    list2.Remove(20);
    cout << list2 << endl;

    ListBase<int> list3 = list1;
    list3.Remove(list2);
    cout << list3 << endl;
    cout << list3[0] << endl;
    cout << endl;

    ListBase<int> list4 = list1;
    cout << (list1 == list2) << endl;
    cout << (list1 == list4) << endl;

    cout << endl;
    cout << (list1.Contains(1000)) << endl;
    cout << (list1.Contains(10)) << endl;

    cout << "---------------------------" << endl;
}

  // Примеры для класса ListBase, Exceptions
void TestListBaseExceptions() {
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "Примеры для класса ListBase, Exceptions: " << endl;
    cout << endl;

    ListBase<int> list1 = ListBase<int>();
    list1.Add(10);
    list1.Add(20);
    list1.Add(30);

    // Выход за границы массива
    try {
        list1.Get(-1);
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    // Выход за границы массива
    try {
        list1.Get(50);
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    // Выход за границы массива
    try {
        int elem = list1[125];
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    // Выход за границы массива
    try {
        list1.RemoveByIndex(10004);
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    // Элемент не найден
    try {
        list1.GetIndex(1323);
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    // Элемент не найден
    try {
        list1.Remove(1400);
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    cout << "---------------------------" << endl;
}

  // Примеры для класса Student
void TestStudent() {
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "Примеры для класса Student: " << endl;
    cout << endl;

    // Статическое создание без параметров
    Student student1 = Student();
    student1.SetNum(1);
    student1.SetYear(3);
    student1.SetName("Студент Студентович");
    student1.SetInfo("Информация о студенте №1");

    // Статическое копирование
    Student student1Copy = student1;
    student1Copy.SetInfo("Статическая копия студента №1");

    cout << student1 << endl;
    cout << student1Copy << endl;

    // Сравнение по номеру
    cout << "student1 " << (student1.Equals(student1Copy) ? "==" : "!=") <<
        " student1Copy"
        << endl << endl;

    // Статическое создание с параметрами
    Student student2 = Student(2, "Студент 2", 2, "Информация 2");
    cout << student2 << endl;

    // Сравнение по номеру
    cout << "student1 " << (student1.Equals(student2) ? "==" : "!=") <<
        " student2" << endl << endl;

    // Динамическое создание с параметрами
    Student *student3 = new Student(3, "Студент 3", 1, "Информация 3");
    cout << (*student3) << endl;

    // Статическое создание из другого объекта
    Student student4 = Student(*student3);
    student4.SetInfo("Копия студента 3 по указателю");
    cout << student4 << endl;

    // Динамическое создание из другого объекта по ссылке
    Student *student5 = new Student(student2);
    student5->SetInfo("Копия студента 2 по ссылке");
    cout << (*student5) << endl;

    delete student3;
    delete student5;
    cout << "---------------------------" << endl;
}

  // Примеры для класса Discipline
void TestDiscipline() {
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "Примеры для класса Discipline: " << endl;
    cout << endl;

    // Статическое создание без параметров
    Discipline d1 = Discipline();
    d1.SetNum(1);
    d1.SetName("Дисциплина 1");
    d1.SetMinMark(56.12423);
    d1.SetExcelentMark(567.2000123);

    // Статическое копирование
    Discipline d1Copy = d1;
    d1Copy.SetName("Статическая копия дисциплины №1");

    cout << d1 << endl;
    cout << d1Copy << endl;

    // Сравнение по номеру
    cout << "d1 " << (d1.Equals(d1Copy) ? "==" : "!=") << " d1Copy"
        << endl << endl;

    // Статическое создание с параметрами
    Discipline d2 = Discipline(2, "Дисциплина 2", 20, 200);
    cout << d2 << endl;

    // Сравнение по номеру
    cout << "d1 " << (d1.Equals(d2) ? "==" : "!=") << " d2"
        << endl << endl;

    // Динамическое создание с параметрами
    Discipline *d3 = new Discipline(3, "Дисциплина 3", 30, 300);
    cout << (*d3) << endl;

    // Статическое создание из другого объекта по указателю
    Discipline d4 = Discipline(*d3);
    d4.SetName("Копия дисциплины 3 по указателю");
    cout << d4 << endl;

    // Динамическое создание из другого объекта по ссылке
    Discipline *d5 = new Discipline(d2);
    d5->SetName("Копия дисциплины 2 по ссылке");
    cout << (*d5) << endl;

    delete d3;
    delete d5;

    cout << "---------------------------" << endl;
}

int UniqStudentNum = 0;
Student GetNewStudent() {
    UniqStudentNum++;

    Student student = Student();
    student.SetNum(UniqStudentNum);

    stringstream name = stringstream();
    name << "Студент " << UniqStudentNum;
    student.SetName(name.str());

    stringstream info = stringstream();
    info << "Информация " << UniqStudentNum;
    student.SetInfo(info.str());

    student.SetYear(1);

    return student;
}

int UniqDisciplineNum = 0;
Discipline GetNewDiscipline() {
    UniqDisciplineNum++;

    Discipline d = Discipline();
    d.SetNum(UniqDisciplineNum);

    stringstream name = stringstream();
    name << "Дисциплина " << UniqDisciplineNum;
    d.SetName(name.str());

    unsigned int rand_val;
    if (rand_s(&rand_val) != 0)
        return d;
    d.SetMinMark(rand_val);

    if (rand_s(&rand_val) != 0)
        return d;
    double excelent = static_cast<double>(rand_val);
    d.SetExcelentMark(excelent > d.GetMinMark() ? excelent :
        d.GetMinMark()*2);

    return d;
}

  // Примеры для класса контейнера Students
void TestStudents() {
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "Примеры для класса Students: " << endl;
    cout << endl;

    UniqStudentNum = 0;

    Student student1 = GetNewStudent();
    Student student2 = GetNewStudent();
    Student student3 = GetNewStudent();
    Student student4 = GetNewStudent();
    Student student5 = GetNewStudent();

    // Создание и добавление объектов
    Students students1 = Students();
    students1.Add(student1);
    students1.Add(student2);
    students1.Add(student3);
    cout << students1 << endl;

    // Создание и уделаение объектов / Contains
    Students students2 = Students(students1);
    students2.Remove(student1);
    cout << students2 << endl;
    cout << "students2.Contains(&student1) = " <<
        students2.Contains(student1) << endl;
    cout << "students2.Contains(&student2) = " <<
        students2.Contains(student2) << endl;
    cout << endl;

    // Создание и массвое удаление
    Students *students3 = new Students(students1);
    students3->Remove(students2);
    cout << *students3 << endl;

    // Создание и массовое добавление объектов
    Students *students4 = new Students();
    students4->Add(students1);
    cout << *students4 << endl;

    delete students3;
    delete students4;

    cout << "---------------------------" << endl;
}

  // Примеры для класса контейнера Students, Exceptions
void TestStudentsExceptions() {
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "Примеры для класса контейнера Students, Exceptions: " <<
        endl;
    cout << endl;

    UniqStudentNum = 0;

    // Создание и добавление объектов
    Students students1 = Students();
    students1.Add(GetNewStudent());
    students1.Add(GetNewStudent());
    students1.Add(GetNewStudent());

    // Выход за границы массива
    try {
        students1.Get(-1);
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    // Выход за границы массива
    try {
        students1.Get(50);
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    // Выход за границы массива
    try {
        Student elem = students1[125];
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    // Выход за границы массива
    try {
        students1.RemoveByIndex(10004);
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    // Элемент не найден
    try {
        students1.GetIndex(GetNewStudent());
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    // Элемент не найден
    try {
        students1.Remove(GetNewStudent());
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    cout << "---------------------------" << endl;
}

  // Примеры для класса контейнера Disciplines
void TestDisciplines() {
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "Примеры для класса Disciplines: " << endl;
    cout << endl;

    UniqDisciplineNum = 0;

    Discipline discipline1 = GetNewDiscipline();
    Discipline discipline2 = GetNewDiscipline();
    Discipline discipline3 = GetNewDiscipline();
    Discipline discipline4 = GetNewDiscipline();
    Discipline discipline5 = GetNewDiscipline();

    // Создание и добавление объектов
    Disciplines disciplines1 = Disciplines();
    disciplines1.Add(discipline1);
    disciplines1.Add(discipline2);
    disciplines1.Add(discipline3);
    cout << disciplines1 << endl;

    // Создание и уделаение объектов / Contains
    Disciplines disciplines2 = Disciplines(disciplines1);
    disciplines2.Remove(discipline1);
    cout << disciplines2 << endl;
    cout << "students2.Contains(&student1) = " <<
        disciplines2.Contains(discipline1) << endl;
    cout << "students2.Contains(&student2) = " <<
        disciplines2.Contains(discipline2) << endl;
    cout << endl;

    // Создание и массвое удаление
    Disciplines *disciplines3 = new Disciplines(disciplines1);
    disciplines3->Remove(disciplines2);
    cout << *disciplines3 << endl;

    // Создание и массовое добавление объектов
    Disciplines *disciplines4 = new Disciplines();
    disciplines4->Add(disciplines1);
    cout << *disciplines4 << endl;

    delete disciplines3;
    delete disciplines4;

    cout << "---------------------------" << endl;
}

  // Примеры для класса контейнера Disciplines, Exceptions
void TestDisciplinesExceptions() {
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "Примеры для класса контейнера Disciplines, Exceptions: " <<
        endl;
    cout << endl;

    UniqStudentNum = 0;

    // Создание и добавление объектов
    Disciplines disciplines1 = Disciplines();
    disciplines1.Add(GetNewDiscipline());
    disciplines1.Add(GetNewDiscipline());
    disciplines1.Add(GetNewDiscipline());

    // Выход за границы массива
    try {
        disciplines1.Get(-1);
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    // Выход за границы массива
    try {
        disciplines1.Get(50);
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    // Выход за границы массива
    try {
        Discipline elem = disciplines1[125];
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    // Выход за границы массива
    try {
        disciplines1.RemoveByIndex(10004);
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    // Элемент не найден
    try {
        disciplines1.GetIndex(GetNewDiscipline());
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    // Элемент не найден
    try {
        disciplines1.Remove(GetNewDiscipline());
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    cout << "---------------------------" << endl;
}


  // Примеры для класса Mark
void TestMark() {
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "Примеры для класса Mark: " << endl;
    cout << endl;

    UniqStudentNum = 0;
    UniqDisciplineNum = 0;

    Student student1 = GetNewStudent();
    Student student2 = GetNewStudent();
    Student student3 = GetNewStudent();
    Student student4 = GetNewStudent();
    Student student5 = GetNewStudent();

    Discipline discipline1 = GetNewDiscipline();
    Discipline discipline2 = GetNewDiscipline();
    Discipline discipline3 = GetNewDiscipline();
    Discipline discipline4 = GetNewDiscipline();
    Discipline discipline5 = GetNewDiscipline();

    // Статическое создание / зачтено, не отличник
    Mark mark1 = Mark(student1, discipline1);
    mark1.SetMark(discipline1.GetMinMark());
    cout << mark1 << endl;

    // Динамическое создание / не зачтено, не отличник
    Mark *mark2 = new Mark(student2, discipline1, discipline1.GetMinMark()/2);
    cout << (*mark2) << endl;

    // Статическое копирование / зачтено, отличник
    Mark mark3 = (*mark2);
    mark3.SetMark(mark3.GetDiscipline().GetExcelentMark() * 2);
    cout << mark3 << endl;

    cout << (mark3 == (*mark2)) << endl;
    cout << mark3.Equals((EqualsAbstr&)mark1) << endl;

    delete mark2;

    cout << "---------------------------" << endl;
}

  // Примеры для класса Mark
void TestMarkList() {
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "Примеры для класса MarkList: " << endl;
    cout << endl;

    UniqStudentNum = 0;
    UniqDisciplineNum = 0;

    Student student1 = GetNewStudent();
    Student student2 = GetNewStudent();
    Student student3 = GetNewStudent();
    Student student4 = GetNewStudent();
    Student student5 = GetNewStudent();

    Discipline discipline1 = GetNewDiscipline();
    Discipline discipline2 = GetNewDiscipline();
    Discipline discipline3 = GetNewDiscipline();
    Discipline discipline4 = GetNewDiscipline();
    Discipline discipline5 = GetNewDiscipline();

    Mark mark1 = Mark(student1, discipline1, rand());
    Mark mark2 = Mark(student2, discipline2, rand());
    Mark mark3 = Mark(student3, discipline3, rand());
    Mark mark4 = Mark(student1, discipline3, rand());
    Mark mark5 = Mark(student3, discipline1, rand());

    // Создание
    MarkList markList1 = MarkList();

    // Добавление
    markList1.Add(mark1);
    markList1.Add(mark2);
    markList1.Add(mark3);
    markList1.Add(mark4);
    markList1.Add(mark5);
    cout << markList1 << endl;

    // Статическое копирование
    MarkList markList2 = markList1;
    // Удаление по оценке
    markList2.Remove(mark1);
    cout << markList2 << endl;

    MarkList markList3 = MarkList(markList1);
    // Удаление по студенту
    markList3.Remove(student1);
    cout << markList3 << endl;

    MarkList *markList4 = new MarkList(markList1);
    // Удаление по дисциплине
    markList4->Remove(discipline1);
    cout << *markList4 << endl;

    delete markList4;

    cout << "---------------------------" << endl;
}

  // Примеры для класса Group
void TesGroup() {
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "Примеры для класса Group: " << endl;
    cout << endl;

    UniqStudentNum = 0;
    UniqDisciplineNum = 0;

    Student student1 = GetNewStudent();
    Student student2 = GetNewStudent();
    Student student3 = GetNewStudent();
    Student student4 = GetNewStudent();
    Student student5 = GetNewStudent();

    Discipline discipline1 = GetNewDiscipline();
    Discipline discipline2 = GetNewDiscipline();
    Discipline discipline3 = GetNewDiscipline();

    Group group = Group(1, "Группа 1");
    group.AddStudent(student1);
    group.AddStudent(student2);
    group.AddStudent(student3);

    group.AddDicipline(discipline1);
    group.AddDicipline(discipline2);
    group.AddDicipline(discipline3);

    group.SetMark(student1, discipline1, discipline1.GetMinMark());
    group.SetMark(student1, discipline2, discipline2.GetMinMark());
    group.SetMark(student1, discipline3, discipline3.GetExcelentMark() * 2);

    group.SetMark(student2, discipline1, discipline1.GetExcelentMark() * 2);
    group.SetMark(student2, discipline2, discipline2.GetExcelentMark() * 2);
    group.SetMark(student2, discipline3, discipline3.GetExcelentMark() * 2);

    group.SetMark(student3, discipline1, discipline1.GetMinMark());
    group.SetMark(student3, discipline2, discipline2.GetMinMark() / 2);
    group.SetMark(student3, discipline3, discipline3.GetMinMark());

    cout << group << endl;

    Group group2 = Group(2, "Группа 2");
    group2.AddStudent(student4);
    group2.AddStudent(student5);

    group2.AddDicipline(discipline1);
    group2.AddDicipline(discipline2);
    group2.AddDicipline(discipline3);

    group2.SetMark(student4, discipline1, discipline1.GetExcelentMark() * 2);
    group2.SetMark(student4, discipline2, discipline2.GetExcelentMark() * 2);
    group2.SetMark(student4, discipline3, discipline3.GetExcelentMark() * 2);

    group2.SetMark(student5, discipline1, discipline1.GetMinMark());
    group2.SetMark(student5, discipline2, discipline2.GetMinMark() / 2);
    group2.SetMark(student5, discipline3, discipline3.GetMinMark());

    Group group3 = group + group2;
    cout << group3 << endl;

    cout << "---------------------------" << endl;
}

  // Примеры для класса Group, Exceptions
void TesGroupExceptions() {
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "Примеры для класса Group, Exceptions: " << endl;
    cout << endl;

    UniqStudentNum = 0;
    UniqDisciplineNum = 0;

    Student student1 = GetNewStudent();
    Student student2 = GetNewStudent();
    Student student3 = GetNewStudent();
    Student student4 = GetNewStudent();
    Student student5 = GetNewStudent();

    Discipline discipline1 = GetNewDiscipline();
    Discipline discipline2 = GetNewDiscipline();
    Discipline discipline3 = GetNewDiscipline();

    Group group = Group(1, "Группа 1");
    group.AddStudent(student1);
    group.AddStudent(student2);
    group.AddStudent(student3);

    group.AddDicipline(discipline1);
    group.AddDicipline(discipline2);
    group.AddDicipline(discipline3);

    group.SetMark(student1, discipline1, discipline1.GetMinMark());
    group.SetMark(student1, discipline2, discipline2.GetMinMark());
    group.SetMark(student1, discipline3, discipline3.GetExcelentMark() * 2);

    group.SetMark(student2, discipline1, discipline1.GetExcelentMark() * 2);
    group.SetMark(student2, discipline2, discipline2.GetExcelentMark() * 2);
    group.SetMark(student2, discipline3, discipline3.GetExcelentMark() * 2);

    group.SetMark(student3, discipline1, discipline1.GetMinMark());
    group.SetMark(student3, discipline2, discipline2.GetMinMark() / 2);
    group.SetMark(student3, discipline3, discipline3.GetMinMark());

    // Добавление уже существующей дисциплины
    try {
        group.AddDicipline(discipline1);
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    // Добавление уже существующего студента
    try {
        group.AddStudent(student1);
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    // Оценка для несущесвующего предмета
    try {
        group.SetMark(student1, GetNewDiscipline(), 1000);
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    // Оценка для несущесвующего студента
    try {
        group.SetMark(GetNewStudent(), discipline1, 2500);
    }
    catch(const std::exception& e) {
        cout << e.what() << endl;
    }

    cout << "---------------------------" << endl;
}


int main() {
    setlocale(LC_ALL, "Russian");

    TestListBase();
    getch();

    TestListBaseExceptions();
    getch();

    TestStudent();
    getch();

    TestStudents();
    getch();

    TestStudentsExceptions();
    getch();

    TestDiscipline();
    getch();

    TestDisciplines();
    getch();

    TestDisciplinesExceptions();
    getch();

    TestMark();
    getch();

    TestMarkList();
    getch();

    TesGroup();
    getch();

    TesGroupExceptions();
    getch();

    return 0;
}
