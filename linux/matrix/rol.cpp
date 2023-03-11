#include<iostream>
#include<sys/time.h>
#include<stdlib.h>
using namespace std;
const int N=10000;
int a[N],b[N][N],sum[N];
int main()
{
    timeval start,finish;
    int step=10;
    //初始化
    for(int i=0;i<N;i++)
    {
        a[i]=i;
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            b[i][j]=i+j;
    //开始计时，测试算法
    for(int j=0;j<10;j++)
    for(int n=N;n<=N;n+=step)
    {

        gettimeofday(&start,NULL);//开始时间
        for(int i=0;i<n;i++)
            sum[i]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                sum[j]+=a[i]*b[i][j];
        gettimeofday(&finish,NULL);//结束时间

        cout<<"n:"<<n<<" time:"<<((finish.tv_sec-start.tv_sec)*1000000.0+finish.tv_usec-start.tv_usec)/1000.0<<"ms"<<endl;
        if(n==100)
            step=100;
		if(n==1000)
			step=1000;

    }
}
