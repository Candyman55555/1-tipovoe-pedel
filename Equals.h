  // Copyright 2015 <Copyright Owner>
#pragma once

const int TypeEqualsAbstr = 0;

  // Абстрактный класс для сравнения объектов
class EqualsAbstr {
 public:
    EqualsAbstr();
    virtual ~EqualsAbstr();

    // Сравнение с другим объектом
    virtual bool Equals(const EqualsAbstr& obj) const;
    virtual bool Equals(const EqualsAbstr* obj) const;

    virtual int ClassType() const;

    // Оператор ==
    friend bool operator==(const EqualsAbstr& left, const EqualsAbstr& right);
};
