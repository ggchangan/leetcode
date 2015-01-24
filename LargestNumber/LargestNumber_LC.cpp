#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<iterator>
using namespace std;

static int i=0;
bool compare2(const int t1,const int t2){
	try{
			i++;
			if(0!=t1||0!=t2) cout << "i=" << i << ";" << "t1=" << t1 << ";"<< "t2="<<t2<<endl;
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
	}
	catch(...){
		cout << "an exception was thrown" << endl;
	}
	
	return true;
}

string largestNumber(vector<int> &num){
	try{
			ostream_iterator<int>output(cout," ");
			copy(num.begin(),num.end(),output);
			cout << endl;
			sort(num.begin(),num.end(),compare2);
			//ostream_iterator<int>output(cout," ");
			copy(num.begin(),num.end(),output);
			cout << endl;
			stringstream ss;
			for(int i=0;i<num.size();i++){
				ss << num[i]; 
			}
			return ss.str();
	}
	catch(...){
		cout << "异常"<<endl;
	}
}

int main(){
	int A[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	vector<int>num(A,A+sizeof(A)/sizeof(A[0]));	
	cout << largestNumber(num) << endl;
	return 0;
}
