#include<iostream>
#include<windows.h>
#include<stdlib.h>
using namespace std;
const int N=10000;
int a[N]={0},b[N][N]={0},sum[N]={0};
int main()
{
    long long start,finish,freq;

    //开始计时，测试算法
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);//时钟频率
    for(int x=0;x<2;x++)//循环两次
    {
        QueryPerformanceCounter((LARGE_INTEGER *)&start);//开始时间
        for(int i=0;i<N;i++)
        {
            sum[i]=0;
            for(int j=0;j<N;j++)
                sum[i]+=a[i]*b[j][i];

        }
        QueryPerformanceCounter((LARGE_INTEGER *)&finish);//结束时间
        cout<<(finish-start)*1000.0/(freq)<<endl;
    }


}
