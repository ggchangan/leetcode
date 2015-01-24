#include<iostream>
#include<vector>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost){
    int n=gas.size();
    if(1==n)return gas[0]>=cost[0]?0:-1;
    vector<int>left(n,0);
    for(int i=0;i<n;i++)left[i]=gas[i]-cost[i];
    int i=0;
    while(i<n&&left[i]<=0)i++;
    if(i==n)return -1;
    while(i<n){
        int sum=left[i];
        bool state=true;
        for(int j=(i+1)%n;j!=i;j=(j+1)%n){
            sum+=left[j];
            if(sum<0){state=false;break;}
        }
        if(state)return i; 
        while(i<n&&left[i]>0)i++;
        while(i<n&&left[i]<=0)i++;
    }

    return -1;
}


int main(){
    int A[]={2,4};
    int B[]={3,4};
    vector<int>gas(A,A+sizeof(A)/sizeof(A[0]));
    vector<int>cost(B,B+sizeof(B)/sizeof(B[0]));    
    cout << canCompleteCircuit(gas,cost) << endl;
	return 0;
}
