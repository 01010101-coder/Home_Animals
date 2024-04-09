#ifndef HOME_ANIMALS_FACTORY_TWO_H
#define HOME_ANIMALS_FACTORY_TWO_H

#include <iostream>
#include <memory>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Fish.h"
#include "Hamster.h"

using namespace std;

class FactoryTwo {
public:
    virtual unique_ptr<Animal> createAnimal() = 0;
};



#endif
