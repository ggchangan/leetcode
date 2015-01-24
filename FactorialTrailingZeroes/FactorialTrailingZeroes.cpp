#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<climits>
#include<iterator>
using namespace std;
int trailingZeroes(int n){
    if(0==n)return 0;
    //int exp5=log10(n)/log10(5);
    //cout << exp5 << endl;
    int sum=0;
    while(n){
        sum+=n/5;
        n/=5;
    }
    /*
    ostream_iterator<int>output(cout," ");
    copy(exp5s.begin(),exp5s.end(),output);
    cout << endl;
    */
    return sum;
}


int main(){
    cout << trailingZeroes(200) << endl;
	return 0;
}
