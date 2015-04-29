  // Copyright 2015 <Copyright Owner>
#include "Exceptions.h"

#include <sstream>
#include <iostream>

using std::stringstream;

ExceptionIndexOutOfBound::ExceptionIndexOutOfBound(int index)
    : std::exception() {
    stringstream msg = stringstream();
    msg << "Exception; Индекс находится за пределами контейнера. index = " <<
        index;

    this->message = msg.str();
}

ExceptionIndexOutOfBound::ExceptionIndexOutOfBound(
    const ExceptionIndexOutOfBound& e)
    : std::exception(e) {
    this->message = e.message;
}

ExceptionIndexOutOfBound::~ExceptionIndexOutOfBound() {
}

const char* ExceptionIndexOutOfBound::what() const throw() {
    return message.c_str();
}
