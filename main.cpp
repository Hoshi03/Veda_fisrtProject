#include <iostream>
#include "MemberManager.h"
#include "line.h"

using namespace std;


int main() {
	
	MemberManager memberManager;
	vector< void (MemberManager::*)() > commands;
	commands.emplace_back(&MemberManager::registration);
	commands.emplace_back(&MemberManager::searchAllMember);
	commands.emplace_back(&MemberManager::login);
	commands.emplace_back(&MemberManager::getCurrentMemberStatus);
	commands.emplace_back(&MemberManager::addAccount);
	commands.emplace_back(&MemberManager::logout);
	commands.emplace_back(&MemberManager::transaction);

	while (true)
	{
		line_1();
#if defined(_WIN32) || defined(_WIN64)
		cout << "1 : regeister member\n2 : search all members\n3 : user login\n4 : get current user status\n5 : add account\n6 : logout\n7 : deposit/withdraw\n -1 : quit\n";
#else // POSIX 시스템 (Linux, macOS 등)
		cout << "1 : regeister member\n2 : search all members\n3 : user login\n4 : get current user status\n5 : add account\n6 : logout\n7 : deposit/withdraw\n -1 : quit\n";
#endif
		line_1();

		int tmp;
		cin >> tmp;

		if (tmp == -1)
		{
			return 0;
		}

		(memberManager.*commands[tmp - 1])();
	}
}