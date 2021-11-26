/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi7_car
 * ALGO		: Brute Force
 * DATE		: 25 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Cell{
	int i, j;
	string s;
};

int n, m;
int a[111][111], dp[111][111];

void solve(){
	int s;
	cin >> m >> s >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	dp[0][s] = 1;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(!a[i][j]){
				dp[i][j] = (dp[i - 1][j] | dp[i - 1][j - 1] | dp[i - 1][j + 1]);
			}
		}
	}
	int ending;
	for(int i=1; i<=m; ++i){
		if(dp[n][i]){
			ending = i;
		}
	}
	stack<int> st;
	for(int i=n; i>=1; --i){
		if(dp[i - 1][ending - 1]){
			st.push(2);
			ending -= 1;
		}
		else if(dp[i - 1][ending]){
			st.push(3);
		}
		else{
			st.push(1);
			ending += 1;
		}
	}
	while(!st.empty()){
		cout << st.top() << "\n";
		st.pop();
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
