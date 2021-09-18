/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Block
 * ALGO		: Fenwick Tree
 * DATE		: 18 Sep 2021
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

//ll tree[1010][1010];

ll tree[2020];

void update(int idy, ll val){
	for(; idy<=2000; idy+=(-idy&idy)){
		tree[idy] += val;
	}
}

ll query(int idy){
	ll res = 0;
	for(; idy; idy-=(-idy&idy)){
		res += tree[idy];
	}
	return res;
}

void solve(){
	int n, m, k, q, opr;
	cin >> n >> m >> k >> q;
	for(int i=1; i<=k+q; ++i){
		cin >> opr;
		if(opr == 1){
			int x, y, l;
			cin >> x >> y >> l;
			update(x + y, 1);
			update(x + y + l, -1);
		}
		else{
			int x, y;
			cin >> x >> y;
			cout << query(x + y) << "\n";
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
