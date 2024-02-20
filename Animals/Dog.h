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
    bool isTrained;
public:
    Dog(string name, int age, string breed, bool isTrained) : Animal(name, age), breed(breed), isTrained(isTrained) {};

    string getBreed() {
        return this->breed;
    }

    bool getIsTrained() {
        return this->isTrained;
    }

    void setBreed(string breed) {
        this->breed = breed;
    }

    void setIsTrained(bool isTrained) {
        this->isTrained = isTrained;
    }

    void makeSound() override {
        cout << "Woof" << endl;
    }

    string getType() override{
        return "Собака";
    }
};



#endif
