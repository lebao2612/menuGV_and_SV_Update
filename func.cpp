#include"header.h"

void khoiTaoSVList(SVList& svlist) {
	svlist.Head = NULL;
	svlist.Tail = NULL;
}

void khoiTaoClassList(ClassList& classlist){
	classlist.Head = NULL;
	classlist.Tail = NULL;
}

void khoiTaoCourseList(CourseList& courselist) {
	courselist.Head = NULL;
	courselist.Tail = NULL;
}

bool checkLoginGV(string a, string b) {
	fstream f;
	string c, d;
	f.open("AccountGV.txt", ios::in);
	if (f.fail())
		return false;
	while (!f.eof()) {
		getline(f, c, ',');
		getline(f, d, '\n');
		if (a == c && b == d) {
			f.close();
			return true;
		}
	}
	f.close();
	return false;
}

bool checkLoginSV(string a, string b) {
	fstream f;
	string c, d;
	f.open("AccountSV.txt", ios::in);
	if (f.fail())
		return false;
	while (!f.eof()) {
		getline(f, c, ',');
		getline(f, d, '\n');
		if (a == c && b == d) {
			f.close();
			return true;
		}
	}
	f.close();
	return false;
}

void changePass(string a, string c, AccountList& accountlist) {
	fstream f;
	f.open(c, ios::out);
	if (f.fail())
		return;
	Account* t = accountlist.Head;
	while (a != t->user) {
		t = t->pnext;
	}
	if (t == NULL)
		return;
	cout << "Nhap mat khau moi: ";
	cin >> t->pass;
	for (Account* temp = accountlist.Head; temp != NULL; temp = temp->pnext) {
		f << temp->user << "," << temp->pass << endl;
	}
	cout << "Thay doi thanh cong" << endl;
	f.close();
}

void InitAccountListGV(AccountList& accountlistGV) {
	accountlistGV.Head = accountlistGV.Tail = NULL;
}

void InitAccountListSV(AccountList& accountlistSV) {
	accountlistSV.Head = accountlistSV.Tail = NULL;
}

Account* CreateAccount(string a, string b) {
	Account* newAccount = new Account;
	newAccount->user = a;
	newAccount->pass = b;
	newAccount->pnext = NULL;
	return newAccount;
}

bool checkAccountListGV(AccountList accountlistGV) {
	if (accountlistGV.Head == NULL)
		return true;
	return false;
}

bool checkAccountListSV(AccountList accountlistSV) {
	if (accountlistSV.Head == NULL)
		return true;
	return false;
}

void saveAccountGV(AccountList& accountlistGV) {
	fstream f;
	f.open("AccountGV.txt");
	while (!f.eof()) {
		string a, b;
		getline(f, a, ',');
		getline(f, b, '\n');
		Account* temp = CreateAccount(a, b);
		if (checkAccountListGV(accountlistGV)) {
			accountlistGV.Head = temp;
			accountlistGV.Tail = temp;
		}
		else {
			accountlistGV.Tail->pnext = temp;
			accountlistGV.Tail = temp;
		}
	}
}

void saveAccountSV(AccountList& accountlistSV) {
	fstream f;
	f.open("AccountSV.txt");
	while (!f.eof()) {
		string a, b;
		getline(f, a, ',');
		getline(f, b, '\n');
		Account* temp = CreateAccount(a, b);
		if (checkAccountListGV(accountlistSV)) {
			accountlistSV.Head = temp;
			accountlistSV.Tail = temp;
		}
		else {
			accountlistSV.Tail->pnext = temp;
			accountlistSV.Tail = temp;
		}
	}
}

void login(AccountList& accountlistGV, AccountList& accountlistSV, SVList& svlist, int n) {
	fstream f1, f2;
	f1.open("AccountGV.txt", ios::in | ios::out);
	f2.open("AccountSV.txt", ios::in | ios::out);
	string a, b;
	int t;
	while (true) {
		cout << "1. Giao Vien" << endl;
		cout << "2. Sinh Vien" << endl;
		cout << "Ban dang nhap voi tu cach: ";
		cin >> t;
		if (t == 1) {
			do {
				system("cls");
				cout << "Nhap tai khoan: ";
				cin >> a;
				cout << "Nhap mat khau: ";
				cin >> b;
			} while (!checkLoginGV(a, b));
			if (checkLoginGV(a, b)) {
				system("cls");
				menuGV(a, svlist, n, accountlistGV);
			}
			else {
				cout << "Dang nhap that bai" << endl;
			}
		}
		if (t == 2) {
			do {
				system("cls");
				cout << "Nhap tai khoan: ";
				cin >> a;
				cout << "Nhap mat khau: ";
				cin >> b;
			} while (!checkLoginSV(a, b));
			system("cls");
			menuHS(a, svlist, n, accountlistSV);
		}
	}
}

