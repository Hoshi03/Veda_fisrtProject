#ifndef DEPOSIT_H
#define DEPOSIT_H

class Account {

    long long money;
public:
    Account(long long money) : money(money) {}
    long long getMoney() const;
    bool deposit(long long money);
    bool withdraw(long long money);
}

#endif //DEPOSIT_H
