#ifndef HOME_ANIMALS_UNKNOWN_H
#define HOME_ANIMALS_UNKNOWN_H
#include <string>
#include <utility>
#include "Animal.h"
#include <iostream>

using namespace std;

class Unknown : public Animal {
private:
    string type;
    string info;
public:
    Unknown(string name, int age, string type, string info) : Animal(name, age), type(type), info(info) {};

    string getInfo() {
        return info;
    }

    void setType(string type) {
        this->type = type;
    }

    void setInfo(string info) {
        this->info = info;
    }

    void makeSound() override {
        cout << "I don't know what to say" << endl;
    }

    string getType() override {
        return type;
    }
};

#endif
