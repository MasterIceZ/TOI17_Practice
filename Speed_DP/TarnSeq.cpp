/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Tarn Sequence
 * ALGO		: Dynamic Programming
 * DATE		: 16 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int a[100100], dp[100100];
vector<int> mem[100100];

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	int sz = 0;
	for(int i=1; i<=n; ++i){
		int idx = lower_bound(dp, dp+sz, a[i]) - dp;
		if(idx == sz){
			++sz;
		}
		dp[idx] = a[i];
		mem[idx].push_back(a[i]);
	}
	cout << sz << endl;
	stack<int> path;
	path.push(mem[sz - 1][0]);
	int val = path.top();
	for(int i=sz-2; i>=0; --i){
		for(auto x: mem[i]){
			if(x < val){
				val = x;
				path.push(x);
				break;
			}
		}
	}
	while(!path.empty()){
		cout << path.top() << " ";
		path.pop();
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
