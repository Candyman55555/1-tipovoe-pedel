  // Copyright 2015 <Copyright Owner>
#pragma once

#include <iostream>
#include <list>
using std::ostream;

#include "Equals.h"

template <typename T>
class ListBase : public EqualsAbstr, public std::list<T> {
 public:
    ListBase();
    ListBase(const ListBase<T>& l);

    virtual ~ListBase();

    virtual int GetCount() const;

    virtual T Get(int index) const;
    virtual int GetIndex(const T& element) const;

    virtual void Add(const T& element);
    virtual void Add(const ListBase<T>& l);

    virtual void RemoveByIndex(int index);
    virtual void Remove(const T& eleemnt);
    virtual void Remove(const ListBase<T>& l);

    virtual bool Contains(const T& element) const;

    virtual bool Equals(const EqualsAbstr& obj) const;

    // Оператор [] (доступ к элементу)
    T operator[](int index);

    // =
    ListBase<T>& operator=(const ListBase<T>& right);
};

#include "ListBaseImpl.h"
