#include<bits/stdc++.h>
using namespace std;
class FCFS
{

    int n;
    vector<int>arrival;
    vector<int>burst;
    vector<int>complete;
    vector<int>turn;
    vector<int>waiting;
    vector<string>process;
public:
    void getProcess()
    {
        cout<<"Enter number of process:\n";
        cin>>n;

        for(int i=0; i<n; i++)
        {
            int a,b;
            string p;
            cout<<"Enter process name, arrival time and burst time of particular process:\n";
            cin>>p>>a>>b;
            arrival.push_back(a);
            burst.push_back(b);
            process.push_back(p);
        }
    }
    void completionTime()
    {
        int temp=burst[0];
        complete.push_back(temp);
        //complete[0]=burst[0];
        for(int i=1; i<n; i++)
        {
            temp+=burst[i];
            complete.push_back(temp);
            //complete[i]=temp;
        }
    }
    void turnAround()
    {
        for(int i=0; i<n; i++)
        {
            turn.push_back(complete[i]-arrival[i]);
            //turn[i]=complete[i]-arrival[i];
        }
    }
    void waitingTime()
    {
        for(int i=0; i<n; i++)
        {
            waiting.push_back(turn[i]-burst[i]);
            //waiting[i]=turn[i]-burst[i];
        }
    }
    void printAverage()
    {
        int wt=0,ta=0;
        for(int x: waiting)
            wt+=x;
        for(int x: turn)
            ta+=x;
        cout<<"Avg waiting time="<<wt/n<<endl;
        cout<<"Avg turn around time="<<ta/n<<endl;
    }
    void printDetails()
    {
        cout<<"Process\t AT \t BT \t CT \t TA \t WT\n";
        for(int i=0; i<n; i++)
            cout<<process[i]<<"\t"<<arrival[i]<<"\t"<<burst[i]<<"\t"<<complete[i]<<"\t"<<turn[i]<<"\t"<<waiting[i]<<"\n";
    }
};
int main()
{
    FCFS f;
    f.getProcess();
    f.completionTime();
    f.turnAround();
    f.waitingTime();
    f.printDetails();
    f.printAverage();
    return 0;
}
