﻿#include <fstream>
#include "MemberManager.h"
#include "account.h"
#include <algorithm>
#include <memory>

using namespace std;

vector<Member>* MemberManager::readFile() {
	vector<Member>* vectorPtr = new vector<Member>;
	ifstream fin;
	fin.open("C:\\Users\\change08\\Desktop\\Veda_fisrtProject\\info.txt");

	if (!fin.is_open()) {
		return vectorPtr;
	}
	int memberCount;
	fin >> memberCount;

	string name, id, pwd;
	int accountCount;
	for (int i = 0; i < memberCount; i++) {
		fin >> name >> id >> pwd;
		(*vectorPtr).emplace_back(Member(name, id, pwd));
		fin >> accountCount;

		int accountId;
		long long money;
		string date;
		for (int j = 0; j < accountCount; j++) {
			fin >> accountId >> money >> date;
			(*vectorPtr)[i].addAccount(Account(accountId, money, Date(date)));
		}
	}

	fin.close();
	return vectorPtr;
}

void MemberManager::writeFile() {
	ofstream fout("C:\\Users\\change08\\Desktop\\Veda_fisrtProject\\info.txt");

	if (!fout.is_open()) {
		cerr << "Error opening file for writing\n";
		return;
	}

	fout << memberList.size() << "\n";
	for (auto& member : memberList) {
		fout << member.getName() << " "
			<< member.getId() << " "
			<< member.getPwd() << "\n";

		fout << member.getAccount().size() << "\n";

		for (const auto& account : member.getAccount()) {
			fout << account.getAccountId() << " "
				<< account.getMoney() << " "
				<< account.getDate().toString() << "\n";
		}
	}

	fout.close();
}

MemberManager::MemberManager() {
	this->memberList = *readFile();
}

MemberManager::~MemberManager() {
	this->writeFile();
	/*delete &(this->memberList);*/
}

void MemberManager::registration() {
	cout << "enter member name, Id, PW\n";
	string name, id, pwd;
	cin >> name >> id >> pwd;
	for (auto i = memberList.begin(); i != memberList.end(); i++)
	{
		string tmp = (*i).getId();
		if (tmp == id)
		{
			cout << "alreay registered member!\n";
			return;
		}
	}
	Member mem(name, id, pwd);
	memberList.push_back(mem);
}


void MemberManager::searchAllMember() {

	cout << "search all registerd members" << '\n';
	for (auto i = memberList.begin(); i != memberList.end(); i++)
	{
		cout << "name : " <<  (*i).getName() << " ID : " << (*i).getId() <<'\n';
		if (!(*i).getAccount().empty())
		{
			vector<Account> tmp = (*i).getAccount();

			for (auto j =tmp.begin(); j != tmp.end(); j++)
			{
				cout << (*j).toString();
			}
		}

		else cout << "Haven't opened an account yet\n";
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
	cout << "name : " << currentMember->getName() << " ID : " << currentMember->getId() << "\n";
	
	if (!currentMember->getAccount().empty())
	{
		//cout << " account ID, account balance ";
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

	currentMember->addAccount(account);
}

void MemberManager::login() {
	
	cout << "enter member ID, PW" << '\n';
	string tmpId, tmpPw;
	cin >> tmpId >> tmpPw;


	for (auto i = memberList.begin(); i != memberList.end(); i++)
	{
		/*if ((*i).getId() == tmpId && (*i).getPwd() == tmpPw)
		{
			cout << "login success\n";
			setCurrentMember(&(*i));
			return;
		}*/



		if ((*i).getId() == tmpId)
		{
			if ((*i).getPwd() == tmpPw) {
				cout << "login success\n";
				setCurrentMember(&(*i));
				return;
			}
			else {
				cout << "password error!\n";
				cout << "login fail\n";

				return;
			}
		}
		else {

			cout << "Id not exist!\n";
			cout << "login fail\n";

			return;

		}
	}

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