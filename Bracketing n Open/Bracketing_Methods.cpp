#include <bits/stdc++.h>
#define error_ 0.00001
#define f(x) exp(x) - (5 * pow(x, 2))

double epsilon;
int i;
float fa;
float fb;
float fc;
float c;
int checker_ = 0;
bool loop = true;

using namespace std;
vector<double> a_;
vector<double> b_;
vector<double> c_;

bool assign(double _x, double _y, double _z)
{
    i = 1;
    a_.push_back(_x);
    b_.push_back(_y);
    c_.push_back(_z);

    while (true)
    {
        i++;
        if (i > 0)
        {
            if (a_[i] == a_[i - 1])
            {
                cout << "masuk kedalam perulangan dengan nilai i: " << i << endl;
                checker_++;
                if (checker_ >= 10)
                {
                    printf("STOP HERE\n");
                    return false;
                }
            }
            else
            {
                printf("%lf, %lf, %lf \n", a_[i], b_[i], c_[i]);
                return true;
            }
        }
    }
}
double _regula_falsi_method(float a, float b)
{
    int check = 0;
    float a_;
    float b_;
    epsilon = fabs(a - b);
    i = 0;
    while (loop)
    {
        fa = f(a);
        fb = f(b);
        c = b - (fb * (b - a) / (fb - fa));
        fc = f(c);
        epsilon = fabs(a - b);
        i++;
        if (check >= 10)
        {
            cout << "metu";
            break;
        }
        if ((fa * fc) < 0)
            b = c;
        else if ((fb * fc) < 0)        
            a = c;
        if (epsilon <= error_)
            break;
        if (i > 1000)
        {
            cout << "tdk ada jawaban";
            break;
        }
        if(a == a_ || b == b_)
            check++;
        a_ = a;
        b_ = b;
    }
    return c;
}

int main()
{
    cout << _regula_falsi_method(0, 1);
}