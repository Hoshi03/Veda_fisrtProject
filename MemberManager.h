#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "Member.h"

using namespace std;

class MemberManager 
{
    vector<Member> memberList;
    Member* currentMember = NULL;

public:
    MemberManager();
    ~MemberManager();

    void registration();
    void searchAllMember();
    bool isRegister(string name);

    void addAccount();
    void transaction();
    void login();
    void logout();
    void getCurrentMemberStatus();
    void setCurrentMember(Member *member);
    Member* getCurrentMember();
};