void menuHS(string a, SVList svlist, int n, AccountList& accountlistSV) {
	int luachon;
	do {
		system("cls");
		cout << "1. Xem thong tin" << endl;
		cout << "2. Xem danh sach mon hoc dang ky" << endl;
		cout << "3. Thay doi mat khau" << endl;
		cout << "4. Dang xuat" << endl;
		cout << "Nhap lua chon: ";
		cin >> luachon;
		switch (luachon) {
		case 4:
			system("cls");
			break;
		case 1:
			system("cls");
			readAccount(a);
			system("pause");
			break;
		case 2:
			system("cls");
			luuMonHocvaoList(svlist);
			readCourseAccount(a, svlist);
			system("pause");
			break;
		case 3:
			system("cls");
			string c = "AccountSV.txt";
			changePass(a, c, accountlistSV);
			system("pause");
			break;
		}
	} while (luachon != 4);
}

void readAccount(string a) {
	fstream f;
	string b, c, d, e, g, h;
	f.open("studentlist.csv", ios::in);
	if (f.fail()) {
		cout << "Khong mo duoc file" << endl;
		return;
	}
	while (!f.eof()) {
		string hoten;
		getline(f, b, ',');
		getline(f, c, ',');
		getline(f, d, ',');
		getline(f, e, ',');
		getline(f, g, ',');
		getline(f, h, '\n');
		hoten = d + " " + c;
		if (a == b) {
			cout << "Ma so sinh vien: " << b << endl;
			cout << "Ho va ten: " << hoten << endl;
			cout << "Gioi tinh: " << e << endl;
			cout << "Ngay sinh: " << g << endl;
			cout << "ID: " << h << endl;
			break;
		}
	}
	f.close();
}

void readCourseAccount(string a, SVList& svlist) {
	fstream f1;
	string ma, ten, lop, gv, sotin, hsmax, nam, thoigian;
	cout << "Cac mon hoc da dang ki: " << endl;
	cout <<left<<setw(20)<< "Ma mon hoc" << setw(30) << "Ten mon hoc" << setw(10) << "Lop hoc" << setw(15) << "Giao vien" << setw(10) << "So tin" << setw(10) << "Toi da" << setw(10) << "Nam hoc" << setw(15) << "Thoi gian hoc" << endl;
	SinhVien* temp = svlist.Head;
	while (temp != NULL) {
		if (a == temp->MSSV) {
			Course* temp1 = temp->data.Head;
			f1.open("courselist.csv", ios::in);
			if (f1.fail()) {
				cout << "Khong mo duoc file courseslist" << endl;
				return;
			}
			string line;
			while (getline(f1, line) && temp1 != NULL) {
				stringstream ss(line);
				getline(ss, ma, ',');
				if (ma == temp1->maMH) {
					cout << left << setw(20) << ma << setw(30);
					getline(ss, ten, ',');
					cout << ten << setw(10);
					getline(ss, lop, ',');
					cout << lop << setw(15);
					getline(ss, gv, ',');
					cout << gv << setw(10);
					getline(ss, sotin, ',');
					cout << sotin << setw(10);
					getline(ss, hsmax, ',');
					cout << hsmax << setw(10);
					getline(ss, nam, ',');
					cout << nam << setw(15);
					getline(ss, thoigian, '\n');
					cout << thoigian << endl;
					temp1 = temp1->pnext;
				}
			}
			f1.close();
			break;
		}
		temp = temp->pnext;
	}
}

void luuMonHocvaoList(SVList& svlist) {
	fstream f;
	f.open("CourseofStudent.csv", ios::in);
	if (f.fail()) {
		cout << "Can't open this file";
		return;
	}
	SinhVien* temp = svlist.Head;
	while(temp){
		string line, a, b;
		getline(f, line);
		stringstream ss(line);
		string element;
		getline(ss, temp->MSSV, ',');
		while (getline(ss, element, ',')) {
			if (temp->data.Head == NULL) {
				Course* temp1 = new Course;
				temp1->maMH = element;
				temp1->pnext = NULL;
				temp->data.Head = temp1;
				temp->data.Tail = temp1;
			}
			else {
				Course* temp1 = new Course;
				temp1->maMH = element;
				temp1->pnext = NULL;
				temp->data.Tail->pnext = temp1;
				temp->data.Tail = temp1;
			}
		}
		temp = temp->pnext;
	}
	f.close();
}

