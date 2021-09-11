/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Yoyo
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

int tree[500050], n;

void update(int idx, int val){
	while(idx <= n){
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
	int m;
	cin >> n >> m;
	while(m--){
		string opr;
		cin >> opr;
		if(opr == "Yoyo"){
			int a, b, c;
			cin >> c >> a >> b;
			update(min(a, b), c);
			update(max(a, b) - + 1, -c);
		}
		else{
			int x;
			cin >> x;
			cout << query(x) << "\n";
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
