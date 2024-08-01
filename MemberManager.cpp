#include "MemberManager.h"
#include <algorithm>
#include<iostream>
#include<fstream>
#include <string>

using namespace std;


MemberManager::MemberManager() {
	string src = "output.txt";
    ifstream file(src);
    if (file.is_open()) {
        string numMembers;
		getline(file, numMembers);
        int numMembersInt = stoi(numMembers);

        for (int i = 0; i < numMembersInt; ++i) {
            string name, id, pwd;
            getline(file, name, ' ');
            getline(file, id, ' ');
            getline(file, pwd);

            Member member(name, id, pwd);

            string numAccounts;
            getline(file, numAccounts);
            int numAccountsInt = stoi(numAccounts);


            for (int j = 0; j < numAccountsInt; ++j) {
                string accountId;
                string money;

				//getline < - stoi나 stod 등으로 형식 변환, file << 형태는 알잘딱
				getline(file, accountId, ' ');
				getline(file, money);
                //file >> accountId >> money;
                Account account(stoi(accountId), stod(money)); 
				member.addAcount(account);

            }

            memberList.push_back(member);
        }
        file.close();
    } else {
        cout << src << "파일을 열 수 없습니다" << '\n';
    }
}

MemberManager::~MemberManager() {
    ofstream file("output.txt");
    if (file.is_open()) {
        int tmp = memberList.size();
        file << tmp << '\n';
        for (auto i = memberList.begin(); i != memberList.end(); i++)
        {
            file << (*i).getName() << " " << (*i).getId() << " " << (*i).getPwd() << '\n';
            tmp = (*i).getAccount().size();
            file << tmp << '\n';

            for (auto j = (*i).getAccount().begin(); j != (*i).getAccount().end(); j++)
            {
                file << (*j).getId() << " " << (*j).getMoney() << '\n';
            }
        }
        file.close();
    }
    else {
        cout << "error" << endl;
    }
}


void MemberManager::registration() {
	cout << "enter member name, Id, PW\n";
	string name, id, pwd;
	cin >> name >> id >> pwd;
	Member mem(name, id, pwd);
	memberList.push_back(mem);
}


void MemberManager::searchAllMember() {

	cout << "search all registered members" << '\n';
	for (auto i = memberList.begin(); i != memberList.end(); i++)
	{
		cout << "name : " <<  (*i).getName() << " ID : " << (*i).getId();
		if ((*i).getAccount().empty())
		{
			cout << '\n';
		}
		else
		{
			cout << "account ID, account balance";
			vector<Account> tmp = (*i).getAccount();
			for (auto j =tmp.begin(); j != tmp.end(); j++)
			{
				cout << (*j).toString();
			}
		}
	}
}

bool MemberManager::isRegister(string name) {
	for (auto i = memberList.begin(); i != memberList.end(); i++)
	{
		if (name == (*i).getName()) {
			cout << "already registerd member" << '\n';
			return true;
		}
	}

	cout << "not registerd member\n";
	return false;
}

void MemberManager::setCurrentMember(Member *member) {
	currentMember = member;
}

Member* MemberManager::getCurrentMember() {
	return currentMember;
}


void MemberManager::getCurrentMemberStatus() {
	//cout << "getCurrentMemberStatus 메서드 호출\n";
	if (currentMember == NULL)
	{
		cout << "please login\n";
		return;
	}
	cout << "name : " << currentMember->getName() << " ID : " << currentMember->getId();
	if (currentMember->getAccount().empty())
	{
		cout << '\n';
	}
	else
	{
		cout << "account ID, account balance";
		vector<Account> tmp = currentMember->getAccount();
		for (auto j = tmp.begin(); j != tmp.end(); j++)
		{
			cout << (*j).toString();
		}
	}
}

void MemberManager::addAccount() {
	if (currentMember == NULL)
	{
		cout << "please login\n";
		return;
	}

	int tmpId =  currentMember->getAccount().size() + 1;
	long long tmpMoney;
	cout << "enter initial account balance\n";
	cin >> tmpMoney;

	Account account(tmpId, tmpMoney);

	currentMember->addAcount(account);
}

void MemberManager::login() {
	
	cout << "enter member ID, PW" << '\n';
	string tmpId, tmpPw;
	cin >> tmpId >> tmpPw;


	for (auto i = memberList.begin(); i != memberList.end(); i++)
	{
		if ((*i).getId() == tmpId && (*i).getPwd() == tmpPw)
		{
			setCurrentMember(&(*i));
			return;
		}
	}

	cout << "login fail\n";
}

void MemberManager::logout() {
	currentMember = NULL;
	cout << "logout!\n";
}

void MemberManager::transaction() {
	//cout << "transaction 메서드 호출\n";
	if (currentMember == NULL)
	{
		cout << "please login\n";
		return;
	}

	vector<Account>& currentAccountList = currentMember->getAccount();
	if (currentMember->getAccount().empty())
	{
		cout << "no account member\n";
		return;
	}

	cout << "deposit : 1,  withdraw 2\n";
	int tmp;
	cin >> tmp;

	cout << "how much deposit/withdra\n";
	int inputMoney;
	cin >> inputMoney;

	if (inputMoney < 0)
	{
		cout << "positive integer\n";
		return;
	}

	cout << "account list\n";

	for (auto j = currentMember->getAccount().begin(); j != currentMember->getAccount().end(); j++)
	{
		cout << (*j).toString();
	}

	int maxAccountCount = currentMember->getAccount().size();

	int choosedAccountCount;
	cin >> choosedAccountCount;
	//cout << "current account max : " << maxAccountCount << "현재 고른 번호 " << choosedAccountCount <<'\n';
	if (choosedAccountCount > maxAccountCount)
	{
		cout << "no that account\n";
		return;
	}

	else {
		if (tmp == 1)
		{
			//cout << "입금 메서드 호출" << '\n';
			if (currentMember->getAccount()[choosedAccountCount].deposit(inputMoney)) {
				//cout << "입금되었습니다" << '\n';
			}
		}
		else if (tmp == 2) {
			//cout << "출금 메서드 호출" << '\n';
			currentMember->getAccount()[choosedAccountCount].withdraw(inputMoney);
		}
	}
}