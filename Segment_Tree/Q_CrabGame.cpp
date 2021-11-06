/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Q_Crab Game
 * ALGO		: Segment Tree
 * DATE		: 6 Sep 2021
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

const int MxN = 100100;
int tree[MxN * 4], a[MxN];

void build(int l, int r, int idx){
	if(l > r){
		return ;
	}
	if(l == r){
		tree[idx] = a[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, idx * 2);
	build(mid + 1, r, idx * 2 + 1);
	tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
}

void update(int l, int r, int idx, int val, int now){
	if(l > r || l > idx || r < idx){
		return ;
	}
	if(l == r){
		tree[now] = val;
		return ;
	}
	int mid = (l + r) >> 1;
	update(l, mid, idx, val, now * 2);
	update(mid + 1, r, idx, val, now * 2 + 1);
	tree[now] = min(tree[now * 2], tree[now * 2 + 1]);
}

int read(int l, int r, int wl, int wr, int now){
	if(l > r || wl > r || wr < l){
		return 1e9 + 10;
	}
	if(wl <= l && r <= wr){
		return tree[now];
	}
	int mid = (l + r) >> 1;
	return min(read(l, mid, wl, wr, now * 2), read(mid + 1, r, wl, wr, now * 2 + 1));
}

void solve(){
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	build(1, n, 1);
	for(int i=1, opr; i<=q; ++i){
		cin >> opr;
		if(opr == 1){
			int idx, v;
			cin >> idx >> v;
			update(1, n, idx, v, 1);
		}
		else{
			int wl, wr;
			cin >> wl >> wr;
			cout << read(1, n, wl, wr, 1) << "\n";
		}
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
//		cout << endl;
	}
	return 0;
}
