#ifndef HOME_ANIMALS_COMPOSITE_H
#define HOME_ANIMALS_COMPOSITE_H
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Fish.h"
#include "Hamster.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CompositeAnimal : public Animal {
public:
    void add(Animal *animal) {
        animals.push_back(animal);
    }

    void remove(Animal *animal) {
        animals.erase(find(animals.begin(), animals.end(), animal));
    }

    void makeSound() const override {
        for (auto animal : animals) {
            animal->makeSound();
        }
    }

    string getType() const override {
        for (auto animal : animals) {
            cout << animal->getType() << endl;
        }
        return "CompositeAnimal";
    }

    int getCost() const override {
        int result = 0;
        for (auto animal : animals) {
            result += animal->getCost();
        }

        return result;
    }
private:
    vector<Animal*> animals;
};

#endif
