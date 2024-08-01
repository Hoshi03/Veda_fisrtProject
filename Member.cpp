#include "Member.h"


Member::Member() {
	this->name = "test";
	this->id = "test";
	this->pwd = "1111";
}

Member::Member(string name, string id, string pwd) {
	this->name = name;
	this->id = id;
	this->pwd = pwd;
}

string Member::getName() {
	return name;
}

string Member::getId() {
	return id;
}

string Member::getPwd() {
	return pwd;
}

vector<Account>& Member::getAccount() {
	return accountList;
}

void Member::addAcount() {
	int tmpId = accountList.size() + 1;
	long long tmpMoney;
	cout << "계좌의 초기자금을 입력해주세요\n";
	cin >> tmpMoney;

	Account newAccount(tmpId, tmpMoney);
	accountList.push_back(newAccount);
}

