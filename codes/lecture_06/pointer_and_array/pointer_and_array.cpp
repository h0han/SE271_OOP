#include <iostream>
using namespace std;

int main() {
  int num = 0;
  int nums[3] = {1, 2, 3};

  int* pnum = &num;   // pnum은 num의 주소값 참조
  int* pnums1 = &nums[0];   // pnums1은 nums[0]값의 주소값 참조
  int* pnums2 = nums;   // pnums2는 nums의 value 참조

  cout << pnums1 << endl << pnums2 << endl;
  cout << *pnums1 << endl << *pnums2 << endl;
  cout << nums[1] << endl << pnums1[1] << endl << pnums2[1] << endl;

  return 0;
}
