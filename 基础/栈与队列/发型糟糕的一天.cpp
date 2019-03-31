#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int a[100000];
void CowCount(int N)
{
    long long sum = 0;
    stack<int> stk;
    stk.push(a[0]);
    for(int i = 1; i< N; i++)
    {
        while(!stk.empty() && a[i] >= stk.top())
            stk.pop();
        sum += stk.size();
        stk.push(a[i]);
        
    }
    cout << sum << endl;
}
int main()
{
    int N;
    cin >> N;
    for(int i = 0;i < N; i++)
        cin >> a[i];
    CowCount(N);
    system("pause");
    return 0;
}