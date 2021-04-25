#include <iostream>
using namespace std;
template <typename T>
class BinarySearchTree {
    public:
        // ham tao
        BinarySearchTree() {
            root = NULL;
        }
        // ham huy
        ~BinarySearchTree() {
            makeEmpty(); // private
        }
        bool isEmpty() {
            return (root == NULL);
        }
        void makeEmpty() {
            makeEmpty(root);
        }
        // xoa rong cay
        // min
        T findMin() {
            BinaryNode *v = findMin(root);
            return v->elem;
        }
        // max
        T findMax() {
            BinaryNode *v = findMax(root);
            return v->elem;
        }
        // check x?
        bool contains(T x) {
            return contains(x, root); // private
        }
        // chen x
        void insert(T x) {
            insert (x, root); // private
        }
        // xoa x
        void remove (T x) {
            remove (x, root); // private
        }
    private:
        struct BinaryNode {
            T elem;
            BinaryNode *left;
            BinaryNode *right;
            BinaryNode(T e, BinaryNode *l, BinaryNode *r) {
                elem = x;
                left = l;
                right = r;
            }
        }
        BinaryNode *root; // goc cay
        // empty
        
        void makeEmpty(BinaryNode * &t) {
            if (t == NULL) { // cay rong
                return;
            }
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
            t = NULL;
        }
        // min
        BinaryNode *findMin(BinaryNode *t) {
            if (t == NULL) {
                return NULL; // cay rong, return null
            }
            if (t->left == NULL) {
                return t; // nut ngoai cung ben trai
            }
            return findMin(t->left); // tim tren cay con trai
        }
        // max
        BinaryNode *findMax(BinaryNode *t) {
            if (t != NULL) {
                while (t->right != NULL) {
                    t = t->right; // max : nhanh ngoai cung ben phai
                }
            }
            return t;
        }
        // check x?
        bool contains(T x, BinaryNode *t) {
            if (t == NULL) {
                return false;
            }
            else if (x < t->elem) {
                return contains(x, t->left);
            }
            else if (x > t->elem) {
                return contains(x, t->right);
            }
            else // gap x
                return true; // da tim thay x
        }
        // chen
        void insert(T x, BinaryNode * &t) {
            if (t ==  NULL) { // neu cay rong, tai vi tri dang xet = x
                t = new BinaryNode(x, NULL, NULL) // left right = NULL
            }
            else if (x < t->elem) {
                insert(x, t->left);
            }
            else if (x > t->elem) {
                insert(x, t->right);
            }
            else // gap roi
                ;
        }
        // xoa
        void remove(T x, BinaryNode *& t) {
            if (t == NULL) {
                return ;
            }
            if (x < t->elem) { 
                remove(x, t->left);
            }
            else if (x > t->elem) {
                remove(x, t->right);
            }
            else if (t->left != NULL && t->right != NULL) { //  nut 2 cay con
                t->elem = findMin(t->right)->elem;
                remove(t->elem, t->right);
            }
            else { // 1 con hoac la la
                BinaryNode *old = t;
                t = (t->left != NULL) ? t->left : t->right;
                delete old;
            }
        }
};
int main() {
    
}