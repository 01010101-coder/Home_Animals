#include "Animal.h"

using namespace std;

string Animal::getName() const {
    return name;
}

int Animal::getAge() const {
    return age;
}

void Animal::setName(string newName) {
    name = move(newName);
}

void Animal::setAge(int age) {
    this->age = age;
}
