#include"header.h"

int main() {
	int n=2;
	SVList svlist;
	AccountList accountlistGV, accountlistSV;
	khoiTaoSVList(svlist);
	InitAccountListGV(accountlistGV);
	InitAccountListSV(accountlistSV);
	saveAccountGV(accountlistGV);
	saveAccountSV(accountlistSV);
	luuSVList(svlist);
	login(accountlistGV, accountlistSV, svlist, n);
}