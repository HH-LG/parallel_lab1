#include <iostream>
#include<windows.h>
#include<stdlib.h>
using namespace std;

const int N=131072;
int a[N]={0};
void sum(int a[],int n)
 {
     if (n == 1)
        return;
     else
     {
        for (int i = 0; i < n / 2; i++)
            a[i] += a[n - i - 1];
        n = n / 2;
        sum(a,n);
     }
 }
int main()
{

    long long start,finish,freq;
        //������
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);//ʱ��Ƶ��;
    for(int n=1;n<=N;n*=2)
    {
        for(int i=0;i<N;i++)
            a[i]=1;
        QueryPerformanceCounter((LARGE_INTEGER *)&start);//��ʼʱ��;

        sum(a,n);

        QueryPerformanceCounter((LARGE_INTEGER *)&finish);//����ʱ��;

        cout<<(finish-start)*1000.0/(freq)<<endl;
    }
}
