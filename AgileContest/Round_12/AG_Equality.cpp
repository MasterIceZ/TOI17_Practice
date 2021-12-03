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

int a[1000100], b[1000100];

void solve(){
	int n, k, p;
	cin >> n >> k >> p;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	int l, r, ans;
	l = 1, r = n;
	while(l < r){
		int mid = (l + r) >> 1;
		int cnt = 0;
		for(int i=1; i<=n; ){
			if(b[mid] < a[i]){
				i+=p;
				cnt++;
			}
			else{
				i++;
			}
		}
		if(cnt > k){
			l = mid + 1;
		}
		else{
			r = mid;
			ans = b[mid];
		}
	}
	cout << ans;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
