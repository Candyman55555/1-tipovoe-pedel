  // Copyright 2015 <Copyright Owner>
#pragma once

#include "Equals.h"

#include <string>

const int TypeObjectNumName = 1;

// Объект с именем и номером
class ObjectNumName : public EqualsAbstr {
 private:
    int num;  // Номер
    std::string name;  // Имя

    void init(int num, const std::string& name);

 public:
    ObjectNumName();
    ObjectNumName(int num, const std::string& name);

    ObjectNumName(const ObjectNumName& obj);

    ~ObjectNumName();

    int GetNum() const;
    void SetNum(int num);

    std::string GetName() const;
    void SetName(const std::string& name);

    // Сравнение с другим объектом
    bool Equals(const EqualsAbstr& obj) const;
    int ClassType() const;

    // оператор =
    ObjectNumName& operator=(const ObjectNumName& right);

    // оператор ==
    friend bool operator==(const ObjectNumName& left,
        const ObjectNumName& right);
};
