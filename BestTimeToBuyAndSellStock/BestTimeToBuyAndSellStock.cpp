#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> &prices){
    int n=prices.size();
    if(0==n||1==n)return 0;
    vector<bool>sign(n,true);
    for(int i=1;i<n;i++){
        if(prices[i]<prices[i-1])sign[i]=false;
    }

    sign[0]=sign[1];
    int ret=0;
    int i=0;
    if(sign[0]){
        while(i<n&&sign[i])i++;
        ret=prices[i-1]-prices[0];
    }
    int buyIndex=0;
    int sellIndex=sign[0]?i-1:0;
    while(i<n){
        while(i<n&&!sign[i])i++;
        if(i==n)break;
        int s=i-1;
        if(prices[s]<prices[buyIndex])buyIndex=s;
        while(i<n&&sign[i])i++;
        //解法有问题，有可能sellIndex<buyIndex,明天重新思考怎么做吧
        if(!sellIndex||(prices[i-1]>prices[sellIndex]))sellIndex=i-1;
        i++;
    }
    
    return max(ret,prices[sellIndex]-prices[buyIndex]);
}

int main(){
    int A[]={6,1,3,2,4,7};
    vector<int>prices(A,A+sizeof(A)/sizeof(A[0]));
    cout<<maxProfit(prices)<<endl;    
	return 0;
}
