#include "MemberManager.h"
#include <algorithm>

using namespace std;



MemberManager::MemberManager() {

}

void MemberManager::registration() {
	cout << "����� ����� �̸�, ID, PW�� �Է����ּ���\n";
	string name, id, pwd;
	cin >> name >> id >> pwd;
	Member mem(name, id, pwd);
	memberList.push_back(mem);
}


void MemberManager::searchAllMember() {

	cout << "��� ��ϵ� ����ڸ� �˻��մϴ�" << '\n';
	for (auto i = memberList.begin(); i != memberList.end(); i++)
	{
		cout << "�̸� : " <<  (*i).getName() << " ID : " << (*i).getId();
		if ((*i).getAccount().empty())
		{
			cout << '\n';
		}
		else
		{
			cout << "����� ���� ID, �ܾ� ";
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
			cout << "��ϵ� ����� �Դϴ�" << '\n';
			return true;
		}
	}

	cout << "��ϵ��� ���� ����� �Դϴ�\n";
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
		cout << "�α��� �Ͻʼ�\n";
		return;
	}
	cout << "�̸� : " << currentMember->getName() << " ID : " << currentMember->getId();
	if (currentMember->getAccount().empty())
	{
		cout << '\n';
	}
	else
	{
		cout << "����� ���� ID, �ܾ� ";
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
		cout << "�α��� �Ͻʼ�\n";
		return;
	}
	currentMember->addAcount();
}

void MemberManager::login() {
	
	cout << "id�� pw�� �Է����ּ���" << '\n';
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

	cout << "�α��� ����\n";
}

void MemberManager::logout() {
	currentMember = NULL;
	cout << "�α׾ƿ� �Ǿ����ϴ�\n";
}

void MemberManager::transaction() {
	if (currentMember == NULL)
	{
		cout << "�α��� �Ͻʼ�\n";
		return;
		vector<Account> currentAccountList = currentMember->getAccount();
		if (currentAccountList.empty())
		{
			cout << "���º��� ����ʼ�\n";
			return;
		}

		cout << "�Ա� : 1�� ��� 2��\n";
		int tmp;
		cin >> tmp;

		cout << "��/����� �ݾ�\n";
		int inputMoney;
		cin >> inputMoney;

		if (inputMoney < 0)
		{
			cout << "����� �Է��Ͻʼ�\n";
			return;
		}

		cout << "���¸��\n";

		for (auto j = currentAccountList.begin(); j != currentAccountList.end(); j++)
		{
			cout << (*j).toString();
		}

		int maxAccountCount = currentAccountList.size();

		int choosedAccountCount;
		cin >> choosedAccountCount;

		if (choosedAccountCount < maxAccountCount)
		{
			cout << "�׷� ���´� �����\n";
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
