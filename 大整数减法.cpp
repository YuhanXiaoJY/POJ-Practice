#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
void Strrev(char * str)
{
	int len = strlen(str);
	char temp[205];
	memcpy(temp, str, (len + 1) * sizeof(char));
	int i = 0;
	for (i = 0; i < len; i++)
	{
		str[i] = temp[len - 1 - i];
	}
}

void BigMinus(char * a1, char * a2)
{
	char big[205], small[205];
	int bigLen, smallLen;
	if (strlen(a1) >= strlen(a2))
	{
		bigLen = strlen(a1);
		smallLen = strlen(a2);
		memcpy(big, a1, (bigLen + 1)*sizeof(char));
		memcpy(small, a2, (smallLen + 1)*sizeof(char));
	}
	else
	{
		bigLen = strlen(a2);
		smallLen = strlen(a1);
		memcpy(big, a2, (bigLen +1 )*sizeof(char));
		memcpy(small, a1, (smallLen + 1)*sizeof(char));
	}
	int carry_bit = 0;
	char result[205];
	for (int i = 0; i < bigLen; i++)
	{
		if (i > smallLen - 1)
			small[i] = '0';
		int minus = big[i] - small[i] - carry_bit;
		if (minus >= 0)
		{
			result[i] = minus + '0';
			carry_bit = 0;
		}
		else
		{
			result[i] = minus + 10 + '0';
			carry_bit = 1;
		}
	}
	result[bigLen] = '\0';

	int j = bigLen - 1;
	while (result[j] == '0')
	{
		result[j] = '\0';
		j--;
	}
	if (strlen(result) == 0)
	{
		cout << '0' << endl;
		return;
	}
	Strrev(result);
	cout << result << endl;

}


int main()
{
	char a1[205];
	char a2[205];
	cin >> a1;
	cin >> a2;
	Strrev(a1);
	Strrev(a2);
	BigMinus(a1, a2);

	//system("pause");
	return 0;
}