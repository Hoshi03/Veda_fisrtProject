#include <iostream>
#include "MemberManager.h"

using namespace std;

int main() {

	MemberManager memberManager;
	Member currentMember();

	while (true)
	{

		cout << "1 : ����� ���\n2 : ��� ����� ����Ʈ �˻�\n3 : ����� �α���\n4 : ���� ����� ���� ��������\n";

		int tmp;
		cin >> tmp;

		if (tmp == 1)
		{
			memberManager.registration();
		}

		if (tmp == 2)
		{
			memberManager.searchAllMember();
		}

		if (tmp == 3)
		{
			memberManager.login();
		}

		if (tmp == 4)
		{
			memberManager.getCurrentMemberStatus();
		}

		if (tmp == -1)
		{
			return 0;
		}
	}
}