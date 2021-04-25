// bai chua, chua hieu lam!
#include <iostream>
using namespace std;
struct MucTu {
    string tuTiengAnh;
    string tuTiengViet;
    MucTu(string tuTA = "", string tuTV = "" ){
        tuTiengAnh = tuTA;
        tuTiengViet = tuTV;
    }
};
class TuDien {
    public:
        // ham tao
        TuDien(int size = 101) {
            tableSize = 101;
            table = new MucTu[tableSize];
            trong = new bool[tableSize];
            for(int i = 0; i < tableSize; i++) {
                trong[i] = true;
            }
        }
        // ham huy
        ~TuDien() {
            delete[] table;
            delete[] trong;
        }
        // chen muc tu
        void chenMucTu(MucTu mt) {
            mt.tuTiengAnh = lower(mt.tuTiengAnh);
            int index = hash(mt.tuTiengAnh);
            bool a = false;
            while(!trong[index]) {
                if (trunglap(mt.tuTiengAnh)) {
                    a = true;
                    break;
                }
                index++;
                index = index % tableSize;
            }
            if(!a) {
                table[index] = mt;
                trong[index] = false;
            } else {
                cout << "trung lap \n";
            }
        }
        // map nghia tviet voi tu ta
        string nghiaTiengViet(string tuTiengAnh) {
            int index = hash(tuTiengAnh);
            while(!trong[index]) {
                if (table[index].tuTiengAnh == tuTiengAnh) {
                    return table[index].tuTiengViet;
                }
            }
            return "";
        }
        // cap nhat nghia tieng viet
        void capNhat(string tuTiengAnh, string tuTiengViet) {
            int index = hash(tuTiengAnh);
            while(!trong[index]) {
                if (table[index].tuTiengAnh == tuTiengAnh) {
                    table[index].tuTiengViet = tuTiengViet;
                }
                index++;
                index = index % tableSize;
            }
        }
        // xoa
        void xoa(string tuTiengAnh) {
            int index = hash(tuTiengAnh);
            while(!trong[index]) {
                if (table[index].tuTiengAnh == tuTiengAnh) {
                    table[index].tuTiengViet = "";
                    trong[index] = true;
                }
                index++;
                index = index % tableSize;
            }
        }
        // check trung lap
        bool trunglap(string tuTiengAnh) {
            int index = hash(tuTiengAnh);
            while(!trong[index]) {
                if(table[index].tuTiengAnh == tuTiengAnh) {
                    return true;
                }
                index++;
                index = index % tableSize;
            }
            return false;
        }
    private:
        MucTu *table;
        int tableSize;
        bool *trong;
        int hash(string tuTiengAnh) {
            int hashVal = 0;
            for (int i = 0; i < tuTiengAnh.size(); i++) {
                hashVal += tuTiengAnh[i];
            }
            return hashVal % tableSize;
        }
        string lower(string &tuTiengAnh) {
            for(int i = 0; i < tuTiengAnh.size(); i++) {
                tuTiengAnh[i] = tolower(tuTiengAnh[i]);
            }
            return tuTiengAnh;
        }
};
int main()
{
    TuDien td;
    // Tao mot vai muc tu
    MucTu mt1("computer", "may tinh");
    MucTu mt2("memory", "bo nho");
    MucTu mt3("hard disk", "dia cung");
    // Chen cac muc tu vao tu dien
    td.chenMucTu(mt1);
    td.chenMucTu(mt2);
    td.chenMucTu(mt3);
    string tuTA, nghiaTV;
    // Yeu cau nhap tu tieng Anh de tra cuu tu dien
    cout << "Nhap tu tieng Anh: ";
    getline(cin, tuTA);
    // Tim nghia tieng Viet
    nghiaTV = td.nghiaTiengViet(tuTA);
    // In ket qua tra cuu
    if (nghiaTV == "")
        cout << "Tu vua nhap khong co trong tu dien" << endl;
    else
        cout << "Nghia cua tu vua nhap la: " << nghiaTV << endl;
    return 0;
}