  // Copyright 2015 <Copyright Owner>
#include "ObjectNumName.h"

#include <iostream>
#include <iomanip>
#include <string>

void ObjectNumName::init(int num, const std::string& name) {
    this->SetNum(num);
    this->SetName(name);
}

ObjectNumName::ObjectNumName() : EqualsAbstr() {
    init(0, std::string(""));
}

ObjectNumName::ObjectNumName(int num, const std::string& name)
    : EqualsAbstr() {
    init(num, name);
}

ObjectNumName::ObjectNumName(const ObjectNumName& obj)
    : EqualsAbstr() {
    this->init(obj.GetNum(), obj.GetName());
}

ObjectNumName::~ObjectNumName() {
}

int ObjectNumName::GetNum() const {
    return this->num;
}

void ObjectNumName::SetNum(int num) {
    this->num = num;
}

std::string ObjectNumName::GetName() const {
    return this->name;
}

void ObjectNumName::SetName(const std::string& name) {
    this->name = std::string(name);
}

//Сравнение с другим объектом
bool ObjectNumName::Equals(const EqualsAbstr& obj) const {
    if (!EqualsAbstr::Equals((EqualsAbstr&)obj)) { return false; }
    return (this->GetNum() == ((ObjectNumName&)obj).GetNum());
}

int ObjectNumName::ClassType() const {
    return TypeObjectNumName;
}

//=
ObjectNumName& ObjectNumName::operator=(const ObjectNumName& right) {
    if (this == &right) {
        return *this;
    }

    this->init(right.GetNum(), right.GetName());
    return *this;
}

//оператор ==
bool operator==(const ObjectNumName& left, const ObjectNumName& right) {
    return left.Equals(right);
}
