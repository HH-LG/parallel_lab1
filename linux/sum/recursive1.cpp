#include <iostream>
#include<sys/time.h>
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

    timeval start,finish;

	for(int j=0;j<50;j++)
    for(int n=N;n<=N;n*=2)
    {
        for(int i=0;i<N;i++)
            a[i]=1;
        gettimeofday(&start,NULL);//开始时间

        sum(a,n);

        gettimeofday(&finish,NULL);//结束时间

        cout<<((finish.tv_sec-start.tv_sec)*1000000.0+finish.tv_usec-start.tv_usec)/1000.0<<endl;
    }
}

