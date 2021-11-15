/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi3_express
 * ALGO		: Brute Force
 * DATE		: 15 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

bool isOpr(char x){
	return x == '*' || x == '+' || x == '^';
}

int pri(char x){
	if(x == '+'){
		return 1;
	}
	if(x == '*'){
		return 2;
	}
	if(x == '^'){
		return 3;
	}
}

string now;

void calc(int idx){
	if(now == "null"){
		return ;
	}
	int n = now.size();
	int b = 0;
	bool ok = false;
	for(int i=1; i<n-1; ++i){
		if(now[i] == '('){
			b++;
		}
		if(now[i] == ')'){
			b--;
		}
		if(b < 0){
			ok = true;
		}
	}
	if(!ok && now[0] == '(' && now.back() == ')' && b == 0){
		if(idx == 1){
			now = now.substr(1, now.size() - 2);
			return ;
		}
		else{
			now = "null";
			return ;
		}
	}
	b = 0;
	int min_opr = 3;
	for(auto x: now){
		if(x == '('){
			b++;
		}
		else if(x == ')'){
			b--;
		}
		if(isOpr(x) && b == 0){
			min_opr = min(min_opr, pri(x));
		}
	}
	vector<string> have;
	string tmp = "";
	b = 0;
	for(int i=0; i<n; ++i){
		if(now[i] == '('){
			b++;
		}
		if(now[i] == ')'){
			b--;
		}
		if(isOpr(now[i]) && pri(now[i]) == min_opr && b == 0){
			have.push_back(tmp);
			tmp = "";
		}
		else{
			tmp += now[i];
		}
	}
	have.push_back(tmp);
	if(have.size() < idx){
		now = "null";
		return ;
	}
	else{
		now = have[idx - 1];
		return ;
	}
}

void solve(){
	string s;
	int q;
	cin >> s >> q;
	while(q--){
		now = s;
		stack<int> st;
		int sz = 0;
		while(1){
			int x;
			cin >> x;
			if(x == 0){
				break;
			}
			st.push(x);
			sz++;
			if(now == "null"){
				continue;
			}
			calc(x);
		}
		while(!st.empty()){
			cout << "op(";
			cout << st.top();
			cout << ",";
			st.pop();
		}
		cout << "p";
		for(int i=1; i<=sz; ++i){
			cout << ")";
		}
		cout << "=" << now;
		cout << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
