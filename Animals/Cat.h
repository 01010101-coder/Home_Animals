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
    string gender;
    double weight;
    string health_status;

public:
    Cat(string name, int age, string color, string gender, double weight, string health_status) : Animal(
            std::move(name), age), color(std::move(color)),
                                                                                                  gender(std::move(
                                                                                                          gender)),
                                                                                                  weight(weight),
                                                                                                  health_status(
                                                                                                          std::move(
                                                                                                                  health_status)) {};

    Cat(Cat &&other) noexcept: Animal(other), color(std::move(other.color)), gender(other.gender), weight(other.weight),
                               health_status(other.health_status) {}



    Cat& operator=(Cat&& other) noexcept {
        if (this != &other) {
            Animal::operator=(other);
            color = std::move(other.color);
            gender = other.gender;
            weight = other.weight;
            health_status = other.health_status;
        }
        return *this;
    }

    string getColor() const {
        return this->color;
    }

    string getGender() const {
        return this->gender;
    }

    double getWeight() const {
        return this->weight;
    }

    string getHealthStatus() const {
        return this->health_status;
    }

    void setColor(string newColor) {
        color = std::move(newColor);
    }

    void setGender(string newGender) {
        gender = std::move(newGender);
    }

    void setWeight(double newWeight) {
        weight = newWeight;
    }

    void setHealthStatus(string newHealthStatus) {
        health_status = std::move(newHealthStatus);
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
