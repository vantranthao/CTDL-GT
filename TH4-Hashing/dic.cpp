#include <iostream>
#include <string>
using namespace std;

// muc tu trong tu dien
struct MucTu
{
    string tuTiengAnh;
    string nghiaTiengViet;
    // constructor
    MucTu(string tuTA = "", string nghiaTV = "")
    {
        tuTiengAnh = tuTA;
        nghiaTiengViet = nghiaTV;
    }
};

// tu dien (probing)
class TuDien
{
public:
    TuDien(int size = 101)
    {
        tableSize = 101;
        // cap phat mang dong
        table = new MucTu[tableSize]; // kieu muc tu: tuTA, tuTV
        trong = new bool[tableSize];
        for (int i = 0; i < tableSize; i++) {
            trong[i] = true;
        }
    }
    ~TuDien()
    {
        // xoa bang bam
        delete[] table;
        delete[] trong;
    }
    // insert
    void chenMucTu(MucTu mt)
    {
        int index = hash(mt.tuTiengAnh);
        // collision
        while(!trong[index]) {
            index++;
            index = index % tableSize;
        }
        table[index] = mt;
        trong[index] = false; // khong trong nua!
        size++;
    }
    // lay nghia tieng viet
    string nghiaTiengViet(string tuTiengAnh)
    {
        int index = hash(tuTiengAnh);
        while(!trong[index]) {
            if (table[index].tuTiengAnh == tuTiengAnh) {
                return table[index].nghiaTiengViet;
            }
            index++;
            index = index % tableSize;
        } 
        return "";
    }
    string capNhatNghiaTV
    int returnSize(){
        return size - 1; // tra ve so luong muc tu trong tu dien
    }

private:
    MucTu *table;  // con tro toi bang bam
    int size; // dem so muc tu co trong tu dien
    int tableSize; // kthuoc bang bam
    bool *trong;   // trong?
    // hasing funtions
    int hash(string tuTiengAnh)
    {
        int hashVal = 0;
        for (int i = 0; i < tuTiengAnh.size(); i++)
        {
            hashVal += tuTiengAnh[i];
        }
        return hashVal % tableSize;
    }
};

int main()
{
    TuDien td;
    MucTu mt1("computer", "may tinh");
    MucTu mt2("memory", "bo nho");
    MucTu mt3("hard disk", "dia cung");
    MucTu mt4("monitor", "man hinh");

    // insert
    td.chenMucTu(mt1);
    td.chenMucTu(mt2);
    td.chenMucTu(mt3);
    td.chenMucTu(mt4);
    string tuTA, nghiaTV;
    // Yeu cau nhap tu tieng Anh de tra cuu tu dien
    cout << "Nhap tu tieng Anh: ";
    getline(cin, tuTA);
    // Tim nghia tieng Viet
    nghiaTV = td.nghiaTiengViet(tuTA);

    //cout << td.returnSize();
    // In ket qua tra cuu
    if (nghiaTV == "")
        cout << "Tu vua nhap khong co trong tu dien" << endl;
    else
        cout << "Nghia cua tu vua nhap la: " << nghiaTV << endl;
    return 0;
}