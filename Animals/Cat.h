#ifndef HOME_ANIMALS_CAT_H
#define HOME_ANIMALS_CAT_H
#include <string>
#include <utility>
#include "Animal.h"
#include <iostream>

using namespace std;

class Cat : public Animal {
private:
    string color;
public:
    Cat(string name, int age, string color) : Animal(name, age), color(color) {};

    string getColor() {
        return this->color;
    }

    void setColor(string color) {
        this->color = color;
    }

    void getCat() {
        cout << name << " " << age << " " << color << endl;
    }

    void makeSound() const override {
        cout << "Meow" << endl;
    }

    string getType() const override{
        return "Кот";
    }
};


#endif
