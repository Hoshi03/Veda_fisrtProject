#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Member.h"

using namespace std;

class MemberManager 
{
    vector<Member> memberList;
    Member* currentMember = NULL;

    // 파일 입출력 함수
    static vector<Member>& readFile();
    void writeFile();
public:
    MemberManager();

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

