#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct process
{
  int processid;
  int at;       
  int bt;
  int ct;
  int wt;
  int tat;
  int rt;
  int start_time;
};

process process[20]; 

void getdata(int num){
    for(int i=0;i<num;i++)
    {
    	
    	cout<<"Process #"<<i<<":"<<endl;
        cout << "Arrival Time: ";
        cin >> process[i].at;
        process[i].processid=i;
        cout << "Burst Time: ";
        cin >> process[i].bt;
    	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	}	
}

void showdata(int num){
	
	
    cout<<"Process Number\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\tResponse Time\n";
    
    for(int i=0;i<num;i++)
	{
		cout<<i<<"\t\t"<<process[i].at<<"\t\t"<<process[i].bt<<"\t\t"<<process[i].ct<<"\t\t"<<process[i].tat<<"\t\t\t"<<process[i].wt<<"\t\t"<<process[i].rt<<endl;
	}
	
}

void fcfs(int num){
	for(int i=0;i<num;i++)
    {
	  if(process[i].start_time = (i==0))
	  {
	    process[i].start_time = process[i].at;
	  } 
	  else
	  {
	    process[i].start_time = max(process[i].at, process[i-1].ct);
	  }
      process[i].ct =  process[i].start_time + process[i].bt;
      process[i].tat = process[i].ct-process[i].at;       
      process[i].wt = process[i].tat-process[i].bt;
      process[i].rt=process[i].wt;
    }
}

bool compare_ARRIVALTIME(struct process a,struct process b)
{
   int x = a.at;
   int y = b.at;
   return x < y;
} 

bool compare_PROCESSID(struct process a,struct process b)
{
   int x = a.processid;
   int y = b.processid;
   return x < y;
}
int main(){
	int num;
	menu:
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"                Welcome to TR-OS"<<endl;
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"  1.Process Management"<<endl;
	cout<<"  2.Memory Management"<<endl;
	cout<<"  3.I/O Management"<<endl;
	cout<<"  4.Other Operations"<<endl;
	cout<<"  99.Exit"<<endl;
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cin>>num;
	switch(num){
		case 1:
			system("CLS");
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			cout<<"Welcome to Process Management:"<<endl;
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			cout<<"1. Create a Process"<<endl;
			cout<<"2. Destroy a Process"<<endl;
			cout<<"3. Suspend a Process"<<endl;
			cout<<"4. Resume a Process"<<endl;
			cout<<"5. Block a Process"<<endl;
			cout<<"6. Wakeup a Process"<<endl;
			cout<<"7. Dispatch a Process"<<endl;
			cout<<"8. Change Process Priority"<<endl;
			cout<<"9. Process Communication with Other Processes"<<endl;
			cout<<"10. Process Scheduling"<<endl;
			cout<<"99. Back"<<endl;
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			cin>>num;
			
			switch(num){
				case 1:
					system("CLS");
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cout<<"Create a Process:"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					int n;
				    cout << "Enter total number of processes: ";
				    cin >> n;
				    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					getdata(n);
					cout<<"1.Execute"<<endl;
					cout<<"99. Back"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cin>>num;
					switch(num){
						case 1:
							system("CLS");
							sort(process,process+n, compare_ARRIVALTIME);
						    fcfs(n);
						    sort(process,process+n, compare_PROCESSID);
							showdata(n);
							cout<<"\n---------------------------------------------------------------------------------------------------------------------"<<endl;
						    cout<<"99. Back"<<endl;
									cin>>num;
									
									switch(num){
										case 99:
										system("CLS");
										goto menu;
										break;
									}
							break;
						case 99:
						system("CLS");
						goto menu;
						break;
					}
						
					break;
				case 2:
					system("CLS");
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cout<<"Destroy a Process:"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cout<<"99. Back"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cin>>num;
					
					switch(num){
						case 99:
						system("CLS");
						goto menu;
						break;
					}
					break;
				case 3:
					system("CLS");
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;;
					cout<<"Suspend a Process:"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cout<<"99. Back"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cin>>num;
					
					switch(num){
						case 99:
						system("CLS");
						goto menu;
						break;
					}
					break;
				case 4:
					system("CLS");
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cout<<"Resume a Process:"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cout<<"99. Back"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cin>>num;
					
					switch(num){
						case 99:
						system("CLS");
						goto menu;
						break;
					}
					break;
				case 5:
					system("CLS");
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cout<<"Block a Process:"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cout<<"99. Back"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cin>>num;
					
					switch(num){
						case 99:
						system("CLS");
						goto menu;
						break;
					}
					break;
				case 6:
					system("CLS");
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cout<<"Wakeup a Process:"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cout<<"99. Back"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cin>>num;
					
					switch(num){
						case 99:
						system("CLS");
						goto menu;
						break;
					}
					break;
				case 7:
					system("CLS");
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cout<<"Dispatch a Process:"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cout<<"99. Back"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cin>>num;
					
					switch(num){
						case 99:
						system("CLS");
						goto menu;
						break;
					}
					break;
				case 8:
					system("CLS");
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cout<<"Change Process Priority:"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cout<<"99. Back"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cin>>num;
					
					switch(num){
						case 99:
						system("CLS");
						goto menu;
						break;
					}
					break;
				case 9:
					system("CLS");
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cout<<"Process Communication with Other Processes:"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cout<<"99. Back"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cin>>num;
					
					switch(num){
						case 99:
						system("CLS");
						goto menu;
						break;
					}
					break;
				case 10:
					system("CLS");
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cout<<"Process Scheduling:"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cout<<"1. FCFS"<<endl;
					cout<<"99. Back"<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cin>>num;
					
					switch(num){
						case 1:
	system("CLS");
	cout <<"++++++++++++++++++++++++FCFS++++++++++++++++++++++++"<<endl;
	int n;
    cout << "Enter total number of processes: ";
    cin >> n;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    getdata(n);
    sort(process,process+n, compare_ARRIVALTIME);
    fcfs(n);
    sort(process,process+n, compare_PROCESSID);
	showdata(n);
	cout<<"\n---------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"99. Back"<<endl;
			cin>>num;
			
			switch(num){
				case 99:
				system("CLS");
				goto menu;
				break;
			}
    
					    case 99:	
						system("CLS");
						goto menu;
						break;
					}
					break;
			}
			
			break;
		case 2:
			system("CLS");
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			cout<<"Welcome to Memory Management:"<<endl;
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			cout<<"99. Back"<<endl;
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			cin>>num;
			
			switch(num){
				case 99:
				system("CLS");
				goto menu;
				break;
			}
			break;
		case 3:
			system("CLS");
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			cout<<"Welcome to I/O Management:"<<endl;
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			cout<<"99. Back"<<endl;
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			cin>>num;
			
			switch(num){
				case 99:
				system("CLS");
				goto menu;
				break;
			}
			break;
		case 4:
			system("CLS");
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			cout<<"Welcome to Other Operations:"<<endl;
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			cout<<"99. Back"<<endl;
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			cin>>num;
			
			switch(num){
				case 99:
				system("CLS");
				goto menu;
				break;
			}
			break;
		case 99:
			system("CLS");
			cout<<"Exiting..."<<endl;
			break;
	}
	return 0;
}
