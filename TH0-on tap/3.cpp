#include <iostream>
using namespace std;
// binary search in integer array
template<typename T>
int binarySearch(T a[], T x, int n) {
  int left = 0;
  int right = n-1;
  while (left <= right) {
    int mid = (right-left)/2;
    if (x < mid) {
      right = mid - 1;
    }
    else if (x > mid) {
      left = mid + 1;
    }
    else return mid;
  }
  return -1;
}

int main() {
  int a[] = {1,3,5,6,9,12,34,56,87,98,100};
  int n = 11, x = 9;
  cout << binarySearch(a, x,n);
  return 0;
}