#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

int reverse(int x){
	if(0==x)return x;
	bool sign=false;
	if(x<0)x=-x,sign=true;
	int zn=0,t=x,n=0;
	int ret=0;
	while(0==t%10)zn++,t/=10;
	t=x;
	while(t)n++,t/=10;
	x=x/(int(pow(10,zn)));
	n-=zn;
	for(int i=1;i<=n;i++){
		if(i==n){
			if(!sign){
				if((double)ret-(double)(INT_MAX-x)/10>0.01)return 0;
			}
			else{
				if(ret<0)ret=-ret;
				if(double(ret+(double)(x+INT_MIN)/10)>0.01)return 0;
			}
		}
		ret=ret*10+x%10;
		x/=10;
	}
	if(sign)ret=-ret;
	return ret;
}

int main(){
	cout << reverse(-INT_MIN) << endl;	
	return 0;
}
