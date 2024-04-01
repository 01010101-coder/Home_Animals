#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <memory>
#include <unordered_set>
#include <unordered_map>
#include "User.h"
#include "Animals/Factory.h"

int Animal::next_id = 1;

void split(const string &s, vector<string> &words) { // сплитим строку
    istringstream ss(s);
    string item;
    while (getline(ss, item, ',')) {
        words.push_back(item);
    }
}

void getTypeOfClass(const string& type, vector<string> &words, vector<Animal*>& animals) { // функция для определения типа животного
    if (type == "Кот") {
        CatFactory catFactory;
        Animal* cat = catFactory.createAnimal(words);
        animals.push_back(cat);
        delete cat;
    }
    else if (type == "Собака") {
        DogFactory dogFactory;
        Animal* dog = dogFactory.createAnimal(words);
        animals.push_back(dog);
        delete dog;
    }
    else if (type == "Рыба") {
        FishFactory fishFactory;
        Animal* fish = fishFactory.createAnimal(words);
        animals.push_back(fish);
        delete fish;
    }
    else if (type == "Хомяк"){
        HamsterFactory hamsterFactory;
        Animal* hamster = hamsterFactory.createAnimal(words);
        animals.push_back(hamster);
        delete hamster;
    }
}

void addData(map<User, vector<Animal*>>& users, vector<string>& words) {
    string name = words[0]; // берем имя владельца
    string type = words[1]; // берем тип животного

    for (auto& user : users) {
        if (user.first.getUsername() == name) {
            getTypeOfClass(type, words, user.second);
            return;
        }
    }

    users.insert({User(name), vector<Animal*>()});

}

int countUniqueValues(const vector<Animal*>& vec) {
    unordered_set<string> uniqueSet; // создаем unordered_set для хранения уникальных значений

    for (const auto& value : vec) {
        uniqueSet.insert(value->getType()); // записыаем значение в set, если оно там есть, то тип животного не будет дублироваться
    }

    return uniqueSet.size();
}

void printType(const string& cons, const map<User, vector<Animal*>> &users) {
    unordered_map<string, string> animals; // создаем unordered_map для хранения только уникальных животных у каждого пользователя
    for (const auto& user : users) { // перебираем пользователей
        for (const auto& animal : user.second) { // перебираем всех животных пользователя
            if (animal->getType() == cons) { // если искомый тип животного
                if (animal->getName() == " ") { // если безымянный
                    animals.insert(make_pair("None", user.first.getUsername()));
                }
                else { // записываем кличку и имя пользователя
                    animals.insert(make_pair(animal->getName(), user.first.getUsername()));
                }
            }
        }
    }

    if (animals.empty()) { // если вида животного не существует
        cout << "No such animal!" << endl;
        return;
    }

    for (const auto& animal : animals) { //  выводим полученные данные
        cout << animal.second << " " << animal.first << endl;
    }
}

void countAnimal(const string& cons, const map<User, vector<Animal*>> &users) {
    int count = 0; // счетчик
    for (const auto& user : users) { // перебираем пользователей
        for (const auto& animal : user.second) { // перебираем животных пользователей
            if (animal->getName() == cons) { // если есть совпадение увеличиваем счетчик
                count++;
            }
        }
    }

    if (count == 0) { // если животных с этой кличкой нет, то выводим соотвествующее сообщение
        cout << "No such animal!" << endl;
        return;
    }

    cout << count << endl;
}

void mostAge(const map<User, vector<Animal*>> &users) {
    unordered_map<string, vector<int>> animals; // создаем map для хранения названия типа животного и возраста
    for (const auto& user : users) { // перебираем всех юзеров
        for (const auto& animal : user.second) { // перебираем всех животных этого юзера
            const string& type = animal->getType(); // получаем тип и возраст
            int age = animal->getAge();

            if (animals.find(type) == animals.end()) { // если этого типа еще нет
                animals[type] = {numeric_limits<int>::max(), numeric_limits<int>::min()}; // записываем новый тип и ставим у него
                // крайние значения возраста
            }

            animals[type][0] = min(animals[type][0], age); // запсываем минимальный из двух
            animals[type][1] = max(animals[type][1], age); // записываем максимальных из двух
        }
    }
    for (const auto& animal : animals) {
        cout << animal.first << " " << animal.second[0] << " " << animal.second[1] << endl;
    }
}

int main() {
    ifstream input("/Users/vladyahnovets/CLionProjects/Home_Animals/input.txt"); // открываем файл

    if (!input.is_open()) { // проверяем открылся ли
        cout << "Can not open input file";
        return 1;
    }



    string line; // переменная для обхода файла
    vector<string> words; // переменная где мы будем хранить слова

    map<User, vector<Animal*>> users; // словарь, который мы используем, чтобы хранить пользователей и их животных
    while (getline(input, line)) { // пока получаем строку
        split(line, words); // сплитим ее
        addData(users, words); // добавляем в словарь нового пользователя или животного к пользователю
        words.clear(); // очиващаем строку
    }

    if (users.empty()) {
        throw runtime_error("No data!");
    }

    bool isRunning = true;
    string console; // для работы с программой
    while (isRunning) {
        cin >> console; // просим действие
        if (console == "0") { // закончить
            isRunning = false;
        }
        else if (console == "1") { // посчитать кол-во уникальных животных
            for (auto& user : users) {
                cout << user.first.getUsername() << " " << countUniqueValues(user.second) << " unique species." << endl;
            }
        }
        else if (console == "2") { // выводим для вида животного всех владельцев и клички
            cout << "Введите вид животного: ";
            cin >> console;
            printType(console, users);
        }
        else if (console == "3") { // сколько животных носит определенную кличку
            cout << "Введите кличку животного: ";
            cin >> console;
            countAnimal(console, users);
        }
        else if (console == "4") { // возраст самого старого и самого молодого животного каждого вида
            mostAge(users);
        }
    }
    return 0;
}
