#include <string>
#include "date.h"

#ifndef DEPOSIT_H
#define DEPOSIT_H

class Account {
    int accountId;
    long long money;
    Date regDate;
public:
    Account(int accountId, long long money) throw(const char*);
    long long getMoney() const;
    bool deposit(long long money);
    bool withdraw(long long money);
    string toString();
    int getId();
};

#endif //DEPOSIT_H
