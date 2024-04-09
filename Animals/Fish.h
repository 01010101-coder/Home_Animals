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
    string diet;

    int cost = 50;
public:
    Fish(const string& name, int age, const string& color, const string& size, const string& diet) : Animal(name, age), color(color), size(size), diet(diet) {};

    Fish(Fish&& other) noexcept : Animal(std::move(other)), color(std::move(other.color)), size(std::move(other.size)), diet(std::move(other.diet)) {}

    Fish& operator=(Fish&& other) noexcept {
        if (this != &other) {
            Animal::operator=(other); // Вызываем оператор присваивания перемещения базового класса
            color = std::move(other.color);
            size = std::move(other.size);
            diet = std::move(other.diet);
        }
        return *this;
    }

    string getColor() const {
        return color;
    }

    string getSize() const {
        return size;
    }

    string getDiet() const {
        return diet;
    }

    void setColor(string _color) {
        this->color = std::move(_color);
    }

    void setSize(string _size) {
        this->size = std::move(_size);
    }

    void setDiet(string _diet) {
        this->diet = std::move(_diet);
    }

    void makeSound() const override {
        cout << "Bloop" << endl;
    }

    string getType() const override {
        return "Рыба";
    }

    int getCost() const override {
        return cost;
    }
};

#endif
