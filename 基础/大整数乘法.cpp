#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;

void Strrev(char * str)
{
	int len = strlen(str);
	char temp[410];
	memcpy(temp, str, (len + 1) * sizeof(char));
	for (int i = 0; i < len; i++)
	{
		str[i] = temp[len - 1 - i];
	}
}

void BigMulti(char * a1, char * a2)
{
	int bigLen, smallLen;
	char big[205],small[205];
	if (strlen(a1) >= strlen(a2))
	{
		bigLen = strlen(a1);
		smallLen = strlen(a2);
		memcpy(big, a1, (bigLen + 1) * sizeof(char));
		memcpy(small, a2, (smallLen + 1) * sizeof(char));
	}
	else
	{
		bigLen = strlen(a2);
		smallLen = strlen(a1);
		memcpy(big, a2, (bigLen + 1) * sizeof(char));
		memcpy(small, a1, (smallLen + 1) * sizeof(char));
	}
	char result[405];
	result[0] = '0';
    result[1]  ='\0';
	for (int i = 0; i < smallLen; i++)
	{
        char temp_result[410];
        for (int k =0 ;k<i; k++)
        {
            temp_result[k] = '0';
        }
        int carry_bit = 0;
		for(int j =0 ;j<bigLen + 1;j++)
        {
            int multi;
            if ( j==bigLen)
            {
                multi = carry_bit;
                if (carry_bit == 0)
                {
                    temp_result[j + i] = '\0';
                    break;
                }
                else
                {
                    temp_result[j + i] = multi + '0';
                    temp_result[j+1 + i] = '\0';
                    break;
                }
                
            }
            multi = (big[j] - '0') * (small[i] - '0') + carry_bit;
            temp_result[j + i] = multi % 10 + '0';
            carry_bit = multi/10;
        }
        BigPlus(result, temp_result);
	}
	//result[bigLen] = '\0';
	Strrev(result);
	cout << result << endl;
}

int main()
{
	char a1[205], a2[205];
	cin >> a1 >> a2;
	Strrev(a1);
	Strrev(a2);
	BigMulti(a1, a2);

	system("pause");
	return 0;
}