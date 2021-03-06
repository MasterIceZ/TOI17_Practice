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
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	int l = 1, r = n, cnt = 0;
	while(l < r){
		dbg(a[l], a[r]);
		if(a[l] == a[r]){
			l++, r--;
		}
		else if(a[l] < a[r]){
			a[l + 1] += a[l];
			l++;
			cnt++;
		}
		else if(a[r] < a[l]){
			a[r - 1] += a[r];
			r--;
			cnt++;
		}
	}
	cout << cnt;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
