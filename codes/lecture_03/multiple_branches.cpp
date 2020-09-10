#include <iostream>
using namespace std;

int main() {
	int iScore{0};
	cout << "Enter your score : " << endl;
	cin >> iScore;
	
	if (iScore >= 85) {
		cout << iScore;
		cout << "Points : ";
		cout << "Grade A";
		cout << endl;
	}
	
	else if (iScore >= 70) {
		cout << iScore << "Points : " << "Grade B" << endl;
	}
	
	else if (iScore >= 50) {
		cout << iScore << "Points : " << "Grade C" << endl;
	}
	
	else {
		cout << iScore << "Points : " << "Grade F";
	}
	
	return 0;
}
