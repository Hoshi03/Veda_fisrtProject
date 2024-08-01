#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "Member.h"

using namespace std;

class MemberManager : public Member
{
    vector<Member> memberList;
    Member* currentMember = NULL;
public:
    MemberManager();

    void registration();
    void searchAllMember();
    bool isRegister(string name);
    void login();
    void getCurrentMemberStatus();
    void setCurrentMember(Member *member);
    Member* getCurrentMember();
};

