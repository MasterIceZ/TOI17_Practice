/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Packbot TOI16
 * ALGO		: Data Structure
 * DATE		: 3 Aug 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

stack<int> st;
stack<char> opr;

int calc(int a, int b){
	int opx = (opr.top() - '0') + 1;
	opr.pop();
	int sum = a + b;
	return (sum * (100 + (1 << opx)) / 100);
}

int pri(char x){
	return isdigit(x) ? x - '0' : -1;
}

void solve(){
	string s;
	cin >> s;
	for(auto x: s){
		if(isalpha(x)){
			st.push(20);
		}
		else if(x == '['){
			opr.push(x);
		}
		else if(x == ']'){
			while(opr.top() != '['){
				int r = st.top();
				st.pop();
				int l = st.top();
				st.pop();
				st.push(calc(l, r));
			}
			opr.pop();
		}
		else{
			while(!opr.empty() && pri(opr.top()) >= pri(x)){
				int r = st.top();
				st.pop();
				int l = st.top();
				st.pop();
				st.push(calc(l, r));
			}
			opr.push(x);
		}
	}
	while(!opr.empty()){
		int l = st.top();
		st.pop();
		int r = st.top();
		st.pop();
		st.push(calc(l, r));
	}
	cout << st.top();
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
