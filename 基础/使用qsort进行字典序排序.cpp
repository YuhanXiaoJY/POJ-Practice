#include <iostream>
#include<string>
#include<cstring>
using namespace std;

int mycompare(const void * e1, const void * e2)
{
    char * ch1 = (char *) e1;
    char * ch2 = (char *) e2;
    return strcmp(ch1, ch2);
}

int main()
{
    char a[100][15];
    for (int i = 0; i< 3; i++)
    {
        cin >> a[i];
    }

    qsort(a, 3, sizeof(a[0]), mycompare);
    cout << sizeof(a[0])<<endl;     //sizeof(a[0])不受a[0]所存的字符串的影响，sizeof()得出的大小是存储空间的大小
    for (int i =0 ; i < 3; i++)
        cout << a[i] << endl;



    system("pause");
    return 0;
}