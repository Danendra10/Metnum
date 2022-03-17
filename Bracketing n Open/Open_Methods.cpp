#include <bits/stdc++.h>
// #define h 0.01
#define f(x) exp(x) - 5*pow(x,2)

using namespace std;

double derivFx(double x)
{
    double h = 0.01;
    double hasil = ((f(x + h) - f(x)) / h);
    return hasil;
    // cout << hasil;
}

double newton_rapshon_method(double x, double e)
{
    int i = 0;
    double xr;
    while (true)
    {
        cout << fabs(xr-x) << i << x << xr << endl;
        xr = x -(f(x)/derivFx(x));
        x = xr;
        i++;
        if(fabs(xr-x) < e)
            break;
    }
    return x;   
}

int main()
{
    // float result = derivFx(1);
    // derivFx(1);
    // cout << result;
    // cout << derivFx(1);
    cout << newton_rapshon_method(0, 0.00001);
}