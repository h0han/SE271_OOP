//#include <iostream>
//#include <string>
//using namespace std;
//
//class Product {
//	int id;
//	string des, prod, price;
//public:
//	Product() {}
//	Product(int id, string price, string des, string prod) {
//		this->id = id;
//		this->price = price;s
//		this->des = des;
//		this->prod = prod;
//	}
//	virtual void show() = 0;
//	int getid() { return id; }
//	int getprice() { return price; }
//	string getdes() { return des; }
//	string getprod() { return prod; }
//};
//
//class Book : public Product {
//	int isbn;
//	string writer, bookname;
//public:
//	Book(int id, string price, string des, string prod, int isbn, string writer, string bookname) : Product(id, price, des, prod) {
//		this->isbn = isbn;
//		this->writer = writer;
//		this->bookname = bookname;
//	}
//	void show();
//	int getisbn() { return isbn; }
//	string getwriter() { return writer; }
//	string getbook() { return bookname; }
//};
//void Book::show() {
//	cout << "--- ��ǰID : " << getid() << endl;
//	cout << "��ǰ���� : " << getdes() << endl;
//	cout << "������ : " << getprod() << endl;
//	cout << "���� : " << getprice() << endl;
//	cout << "ISBN : " << getisbn() << endl;
//	cout << "å���� : " << getbook() << endl;
//	cout << "���� : " << getwriter() << endl;
//}
//
//class ConversationBook : public Book {
//	string lang;
//public:
//	ConversationBook(int id, string price, string des, string prod, int isbn, string writer, string bookname, string lang) : Book(id, price, des, prod, isbn, writer, bookname) {
//		this->lang = lang;
//	}
//	void show();
//	string getlang() { return lang; }
//};
//
//void ConversationBook::show() {
//	cout << "--- ��ǰID : " << getid() << endl;
//	cout << "��ǰ���� : " << getdes() << endl;
//	cout << "������ : " << getprod() << endl;
//	cout << "���� : " << getprice() << endl;
//	cout << "ISBN : " << getisbn() << endl;
//	cout << "å���� : " << getbook() << endl;
//	cout << "���� : " << getwriter() << endl;
//	cout << "��� : " << getlang() << endl;
//}
//
//class CompactDisc : public Product {
//	string albumNm, singer;
//public:
//	CompactDisc(int id, string price, string des, string prod, string albumNm, string singer) : Product(id, price, des, prod) {
//		this->albumNm = albumNm;
//		this->singer = singer;
//	}
//	void show();
//	string getalbunNm() { return albumNm; }
//	string getsinger() { return singer; }
//};
//
//void CompactDisc::show() {
//	cout << "--- ��ǰID : " << getid() << endl;
//	cout << "��ǰ���� : " << getdes() << endl;
//	cout << "������ : " << getprod() << endl;
//	cout << "���� : " << getprice() << endl;
//	cout << "�ٹ����� : " << getalbunNm() << endl;
//	cout << "���� :	" << getsinger() << endl;
//}
//
//
//int main() {
//	Product* p[100];
//	int id = 0;
//	int isbn, price;
//	string des, prod, writer, bookname, lang, albumNm, singer;
//	cout << "***** ��ǰ ���� ���α׷��� �۵��մϴ� *****" << endl;
//	for (;;) {
//		cout << "��ǰ�߰�-1, ��� ��ǰ ��ȸ-2, ������-3 ? " << endl;
//		int n;
//		cin >> n;
//		if (n == 1) {
//			cout << "å-1, ����-2, ȸȭå-3" << endl;
//			cin >> n;
//			cin.ignore();
//			if (n == 1) {
//				cout << "��ǰ����>>"; getline(cin, des);
//				cout << "������>>"; getline(cin, prod);
//				cout << "����>>"; getline(cin, price);
//				cout << "ISBN>>"; getline(cin, isbn);
//				cout << "��ǰ����>>"; getline(cin, des);
//				cout << "��ǰ����>>"; getline(cin, des);
//			}
//		}
//	}
//
//	return 0;
//}