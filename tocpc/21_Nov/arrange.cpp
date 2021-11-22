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

int a[1000100];

struct Segment{
	int st = 1e9, ed = -1, wi = 0;
	bool operator < (const Segment& o) const{
		if(ed != o.ed){
			return ed < o.ed;
		}
		return st < o.st;
	}
} seg[1000100];

int tmp[1000100];
int dp[1000100];

void solve(){
	int n, m;
	cin >> n >> m;
	int maxV = -1;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		seg[a[i]].wi++;
		maxV = max(maxV, a[i]);
	}
	for(int i=1; i<=n; ++i){
		seg[a[i]].st = min(seg[a[i]].st, i);
		dbg(seg[a[i]].st, a[i]);
	}
	for(int i=n; i>=1; --i){
		seg[a[i]].ed = max(seg[a[i]].ed, i);
		dbg(seg[a[i]].ed, a[i]);
	}
	sort(seg + 1, seg + maxV + 1);
	for(int i=1; i<=maxV; ++i){
		tmp[i] = seg[i].ed;
		dbg(seg[i].st, tmp[i]);
	}
	dp[0] = 0;
	for(int i=1; i<=maxV; ++i){
		int idx = lower_bound(tmp + 1, tmp + maxV + 1, seg[i].st) - (tmp + 1);
		dp[i] = max(dp[i - 1], dp[idx] + seg[i].wi);
		dbg(dp[i], idx);
	}
	cout << n - dp[maxV];
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
