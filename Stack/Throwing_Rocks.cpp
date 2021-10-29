/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: throwing rocks
 * ALGO		: Stack
 * DATE		: 29 Oct 2021
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

double s[100100], t[100100];

void solve(){
	double n, m, v;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> s[i];
	}
	for(int j=1; j<=n; ++j){
		cin >> v;
		t[j] = j + (m / v);
	}
		deque<ll> st;
	for(int i=1; i<=n; ++i){
		while(!st.empty() && t[i] < t[st.back()] && s[i] > s[st.back()]){
			st.pop_back();
		}
		if(!st.empty() && t[i] < t[st.back()] && s[i] <= s[st.back()]){
			t[i] = t[st.back()];
		}
		st.push_back(i);
	}
	cout << st.size() << "\n";
	while(!st.empty()){
		cout << st.front() << " ";
		st.pop_front();
	}
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
