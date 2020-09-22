#include <iostream>
using namespace std;

void swap1(int num1, int num2) {    // call by value
  int temp{num1};
  num1 = num2;
  num2 = temp;
}

void swap2(int* num1, int* num2) {    // call by reference
  int temp{*num1};
  *num1 = *num2;
  *num2 = temp;
}

int main() {
  int num1{1};
  int num2{3};
  cout << num1 << " " << num2 << endl;
  swap1(num1, num2);
  cout << num1 << " " << num2 << endl;
  swap2(&num1, &num2);
  cout << num1 << " " << num2 << endl;

  return 0;
}
