#include<iostream>
#include<vector>
using namespace std;

class MinStack {

public:
    void push(int x) {
		if(cur==nums.size()-1){
			nums.resize(2*nums.size());
			links.resize(2*nums.size());
		}
		int t=find(x);
		if(-1==t){
			links[cur]=index;
			index = cur;
		}
		else{
			links[cur]=links[t];
			links[t]=cur;
		}
		nums[cur]=x;
		cur++;
    }
    void pop() {
		if(index==cur-1){
			index=links[index];
			cur--;
			return;
		}
		int x=nums[cur-1];
		int t=find(x);
		links[t]=links[cur-1];
		cur--;
    }
    int top() {
		return nums[cur-1];
    }
    int getMin() {
		return nums[index];
    }
	MinStack(int x=-1,int r=0):index(x),cur(r){nums.resize(100);links.resize(100);}
private:
	int find(int x){
		int q=index;
		int p=-1;
		while(q!=-1){
			if(nums[q]>=x)return p;
			p=q;
			q=links[q];
		}

		return p;
	}
private:
	int index;
	int cur;
	vector<int>nums;
	vector<int>links;
};

int main(){
	MinStack mstack;
	mstack.push(2);
	mstack.push(1);
	mstack.push(5);
	mstack.push(4);
	mstack.pop();
	mstack.pop();
	mstack.pop();
	mstack.pop();

	return 0;
}
