#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int passlen[400005];
int kmpnext[400005];

void GetNext(string str)
{
    int m = str.length();
    int q, k = 0;
    kmpnext[0] = 0;
    for(q = 1; q < m ; ++q)
    {
        while(k > 0 && str[q] != str[k])
            k = kmpnext[k-1];
        if(str[q] == str[k])
            ++k;
        kmpnext[q] = k; 
    }
}

int main()
{
    string str, p;
    while(cin >> str)
    {
        memset(passlen, 0, sizeof(passlen));
        memset(kmpnext, 0, sizeof(kmpnext));
        int num = 0;
        int len = str.length();
        int possible_len = len;
        passlen[num++] = len;
        GetNext(str);
        while(kmpnext[possible_len - 1] > 0)
        {
            passlen[num++] = kmpnext[possible_len - 1];
            possible_len = kmpnext[possible_len - 1];
        }
        
        for(int i = num - 1; i >= 0; --i)
            cout << passlen[i] << ' ';
        cout << endl;
    }

    system("pause");
    return 0;
}