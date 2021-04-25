// cai dat cay AVL
#include <iostream>
using namespace std;
template <typename T>
struct AvlNode
{
    T elem;
    AvlNode *left;
    AvlNode *right;
    int height;
    AvlNode(T e, AvlNode *l, AvlNode *r, int h)
    {
        elem = e;
        left = l;
        right = r;
        height = h;
    }
};
int height(AvlNode *t)
{
    return t == NULL ? -1 : t->height;
}
void rotateWithLeftChild(AvlNode *&k2)
{

    AvlNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2 = k1;
}
void rotateWithRightChild(AvlNode *&k2)
{
    AvlNode *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2 = k1;
}
// phai trai
void doubleWithLeftChild(AvlNode *&k3)
{
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}
// trai phai
void doubleWithRightChild(AvlNode *&k3)
{
    rotateWithLeftChild(k3->right);
    rotateWithRightChild(k3);
}
// private
void insert(T x, AvlNode *&t)
{
    if (t == NULL)
    {
        t = new AvlNode(x, NULL, NULL, 0);
    }
    else if (x < t->elem)
    {
        insert(x, t->left);
    }
    else if (x > t->elem)
    {
        insert(x, t->right);
    }
    balance(t); // can bang sau khi chen
}
// giong nhu xoa cay nhi phan
void remove(T x, AvlNode *&t)
{
    balance(t);
}
void balance(AvlNode *&t)
{
    if (t == NULL)
        return;
    if (height(t->left) - height(t->right) > 1)
        if (height(t->left->left) >= height(t->left->right))
            rotateWithLeftChild(t);
        else
            doubleWithLeftChild(t);

    else if (height(t->right) - height(t->left) > 1)
        if (height(t->right->right) >= height(t->right->left))
            rotateWithRightChild(t);
        else
            doubleWithRightChild(t);

    t->height = max(height(t->left), height(t->right)) + 1;
}
int main()
{
}