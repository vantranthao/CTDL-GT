#include <iostream>
using namespace std;
template<typename T>
class Stack1 {
  public:
    Stack(int capacity = 100) {
      theArray = new T[capacity];
      topOfStack = -1; // dung lg mang
    }
    ~Stack() {
      delete[] theArray;
    }
    bool empty() {
      return (topOfStack == -1);
    }
    int getSize() {
      return (topOfStack+1); // start from 0
    }
    // push in stack
    void push(T e) {
      topOfStack++; // tang 1
      theArray[topOfStack] = e;
    }
    // pop ele 
    void pop(T e) {
      topOfStack--;
    }
    T top() {
      return theArray[topOfStack];
    }
    // in cac ptu
    void print() {
      for(int i = topOfStack; i>=0; i--) {
        cout << theArray[i];
      }
      cout << endl;
    }
    // check x in stack ?
    bool contains(T x) {
      for(int i = topOfStack; i>=0; i--) {
        if (theArray[i] == x) {
          return true;
        }
      }
      return false;
    }

  private:
    T *theArray;
    int topOfStack = 0; // top element
};

class Stack2 {
  
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

  cout << "Kich thuoc ngan xep sau khi chen: " << s.getSize() << endl;
  // in ra cac phan tu
  s.print();
  // Kich thuoc stack sau khi xoa ptu
  cout << "Kich thuoc stack sau khi pop: " << s.getSize() << endl;

  s.contains('A');
}