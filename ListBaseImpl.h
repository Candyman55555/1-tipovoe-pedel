  // Copyright 2015 <Copyright Owner>
#pragma once

#include <list>
#include <algorithm>

#include "Exceptions.h"

template <typename T>
ListBase<T>::ListBase()
    : EqualsAbstr(), std::list<T>() {
}

template <typename T>
ListBase<T>::ListBase(const ListBase<T>& l)
    : EqualsAbstr(), std::list<T>(l) {
}

template <typename T>
ListBase<T>::~ListBase() {
}

template <typename T>
int ListBase<T>::GetCount() const {
    return this->size();
}

template <typename T>
T ListBase<T>::Get(int index) const {
    if (index < 0 || index >= GetCount())
        throw ExceptionIndexOutOfBound(index);

    auto result = std::find_if(this->begin(), this->end(),
            [index, this](const T& elem) -> bool {
                    return this->GetIndex(elem) == index;
                });

    return *result;
}

template <typename T>
int ListBase<T>::GetIndex(const T& element) const {
    auto result = std::find_if(this->begin(), this->end(),
            [element](const T& elem) -> bool {
                    return element == elem;
                });

    if (result == std::end(*this))
        throw ExceptionObjectNotFound<T>(element);

    return std::distance(this->begin(), result);
}

template <typename T>
void ListBase<T>::Add(const T& element) {
    this->insert(this->end(), element);
}

template <typename T>
void ListBase<T>::Add(const ListBase<T>& l) {
    this->insert(this->end(), l.begin(), l.end());
}

template <typename T>
void ListBase<T>::RemoveByIndex(int index) {
    T elem = Get(index);
    this->Remove(elem);
}

template <typename T>
void ListBase<T>::Remove(const T& element) {
    if (!this->Contains(element))
        throw ExceptionObjectNotFound<T>(element);

    this->remove_if(
        [element](const T& elem) -> bool {
                return element == elem;
            });
}

template <typename T>
void ListBase<T>::Remove(const ListBase<T>& l) {
    this->remove_if(
        [l](const T& elem) -> bool {
                return l.Contains(elem);
            });
}

template <typename T>
bool ListBase<T>::Contains(const T& element) const {
    auto result = std::find_if(this->begin(), this->end(),
            [element](const T& elem) -> bool {
                    return element == elem;
                });

    return result != std::end(*this);
}

template <typename T>
bool ListBase<T>::Equals(const EqualsAbstr& obj) const {
    if (!EqualsAbstr::Equals((EqualsAbstr&)obj)) return false;

    ListBase<T>& o = (ListBase<T>&)obj;
    if (o.size() != this->size()) return false;

    bool equals = true;

    std::for_each(this->begin(), this->end(),
            [o, &equals](const T& elem) {
                    equals &= equals & o.Contains(elem);
                });

    return equals;
}

//=
template <typename T>
ListBase<T>& ListBase<T>::operator=(const ListBase<T>& right) {
    if (this == &right) {
        return *this;
    }

    this->clear();
    this->Add(right);

    return *this;
}

  // Оператор [] (доступ к элементу)
template <typename T>
T ListBase<T>::operator[](int index) {
    return this->Get(index);
}

  // Оператор ==
template <typename T>
bool operator==(const ListBase<T>& left, const ListBase<T>& right) {
    return left.Equals(right);
}

  // Оператор <<
template <typename T>
ostream& operator<<(ostream& os, const ListBase<T>& l) {
    for (int i = 0; i < l.GetCount(); i++) {
        T elem = l.Get(i);
        os << elem << endl;
    }

    return os;
}
