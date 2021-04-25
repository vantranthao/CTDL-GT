#include <iostream>
using namespace std;
template<typename T>
class Stack {
  public:
    Stack(int capacity = 100) {
      theArray1 = new T[capacity];
      theArray2 = new T[capacity];
      topOfStack1 = -1;
      topOfStack2 = -1;
    }
    ~Stack() {
      delete[] theArray1;
      delete[] theArray2;
    }
    bool empty() {
      return (topOfStack1 == -1 || topOfStack2 == -1);
    }
    int getSize() { //  size of theArray1
      return (topOfStack1+1); // start from 0
    }
    // push in stack
    void push(T e) {
      topOfStack1++; // tang 1
      theArray1[topOfStack1] = e;
    }
    // pop ele 
    void pop(T e) {
      topOfStack1--;
    }
    // in cac ptu
    void print() {
      for(int i = topOfStack1; i>=0; i--) {
        cout << theArray1[i];
      }
      cout << endl;
    }

  private:
    T *theArray1, *theArray2;
    int topOfStack1, topOfStack2; // top element
};
int main() {
  Stack<char> s;
  if (s.empty()) {
    cout << "Ngan xep dang rong!" << endl;
  }
  s.push('B');
  s.push('E');
  s.push('K');
  s.push('A');
  s.push('C');

  cout << "Kich thuoc ngan xep 1 sau khi chen: " << s.getSize() << endl;
  // in ra cac phan tu
  s.print();
  // Kich thuoc stack sau khi xoa ptu
  cout << "Kich thuoc stack 1 sau khi pop: " << s.getSize() << endl;
}