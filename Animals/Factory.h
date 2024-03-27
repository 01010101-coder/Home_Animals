#ifndef HOME_ANIMALS_FACTORY_H
#define HOME_ANIMALS_FACTORY_H
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Fish.h"
#include "Hamster.h"
#include <iostream>
#include <string>
#include <utility>
#include <vector>


class AnimalFactory {
public:
    virtual Animal* createAnimal(vector<string>& params) const = 0;
    virtual ~AnimalFactory() = default;
};

class CatFactory : public AnimalFactory {
public:
     Animal* createAnimal(vector<string>& params) const override {
        return new Cat(params[2], stoi(params[3]), params[4], params[5], stod(params[6]), params[7]);
    }
};

class DogFactory : public AnimalFactory {
public:
    Animal* createAnimal(vector<string>& params) const override{
        return new Dog(params[2], stoi(params[3]), params[4], params[5], stoi(params[6]), params[7], stoi(params[8]));
    }
};

class FishFactory : public AnimalFactory {
public:
    Animal* createAnimal(vector<string>& params) const override {
        return new Fish(params[2], stoi(params[3]), params[4], params[5], params[6]);
    }
};

class HamsterFactory : public AnimalFactory {
public:
    Animal* createAnimal(vector<string>& params) const override {
        return new Hamster(params[2], stoi(params[3]), params[4], params[5], stod(params[6]));
    }
};

#endif