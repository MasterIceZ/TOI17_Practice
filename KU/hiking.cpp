/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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
	int n, s;
	cin >> n >> s;
	int minn, maxx;
	minn = s;
	maxx = s;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		if(x % 12 == 0){
			minn -= 10 * (x)/3;
			maxx -= 10 * (x)/4;
		}
		else if(x % 3 == 0){
			maxx -= 10 * (x)/3;
			minn -= 10 * (x)/3;
		}
		else if(x % 4 == 0){
			minn -= 10 * (x)/4;
			maxx -= 10 * (x)/4;
		}
	}
	cout << minn << " " << maxx;
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
