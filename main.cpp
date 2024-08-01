#include <iostream>
#include "MemberManager.h"

using namespace std;

int main() {

	MemberManager memberManager;
	Member currentMember();

	while (true)
	{

		cout << "1 : 사용자 등록\n2 : 모든 사용자 리스트 검색\n3 : 사용자 로그인\n4 : 현재 사용자 정보 가져오기\n";

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