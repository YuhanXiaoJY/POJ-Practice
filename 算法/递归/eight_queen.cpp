/*
Author: Yuhan Xiao
Problem: Use string to solve the eight-queens problem
Date: 2019.3.7
*/
#include<iostream>
#include<string>
using namespace std;
string pos;
string result[100];
int cnt = 0;
bool posValid(int row, int position)
{
    for(int i = 0; i < row; i++)
    {
        if(pos[i] == position + '0' || row - i == abs(position + '0' - pos[i]))
            return false;
    }
    return true;
}

void Queen(int row)
{
    for(int i = 0; i< 8;i++)
    {
        if (!posValid(row, i + 1))
            continue;
        pos[row] = i +1+ '0';
        //cout << row <<' ' << i <<' '<< pos[row]<<endl;
        if(row == 7)
        {
            pos[row + 1] = '\0';
            //cout << pos.c_str() <<endl;
            result[cnt++] = pos.c_str();
            //pos[row] = '';
            return;
        }
            
        Queen(row + 1);
    }
}

int main()
{
    Queen(0);
    int n;
    cin >> n;
    while(n--)
    {
        int b;
        cin >> b;
        cout << result[b-1].c_str()<<endl;
    }

    system("pause");
    return 0;
}



/*
注意：使用string时，尽量不要修改string中的字符串。如果修改，输出时应使用string.c_str()，否则很可能出现输出不了的问题
*/