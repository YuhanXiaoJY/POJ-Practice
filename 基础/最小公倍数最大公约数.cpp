#include<iostream>
using namespace std;
int ComMulti(int max, int min)
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
int ComDivis(int max, int min)
{
    //最大公约数=m*n/最小公倍数
    int com_multi = ComMulti(max, min);
    return max*min / com_multi;
}
int main()
{
    int m, n, max, min, tmp;
    cin >> m >> n;
    if(m > n)
    {
        max = m;
        min = n;
    }
    else
    {
        max = n;
        min = m;
    }
    int com_multi = ComMulti(max, min);
    int com_divis = ComDivis(max, min);

    cout << com_multi << endl;
    cout << com_divis << endl;
    system("pause");
    return 0;
}