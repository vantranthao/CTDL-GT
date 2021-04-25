// cai dat cho vecto va cac thao tac cua vecto
#include <iostream>
using namespace std;

template<typename T>
class Vector {
  private:
    int size; // do lon
    int capacity; // dung luong vecto
    T *array;

    // tang dung luong vecto
    void expand (int newCapacity) {
      if (newCapacity <= size) {
        return;
      }
      T *old = array;
      array = new T[capacity];
      for(int i = 0; i < size; i++) {
        array[i] = old[i];
      } 
      delete[] old;
      capacity = newCapacity;
    }

  public:
    Vector(int initCapacity = 16) {
      size = 0;
      capacity = initCapacity;
      array = new T[capacity];
    }
    ~Vector() {
      delete[] array;
    }
    int getSize() {
      return size;
    }
    bool isEmpty() {
      return (size == 0);
    }
    // access 1 ptu thong qua index cua no
    T & operator[] (int index) {
      return array[index];
    }
    // thao tac!
    void pushBack(T newElement) {
      if (size == capacity) {
        expand(2*capacity); // x2 size
      }
      array[size] = newElement;
      size++;
    }
    void insert(int pos, T newElement) {
      if (size == capacity) {
        expand(2*capacity);
      }
      for (int i = size; i > pos; i--) {
        array[i] = array[i-1];
      }
      array[pos] = newElement;
      size++;
    }
    void popBack() {
      size--;
    }
    void erase(int pos) {
      for (int i = pos; i < size - 1; i++){
        array[i] = array[i + 1];
      }
      size--;
    }
    void print() {
      for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
      }
    }

};
int main() {
  Vector<int> v;
  v.pushBack(6);
  v.pushBack(2);
  v.pushBack(9);
  v.pushBack(1);
  v.pushBack(8);
  cout << "Cac phan tu: ";
  v.print(); // se in ra 6 2 9 1 8
  cout << "Kich thuoc: " << v.getSize() << endl; // se in ra 5
  v.insert(2, 7);
  cout << "Sau khi chen 7 vao vi tri 2: ";
  v.print(); // se in ra 6 2 7 9 1 8
  v.popBack();
  v.erase(1);
  cout << "Sau khi xoa 8 va 2: ";
  v.print(); // se in ra 6 7 9 1
  return 0;
}