void luuSVList(SVList& svlist) {
	fstream f;
	f.open("studentlist.csv", ios::in);
	if (f.fail()) {
		cout << "Can't open this file";
		return;
	}
	while (!f.eof()) {
		SinhVien* temp = new SinhVien;
		string line;
		getline(f, line);
		stringstream ss(line);
		temp->data.Head = NULL;
		temp->data.Tail = NULL;
		getline(ss, temp->MSSV, ',');
		getline(ss, temp->Ten, ',');
		getline(ss, temp->Ho, ',');
		getline(ss, temp->Gioitinh, ',');
		getline(ss, temp->Ngaysinh, ',');
		getline(ss, temp->ID, '\n');
		if (svlist.Head == NULL) {
			svlist.Head = temp;
			svlist.Tail = temp;
			temp->pnext = NULL;
		}
		else {
			svlist.Tail->pnext = temp;
			svlist.Tail = temp;
			temp->pnext = NULL;
		}
	}
}

void menuGV(string a, SVList& svlist, int n, AccountList& accountlistGV) {
	ClassList classlist;
	CourseList courselist;
	khoiTaoClassList(classlist);
	khoiTaoCourseList(courselist);
	saveClassList(classlist);
	int luachon;
	do {
		system("cls");
		cout << "1. Tao nam hoc moi" << endl;
		cout << "2. Xem danh sach lop hoc" << endl;
		cout << "3. Them lop hoc moi" << endl;
		cout << "4. Thay doi mat khau" << endl;
		cout << "5. Dang xuat" << endl;
		cout << "Nhap lua chon: ";
		cin >> luachon;
		cin.ignore();
		switch (luachon) {
		case 5:
			system("cls");
			break;
		case 1:
			system("cls");
			taoNamHocMoi();
			system("pause");
			break;
		case 2:
			system("cls");
			xuatDanhSachCacLop(classlist);
			cout << endl;
			int t;
			cout << "1. Thao tac voi cac lop" << endl;
			cout << "2. Thoat" << endl;
			cout << "Lua chon: ";
			cin >> t;
			if (t == 1) {
				cin.ignore();
				cout << "Nhap ten lop: ";
				getline(cin, a);
				SVList sv;
				khoiTaoSVList(sv);
				menuThaoTacCacLop(sv, a);
			}
			//system("pause");
			break;
		case 3:
			system("cls");
			taoLopHocMoi(classlist);
			system("pause");
			break;
		case 4:
			system("cls");
			string c = "AccountGV.txt";
			changePass(a, c, accountlistGV);
			system("pause");
			break;
		}
	} while (luachon != 5);
}

void taoNamHocMoi() {
	string a;
	cout << "Nhap nam hoc moi: ";
	getline(cin, a);
}

Class* CreateClass(string a) {
	Class* newClass = new Class;
	newClass->maLop = a;
	newClass->pnext = NULL;
	return newClass;
}

bool checkClassList(ClassList classlist) {
	if (classlist.Head == NULL) {
		return true;
	}
	return false;
}

void addClass(ClassList& classlist,string a) {
	Class* temp = CreateClass(a);
	if (checkClassList(classlist)) {
		classlist.Head = temp;
		classlist.Tail = temp;
	}
	else {
		classlist.Tail->pnext = temp;
		classlist.Tail = temp;
	}
}

void saveClassList(ClassList& classlist) {
	fstream f;
	f.open("ClassList.csv");
	if (f.fail()) {
		cout << "Khong the mo duoc file" << endl;
		return;
	}
	while (!f.eof()) {
		string a;
		f >> a;
		if(a=="")
			break;
		Class* newClass = CreateClass(a);
		if (checkClassList(classlist)) {
			classlist.Head = newClass;
			classlist.Tail = newClass;
		}
		else {
			classlist.Tail->pnext = newClass;
			classlist.Tail = newClass;
		}
	}
}

void xuatDanhSachCacLop(ClassList classlist) {
	if (checkClassList(classlist)) {
		cout << "Danh sach lop dang trong" << endl;
		return;
	}
	Class* p = classlist.Head;
	while (p != NULL) {
		cout << p->maLop << endl;
		p = p->pnext;
	}
}

void taoLopHocMoi(ClassList& classlist) {
	string a;
	cout << "Nhap ten lop hoc: ";
	getline(cin, a);
	addClass(classlist, a);
	fstream f1;
	f1.open("ClassList.csv", ios::app);
	if (f1.fail()) {
		cout << "Khong the mo duoc file" << endl;
		return;
	}
	f1 << a << endl;
	f1.close();
}

