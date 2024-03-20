#include "User.h"

User::User(string username) {
    this->username = username;
}

string User::getUsername() const {
    return username;
}

void User::setUsername(string username) {
    this->username = username;
}


ostream& operator<<(ostream& os, const User& user) {
    os << user.getUsername();
    return os;
}

bool User::operator<(const User& user) const {
    return this->getUsername() < user.getUsername();
}