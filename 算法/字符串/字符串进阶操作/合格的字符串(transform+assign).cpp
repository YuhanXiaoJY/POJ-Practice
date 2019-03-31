#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<algorithm>
#include<functional>
#include<list>
#include<cstring>
#include<vector>
#include<string>
#include<stack>
//#define debug
using namespace std;
bool HWPass(string hw, string temp)
{
	int pos1 = temp.find('[');
	int pos2 = temp.rfind(']');
	//标记模板中的字符，方便后面的查找判断
	map<char, int> mymap;
	for (int i = pos1 + 1; i < pos2; i++)
	{
		mymap[temp[i]] = 1;
	}
	string hw_part1, hw_part3, temp_part1, temp_part3;
	temp_part1.assign(temp, 0, pos1);
	temp_part3.assign(temp, pos2 + 1, hw.length() - pos2 + 1);
	hw_part1.assign(hw, 0, pos1);
	hw_part3.assign(hw, pos1 + 1, hw.length() - pos2 + 1);
	char hw_part2 = hw[pos1];

#ifdef debug
	cout << "[d]" << endl;
	cout << hw_part1 << ' ' << hw_part2 << ' ' << hw_part3 << endl;
	cout << temp_part1 << ' ' << temp_part3 << endl;
	cout << "[d]" << endl;

#endif

	if (hw_part1 != temp_part1 || hw_part3 != temp_part3)
		return false;
	if (mymap[hw_part2] == 0)
		return false;
	return true;

}
int main()
{
	int n; 
	cin >> n;
	string hw[55];
	for (int i = 0; i < n; i++)
	{
		cin >> hw[i];
	}
	string temp;
	cin >> temp;
	transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
	for (int i = 0; i < n; i++)
	{
		string str = hw[i];	//transform的第三个参数不能是未初始化string的迭代器
		transform(hw[i].begin(), hw[i].end(), str.begin(), ::tolower);	//将string改为小写，头文件为algorithm
		bool hw_pass = HWPass(str, temp);
		if (hw_pass)
			cout << i + 1 << ' ' << hw[i] << endl;
	}
	system("pause");
	return 0;
}