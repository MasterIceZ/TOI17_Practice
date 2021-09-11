/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Get Ruby
 * ALGO		: Fenwick Tree
 * DATE		: 9 Sep 2021
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

int tree[750500];

void update(int idx, int val){
	while(idx <= 750000){
		tree[idx] += val;
		idx += idx&(-idx);
	}
}

int query(int idx){
	int sum = 0;
	while(idx > 0){
		sum += tree[idx];
		idx -= idx&(-idx);
	}
	return sum;
}

void solve(){
	int n, m, a, b;
	cin >> n >> m;
	while(m--){
		string opr;
		cin >> opr >> a >> b;
		if(opr == "Bury"){
			update(b, a);
		}
		else{
			cout << query(b) - query(a - 1) << "\n";
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
