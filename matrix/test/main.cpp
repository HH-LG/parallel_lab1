#include<iostream>
#include<windows.h>
#include<stdlib.h>
using namespace std;
const int N=10000;
int a[N]={0},b[N][N]={0},sum[N]={0};
int main()
{
    long long start,finish,freq;

    //��ʼ��ʱ�������㷨
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);//ʱ��Ƶ��
    for(int x=0;x<2;x++)//ѭ������
    {
        QueryPerformanceCounter((LARGE_INTEGER *)&start);//��ʼʱ��
        for(int i=0;i<N;i++)
        {
            sum[i]=0;
            for(int j=0;j<N;j++)
                sum[i]+=a[i]*b[j][i];

        }
        QueryPerformanceCounter((LARGE_INTEGER *)&finish);//����ʱ��
        cout<<(finish-start)*1000.0/(freq)<<endl;
    }


}
