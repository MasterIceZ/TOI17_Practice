/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Operation Sort
 * ALGO		: Data Structure
 * DATE		: 28 Aug 2021
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

bool isOpr(char now){
	if(now == '+' || now == '-' || now == '/' || now == '*'){
		return true;
	}
	return false;
}

void solve(){
	string s;
	cin >> s;
	reverse(all(s));
	stack<string> st;
	for(int i=0; i<s.size(); ++i){
		if(isOpr(s[i])){
			string l = st.top();
			st.pop();
			string r = st.top();
			st.pop();
			string ans = l + r + s[i];
			st.push(ans);
		}
		else{
			st.push(string(1, s[i]));
		}
	}
	cout << st.top();
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
