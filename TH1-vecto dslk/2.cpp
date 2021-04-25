// cai dat cho dslk don va cac thao tac cua dslk don (single list)
#include <iostream>
using namespace std;

template <typename T>
class SingleList
{
private:
  struct Node
  {
    T elem;
    Node *next;
    Node (T e, Node *n) {
      elem = e;
      next = n;
    }
  };

  Node *head; //con tro head tro den nutdau
  int size = 0;

public:
  SingleList()
  {
    head = NULL;
  }
  ~SingleList()
  {
    while(!empty()) {
      popFront();
    }
  }
  bool empty()
  {
    return (head == NULL);
  }
  int getSize()
  {
    return size;
  }
  T front()
  {
    return head->elem;
  }
  // in ra man hinh!
  void print()
  {
    Node *p = head;
    while(p != NULL) {
      cout << p->elem << " ";
      p = p->next;
    }
  }
  void pushFront(T x)
  {
    Node *v = new Node(x,head);
    head = v;
    size++;
  }
  void popFront()
  {
    Node *old = head;
    head = head->next;
    delete old;
    size--;
  }
  // ktra x co trong list ?
  bool contains(T x)
  {
    Node *p = head;
    while(p != NULL) {
      if(x == p->elem) {
        return true;
      }
      p = p->next;
    }
    return false;
  }
  // delete x at the first met
  // void remove(T x)
  // {
  
  // }
};

int main()
{
  SingleList<int> ds;
  ds.pushFront(4);
  ds.pushFront(7);
  ds.pushFront(2);
  ds.pushFront(6);
  ds.pushFront(9);
  cout << "Danh sach phan tu: ";
  ds.print();                                       // in ra: 9 6 2 7 4
  cout << "Kich thuoc danh sach: " << ds.getSize(); // in ra: 5
  cout << endl;
  if (ds.contains(7))
    cout << "Tim duoc 7 trong danh sach" << endl;
  if (!ds.contains(10))
    cout << "Khong tim duoc 10 trong danh sach" << endl;
  ds.popFront(); // xoa 9
  cout << "Danh sach sau khi xoa phan tu dau tien: ";
  ds.print(); // in ra: 6 2 7 4
  
  // ds.remove(2);
  // cout << "Danh sach sau khi xoa 2: ";
  // ds.print(); // in ra: 6 7 4
  return 0;
}