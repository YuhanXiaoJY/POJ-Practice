#include<iostream>
#include<algorithm>
#include<set>
#include<functional>
#include<vector>
using namespace std;
int a[1000005];
int Max[1000005];
int Min[1000005];
int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    multiset<int, less<int> > bi_que;
    for(int i = 0; i < k; i++)
    {
        bi_que.insert(a[i]);
    }
    multiset<int, less<int> >::iterator p1 = bi_que.begin();
    multiset<int, less<int> >::iterator p2 = bi_que.end();
    --p2;
    multiset<int, less<int> >::iterator remv;
    Max[0] = *p2;
    Min[0] = *p1;
    for(int i = k; i < n;i++)
    {
        bi_que.insert(a[i]);
        remv = bi_que.find(a[i - k]);
        bi_que.erase(remv);
        p1 = bi_que.begin();
        p2 = bi_que.end();
        --p2;
        Max[i - k + 1] = *p2;
        Min[i - k + 1] = *p1;
    }
    for(int i = 0 ; i< n- k + 1; i++)
        cout << Min[i] << ' ';
    cout << endl;
    for(int i = 0; i< n-k+1; i++)
        cout << Max[i] << ' ';
    cout << endl;
    system("pause");
    return 0;
}