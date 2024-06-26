#ifndef HOME_ANIMALS_HAMSTER_H
#define HOME_ANIMALS_HAMSTER_H
#include "Animal.h"
#include <iostream>

using namespace std;

class Hamster : public Animal {
private:
    string species;
    string size;
    double weight;

    int cost = 75;
public:
    Hamster(const string& name, int age, const string& species, const string& size, double weight) : Animal(name, age), species(species), size(size), weight(weight) {}

    Hamster(Hamster&& other) noexcept : Animal(other), species(other.species), size(other.size), weight(other.weight) {}

    Hamster& operator=(Hamster&& other) noexcept {
        if (this != &other) {
            Animal::operator=(other);
            species = other.species;
            size = other.size;
            weight = other.weight;
        }
        return *this;
    }

    string getSpecies() const {
        return species;
    }

    string getSize() const {
        return size;
    }

    double getWeight() const {
        return weight;
    }

    void setSpecies(string species_) {
        this->species = std::move(species_);
    }

    void setSize(string size_) {
        this->size = std::move(size_);
    }

    void setWeight(int weight_) {
        this->weight = weight_;
    }

    void makeSound() const override {
        cout << "Хрум" << endl;
    }

    string getType() const override {
         return "Хомяк";
    }

    int getCost() const override {
        return cost;
    }
};


#endif
