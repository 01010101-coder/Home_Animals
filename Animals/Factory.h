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

using namespace std;

class AnimalFactory2 {
public:
    virtual unique_ptr<Animal> createAnimal(const vector<string>& params) const = 0;
    virtual ~AnimalFactory() = default;
};

class CatFactory : public AnimalFactory2 {
public:
    unique_ptr<Animal> createAnimal(const vector<string>& params) const override {
        return make_unique<Cat>(params[0], stoi(params[1]), params[2], params[3], stod(params[4]), params[5]);
    }
};

class DogFactory : public AnimalFactory2 {
public:
    unique_ptr<Animal> createAnimal(const vector<string>& params) const override {
        return make_unique<Dog>(params[0], stoi(params[1]), params[2], params[3], stoi(params[4]), params[5], stoi(params[6]));
    }
};

class FishFactory : public AnimalFactory2 {
public:
    unique_ptr<Animal> createAnimal(const vector<string>& params) const override {
        return make_unique<Fish>(params[0], stoi(params[1]), params[2], params[3], params[4]);
    }
};

class HamsterFactory : public AnimalFactory2 {
public:
    unique_ptr<Animal> createAnimal(const vector<string>& params) const override {
        return make_unique<Hamster>(params[0], stoi(params[1]), params[2], params[3], stod(params[4]));
    }
};

#endif