#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
using namespace std;
int dict[1000005];
int main()
{
    cin.sync_with_stdio(false);
    int M,N;
    int find = 0;
    cin >> M >> N;
    queue<int> index;
    while(N--)
    {
        int word;
        cin >> word;
        if(dict[word] == 0 && index.size() < M)
        {
            index.push(word);
            ++dict[word];
            ++find;
        }
        else if(dict[word] == 0 && index.size() >= M)
        {
            int remv = index.front();
            dict[remv] = 0;
            index.pop();
            index.push(word);
            ++dict[word];
            ++find;
        }

    }
    cout << find <<endl;
    system("pause");
    return 0;

}
