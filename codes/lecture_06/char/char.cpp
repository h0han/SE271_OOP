#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;
//compile error
int main() {
  char str[20] = "Hello";
  char str2[] = "World";
  cout << strlen(str) << endl;
  cout << sizeof(str) << endl;
  strncat_s(str, str2, 4);    // 두 문자열을 합치는 메서드, 첫 번째 파라미터에 두 번째 파라미터를 마지막 파라미터 수 만큼 병합
  cout << str << endl;

  if (strcmp(str, "HelloWorld") == 0) {   // strcmp; p1과 p2의 문자열 비교
    cout << "OK" << endl;
  }
  else {
    cout << "Not Match!" << endl;
  }
  char str01[] = "10";
  char str02[] = "20";
  cout << atoi(str01) * atof(str02) << endl;
  // atoi = char to int
  // atof = char to float
  // atol = char to long int
}
