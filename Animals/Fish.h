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
    Fish(string name, int age, string color, string size) : Animal(std::move(name), age), color(std::move(color)), size(std::move(size)) {};

    Fish(Fish&& other) noexcept : Animal(other), color(std::move(other.color)), size(std::move(other.size)) {}

    Fish& operator=(Fish&& other) noexcept {
        if (this != &other) {
            Animal::operator=(other); // Вызываем оператор присваивания перемещения базового класса
            color = std::move(other.color);
            size = std::move(other.size);
        }
        return *this;
    }

    string getColor() {
        return color;
    }

    string getSize() {
        return size;
    }

    void setColor(string _color) {
        this->color = std::move(_color);
    }

    void setSize(string _size) {
        this->size = std::move(_size);
    }

    void makeSound() const override {
        cout << "Bloop" << endl;
    }

    string getType() const override {
        return "Рыба";
    }
};

#endif
