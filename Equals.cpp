  // Copyright 2015 <Copyright Owner>
#include "Equals.h"

EqualsAbstr::EqualsAbstr() {}
EqualsAbstr::~EqualsAbstr() {}

  // Сравнение с другим объектом
bool EqualsAbstr::Equals(const EqualsAbstr& obj) const {
    if (this == &obj) return true;
    return (this->ClassType() == obj.ClassType());
}

bool EqualsAbstr::Equals(const EqualsAbstr* obj) const {
    if (obj == 0) return false;
    return Equals(*obj);
}

int EqualsAbstr::ClassType() const {
    return TypeEqualsAbstr;
}


bool operator==(const EqualsAbstr& left, const EqualsAbstr& right) {
    return left.Equals(right);
}
