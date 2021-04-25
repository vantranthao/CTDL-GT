// cai dat vecto, DONE
#include <iostream>
using namespace std;

template <typename T>
class Vector
{
public:
    // ham tao O(1)
    Vector(int initCapacity = 16)
    {
        size = 0;
        capacity = initCapacity;
        array = new T[capacity];
    }
    // ham huy O(1)
    ~Vector()
    {
        delete[] array;
    }
    // toan tu gan O(n)
    Vector &operator=(Vector &rhs)
    {
        if (this != &rhs)
        {
            size = rhs.size;
            capacity = rhs.capacity;
            delete[] array;
            array = new T[capacity];
            for (int i = 0; i < size; i++)
            {
                array[i] = rhs.array[i];
            }
        }
        return *this;
    }
    // kthuoc vecto O(1)
    int getSize()
    {
        return size;
    }
    // is empty ? O(1)
    bool isEmpty()
    {
        return (size == 0);
    }
    // truy nhap ptu dung chi so O(1)
    T &operator[](int index)
    {
        return array[index];
    }
    // chen vao dau O(1)
    void pushBack(T e)
    {
        if (capacity == size)
        { // *2 dung luong neu vecto's full
            expand(2 * capacity);
        }
        array[size] = e;
        size++; // update size
    }
    // chen vao giua O(n)
    void insert(int pos, T e)
    {
        if (size == capacity)
        {
            expand(2 * capacity);
        }
        for (int i = size; i > pos; i--)
        {                    // lui all ptu
            array[i] = array[i - 1]; //  tu pos sang phai 1 don vi
        }
        array[pos] = e; //
        size++;         // update capacity
    }
    // xoa
    void popBack()
    {
        size--; // xoa 1 ptu o cuoi O(1)
    }
    void clear()
    {
        size = 0; // xoa all O(1)
    }
    void eraser(int pos)
    { // xoa o giua O(n)
        for (int i = pos; i < size; i++)
        {
            array[i] = array[i + 1];
        }
        size--;
    }
    // ham in ra
    void print() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
    }

private:
    int size;     // kthuoc vecto
    int capacity; //  dung luong vecto
    T *array;     // con tro toi mang
    // tang dung luong vector/ capacity/ tro giup thao tac chen ? full
    // O(n)
    void expand(int newCapacity)
    {
        if (newCapacity <= size)
        {
            return;
        }
        T *old = array;             // giu lai dia chi mang cu
        array = new T[newCapacity]; // tao mang moi co dung luong moi
        for (int i = 0; i < size; i++)
        {
            array[i] = old[i]; // copy all ele mang cu sang mang moi array
        }
        delete[] old;           // xoa mang cu
        capacity = newCapacity; // update dung luong moi
    }
};

int main()
{
    Vector<int> v;
    v.pushBack(6);
    v.pushBack(2);
    v.pushBack(9);
    v.pushBack(1);
    v.pushBack(8);
    cout << "Cac phan tu: ";
    v.print();                                     // se in ra 6 2 9 1 8
    cout << "Kich thuoc: " << v.getSize() << endl; // se in ra 5
    v.insert(2, 7);
    cout << "Sau khi chen 7 vao vi tri 2: ";
    v.print(); // se in ra 6 2 7 9 1 8
    v.popBack();
    v.eraser(1);
    cout << "Sau khi xoa 8 va 2: ";
    v.print(); // se in ra 6 7 9 1
    return 0;
}