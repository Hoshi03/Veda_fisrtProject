#pragma once
#include <iostream>
#include <vector>
#include "account.h"


using namespace std;

class Member{
    string name, id, pwd;
    vector<Account> accountList;

    public:
        Member();
        Member(string name, string id, string pwd);
        string getName();
        string getId();
        string getPwd();
        vector<Account>& getAccount();

        void addAcount(Account newAccount);

};