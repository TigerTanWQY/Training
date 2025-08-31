#include<iostream>
#include<cmath>
using namespace std;
double MySqrt(double n)
{
    double x = 1.0;
    double p = 1e-5;
    while(fabs(x*x - n) > p)
        x = (x + n / x) / 2.0;
    return x;
}
int main()
{
    cout<<MySqrt(82)<<endl;
}