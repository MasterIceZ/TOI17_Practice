/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: RT_Rank Current
 * ALGO		: Fenwick Tree
 * DATE		: 13 Nov 2021
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

const int MxN = 300300;
int tree[MxN];

void update(int idx, int val){
	for(; idx<=300000; idx+=idx&-idx){
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

void solve(){
	int q;
	cin >> q;
	vector<pair<int, int>> v;
	map<int, int> mp;
	while(q--){
		int opr, val;
		cin >> opr >> val;
		v.emplace_back(opr, val);
		mp[val] = 1;
	}
	int idx = 0;
	for(auto x: mp){
		mp[x.first] = ++idx;
	}
	for(auto x: v){
		if(x.first == 1){
			update(mp[x.second], 1);
		}
		else{
			cout << read(mp[x.second]) << "\n";
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
