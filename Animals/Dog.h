#ifndef HOME_ANIMALS_DOG_H
#define HOME_ANIMALS_DOG_H
#include <string>
#include <utility>
#include "Animal.h"
#include <iostream>

using namespace std;

class Dog : public Animal {
private:
    string breed;
    string color;
    bool isTrained;

public:
    Dog(string name, int age, string breed, string color, bool isTrained) : Animal(std::move(name), age),
    breed(std::move(breed)), color(std::move(color)), isTrained(isTrained) {};

    Dog(Dog&& other) noexcept : Animal(other), breed(std::move(other.breed)),
                                color(std::move(other.color)), isTrained(other.isTrained) {}

    Dog& operator=(Dog&& other) noexcept {
        if (this != &other) {
            Animal::operator=(other); // Вызываем оператор присваивания перемещения базового класса
            breed = other.breed;
            color = std::move(other.color);
            isTrained = other.isTrained;
        }
        return *this;
    }

    string getBreed() {
        return this->breed;
    }

    bool getIsTrained() const{
        return this->isTrained;
    }

    void setBreed(string _breed) {
        this->breed = std::move(_breed);
    }

    void setIsTrained(bool _isTrained) {
        this->isTrained = _isTrained;
    }

    void makeSound() const override {
        cout << "Woof" << endl;
    }

    string getType() const override{
        return "Собака";
    }
};



#endif
