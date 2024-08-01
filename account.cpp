#include "account.h"

Account::Account(int accountId, long long money) throw(const char*) {
    if (accountId < 0) throw "계좌 ID는 양수여야 합니다.\n";
    if (money < 0) throw "잔액은 음수일 수 없습니다.\n";
    this->accountId = accountId;
    this->money = money;
}

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
