#include<iostream>
#include<vector>
using namespace std;

void generator(vector<vector<int> > &orders,vector<int> &order,int l, int r, int k){
    if(0==k){
        orders.push_back(order);
        return;
    }
    if(k==r-l+1){
        for(int i=l;i<=r;i++)order.push_back(i);
        orders.push_back(order);
        return;
    }
    generator(orders,order,l+1,r,k);
    for(int i=0;i<k;i++)order.pop_back();
    order.push_back(l);
    generator(orders,order,l+1,r,k-1);
}
vector<vector<int> > combine(int n, int k){
    vector<vector<int> >orders;
    if(k<=0||n<=0) return orders;
    if(k>n) return orders;
    vector<int>order;
    generator(orders,order,1,n,k);

    return orders;
}
int main(){
    vector<vector<int> >orders;
    int n=4;
    int k=2;
    orders=combine(n,k);
	for(int i=0;i<orders.size();i++){
        for(int j=0;j<orders[i].size();j++){
            cout << orders[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}
