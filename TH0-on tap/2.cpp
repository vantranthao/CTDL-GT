#include <iostream>
using namespace std;
// linear search in integer array
template<typename T>
int linearSearch(T a[], int n, T x) {
  for (int i = 0; i < n; i++)
    if(a[i] == x)
      return i;
  return -1;
}
int main() {
  int a[] = {12,142,1,343,76};
  int n = 5;
  int x = 142;
  cout << linearSearch(a, n, x);
  return 0;
}