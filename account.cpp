#include "account.h"

long long Account::getMoney() const {
    return this->money;
}

bool Account::deposit(long long money) {
    // 예외가 나오는 경우가 있을까..?
    this->money += money;
    return true;
}

bool Account::withdraw(long long money) {
    if (this->money < money) {
        return false;
    }

    this->money -= money;
    return true;
}
