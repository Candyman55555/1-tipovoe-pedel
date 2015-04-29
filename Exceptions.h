  // Copyright 2015 <Copyright Owner>
#pragma once

#include <string>
#include <exception>

using std::string;
using std::exception;

  // Выход за границы контейнера
class ExceptionIndexOutOfBound : public exception {
 protected:
    string message;

 public:
    explicit ExceptionIndexOutOfBound(int index);
    ExceptionIndexOutOfBound(const ExceptionIndexOutOfBound& e);

    virtual ~ExceptionIndexOutOfBound();

    virtual const char* what() const throw();
};

  // Базовый класс для исключений,
  // Связанных с элементом списка

template <typename T>
class ExceptionObjectExist : public exception {
 protected:
    string message;

 public:
    explicit ExceptionObjectExist(const T& object);
    ExceptionObjectExist(const ExceptionObjectExist& e);

    virtual ~ExceptionObjectExist();

    virtual const char* what() const throw();
};

template <typename T>
class ExceptionObjectNotFound : public exception {
 protected:
    string message;

 public:
    explicit ExceptionObjectNotFound(const T& object);
    ExceptionObjectNotFound(const ExceptionObjectNotFound& e);

    virtual ~ExceptionObjectNotFound();

    virtual const char* what() const throw();
};

#include "ExceptionsImpl.h"
