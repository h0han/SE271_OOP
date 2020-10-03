#include <iostream>
#include "hw1_201911189.h"

int count_odd(const unsigned int* array, int size) {
  int cnt = 0;
  for (int i = 0; i < size; i++) {
    if (array[i]/2 != 0) {
      cnt += 1;
    }
  }
  return cnt;
}

#ifdef SE271_HW1
int main() {
  using std::cout;
  using std::endl;

  // problem 1
  unsigned int a[] = {0, 1, 2, 3, 5};
  std::size_t size_a = sizeof(a)/sizeof(int);
  cout << "problem 1: " << count_odd(a, (int)size_a) << endl;
}
#endif
