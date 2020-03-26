#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	//khai bao bien thoi gian BurstTime và WaitingTime
	int bt[30], wt[30] ;
	int n, i, j, tb =0, k, tg = 0;
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
    	tg += bt[i]; 
    	wt[i] = tg - bt[i];
		tb += wt[i];
        cout<<"\nP["<<p[i]<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i];
    }
	
	cout<<"\n\nThoi gian cho tb = "<<tb/n;
	
	cout<<endl;
	return 0;
}
