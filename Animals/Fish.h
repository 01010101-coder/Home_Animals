#ifndef HOME_ANIMALS_FISH_H
#define HOME_ANIMALS_FISH_H
#include <string>
#include <utility>
#include "Animal.h"
#include <iostream>

using namespace std;

class Fish : public Animal {
private:
    string color;
    string size;
public:
    Fish(string name, int age, string color, string size) : Animal(name, age), color(color), size(size) {};

    string getColor() {
        return color;
    }

    string getSize() {
        return size;
    }

    void setColor(string color) {
        this->color = color;
    }

    void setSize(string size) {
        this->size = size;
    }

    void makeSound() const override {
        cout << "Bloop" << endl;
    }

    string getType() const override {
        return "Рыба";
    }
};

#endif
