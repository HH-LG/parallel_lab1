#include <iostream>
#include<windows.h>
#include<stdlib.h>
using namespace std;

const int N=100000;
int a[N]={0};
int main()
{

    long long start,finish,freq;
    int sum,step=500;
    for(int i=0;i<N;i++)
        a[i]=i;

    //链式
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);//时钟频率;
    for(int n=0;n<=N;n+=step)
    {
        sum=0;
        QueryPerformanceCounter((LARGE_INTEGER *)&start);//开始时间;

        for(int i=0;i<n;i+=2)
            sum+=a[i]+a[i+1];

        QueryPerformanceCounter((LARGE_INTEGER *)&finish);//结束时间;

        cout<<(finish-start)*1000.0/(freq)<<endl;
        if(n==1000)
            step=1000;
        if(n==10000)
            step=10000;
    }
}
