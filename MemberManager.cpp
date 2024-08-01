#include "MemberManager.h"
#include <algorithm>

using namespace std;



MemberManager::MemberManager() {

}

void MemberManager::registration() {
	cout << "등록할 사용자 이름, ID, PW를 입력해주세요\n";
	string name, id, pwd;
	cin >> name >> id >> pwd;
	Member mem(name, id, pwd);
	memberList.push_back(mem);
}


void MemberManager::searchAllMember() {

	cout << "모든 등록된 사용자를 검색합니다" << '\n';
	for (auto i = memberList.begin(); i != memberList.end(); i++)
	{
		cout << "이름 : " <<  (*i).getName() << " ID : " << (*i).getId();
		if ((*i).getAccount().empty())
		{
			cout << '\n';
		}
		else
		{
			cout << "사용자 계좌 ID, 잔액 ";
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
			cout << "등록된 사용자 입니다" << '\n';
			return true;
		}
	}

	cout << "등록되지 않은 사용자 입니다\n";
	return false;
}

void MemberManager::setCurrentMember(Member *member) {
	currentMember = member;
}

Member* MemberManager::getCurrentMember() {
	return currentMember;
}


void MemberManager::getCurrentMemberStatus() {
	if (currentMember == NULL)
	{
		cout << "로그인 하십쇼\n";
		return;
	}
	cout << "이름 : " << currentMember->getName() << " ID : " << currentMember->getId();
	if (currentMember->getAccount().empty())
	{
		cout << '\n';
	}
	else
	{
		cout << "사용자 계좌 ID, 잔액 ";
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
		cout << "로그인 하십쇼\n";
		return;
	}
	currentMember->addAcount();
}

void MemberManager::login() {
	
	cout << "id와 pw를 입력해주세요" << '\n';
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

	cout << "로그인 실패\n";
}

void MemberManager::logout() {
	currentMember = NULL;
	cout << "로그아웃 되었습니다\n";
}

void MemberManager::transaction() {
	if (currentMember == NULL)
	{
		cout << "로그인 하십쇼\n";
		return;
		vector<Account> currentAccountList = currentMember->getAccount();
		if (currentAccountList.empty())
		{
			cout << "계좌부터 만드십쇼\n";
			return;
		}

		cout << "입금 : 1번 출금 2번\n";
		int tmp;
		cin >> tmp;

		cout << "입/출금할 금액\n";
		int inputMoney;
		cin >> inputMoney;

		if (inputMoney < 0)
		{
			cout << "양수로 입력하십쇼\n";
			return;
		}

		cout << "계좌목록\n";

		for (auto j = currentAccountList.begin(); j != currentAccountList.end(); j++)
		{
			cout << (*j).toString();
		}

		int maxAccountCount = currentAccountList.size();

		int choosedAccountCount;
		cin >> choosedAccountCount;

		if (choosedAccountCount < maxAccountCount)
		{
			cout << "그런 계좌는 없어요\n";
			return;
		}

		else {
			if (tmp == 1)
			{
				currentAccountList[choosedAccountCount].deposit(inputMoney);
			}
			else if (tmp == 2) {
				currentAccountList[choosedAccountCount].withdraw(inputMoney);
			}
		}
	}
}
