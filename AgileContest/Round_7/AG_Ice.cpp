/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Ice
 * ALGO		: Fenwick Tree
 * DATE		: 9 Oct 2021
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
ll v[MxN];
struct Tree{
	ll tree[3][MxN];
	void update(int idxi, int idxj, ll val){
		for(; idxj <= 100000; idxj+=idxj&-idxj){
			tree[idxi][idxj] += val;
		}
	}

	ll read(int idxi, int idxj){
		ll res = 0;
		for(; idxj; idxj-=idxj&-idxj){
			res += tree[idxi][idxj];
		}
		return res;
	}
};
void solve(){
	int n, q;
	cin >> n >> q;
	Tree fw1, fw2;
	for(int i=1; i<=n; ++i){
		ll val;
		cin >> val;
		v[i] = val;
		dbg(val);
		fw1.update(i % 2, i, val * i);
		fw2.update(i % 2, i, val);
	}
	while(q--){
		char opr;
		cin >> opr;
		if(opr == 'Q'){
			int l, r;
			cin >> l >> r;
//			ll pl = fw1.read(l % 2, r) - fw1.read(l % 2, l - 1) + fw2.read((l+1) % 2, r) - fw2.read((l+1) % 2, l - 1);
//			ll mi = fw1.read((l + 1) % 2, r) - fw1.read((l + 1) % 2, l - 1) + fw2.read(l % 2, r) - fw2.read(l % 2, l - 1);
//			mi *= (l - 1);
			ll pl = fw1.read(l % 2, r) - fw1.read(l % 2, l - 1) - ((fw2.read(l % 2, r) - fw2.read(l % 2, l -1)) * (l - 1));
			ll mi = fw1.read((l + 1) % 2, r) - fw1.read((l + 1) % 2, l - 1) - ((fw2.read((l + 1) % 2, r) - fw2.read((l + 1) % 2, l - 1)) * (l - 1));
			dbg(pl, mi);
			cout << pl - mi << "\n";
		}
		else{
			int idx;
			ll val;
			cin >> idx >> val;
			ll to_update = val - v[idx];
			fw2.update(idx % 2, idx, to_update);
			to_update = val * idx - v[idx] * idx;
			fw1.update(idx % 2, idx, to_update);
			v[idx] = val;
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
