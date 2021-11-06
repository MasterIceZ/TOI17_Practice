/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Segment Tree
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

const int MxN = 100100;
int tree[MxN * 4];

void update(int l, int r, int idx, int val, int now){
	if(l > r || l > idx || r < idx){
		return ;
	}
	if(l == r){
		tree[now] = val;
		return ;
	}
	int mid = (l + r) >> 1;
	dbg(l, mid, r);
	update(l, mid, idx, val, now * 2);
	update(mid + 1, r, idx, val, 1 + now * 2);
	tree[now] = max(tree[now * 2], tree[now * 2 + 1]);
}

int read(int l, int r, int ll, int rr, int now){
	if(l > r || l > rr || r < ll){
		return -1e9 - 10;
	}
	if(ll <= l && r <= rr){
		return tree[now];
	}
	int mid = (l + r) >> 1;
	dbg(l, mid, r);
	return max(read(l, mid, ll, rr, now * 2), read(mid + 1, r, ll, rr, now * 2 + 1));
}

void solve(){
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=q; ++i){
		char opr;
		cin >> opr;
		if(opr == 'U'){
			int x, y;
			cin >> x >> y;
			update(1, n, x, y, 1);
		}
		else{
			int l, r;
			cin >> l >> r;
			cout << read(1, n, l, r, 1) << "\n";
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
