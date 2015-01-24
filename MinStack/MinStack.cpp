#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    void push(int x){
		if(nums.empty()||x<=minNums.top())minNums.push(x);
		nums.push(x);
    }
    void pop(){
		if(nums.top()==minNums.top())minNums.pop();
		nums.pop();
    }
    int top(){
		return nums.top();
    }
    int getMin(){
    	return minNums.top();
	}
	MinStack(){};
private:
	stack<int>nums;
	stack<int>minNums;
};

int main(){
	MinStack mstack;
	mstack.push(-2);
	mstack.push(0);
	mstack.push(-1);
	cout << mstack.getMin() << endl;
	cout << mstack.top() << endl;
	mstack.pop();
	cout << mstack.getMin() << endl;

	return 0;
}
