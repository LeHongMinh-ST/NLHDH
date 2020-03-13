#include<iostream>
#include<stdio.h>

using namespace std;
//Khai bao cau truc
struct tientrinh
{
    char ten[12]; //Tên tien trinh
    int t_xh;//thoi gian xuat hien cua tien trinh
    int t_th;//thoi gian thuc hien cua tien trinh
    int t_bd;//thoi diem bat dau xu ly cua tien trinh
    int t_kt;//thoi diem ket thuc xu ly cua tien trinh
    int t_cho;//thoi gian cho cua tien trinh
//    int t_xuly;//thoi gian thuc hien cua tien trinh

};
int timeout;//thoi gian cuoi cung cua tien trinh vua ket thuc

//khai bao ham
void sjf(tientrinh a[],int n);
//===chuong trinh chinh===
int main()
{
	struct tientrinh a[100];
	int num, tbc = 0, sum=0;
      
    cout<<"Nhap so tien trinh: "; 
    cin>>num;  
    for(int i=0; i<num; i++) 
    {  
        cout<<"Nhap ten tien trinh: ";
        fflush(stdin);
        gets(a[i].ten);
        cout<<"Nhap thoi gian xuat hien: "; 
        cin>>a[i].t_xh; 
        cout<<"Nhap thoi gian thuc hien: "; 
        cin>>a[i].t_th;
        sum+=a[i].t_th;
		cout<<"\n-------------------\n";
    } 
      
    cout<<"Process ID\tArrival Time\tBurst Time\n"; 
    for(int i=0; i<num; i++) 
    { 
        cout<<i+1<<"\t\t"<<a[i].t_xh<<"\t\t"<<a[i].t_th<<"\n"; 
    }
    int n = num;

	sjf(a,num);
	//hien thi hinh
	//...
	
	//hien thi kq tinh toan
	cout<<"\n\nTINH THOI GIAN CHO CUA TUNG TIEN TRINH\n";
    cout<<"     Tg_Cho = Tg_bdau - Tg_Xhien\n";
    
    for(int i=0;i<num;i++)
    {
    	cout<<"\t\t"<<a[i].ten<<" = "<<a[i].t_bd<<" - "<<a[i].t_xh<<"\n";
	}
	cout<<"Thoi gian cho TB: ( ";
	for(int i=0;i<num;i++)
	{
		tbc += a[i].t_cho; 
		if(i==num-1) cout<<a[i].t_cho;
		else cout<<a[i].t_cho<<" + ";
	}
	cout<<" )/"<<num<<" = "<<tbc/num;
    
	cout<<endl;
	return 0;
}
//dinh nghia ham
void sjf(tientrinh a[],int n)
{
	tientrinh tg;
	for(int i=0;i<n;i++)
	{
		if(a[i].t_xh>=timeout)/*neu thoi gian xuat hien cua tien trinh vua nap >= thoi gian ket thuc cua tien trinh truoc
									thi phai chon tien trinh co thoi gian XUAT HIEN nho nhat tiep theo*/
		{
			cout<<"/";
			for(int j=i+1;j<n;j++)
			{
				/* neu thoi gian XUAT HIEN cua j < cua i
                Hoac bang nhau nhung thoi gian thuc hien cua j phai nho hon cua i
                thi moi cho j vao truoc i
                */
				if((a[j].t_xh<a[i].t_xh)||(a[j].t_xh==a[i].t_xh&&a[j].t_th<a[i].t_th))//chon tien trinh co tgian xuat hien nho nhat
				{
					tg=a[i];
					a[i]=a[j];
					a[j]=tg;
				}
			}
			for(int j=i+1;j<n;j++) cout<<" "<<a[j].t_xh;
			cout<<"/";
		}
		else
		{
			cout<<"|";
			for(int j=i+1;j<n;j++)
			{
                /*
                Neu thoi gian THUC HIEN cua tien trinh j < cua tien trinh i
                Hoac bang nhau nhung thoi gian XUAT HIEN cua j phai nho hon cua i thi moi cho j vao truoc i.
                */
				if(((a[j].t_th<a[i].t_th)||(a[j].t_th==a[i].t_th&&a[j].t_xh<a[i].t_xh))&&a[j].t_xh<=timeout)
				{
					tg=a[i];
					a[i]=a[j];
					a[j]=tg;
				}
			}
			for(int j=i+1;j<n;j++) cout<<" "<<a[j].t_xh;
			cout<<"|";
		}
		if (i == 0)//xu ly voi tien trinh dau tien.(t xuat hien be nhat)
        {
			a[i].t_bd = a[i].t_xh;//tien trinh dau tien thi t_bd =t_xh
			a[i].t_kt = a[i].t_bd + a[i].t_th;
		}
		else//xu ly voi cac tien trinh con lai
        {
			if(a[i].t_xh <= a[i - 1].t_kt)//neu tien trinh sau xuat hien truoc khi tien trinh dang thuc hien ket thuc
				a[i].t_bd = a[i - 1].t_kt;
			else//neu tien trinh dang thuc hien ma van chua co tien trinh moi xuat hien
				a[i].t_bd = a[i].t_xh;
			a[i].t_kt = a[i].t_bd + a[i].t_th;
		}
		a[i].t_cho=a[i].t_bd-a[i].t_xh;//tinh thoi gian cho
		timeout = a[i].t_kt;
	}
}
