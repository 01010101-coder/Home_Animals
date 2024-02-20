#ifndef HOME_ANIMALS_USER_H
#define HOME_ANIMALS_USER_H
#include <iostream>
#include <string>

using namespace std;

class User {
private:
    string username;
//    string phone;

public:
    User(string username);

    string getUsername() const;
//    string getPhone() const;

    void setUsername(string username);
//    void setPhone(string phone);

    friend ostream &operator<<(ostream &os, const User &user);
    bool operator<(const User &user) const;
};


#endif
