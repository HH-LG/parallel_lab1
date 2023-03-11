#include <iostream>
#include<sys/time.h>
#include<stdlib.h>
using namespace std;

const int N=131072;
int a[N]={0};
int main()
{

    timeval start,finish;
	
	for(int j=0;j<50;j++)
    for(int n=N;n<=N;n*=2)
    {
        for(int i=0;i<N;i++)
            a[i]=1;
        gettimeofday(&start,NULL);//开始时间

        for (int m = n; m > 1; m /= 2) // log(n)个步骤
            for (int i = 0; i < m / 2; i++)
                a[i ] = a[i * 2] + a[i * 2 + 1]; // 相邻元素相加连续存储到数组最前面

        gettimeofday(&finish,NULL);//结束时间

        cout<<((finish.tv_sec-start.tv_sec)*1000000.0+finish.tv_usec-start.tv_usec)/1000.0<<endl;
    }
}

