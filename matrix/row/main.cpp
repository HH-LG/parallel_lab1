#include<iostream>
#include<windows.h>
#include<stdlib.h>
using namespace std;
const int N=10000;
int a[N],b[N][N],sum[N];
int main()
{
    long long start,finish,freq;
    int step=20;
    //��ʼ��
    for(int i=0;i<N;i++)
    {
        a[i]=i;
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            b[i][j]=i+j;
    //��ʼ��ʱ�������㷨
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);//ʱ��Ƶ��
    for(int n=0;n<=N;n+=step)
    {

        QueryPerformanceCounter((LARGE_INTEGER *)&start);//��ʼʱ��
        for(int i=0;i<n;i++)
            sum[i]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                sum[j]+=a[i]*b[i][j];
        QueryPerformanceCounter((LARGE_INTEGER *)&finish);//����ʱ��

        cout<<(finish-start)*1000.0/(freq)<<endl;
        if(n==100)
            step=100;
        if(n==1000)
            step=1000;

    }
}
