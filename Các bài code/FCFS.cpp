#include<iostream>
#include<stdio.h>

using namespace std;

void doiCho(int &a, int &b);

int main()
{
	//khai bao bien thoi gian BurstTime và WaitingTime
	int bt[30], wt[30] ;
	int n, i, j, tb =0, k;
	int p[30];
	
	cout<<"Nhap vao so tien trinh: ";
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		cout<<"\n\nNhap Process: P";
		cin>>p[i];
		cout<<"Nhap Burst Time: ";
		cin>>bt[i];
	}
	
	cout<<"\nProcess\t    Burst Time    \tWaiting Time";
	for(i=0;i<n;i++)
    {
    	tb += bt[i]; 
    	wt[i] = tb - bt[i];
        cout<<"\nP["<<p[i]<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i];
    }
	
	tb = 0;
	cout<<"\n\nThoi gian cho tb = ";
	for(i = 0;i<n;i++)
	{
		tb += wt[i];
	}
	cout<<tb/n;
	
	cout<<endl;
	return 0;
}
//Dinh nghia ham
void doiCho(int &a, int &b)
{
	int tg = a;
	a = b;
	b = tg;
}
