#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
string grid[10005];
int mymax(int a, int b)
{
    if(a >= b)
        return a;
    else
    {
        return b;
    }
    
}
int mymin(int a, int b)
{
    if(a < b)
    return a;
    else
    {
        return b;
    }
    
}
int ComDivis(int max, int min)
{
    int tmp = min;
    while(max%min != 0)
    {
        tmp = max%min;
        max = min;
        min = tmp;
    }
    return tmp;
}
int ComMulti(int max, int min)
{
    int com_multi = ComDivis(max, min);
    return max*min/com_multi;
}
int GetNext(int choice, int index, int len)
{
    int next[10005];
    int q, k;
    k = 0;
    next[0] = 0;
    //row
    if(choice == 1)
    {
        for(q = 1; q < len; q++)
        {
            while(k > 0 && grid[index][q] != grid[index][k])
                k = next[k-1];
            if(grid[index][q] == grid[index][k])
                ++k;
            next[q] = k; 
        }
        return next[len-1];
    }
    else if(choice == 2)  //column
    {
        for(q = 1; q < len; q++)
        {
            while(k > 0 && grid[q][index] != grid[k][index])
                k = next[k - 1];
            if(grid[q][index] == grid[k][index])
                ++k;
            next[q] = k;
        }
        return next[len -1];
    }
    
}
int GetRow(int r, int c)
{
    int com_multi = 1;
    for(int i = 0; i< r; i++)
    {
        int ovlap = c - GetNext(1, i, c);
        int max = mymax(ovlap, com_multi);
        int min = mymin(ovlap, com_multi);
        com_multi = ComMulti(max, min);
    }
    return mymin(com_multi, c); //不能超过矩阵本身的列数
}
int GetColumn(int r, int c)
{
    int com_multi = 1;
    for(int i = 0; i < c; i++)
    {
        int ovlap = r - GetNext(2, i, r);
        int max = mymax(ovlap, com_multi);
        int min = mymin(ovlap, com_multi);
        com_multi = ComMulti(max, min);
    }
    return mymin(com_multi, r); //不能超过矩阵本身的行数
}
int main()
{
    int R,C;
    cin >> R >> C;
    for(int i = 0; i < R; i++)
        cin >> grid[i];
    int row, column;
    row = GetRow(R, C);
    column = GetColumn(R, C);
    cout << row*column << endl;
    system("pause");
    return 0;
}