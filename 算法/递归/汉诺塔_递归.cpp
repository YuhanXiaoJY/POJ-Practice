#include<iostream>
#include<cstdlib>
using namespace std;

void Hanoi(int n, const char src, const char mid, const char des)
{
	if (n == 1)
	{
		cout << 1 << ':' << src << "->" << des << endl;
		return;
	}
	Hanoi(n - 1, src, des, mid);
	cout << n << ':' << src << "->" << des << endl;
	Hanoi(n - 1, mid, src, des);
}

int main()
{
	int n;
	char A, B, C;
	cin >> n;
	cin >> A >> B >> C;
	Hanoi(n, A, B, C);
	system("pause");
	return 0;
}