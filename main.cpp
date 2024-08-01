#include <iostream>
#include "MemberManager.h"
#include "date.h"
#include "account.h"

using namespace std;

int main() {

	MemberManager memberManager;
	Member currentMember(); // 없어도 되는..?

	vector< void (MemberManager::*)() > commands;
	commands.emplace_back(&MemberManager::registration);
	commands.emplace_back(&MemberManager::searchAllMember);
	commands.emplace_back(&MemberManager::getCurrentMemberStatus);
	commands.emplace_back(&MemberManager::addAccount);
	commands.emplace_back(&MemberManager::logout);
	commands.emplace_back(&MemberManager::transaction);

	while (true)
	{



#if defined(_WIN32) || defined(_WIN64)
		cout << "1 : 사용자 등록\n2 : 모든 사용자 리스트 검색\n3 : 사용자 로그인\n4 : 현재 사용자 정보 가져오기\n5 : 계좌 추가하기\n6 : 로그아웃\n7 : 계좌 입출금\n -1 : 종료\n";
#else // POSIX 시스템 (Linux, macOS 등)
		cout << "1 : ����� ���\n2 : ��� ����� ����Ʈ �˻�\n3 : ����� �α���\n4 : ���� ����� ���� ��������\n5 : ���� �߰��ϱ�\n6 : �α׾ƿ�\n-1 : ����\n";
#endif

		int tmp;
		cin >> tmp;

		(memberManager.*commands[tmp - 1])();

		if (tmp == -1)
		{
			return 0;
		}

	}

}