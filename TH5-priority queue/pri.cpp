#include <iostream>
#include <iomanip> // De can chinh viec in an tren man hinh
#include <vector>
#include <string>
using namespace std;
template <typename T>

// doi cho 2 so
void swap(T x, T y) {
    T temp = x;
    x = y;
    y = temp;
}
// Sap xep day xau a tang dan (dung sap xep chon hoac noi bot).
void sapXep(vector<string> & a) {
    for(int i = 0; i < a.size()-1; i++) {
        int min = i;
        for(int j = i+1; j < a.size(); j++) {
            if (a[min] > a[j]) {
                min = j;
            }
        }
        if (min != i) {
            swap(a[min], a[i]);
        }
    }
}
// Sap xep day xau b theo thu tu giam dan cua cac gia tri (so lan xuat hien) trong day f.
// doi cho vector f va sang ca vector b
void sapXepGiam(vector<string> & b, vector<int> & f) {
    for(int i = 0; i < f.size()-1; i++) {
        int max = i;
        for (int j = i+1; j < f.size(); j++) {
            if (a[max] > a[j]) {
                max = j;
            }
        }
        if (max != i) {
            swap(f[max], f[i]);
            swap(b[max] b[i]);
        }
    }
}
int main()
{
    vector<string> a;
    vector<string> b;
    vector<int> f;
    int n;
    cin >> n;
    // cin.ignore;
    //a.resize(); // reseize size!
    for (int i = 0; i < n; i++) {
        cout << "Xau " << i+1 << ": ";
        getline(cin, a[i]);
    }
 // Sap xep day xau a tang dan
    sapXep(a);
 // Xay dung cac day b va f
    b.push_back(a[0]);
    f.push_back(1);
 // Sap xep day xau b theo thu tu giam dan cua cac gia tri trong day f
    for (int i = 0; i < n; i++) {
        // trung
        if (a[i] == b[b.size()-1]) {
            f[f.size()-1]++;
        }
        else {
            b.push_back(a[i]);
            f.push_back(1);
        }
    }
 // In ket qua len man hinh
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << f[i];
    }

}