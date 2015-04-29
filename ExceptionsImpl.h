  // Copyright 2015 <Copyright Owner>
#pragma once

#include <sstream>
#include <iostream>


  // ObjectExist;

template <typename T>
ExceptionObjectExist<T>::ExceptionObjectExist(const T& object) {
    std::stringstream msg;
    msg << "Exception; Объект уже сущесвует в контейнере; object = ";
    msg << object;

    message = msg.str();
}

template <typename T>
ExceptionObjectExist<T>::ExceptionObjectExist(const ExceptionObjectExist<T>& e)
    : std::exception(e) {
    this->message = e.message;
}

template <typename T>
ExceptionObjectExist<T>::~ExceptionObjectExist() {
}

template <typename T>
const char* ExceptionObjectExist<T>::what() const throw() {
    return message.c_str();
}

  // ObjectNotFound;

template <typename T>
ExceptionObjectNotFound<T>::ExceptionObjectNotFound(const T& object) {
    std::stringstream msg;
    msg << "Exception; Объект не найден; object = ";
    msg << object;

    message = msg.str();
}

template <typename T>
ExceptionObjectNotFound<T>::ExceptionObjectNotFound(
    const ExceptionObjectNotFound<T>& e)
    : std::exception(e) {
    this->message = e.message;
}

template <typename T>
ExceptionObjectNotFound<T>::~ExceptionObjectNotFound() {
}

template <typename T>
const char* ExceptionObjectNotFound<T>::what() const throw() {
    return message.c_str();
}
