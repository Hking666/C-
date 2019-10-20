#include<iostream>
using  namespace std;

#include<vector>
int  main()
{
	int  a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	v.erase(pos);
	cout << *pos << endl;

	pos = find(v.begin(), v.end(), 3);
	v.insert(pos,30);
	cout << *pos << endl;

	return 0;

}