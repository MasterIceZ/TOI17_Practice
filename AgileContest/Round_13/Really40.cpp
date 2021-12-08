/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

void solve(){
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		q.push(x);
	}
	int cnt = 0;
	for(int i=1; i<=k; ++i){
		while((q.front() % n) != (i % n)){
			dbg(i, q.front());
			q.push(q.front());
			q.pop();
			cnt++;
		}
	}
	cout << cnt;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
//		solve2();
		cout << "\n";
	}
	return 0;
}
