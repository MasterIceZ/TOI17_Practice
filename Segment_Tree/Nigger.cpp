/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Nigger
 * ALGO		: Lazy Segment Tree
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

const int MxN = 100100;
int tree[MxN * 4], lazy[MxN * 4];

void update(int l, int r, int wl, int wr, int now){
	if(lazy[now]){
		tree[now] = (r - l + 1) - tree[now];
		lazy[now * 2] ^= 1;
		lazy[now * 2 + 1] ^= 1;
		lazy[now] = 0;
	}
	if(l > wr || r < wl){
		return ;
	}
	if(wl <= l && r <= wr){
		tree[now] = (r - l + 1) - tree[now];
		lazy[now * 2] ^= 1;
		lazy[now * 2 + 1] ^= 1;
		return ;
	}
	int mid = (l + r) >> 1;
	update(l, mid, wl, wr, now * 2);
	update(mid + 1, r, wl, wr, now * 2 + 1);
	tree[now] = tree[now * 2] + tree[now * 2 + 1];
}

int read(int l, int r, int wl, int wr, int now){
	if(lazy[now]){
		tree[now] = (r - l + 1) - tree[now];
		lazy[now * 2] ^= 1;
		lazy[now * 2 + 1] ^= 1;
		lazy[now] = 0;
	}
	if(l > wr || r < wl){
		return 0;
	}
	if(wl <= l && r <= wr){
		return tree[now];
	}
	int mid = (l + r) >> 1;
	dbg(l, mid, r);
	return read(l, mid, wl, wr, now * 2) + read(mid + 1, r, wl, wr, now * 2 + 1);
}

void solve(){
	int n, q, opr, s, e;
	cin >> n >> q;
	while(q--){
		cin >> opr >> s >> e;
		if(!opr){
			update(1, n, s, e, 1);
		}
		else{
			cout << read(1, n, s, e, 1) << "\n";
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
	}
	return 0;
}
