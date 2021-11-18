/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o61_oct_c1_charprint
 * ALGO		: Fenwick Tree, Heap
 * DATE		: 17 Nov 2021
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

unordered_map<char, priority_queue<ll, vector<ll>, greater<ll>>> mp;

void mode0(string s){
	ll res = 0;
	for(int i=0; i<s.size(); ++i){
		if(mp[s[i]].empty()){
			cout << -1 ;
			return ;
		}
		else{
			res += mp[s[i]].top() + 1;
			mp[s[i]].pop();
		}
	}
	cout << res ;
}

struct Fenwick{
	ll tree[300300];
	void update(int idx, ll val){
		for(; idx<=300000; idx+=idx&-idx){
			tree[idx] += val;
		}
	}
	ll read(int idx){
		ll res = 0;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
} fw;

void mode1(string a, string s){
	for(int i=1; i<a.size(); ++i){
		fw.update(i, i);
		fw.update(i + 1, -i);
		dbg(fw.read(i));
	}
	ll res = 0;
	for(int i=0; i<s.size(); ++i){
		if(mp[s[i]].empty()){
			cout << -1;
			return ;
		}
		else{
			res += fw.read(mp[s[i]].top()) + 1;
			dbg(fw.read(mp[s[i]].top()));
			fw.update(1 + mp[s[i]].top(), -1);
			mp[s[i]].pop();
		}
	}
	cout << res;
}

void solve(){
	int opr;
	cin >> opr;
	string s, t;
	cin >> s >> t;
	for(int i=0; i<s.size(); ++i){
		mp[s[i]].push(i);
	}
	if(!opr){
		mode0(t);		
	}
	else{
		mode1(s, t);
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
