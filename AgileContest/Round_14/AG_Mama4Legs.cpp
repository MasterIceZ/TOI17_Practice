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

const int MxN = 100100;
int a[MxN], l[MxN], r[MxN];
int tree[MxN];

void update(int idx, int v){
	for(; idx<=100000; idx+=idx&-idx){
		tree[idx] = max(v, tree[idx]);
	}
}

int read(int idx){
	int res = 0;
	for(; idx; idx-=idx&-idx){
		res = max(res, tree[idx]);
	}
	return res;
}
vector<int> compress;

void solve(){
	compress.clear();
	memset(l, 0, sizeof l);
	memset(r, 0, sizeof r);
	memset(tree, 0, sizeof tree);
	int n, res = 0, it = 0, ans = 0;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		compress.push_back(a[i]);
	}
	sort(compress.begin(), compress.end());
	compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
	for(int i=1; i<=n; ++i){
		a[i] = upper_bound(compress.begin(), compress.end(), a[i]) - compress.begin();
	}
	for(int i=1; i<=n; ++i){
//		l[i] = (mp[a[i]] > mp[a[i - 1]] ? l[i - 1] + 1 : 1);
		l[i] = (a[i] > a[i - 1] ? l[i - 1] + 1: 1);
	}
	for(int i=n; i>=1; --i){
//		r[i] = (mp[a[i]] < mp[a[i + 1]] ? r[i + 1] + 1 : 1);
		r[i] = (a[i] < a[i + 1] ? r[i + 1] + 1: 1);
	}
	for(int i=1; i<=n; ++i){
//		update(mp[a[i]], l[i]);
//		int res = read(mp[a[i]] - 1);
		update(a[i], l[i]);
		int res = read(a[i] - 1);
		ans = max(ans, r[i] + res);
//		dbg(res, a[i]);
	}
//	for(int i=1; i<=n; ++i){
//		cout << a[i] << " ";
//	}
//	cout << "\n";
	cout << ans;
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
