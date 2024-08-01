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
		cout << (*i).getName() << " " << (*i).getId() << " " << '\n';
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
	cout << getCurrentMember()->getName();
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

