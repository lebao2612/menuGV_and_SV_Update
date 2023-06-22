#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>

using namespace std;

struct Account {
	string user;
	string pass;
	Account* pnext;
};

struct AccountList {
	Account* Head;
	Account* Tail;
};

struct Class {
	string maLop;
	Class* pnext;
};

struct ClassList {
	Class* Head;
	Class* Tail;
};

struct Course {
	string maMH;
	string tenMH;
	string tenLop;
	string tenGV;
	int soTin;
	int soLuongMax;
	int namHoc;
	string gioHoc;
	Course* pnext;
};

struct CourseList {
	Course* Head;
	Course* Tail;
};

struct SinhVien {
	int No;
	string MSSV;
	string Ten;
	string Ho;
	string Gioitinh;
	string Ngaysinh;
	string ID;
	CourseList data;
	SinhVien* pnext;
};

struct SVList {
	SinhVien* Head;
	SinhVien* Tail;
};


void khoiTaoSVList(SVList& svlist);
void khoiTaoClassList(ClassList& classlist);
void khoiTaoCourseList(CourseList& courselist);
bool checkLoginGV(string a, string b);
bool checkLoginSV(string a, string b);
void changePass(string a, string c, AccountList& accountlist);
void InitAccountListGV(AccountList& accountlistGV);
void InitAccountListSV(AccountList& accountlistSV);
Account* CreateAccount(string a, string b);
bool checkAccountListGV(AccountList accountlistGV);
bool checkAccountListSV(AccountList accountlistSV);
void saveAccountGV(AccountList& accountlistGV);
void saveAccountSV(AccountList& accountlistSV);
void login(AccountList& accountlistGV, AccountList& accountlistSV, SVList& svlist, int n);
void menuHS(string a, SVList svlist, int n, AccountList& accountlistSV);
void readAccount(string a);
void readCourseAccount(string a, SVList& svlist);
void luuMonHocvaoList(SVList& svlist);
void luuSVList(SVList& svlist);
void menuGV(string a, SVList& svlist, int n, AccountList& accountlistGV);
void taoNamHocMoi();
Class* CreateClass(string a);
bool checkClassList(ClassList classlist);
void saveClassList(ClassList& classlist);
void xuatDanhSachCacLop(ClassList classlist);
void taoLopHocMoi(ClassList& classlist);
void addClass(ClassList& classlist, string a);
void menuThaoTacCacLop(SVList& svlist, string a);
int demSoLuongSV(SVList sv);
bool checkSVList(SVList& svlist);
void themHocSinhVaoLopThuCong(SVList& sv);
void saveSVVaoFile(string a, SVList sv);
void themHocSinhVaoLopbangFile(SVList& sv);
void xuatThongTinSVCuaLop(string a);