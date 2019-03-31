#include<iostream>
using namespace std;
int Apple(int m, int n)
{
    if(m < n)
        return Apple(m,m);
    if(n == 1 || n==0)
        return 1;
    return Apple(m-n, n) + Apple(m, n-1);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m,n;
        cin >> m  >> n;
        cout << Apple(m, n) << endl;
    }
    system("pause");
    return 0;
}