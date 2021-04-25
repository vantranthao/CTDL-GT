#include <iostream>
using namespace std;

template<typename T>
class Queue {
  public:
    Queue() {
      front = NULL;
      back = NULL;
      size = 0;
    }
    ~Queue() {
      while(!empty()) {
        dequeue();
      }
    }
    bool empty() {
      return (size == 0);
    }
    int getSize() {
      return size;
    }
    // push at the end
    void enqueue(T e) {
      Node *temp = new Node;
      temp->elem = e;
      temp->next = NULL;
      if(front == NULL) { // rong?
        front = temp;
      }
      else {
        back->next = temp;
      }
      back = temp; // update
      size++;
    }
    // delete at the begin
    void dequeue() {
      Node *temp;
      if (front == NULL) {
        cout << "Empty!";
      }else {
        temp = front;
        front = front->next;
        delete temp;
        size--;
      }
      
    }

    void print() {
      Node *p = front;
      while(p != NULL) {
        cout << p->elem << " ";
        p = p->next;
      } 
      cout << endl;
    }
    // check x in queue?
    bool contains(T x) {
      Node *p = front;
      while(p != NULL) {
        if(x == p->elem) return true;
        p = p->next;
      }
      return false;
    }
    
  private:
    struct Node {
      T elem;
      Node *next;
    };
    Node *front;
    Node *back;
    int size; 
};
int main() {
  Queue<int> q;
  q.enqueue(3);
  q.enqueue(6);
  q.enqueue(1);
  q.enqueue(2);

  cout << "Kich thuoc hang doi sau khi chen: " << q.getSize() << endl;
  cout << "Cac phan tu: " ;
  q.print();
}