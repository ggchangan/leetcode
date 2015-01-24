#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<sstream>
#include<set>
#include<climits>
#include<map>
using namespace std;

string fractionToDecimal(int numerator, int denominator){
    if(0==numerator)return "0";
    if(0==denominator)return "";
    bool sign=(numerator<0)^(denominator<0)?true:false;
    //防止溢出,使用long
    long long lnumerator=llabs(numerator),ldenominator=llabs(denominator);
    long long integer=lnumerator/ldenominator;

    stringstream ss;
    ss<<integer;
    string left=ss.str();
    left=(sign?"-":"")+left;
    ss.str("");ss.clear();
    if(0==lnumerator%ldenominator)return left; 
    lnumerator%=ldenominator;

    map<long long,int>loopPos;    
    string right="";
    bool loop=false;
    int index=0;
    int nZero=0;
    while(lnumerator){
        int i=1;
        while((long long)lnumerator*pow(10,i)<ldenominator)i++;
        long long t=lnumerator*pow(10,i);
        if(loopPos.count(t)){
            loop=true;
            index=loopPos[t];
            nZero=i-1;
            break;
        }
        index+=i;
        loopPos.insert(pair<long long,int>(t,index));
        lnumerator=t%ldenominator;
        long long quotient=t/ldenominator;
        for(int j=1;j<=i-1;j++)ss<<0;
        ss<<quotient;
    }
    right=loop?ss.str().substr(0,index-1-nZero)+"("+ss.str().substr(index-1-nZero)+")":ss.str();

    return left+"."+right;
}

int main(){
    cout << fractionToDecimal(-1,INT_MIN)<<endl;	
    cout << fractionToDecimal(7,-12)<<endl;	
    cout << fractionToDecimal(1,99)<<endl;	
    cout << fractionToDecimal(1,90)<<endl;	
    cout << fractionToDecimal(INT_MIN,-1)<<endl;	
    cout << fractionToDecimal(-50,8)<<endl;	
    cout << fractionToDecimal(1,6)<<endl;	
    cout << fractionToDecimal(INT_MIN,-3)<<endl;	
	return 0;
}
