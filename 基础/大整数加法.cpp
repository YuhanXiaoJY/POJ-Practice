#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<cmath>
using namespace std;

void Strrev(char * str)
{
	char temp[205];
	memcpy(temp, str, strlen(str) * sizeof(char));
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		str[i] = temp[len - 1 - i];
	}
	
}

int max(int a, int b)
{
	if (a > b)
		return a;
	else
			
		return b;
}

int min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}

char * BigPlus(char * integer1, char * integer2)
{
	char *sum = new char[205];
	int len1 = strlen(integer1);
	int len2 = strlen(integer2);
	int carry_bit = 0;
	Strrev(integer1);
	Strrev(integer2);    // only applied to type of char. Use function "reverse" to reverse a string.

	int iteration = max(len1, len2) + 1;
	int point = min(len1, len2);
	int i;
	for (i = 0; i < iteration; i++)
	{
		int add;
		if (i < point)
			add = integer1[i] - '0' + integer2[i] - '0' + carry_bit;
		else if (i >= point && i< iteration - 1)
		{
			if (len1 >= len2)
			{
				add = integer1[i] - '0' + carry_bit;
				//cout << add << endl;
			}	
			else
			{
				add = integer2[i] - '0' + carry_bit;
				//cout << add << endl;
			}
				
		}
		else
		{
			if (carry_bit > 0)
			{
				//cout << carry_bit << endl;
				sum[i] = carry_bit + '0';
				sum[i+1] = '\0';
				break;
			}	
			else
			{
				//cout << i << endl;
				sum[i] = '\0';
				break;
			}

		}


		carry_bit = add / 10;
		sum[i] = (add % 10) + '0';

	}
	Strrev(sum);
	return sum;
}

void rzero(char * str)	// remove the preposed zeros
{
	int len = strlen(str);
	if (len == 1 && str[0] == '0')
		return;


	if (str[0] != '0') 
		return;
	int i = 0;
	int j = 0;
	char temp[205];
	memcpy(temp, str, (len+1) * sizeof(char));	//trap! It is vital that we use 'len + 1' or the '\0' will not be copied to temp
	while (temp[i] == '0')
		i++;
	
	while (i <= len)
	{
		str[j++] = temp[i++];

	}
}

int main()
{
	char integer1[205], integer2[205];
	cin >> integer1;
	cin >> integer2;
	rzero(integer1);
	rzero(integer2);
	//cout << integer1 << endl << integer2 << endl;
	char *sum = BigPlus(integer1, integer2);
	cout << sum << endl;
	delete sum;
	//system("pause");
	return 0;
}


/*
注意点：
1、函数返回指针时，要注意该指针是否是临时的，若是临时的，则函数返回后该指针将成为空指针。因此，为保证指针非临时，需要在函数中
new一个空间，该空间的释放由自己决定，函数返回该指针时就不会清空其中的内容
2、openjudge不支持strrev函数
*/