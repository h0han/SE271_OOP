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
//	cout << "--- 상품ID : " << getid() << endl;
//	cout << "상품설명 : " << getdes() << endl;
//	cout << "생산자 : " << getprod() << endl;
//	cout << "가격 : " << getprice() << endl;
//	cout << "ISBN : " << getisbn() << endl;
//	cout << "책제목 : " << getbook() << endl;
//	cout << "저자 : " << getwriter() << endl;
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
//	cout << "--- 상품ID : " << getid() << endl;
//	cout << "상품설명 : " << getdes() << endl;
//	cout << "생산자 : " << getprod() << endl;
//	cout << "가격 : " << getprice() << endl;
//	cout << "ISBN : " << getisbn() << endl;
//	cout << "책제목 : " << getbook() << endl;
//	cout << "저자 : " << getwriter() << endl;
//	cout << "언어 : " << getlang() << endl;
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
//	cout << "--- 상품ID : " << getid() << endl;
//	cout << "상품설명 : " << getdes() << endl;
//	cout << "생산자 : " << getprod() << endl;
//	cout << "가격 : " << getprice() << endl;
//	cout << "앨범제목 : " << getalbunNm() << endl;
//	cout << "가수 :	" << getsinger() << endl;
//}
//
//
//int main() {
//	Product* p[100];
//	int id = 0;
//	int isbn, price;
//	string des, prod, writer, bookname, lang, albumNm, singer;
//	cout << "***** 상품 관리 프로그램을 작동합니다 *****" << endl;
//	for (;;) {
//		cout << "상품추가-1, 모든 상품 조회-2, 끝내기-3 ? " << endl;
//		int n;
//		cin >> n;
//		if (n == 1) {
//			cout << "책-1, 음악-2, 회화책-3" << endl;
//			cin >> n;
//			cin.ignore();
//			if (n == 1) {
//				cout << "상품설명>>"; getline(cin, des);
//				cout << "생산자>>"; getline(cin, prod);
//				cout << "가격>>"; getline(cin, price);
//				cout << "ISBN>>"; getline(cin, isbn);
//				cout << "상품설명>>"; getline(cin, des);
//				cout << "상품설명>>"; getline(cin, des);
//			}
//		}
//	}
//
//	return 0;
//}