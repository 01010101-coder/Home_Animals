#include "User.h"

User::User(string username) {
    this->username = username;
//    this->phone = phone;
}

string User::getUsername() const {
    return username;
}

//string User::getPhone() const {
//    return phone;
//}

void User::setUsername(string username) {
    this->username = username;
}

//void User::setPhone(string phone) {
//    this->phone = phone;
//}

ostream& operator<<(ostream& os, const User& user) {
    os << user.getUsername();
    return os;
}

bool User::operator<(const User& user) const{
    return this->getUsername() < user.getUsername();
}