#ifndef HOME_ANIMALS_ANIMAL_H
#define HOME_ANIMALS_ANIMAL_H
#include <string>
#include <utility>

using namespace std;

class Animal {
protected:
    static int next_id;
    string name;
    int age;
    const int id_;
public:
    Animal(const string& name, int age) : id_(next_id++), name(name), age(age) {};

//    Animal(Animal&& other) : id_(other.id_), name(std::move(other.name)), age(other.age) {};

    Animal(): id_(next_id++), name(""), age(0) {};

    Animal& operator=(const Animal& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
        }
        return *this;
    }

    virtual ~Animal() = default;

    string getName() const;
    int getAge() const;

    void setName(string newName);
    void setAge(int age);

    virtual void makeSound() const = 0;
    virtual string getType() const = 0;
    virtual int getCost() const = 0;
};
#endif
