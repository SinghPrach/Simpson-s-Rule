#include <iostream>
#include<math.h>
#include<iomanip>
#include<stdlib.h>

using namespace std;

double function(double x)
{
    double f = (1/(1-(x*x)));
    return f;
}

int main()
{
    double a,b,n,N,t,delx,integration,a1,k,sum,actualvalue,integrat,error;
    int i;
    actualvalue = -0.3810700260234484;
    cout<<"Enter the value of first boundary:";
    cin>>a;
    cout<<"Enter the value of second boundary:";
    cin>>b;
    cout<<"Enter the minimum number of intervals:";
    cin>>n;
    cout<<"Enter the maximum number of intervals:";
    cin>>N;
    cout<<"Number of intervals \t Integral Value \t Error"<<endl;
    delx = (b-a)/n;
    for(;n<=N;n++)
    {
        a1 = 0;
        delx = (b-a)/n;
        integration = function(a)+function(b);
        integrat = 0;
        for(i=1;i<=n-1;i++)
        {
            k = a+i*(delx);
            if(i%2==0)
                {
                    integrat = integrat + 2.0 * (function(k));
                }
            else
                {
                    integrat = integrat + 4.0 * (function(k));
                }
        }
        integration = (integration+integrat) * delx/3.0;
        error = fabs(integration-actualvalue);
        cout <<n<< "\t \t \t" <<integration<<"\t \t \t"<<error<<endl;
    }
    return 0;
}
