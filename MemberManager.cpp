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
		cout << (*i).getName() << " " << (*i).getId() << " " << '\n';
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
	cout << getCurrentMember()->getName();
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

