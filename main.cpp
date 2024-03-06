#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <memory>
#include <unordered_set>
#include <unordered_map>
#include "Animals/Cat.h"
#include "Animals/Dog.h"
#include "Animals/Fish.h"
#include "Animals/Unknown.h"
#include "User.h"

void split(const string &s, vector<string> &words) {
    istringstream ss(s);
    string item;

    while (getline(ss, item, ',')) {
        words.push_back(item);
    }
}

shared_ptr<Animal> getTypeOfClass(string type, vector<string> &words) {
    shared_ptr<Animal> universalVariable;
    if (type == "Кот") {
        universalVariable = make_shared<Cat>(words[2], stoi(words[3]), words[4]);
    }
    else if (type == "Собака") {
        universalVariable = make_shared<Dog>(words[2], stoi(words[3]), words[4], stoi(words[5]));
    }
    else if (type == "Рыба") {
        universalVariable = make_shared<Fish>(words[2], stoi(words[3]), words[4], words[5]);
    }
    else {
        universalVariable = make_shared<Unknown>(words[2], stoi(words[3]), type, words[4]);
    }
    return universalVariable;
}

void addData(map<User, vector<shared_ptr<Animal>>>& users, vector<string>& words) {
    string name = words[0];
    string type = words[1];
    shared_ptr<Animal> universalVariable = getTypeOfClass(type, words);

    for (auto& user : users) {
        if (user.first.getUsername() == name) {
            user.second.push_back(universalVariable);
            return;
        }
    }

    users.insert({User(name), {universalVariable}});
}

int countUniqueValues(const vector<shared_ptr<Animal>>& vec) {
    unordered_set<string> uniqueSet;

    for (const auto& value : vec) {
        uniqueSet.insert(value->getType());
    }

    return uniqueSet.size();
}

void printType(const string cons, const map<User, vector<shared_ptr<Animal>>> &users) {
    unordered_map<string, string> animals;
    for (const auto& user : users) {
        for (const auto& animal : user.second) {
            if (animal->getType() == cons) {
                if (animal->getName() == " ") {
                    animals.insert(make_pair("None", user.first.getUsername()));
                }
                else {
                    animals.insert(make_pair(animal->getName(), user.first.getUsername()));
                }
            }
        }
    }

    if (animals.empty()) {
        cout << "No such animal!" << endl;
        return;
    }

    for (const auto& animal : animals) {
        cout << animal.second << " " << animal.first << endl;
    }
}

void countAnimal(const string cons, const map<User, vector<shared_ptr<Animal>>> &users) {
    int count = 0;
    for (const auto& user : users) {
        for (const auto& animal : user.second) {
            if (animal->getName() == cons) {
                count++;
            }
        }
    }

    if (count == 0) {
        cout << "No such animal!" << endl;
        return;
    }

    cout << count << endl;
}

void mostAge(const map<User, vector<shared_ptr<Animal>>> &users) {
    unordered_map<string, vector<int>> animals;
    for (const auto& user : users) {
        for (const auto& animal : user.second) {
            const string& type = animal->getType();
            int age = animal->getAge();

            if (animals.find(type) == animals.end()) {
                animals[type] = {numeric_limits<int>::max(), numeric_limits<int>::min()};
            }

            animals[type][0] = min(animals[type][0], age);
            animals[type][1] = max(animals[type][1], age);
        }
    }
    for (const auto& animal : animals) {
        cout << animal.first << " " << animal.second[0] << " " << animal.second[1] << endl;
    }
}

int main() {
    ifstream input("/Users/vladyahnovets/CLionProjects/Home_Animals/input.txt");
    if (!input.is_open()) {
        cout << "Can not open input file";
        return 1;
    }

    string line;
    vector<string> words;

    map<User, vector<shared_ptr<Animal>>> users;
    while (getline(input, line)) {
        split(line, words);
        addData(users, words);
        words.clear();
    }

    bool isRunning = true;
    string console;
    while (isRunning) {
        cin >> console;
        if (console == "0") {
            isRunning = false;
        }
        else if (console == "1") {
            for (auto& user : users) {
                cout << user.first.getUsername() << " " << countUniqueValues(user.second) << " unique species." << endl;
            }
        }
        else if (console == "2") {
            cout << "Введите вид животного: ";
            cin >> console;
            printType(console, users);
        }
        else if (console == "3") {
            cout << "Введите кличку животного: ";
            cin >> console;
            countAnimal(console, users);
        }
        else if (console == "4") {
            mostAge(users);
        }
    }
    return 0;
}
