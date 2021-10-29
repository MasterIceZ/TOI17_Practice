/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Pod
 * ALGO		: Math, Data Structure
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

void solve(){
	unordered_map<int, int> mp;
	int n, k, x;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> x;
		mp[x]++;
	}
	int nin = 1e9;
	for(int i=1; i<=k; ++i){
		nin = min(nin, mp[i]);
	}
	cout << n - (nin * k);
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
