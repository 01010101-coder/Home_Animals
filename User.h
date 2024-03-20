#ifndef HOME_ANIMALS_USER_H
#define HOME_ANIMALS_USER_H
#include <iostream>
#include <string>

using namespace std;

class User {
private:
    string username;

public:
    User(string username);

    string getUsername() const;

    void setUsername(string username);

    friend ostream &operator<<(ostream &os, const User &user);
    bool operator<(const User &user) const;
};


#endif
