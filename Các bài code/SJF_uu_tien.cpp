#include <iostream>

using namespace std; 

//Khai bao cau truc process
struct Process { 
    int pid; // Process ID 
    int bt; // Burst Time 
    int art; // Arrival Time 
}; 
  
//Khai bao ham
void findWaitingTime(Process proc[], int n, int wt[]); 
void findavgTime(Process proc[], int n);

//===Chuong trinh chinh===
int main() 
{ 
    Process proc[] = { { 1, 7, 0 }, { 2, 4, 2 }, 
                    { 3, 1, 4 }, { 4, 4, 5 } }; 
    int n = sizeof(proc) / sizeof(proc[0]); 
  
    findavgTime(proc, n); 
    
    cout<<endl;
    return 0; 
}
//===Dinh nghia ham
// Ham tim thoi gian cho cho cac tien trinh
void findWaitingTime(Process proc[], int n, int wt[]) 
{ 
    int rt[n]; 
  
    // Copy burst time vao rt[] 
    for (int i = 0; i < n; i++) 
        rt[i] = proc[i].bt; 
  
    int complete = 0, t = 0, minm = INT_MAX; 
    int shortest = 0, finish_time; 
    bool check = false; 
  
    // Xu ly cho toi khi cac tien trinh duoc hoan thanh
    while (complete != n) { 
  
         //Tìm quá trình voi muc toi thieu
         // thoi gian còn lai trong so cac qua trinh den
         // thoi gian hien tai
        for (int j = 0; j < n; j++) { 
            if ((proc[j].art <= t) && 
            (rt[j] < minm) && rt[j] > 0) { 
                minm = rt[j]; 
                shortest = j; 
                check = true; 
            } 
        } 
  
        if (check == false) { 
            t++; 
            continue; 
        } 
  
        // Giam thoi gian con lai
        rt[shortest]--; 
  
        // Cap nhat thoi gian toi thieu
        minm = rt[shortest]; 
        if (minm == 0) 
            minm = INT_MAX; 
  
        // Neu 1 qua trinh da duoc hoan thanh thì thuc thi tiep
        if (rt[shortest] == 0) { 
  
            // Tang so tien trinh hoan thanh 
            complete++; 
            check = false; 
  
            // Tim thoi gian ket thuc cua qua trinh hien tai
            finish_time = t + 1; 
  
            // Tinh tgian cho
            wt[shortest] = finish_time - 
                        proc[shortest].bt - 
                        proc[shortest].art; 
  
            if (wt[shortest] < 0) 
                wt[shortest] = 0; 
        } 
        // Tang thoi gian
        t++; 
    } 
}

// Ham tinh tgian cho TB
void findavgTime(Process proc[], int n) 
{ 
    int wt[n], tat[n], total_wt = 0, 
                    total_tat = 0; 
   
    findWaitingTime(proc, n, wt); 
  
    // Dua ket qua
    cout << "Processes "
        << " Burst time "
        << " Waiting time\n"; 
  
    // Tinh tong thoi gian cho
    for (int i = 0; i < n; i++) { 
        total_wt = total_wt + wt[i]; 
        cout << " " << proc[i].pid << "\t\t"
            << proc[i].bt << "\t\t " << wt[i] <<endl;
    }  
    cout << "\nAverage waiting time = "
        << (float)total_wt / (float)n; 
} 
