/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: jobs
 * ALGO		: Implementation
 * DATE		: 12 Nov 2021
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
	int n;
	cin >> n;
	int minn = 0, maxx = 0;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		if(x <= 18){
			minn++;
		}
		else{
			maxx++;
		}
	}
	int days = min(minn, maxx) * 2;
	minn -= days / 2;
	maxx -= days / 2;
	dbg(minn, maxx);
	if(minn > 0){
		days += minn;
	}
	if(maxx > 0){
		days += (maxx - 1) * 2 + 1;
	}
	cout << days;
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
