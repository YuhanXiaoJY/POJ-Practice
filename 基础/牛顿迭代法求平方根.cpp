#include<iostream>
using namespace std;
const double EPS = 0.001;
void Newton()
{
    double a;
    cin >> a;
    double x1 = a;
    double x2 = a/2;
    while(abs(x2 - x1) > EPS)
    {
        x1 = x2;
        x2 = (x1 + a/x1)/2;
    }
    cout << x2 << endl;

}
int main()
{
    Newton();
    system("pause");
    return 0;
}