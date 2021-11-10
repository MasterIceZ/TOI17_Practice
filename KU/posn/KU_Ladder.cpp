/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: KU_Ladder 
 * ALGO		: Implementation
 * DATE		: 10 Nov 2021
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

int a[1010];

void solve(){
	int n, m, x;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	int now = 0;
	while(m--){
		cin >> x;
		now += x;
		if(now < 0 || now > n){
			continue;
		}
		now += a[now];
	}
	if(now <= 0){
		cout << 0;
	}
	else if(now >= n){
		cout << n;
	}
	else{
		cout << now;
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
