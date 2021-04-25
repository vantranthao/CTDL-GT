// Nguyen Manh Hien
// hiennm@tlu.edu.vn

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<T> timGiao(vector<T> & a, vector<T> & b)
{
	vector<T> c;
	
	int i = 0, j = 0;

  while (i < a.size() && j < b.size())
	{
		if (a[i] < b[j])
			i++;
		else if (a[i] > b[j])
			j++;
		else
		{
			c.push_back(a[i]);
			i++;
			j++;
    }
  }
	
	return c;
}

int main()
{
	vector<int> a = {1, 3, 5, 6, 9}; // Phai chon C++11 trong Dev-C++: Tools/Compiler Options/Settings/Code Generation/Language standard = ISO C++11
	vector<int> b = {2, 3, 4, 6, 10};
	
	vector<int> c = timGiao(a, b);
	
	cout << "Giao la: ";
	for (int i = 0; i < c.size(); i++)
		cout << c[i] << " ";
	
	return 0;
}