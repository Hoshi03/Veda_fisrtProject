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

	while (true)
	{

		cout << "1 : ����� ���\n2 : ��� ����� ����Ʈ �˻�\n3 : ����� �α���\n4 : ���� ����� ���� ��������\n5 : ���� �߰��ϱ�\n6 : �α׾ƿ�\n-1 : ����\n";

		int tmp;
		cin >> tmp;

		(memberManager.*commands[tmp - 1])();

		if (tmp == -1)
		{
			return 0;
		}

	}

}