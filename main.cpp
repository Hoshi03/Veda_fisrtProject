#include <iostream>
#include "MemberManager.h"
#include "date.h"
#include "account.h"

using namespace std;

int main() {

	MemberManager memberManager;
	Member currentMember();

	while (true)
	{

		cout << "1 : ����� ���\n2 : ��� ����� ����Ʈ �˻�\n3 : ����� �α���\n4 : ���� ����� ���� ��������\n5 : ���� �߰��ϱ�\n6 : �α׾ƿ�\n-1 : ����\n";

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

		if (tmp == 5)
		{
			memberManager.addAccount();
		}

		if (tmp == 6)
		{
			memberManager.logout();
		}



		if (tmp == -1)
		{
			return 0;
		}

		
	}


	//Date date;
	////cout << date.toString();
	//Account account(1,10000);
	//cout << account.toString();
}