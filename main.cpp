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

		cout << "1 : 사용자 등록\n2 : 모든 사용자 리스트 검색\n3 : 사용자 로그인\n4 : 현재 사용자 정보 가져오기\n5 : 계좌 추가하기\n6 : 로그아웃\n-1 : 종료\n";

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