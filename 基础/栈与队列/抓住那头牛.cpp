#include<iostream>
#include<queue>
using namespace std;
int Time[100005];
int visited[100005];
void CatchCow(int n, int k)
{
    queue<int> que;
    visited[n] = 1;
    Time[n] = 0;
    que.push(n);
    int d[3];
    while(!que.empty())
    {
        int pos = que.front();
        que.pop();
        if(pos == k)
            break;
        d[0] = pos - 1;
        d[1] = pos + 1;
        d[2] = pos*2;

        for(int i = 0 ;i< 3; i++)
        {
            if(d[i] < 0 || d[i] >100000 || visited[d[i]])
                continue;
            que.push(d[i]); 
            visited[d[i]] = 1;
            Time[d[i]] = Time[pos] + 1;
            // cout << d[i] <<' ' << time[d[i]] << endl;
            // cout << que.size() << endl;

        }
    }
    cout << Time[k] << endl;
}
int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    CatchCow(n ,k);
    system("pause");
    return 0;
}