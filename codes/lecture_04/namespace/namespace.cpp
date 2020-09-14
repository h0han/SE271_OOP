#include <iostream>
using namespace std;

namespace CIRCLE {
  double PI = 3.14;
  double calArea(int radius) {
    double dVal = radius * radius * PI;
    return dVal;
  }
}

int main() {
  cout << CIRCLE::PI << endl;
  cout << CIRCLE::calArea << endl;

  return 0;
}
