#pragma once
#include <iostream>

using namespace std;

class Member{
    string id, name, pwd;

    public:
        Member();
        Member(string name, string id, string pwd);
        string getName();
        string getId();
        string getPwd();
};