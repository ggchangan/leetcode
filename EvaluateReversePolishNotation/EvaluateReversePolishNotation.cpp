#include<iostream>
#include<stack>
#include<cstdlib>
#include<vector>
using namespace std;


int evalRPN(vector<string> &tokens){	
	int n=tokens.size();
	if(0==n)return 0;
	if(1==n)return atoi(tokens[0].c_str());
	stack<int>operators;
	for(int i=0;i<n;i++){
		if("+"==tokens[i]||"-"==tokens[i]||"/"==tokens[i]||"*"==tokens[i]){
			int right=operators.top();operators.pop();
			int left=operators.top();operators.pop();
			if("+"==tokens[i]) operators.push(left+right);
			else if("-"==tokens[i])operators.push(left-right);
			else if("*"==tokens[i])operators.push(left*right);
			else if("/"==tokens[i])operators.push(left/right);
		}
		else{
			operators.push(atoi(tokens[i].c_str()));
		}
	}

	return operators.top();
}

int main(){
	string A[]={"4", "13", "5", "/", "+"};
	int n=5;
	vector<string> tokens;	
	for(int i=0;i<n;i++){
		tokens.push_back(A[i]);
	}
	cout << evalRPN(tokens) << endl;
	return 0;
}