//a LA TEN LOP CAN THAO TAC
void menuThaoTacCacLop(SVList& sv, string a) {
	int luachon;
	do {
		system("cls");
		cout << "1. Them sinh vien vao lop thu cong" << endl;
		cout << "2. Them sinh vien vao lop bang file" << endl;
		cout << "3. Xuat thong tin cua lop" << endl;
		cout << "4. Thoat" << endl;
		cout << endl;
		cout << "Lua chon cua ban: ";
		cin >> luachon;
		switch (luachon) {
		case 1:
			system("cls");
			cin.ignore();
			themHocSinhVaoLopThuCong(sv);
			saveSVVaoFile(a, sv);
			system("pause");
			break;
		case 2:
			system("cls");
			cin.ignore();
			themHocSinhVaoLopbangFile(sv);
			saveSVVaoFile(a, sv);
			system("pause");
			break;
		case 3:
			system("cls");
			xuatThongTinSVCuaLop(a);
			system("pause");
			break;
		case 4:
			break;
		}
	} while (luachon != 4);
}

int demSoLuongSV(SVList sv) {
	int dem = 0;
	SinhVien* temp = sv.Head;
	while (temp != NULL) {
		dem++;
		temp = temp->pnext;
	}
	return dem;
}

bool checkSVList(SVList& svlist) {
	if (svlist.Head == NULL) {
		return true;
	}
	return false;
}

void themHocSinhVaoLopThuCong(SVList& sv) {
	SinhVien* temp = new SinhVien;
	temp->pnext = NULL;
	temp->No = demSoLuongSV(sv) + 1;
	cout << "Nhap MSSV: ";
	getline(cin, temp->MSSV);
	cout << "Nhap Ten: ";
	getline(cin, temp->Ten);
	cout << "Nhap Ho: ";
	getline(cin, temp->Ho);
	cout << "Nhap Gioi tinh: ";
	getline(cin, temp->Gioitinh);
	cout << "Nhap Ngay sinh: ";
	getline(cin, temp->Ngaysinh);
	cout << "Nhap ID: ";
	getline(cin, temp->ID);
	if (checkSVList(sv)) {
		sv.Head = temp;
		sv.Tail = temp;
	}
	else {
		sv.Tail->pnext = temp;
		sv.Tail = temp;
	}
}

void saveSVVaoFile(string a, SVList sv) {
	string b = "Classes\\" + a + ".csv";
	fstream f;
	f.open(b, ios::out);
	if (f.fail()) {
		cout << "Khong mo duoc file" << endl;
		return;
	}
	SinhVien* temp = sv.Head;
	while (temp != NULL) {
		f << temp->No << "," << temp->MSSV << "," << temp->Ten << "," << temp->Ho << "," << temp->Gioitinh << "," << temp->Ngaysinh << "," << temp->ID << endl;
		temp = temp->pnext;
	}
	f.close();
}

void themHocSinhVaoLopbangFile(SVList& sv) {
	fstream f;
	string a;
	cout << "Nhap duong dan file: ";
	getline(cin, a);
	f.open(a, ios::in);
	if (f.fail()) {
		cout << "Khong mo duoc file" << endl;
		return;
	}
	while (!f.eof()) {
		SinhVien* temp = new SinhVien;
		temp->pnext = NULL;
		string a;
		getline(f, a, ',');
		temp->No = demSoLuongSV(sv) + 1;
		getline(f, temp->MSSV, ',');
		getline(f, temp->Ten, ',');
		getline(f, temp->Ho, ',');
		getline(f, temp->Gioitinh, ',');
		getline(f, temp->Ngaysinh, ',');
		getline(f, temp->ID, '\n');
		if (checkSVList(sv)) {
			sv.Head = temp;
			sv.Tail = temp;
		}
		else {
			sv.Tail->pnext = temp;
			sv.Tail = temp;
		}
	}
	f.close();
}

void xuatThongTinSVCuaLop(string a) {
	string b = "Classes\\" + a + ".csv";
	fstream f;
	f.open(b, ios::in);
	if (f.fail()) {
		cout << "Khong mo duoc file" << endl;
		return;
	}
	cout << left << setw(10) << "STT" << setw(15) << "MSSV" << setw(30) << "Ho va ten" << setw(15) << "Gioi tinh" << setw(20) << "Ngay sinh" << setw(20) << "ID" << endl;
	string No, Maso, Ten, Ho, GioiTinh, Ngaysinh, ID;
	while (!f.eof()) {
		getline(f, No, ',');
		if (No == "")
			break;
		getline(f, Maso, ',');
		getline(f, Ten, ',');
		getline(f, Ho, ',');
		getline(f, GioiTinh, ',');
		getline(f, Ngaysinh, ',');
		getline(f, ID, '\n');
		string hoten = Ho + " " + Ten;
		cout <<left<<setw(10)<< No << setw(15) << Maso << setw(30) << hoten << setw(15) << GioiTinh << setw(20) << Ngaysinh << setw(20) << ID << endl;
	}
}