/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Manage_Water
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

int tree[2020][2020], n;

void update(int idxi, int idxj, int val){
	while(idxi <= n){
		int now = idxj;
		while(now <= n){
			tree[idxi][now] += val;
			now += now&(-now);
		}
		idxi += idxi&(-idxi);
	}
}

int query(int idxi, int idxj){
	int sum = 0;
	while(idxi > 0){
		int now = idxj;
		while(now > 0){
			sum += tree[idxi][now];
			now -= now&(-now);
		}
		idxi -= idxi&(-idxi);
	}
	return sum;
}

void solve(){
	while(1){
		int opr;
		cin >> opr;
		if(opr == 3){
			return ;
		}
		else if(opr == 0){
			cin >> n;
		}
		else if(opr == 1){
			int x, y, c;
			cin >> x >> y >> c;
			x += 1, y += 1;
			update(x, y, c);
		}
		else{
			int a, b, x, y;
			cin >> a >> b >> x >> y;
			a += 1, b += 1, x += 1, y += 1;
			cout << query(x, y) - query(a - 1, y) - query(x, b - 1) + query(a - 1, b - 1) << "\n";
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
