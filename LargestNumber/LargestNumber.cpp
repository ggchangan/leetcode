#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<iterator>
using namespace std;

bool compare2(int t1, int t2){
	stringstream s;
	s<<t1;
	string s1=s.str();
	s.str("");
	s.clear();
	s<<t2;
	string s2=s.str();
	bool exchange=false;
	int n,m;
	if(s1.size()>=s2.size()){
		n=s1.size();
		m=s2.size();
	}
	else{
		n=s2.size();
		m=s1.size();
		string t=s1;s1=s2;s2=t;
		exchange=true;
	}
	
	int i=0,j=0;
	while(i<n){
		if(s1[i]>s2[j])return exchange?false:true;
		else if(s1[i]<s2[j]) return exchange?true:false;
		i++;
		j=(j+1)%m;
	}
	
	return true;
}

bool myCompare(int t1, int t2){
	stringstream s;
	s<<t1<<""<<t2;
	string s1=s.str();
	s.str("");s.clear();
	s<<t2<<""<<t1;
	string s2=s.str();
	return s1>s2;
}
string largestNumber(vector<int> &num){
	if(num.empty())return "";
	sort(num.begin(),num.end(),myCompare);
	//ostream_iterator<int>output(cout," ");
	//copy(num.begin(),num.end(),output);
	if(0==num[0])return "0";
	stringstream s;
	ostream_iterator<int>outstr(s);
	copy(num.begin(),num.end(),outstr);
	return s.str();
}

int main(){
	int A[]={3, 30, 34, 5, 9};
	vector<int>num(A,A+sizeof(A)/sizeof(A[0]));	
	cout << largestNumber(num) << endl;
	return 0;
}
