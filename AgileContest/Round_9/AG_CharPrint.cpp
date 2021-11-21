/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Char Print
 * ALGO		: Fenwick Tree
 * DATE		: 18 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

string s, t;
unordered_map<char, queue<int>> mp;

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

void mode1(){
	for(int i=1; i<=s.size(); ++i){
		fw.update(i, 1);
	}
	ll sum = 0;
	for(int i=0; i<t.size(); ++i){
		if(mp[t[i]].empty()){
			cout << -1;
			return ;
		}
		else{
			sum += 1 +  fw.read(mp[t[i]].front());
			fw.update(mp[t[i]].front() + 1, -1);
			mp[t[i]].pop();
		}
	}
	cout << sum;
}

void mode0(){
	ll res = 0;
	for(int i=0; i<t.size(); ++i){
		if(mp[t[i]].empty()){
			cout << -1;
			return ;
		}
		else{
			res += 1 + mp[t[i]].front();
			mp[t[i]].pop();
		}
	}
	cout << res;
}

void solve(){
	int x;
	cin >> x >> s >> t;
	for(int i=0; i<s.size(); ++i){
		mp[s[i]].push(i);
	}
	if(x){
		mode1();
	}
	else{
		mode0();
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
