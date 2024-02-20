#ifndef HOME_ANIMALS_ANIMAL_H
#define HOME_ANIMALS_ANIMAL_H
#include <string>
#include <utility>

using namespace std;

class Animal {
protected:
    string name;
    int age;
public:

    Animal(string name, int age) : name(name), age(age) {};

    string getName() const;
    int getAge() const;

    void setName(string name);
    void setAge(int age);

    virtual void makeSound() = 0;
    virtual string getType() = 0;
};

#endif
