#include <iostream>
#include<sys/time.h>
#include<stdlib.h>
using namespace std;

const int N=131072;
int a[N]={0};
int main()
{

    timeval start,finish;
    int sum,step=500;
    for(int i=0;i<N;i++)
        a[i]=i;

    //链式
	for(int j=0;j<50;j++)
    for(int n=N;n<=N;n+=step)
    {
        sum=0;
        gettimeofday(&start,NULL);//开始时间

        for(int i=0;i<n;i++)
            sum+=a[i];

        gettimeofday(&finish,NULL);//结束时间


        cout<<((finish.tv_sec-start.tv_sec)*1000000.0+finish.tv_usec-start.tv_usec)/1000.0<<endl;
        if(n==1000)
            step=1000;
        if(n==10000)
            step=10000;
      }
}

