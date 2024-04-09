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
    double weight;
    string temperament;
    bool isTrained;

    int cost = 500;
 // name, age, breed, color, weight, temperament, isTrained
public:
    Dog(const string& name, int age, const string& breed, const string& color,
        double weight, const string& temperament, bool isTrained) : Animal(name, age), breed(breed),
        color(color), weight(weight), temperament(temperament), isTrained(isTrained) {};

    Dog(Dog&& other) noexcept : Animal(other), breed(std::move(other.breed)),
                                color(std::move(other.color)), weight(other.weight), temperament(other.temperament), isTrained(other.isTrained) {}

    Dog& operator=(Dog&& other) noexcept {
        if (this != &other) {
            Animal::operator=(other); // Вызываем оператор присваивания перемещения базового класса
            breed = other.breed;
            color = std::move(other.color);
            weight = other.weight;
            temperament = other.temperament;
            isTrained = other.isTrained;
        }
        return *this;
    }

    string getBreed() const {
        return this->breed;
    }

    double getWeight() const {
        return this->weight;
    }

    string getTemperament() const {
        return this->temperament;
    }

    bool getIsTrained() const {
        return this->isTrained;
    }

    void setBreed(string _breed) {
        this->breed = std::move(_breed);
    }

    void setWeight(double _weight) {
        this->weight = _weight;
    }

    void setTemperament(string _temperament) {
        this->temperament = std::move(_temperament);
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

    int getCost() const override {
        return cost;
    }
};



#endif
