/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

const int MxN = 5050;

struct Fenwick{
	int tree[MxN];
	void update(int idx, int val){
		for(; idx <=5000; idx+=idx&-idx){
			tree[idx] += val;
		}
	}
	int read(int idx){
		int res = 0;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
} fw;

void solve(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		fw.update(i, 1);
	}
	int a, b, l, r, nxt;
	while(fw.read(n + 1)){
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
