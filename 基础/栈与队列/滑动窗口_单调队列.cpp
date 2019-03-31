#include<iostream>
#include<queue>
using namespace std;
int a[1000005];
int Max[1000005];
int Min[1000005];
void GetMaxMin(int n ,int k)
{
    deque<int> max_que, min_que;
    max_que.push_back(0);
    min_que.push_back(0);
    for(int i = 1; i < k; ++i)
    {
        //remove the elements in the tail
        while(!max_que.empty() && a[i] >= a[max_que.back()])
            max_que.pop_back();
        max_que.push_back(i);
        while(!min_que.empty() && a[i] <= a[min_que.back()])
            min_que.pop_back();
        min_que.push_back(i);
    }
    Max[0] = a[max_que.front()];
    Min[0] = a[min_que.front()];

    for(int i = k; i< n; ++i)
    {
        //remove the elements in the tail
        while(!max_que.empty() && a[i] >= a[max_que.back()])
            max_que.pop_back();
        max_que.push_back(i);
        while(!min_que.empty() && a[i] <= a[min_que.back()])
            min_que.pop_back();
        min_que.push_back(i);

        //update the outdated head
        if(max_que.front() <= i - k)
            max_que.pop_front();
        if(min_que.front() <= i - k)
            min_que.pop_front();
        Max[i -k +1] = a[max_que.front()];
        Min[i- k + 1] = a[min_que.front()];
    }

    for(int i = 0; i < n -k + 1; i++)
        cout << Min[i] << ' ';
    cout << endl;
    for(int i = 0; i< n - k +1; i++)
        cout << Max[i] << ' ';
    cout << endl;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 0;i < n; i++)
        cin >> a[i];
    GetMaxMin(n, k);
    system("pause");
    return 0;
}