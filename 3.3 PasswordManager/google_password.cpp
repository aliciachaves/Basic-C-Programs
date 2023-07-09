#include "google_password.h"

#include <iostream>

void GooglePassword::insert(const std::string& url,
    const std::string& login,
    const std::string& password) {

    Usuario novo;
    novo.login = login;
    novo.password = password;
    if (validPassword(password)) {
        this->passwords_.insert(std::pair<string, Usuario>(url, novo));
    }
}

void GooglePassword::remove(const std::string& url) {
    
    auto it = this->passwords_.begin();
    while (it != this->passwords_.end()) {

        if (it->first == url) {
            it = this->passwords_.erase(it);
        }

        it++;
    }

}


void GooglePassword::update(const std::string& url,
    const std::string& login,
    const std::string& old_password,
    const std::string& new_password) {

    auto it = this->passwords_.begin();
    while (it != this->passwords_.end()) {

        if (it->second.password == old_password && validPassword(new_password)) {
            it->second.password = new_password;
            it->second.login = login;
        }

        it++;
    }
}

void GooglePassword::printPasswords() {

    std::cout << this->passwords_.size() << std::endl;

    auto it = this->passwords_.begin();
    while (it != this->passwords_.end()) {

        std::cout << it->first << ": " << it->second.login << " and " << it->second.password << std::endl;

        it++;
    }
}

bool GooglePassword::validPassword(const std::string& password) const {
    string seq = "123456";
    string branco = " ";
    if (password.length() < 50 && password.length() > 6) {
        size_t found = password.find(seq);
        if (found == string::npos) {
            found = password.find(branco);
            if (found == string::npos) {
                return 1;
            }
        }
    }
    return 0;
}
