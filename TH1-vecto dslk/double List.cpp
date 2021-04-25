#include <iostream>
using namespace std;
template<typename T>
class doubleList {
    public:
        // ham tao
        doubleList() {
            header = NULL;
            trailer = NULL;
            currentPos = NULL;
        }
        // ham huy
        ~doubleList() {
            while(!empty()) {
                popFront();
            }
        }
        // is empty
        bool isEmpty() {
            return (size == 0);
        }
        // chen dau dsach
        void pushFront(T e) {
            Node v*;
            v->elem = e;
            v->next = header;
            header = v;
            size++;
        }
        // chen cuoi dsach
        void pushBack(T e) {
            Node *v;
            v->elem = e;
            v->prev = trailer;
            trailer->next = v;
            trailer = v;
            size++;
        }
        // xoa dau dsach
        void popFront() {
            DNode *old = header;
            header = header->next;
            delete old;
            size--;
        }
        // xoa cuoi dsach
        void popBack() {
            DNode *old = trailer;
            trailer = trailer->prev;
            delete old;
            size--;
        }
        // chen vao ngay truoc vi tri hien hanh O(1)
        void insert(T e) {
            DNode *v = currentPos; // nut hien hanh
            DNode *u = new DNode; // nut moi
            u->elem = e;
            u->next = v;
            u->prev = v->prev;

            v->prev->next = u;
            v->prev = u;
            size++; 
        }
        // xoa ptu o vi tri hien hanh
        void remove() {
            DNode *v = currentPos;
            DNode *u = v->prev; // nut truoc
            DNode *w = v->next; // nut sau

            u->next = w;
            w->prev = u;
            delete v;
            currentPos = w;
            size--;
        }
        // lay ptu dau dsach
        T front() {
            return header->elem;
        }
        // lay ptu cuoi dsach
        T back() {
            return trailer->elem;
        }
        // lay ptu hien hanh
        T current() {
            return currentPos->elem;
        }
        // chuyen sang nut next
        void moveNext() {

        }
        // chuyen ve nut back
        void movePrevious() {

        }
        // chuyen ve dau dsach
        void moveFront() {

        }
        // chuyen ve cuoi dsach
        void moveBack() {

        }
        // duyet dsach
    private:
        int size;
        struct DNode {
            T elem;
            DNode *next;
            DNode *prev;
        };
        DNode *header; // dau dsach
        DNode *trailer; // cuoi dsach
        DNode *currentPos; // vi tri hien hanh
};

int main() {
    cout << "Hello";
}