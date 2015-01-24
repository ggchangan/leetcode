#include<iostream>
#include<vector>
#include<string>
using namespace std;

void generate(int left,int right,string s,vector<string> &parentheses){
	if(0==left&&0==right){
		parentheses.push_back(s);
		return;
	}
	if(left>0)generate(left-1,right,s+'(',parentheses);
	if(right>0&&right>left)generate(left,right-1,s+')',parentheses);
}
vector<string> generateParenthesis(int n){
	vector<string>parentheses;
	generate(n,n,"",parentheses);
	return parentheses;
}
int main(){
	vector<string>parentheses;
	int n=4;
	parentheses=generateParenthesis(n);
	for(int i=0;i<parentheses.size();i++){
		cout << parentheses[i] << endl;
	}
	return 0;
}
