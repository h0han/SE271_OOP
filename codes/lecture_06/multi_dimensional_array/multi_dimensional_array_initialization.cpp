#include <iostream>
using namespace std;
// compile error
int main() {
  int id0[3] = {1, 2, 3};
  int id1[] = {1, 2, 3};
  int id2[2][3] = {1, 2, 3, 4, 5, 6};
  int id3[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int id4[][3] = {{1 }, {4, 5, 6}};

  cout << id0 << endl;
  cout << id1 << endl;
  cout << id2 << endl;
  cout << id3 << endl;
  cout << id4 << endl;

  return 0;
}
