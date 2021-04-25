#include <iostream>
#include <string>
using namespace std;
// kieu cua nust tren cay(thong tin ve sv)
struct Node
{
    int sbd;
    string hoTen;
    Node *left;
    Node *right;
    // constructor
    Node(int s, string h, Node *l, Node *r)
    {
        sbd = s;
        hoTen = h;
        left = l;
        right = r;
    }
};
// lop cua cay nhi phan tim kiem
class BSTree
{
public:
    // ham tao (cay rong)
    BSTree()
    {
        root = NULL;
    }
    // ham huy
    ~BSTree()
    {
        makeEmpty();
    }
    // is empty ?
    bool isEmpty()
    {
        return (root == NULL);
    }
    // xoa het cac nut
    void makeEmpty()
    {
        makeEmpty(root);
    };
    // chen 1 sv moi vao cay
    void insert(int sbd, string hoTen)
    {
        insert(sbd, hoTen, root); // private
    }
    // tim sv theo sbd
    Node *search(int sbd)
    {
        return search(sbd, root);
    }
    // duyet truoc
    void preOrder() {
        preOrder(root);
    }
    void inOrder() {
        inOrder(root);
    }
    void postOrder() {
        postOrder(root);
    }
private:
    Node *root;
    // duyet truoc
    void preOrder(Node *t) {
        if (t != NULL) {
            cout << t->sbd << " " << t->hoTen << endl;
            preOrder(t->left);
            preOrder(t->right);
        }
    }
    void inOrder(Node *t) {
        if (t != NULL) {
            preOrder(t->left);
            cout << t->sbd << " " << t->hoTen << endl;
            preOrder(t->right);
        }
    }
    void postOrder(Node *t) {
        if (t != NULL) {
            preOrder(t->left);
            preOrder(t->right);
            cout << t->sbd << " " << t->hoTen << endl;
        }
    }
    // xoa rong cay
    void makeEmpty(Node *&t)
    {
        if (t == NULL)
        {
            return;
        }
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = NULL;
    }
    // chen sv moi vao cay
    void insert(int sbd, string hoTen, Node *&t)
    {
        if (t == NULL)
        {
            t = new Node(sbd, hoTen, NULL, NULL);
        }
        else if (sbd < t->sbd)
        {
            insert(sbd, hoTen, t->left);
        }
        else if (sbd > t->sbd)
        {
            insert(sbd, hoTen, t->right);
        }
        else
            ;
    }
    // tm sv theo sbd
    Node *search(int sbd, Node *t)
    {
        if (t == NULL)
        {
            return NULL;
        }
        if (sbd == t->sbd)
        {
            return t;
        }
        else if (sbd < t->sbd)
        {
            return search(sbd, t->left);
        }
        else if (sbd > t->sbd)
        {
            return search(sbd, t->right);
        }
    }
};

int main()
{
    BSTree bst;
    // Chen mot so sinh vien moi vao cay.
    bst.insert(5, "Tuan");
    bst.insert(6, "Lan");
    bst.insert(3, "Cong");
    bst.insert(8, "Huong");
    bst.insert(7, "Binh");
    bst.insert(4, "Hai");
    bst.insert(2, "Son");
    // Tim hai sinh vien co so bao danh 4 va 9.
    Node *n1 = bst.search(4);
    Node *n2 = bst.search(9);
    // In ket qua tim kiem
    if (n1 != NULL)
        cout << "Sinh vien voi SBD=4 la " << n1->hoTen << endl;
    if (n2 == NULL)
        cout << "Khong tim thay sinh vien voi SBD=9" << endl;
    // Lam rong cay.
    bst.makeEmpty();
    if (bst.isEmpty())
        cout << "Cay da bi xoa rong" << endl;
    return 0;
}