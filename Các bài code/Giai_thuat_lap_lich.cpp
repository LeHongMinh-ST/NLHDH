#include<iostream>
 
using namespace std;

//===Chuong trinh chinh===
int main()
{
	//Khai bao bien
    int bt[20],p[20],wt[20],pr[20],i,j,n,total=0,pos,temp,avg_wt;
    cout<<"Enter Total Number of Process:";
    cin>>n;
 
    cout<<"\nEnter Burst Time and Priority\n";
    for(i=0;i<n;i++)
    {
        cout<<"\nP["<<i+1<<"]\n";
        cout<<"Burst Time:";
        cin>>bt[i];
        cout<<"Priority:";
        cin>>pr[i];
        p[i]=i+1;           //Chua so tien trinh
    }
 
    //Dung giai thuat sap xep chon de sap xep tg thuc hien, muc uu tien, so tien trinh theo thu tu tang dan.
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
 		//Doi cho thoi gian thuc hien
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 		
 		//Doi cho muc uu tien
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
 		//Doi cho tien trinh
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;            //Thoi gian cho cho tien trinh dau tien = 0
 
    //Tinh thoi gian cho
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      //Tinh thoi gian cho TB

 
    cout<<"\nProcess\t    Burst Time    \tWaiting Time";
 	for(i=0;i<n;i++)
    {
        cout<<"\nP["<<p[i]<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i];
    }
    cout<<"\n\nAverage Waiting Time="<<avg_wt;
 
    return 0;
}
