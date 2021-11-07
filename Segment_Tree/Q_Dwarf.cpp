/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Q_Dwarf
 * ALGO		: Segment Tree
 * DATE		: 6 Nov 2021
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

const int MxN = 200200;

int a[MxN], pos[MxN];
int min_tree[MxN * 4], max_tree[MxN * 4];

void build(int l, int r, int now){
	if(l > r){
		return ;
	}
	if(l == r){
		min_tree[now] = pos[l];
		max_tree[now] = pos[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, now * 2);
	build(mid + 1, r, now * 2 + 1);
	min_tree[now] = min(min_tree[now * 2], min_tree[now * 2 + 1]);
	max_tree[now] = max(max_tree[now * 2], max_tree[now * 2 + 1]);
}

void update(int l, int r, int idx, int val, int now){
	if(l > r || l > idx || r < idx){
		return ;
	}
	if(l == r){
		min_tree[now] = val;
		max_tree[now] = val;
		return ;
	}
	int mid = (l + r) >> 1;
	update(l, mid, idx, val, now * 2);
	update(mid + 1, r, idx, val, now * 2 + 1);
	min_tree[now] = min(min_tree[now * 2], min_tree[now * 2 + 1]); 
	max_tree[now] = max(max_tree[now * 2], max_tree[now * 2 + 1]); 
}

int read_min(int l, int r, int wl, int wr, int now){
	if(l > r || l > wr || r < wl){
		return 1e9 + 10;
	}
	if(wl <= l && r <= wr){
		return min_tree[now];
	}
	int mid = (l + r) >> 1;
	return min(read_min(l, mid, wl, wr, now * 2), read_min(mid + 1, r, wl, wr, now * 2 + 1));
}

int read_max(int l, int r, int wl, int wr, int now){
	if(l > r || l > wr || r < wl){
		return -1e9 - 10;
	}
	if(wl <= l && r <= wr){
		return max_tree[now];
	}
	int mid = (l + r) >> 1;
	return max(read_max(l, mid, wl, wr, now * 2), read_max(mid + 1, r, wl, wr, now * 2 + 1));
}

void solve(){
	int opr, n, q;
	cin >> n >> q;
	for(int i=1, x; i<=n; ++i){
		cin >> a[i];
		pos[a[i]] = i;
	}
	build(1, n, 1);
	for(int i=1; i<=q; ++i){
		cin >> opr;
		if(opr == 1){
			int l, r;
			cin >> l >> r;
			update(1, n, a[l], r, 1);
			update(1, n, a[r], l, 1);
			swap(a[l], a[r]);
		}
		else{
			int l, r;
			cin >> l >> r;
			int maxx = read_max(1, n, l, r, 1);
			int minn = read_min(1, n, l, r, 1);
			bool ok = (maxx - minn == r - l);
			dbg(maxx, minn, r - l);
			cout << (ok ? "YES" : "NO") << "\n";
		}
	}
	return ;
}

int main(){
//	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
