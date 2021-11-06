/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Components
 * ALGO		: Dynamic Programming
 * DATE		: 2 Nov 2021
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

vector<int> prime = {0};
bitset<1000010> ch;
int p[1000100];

int fr(int u){
	return u == p[u] ? u : p[u] = fr(p[u]);
}

void solve(){
	int n;
	cin >> n;
	int pr = prime[n];
	for(int i=1; i<=pr; ++i){
		p[i] = i;
	}
	for(ll i=1; i<=pr; ++i){
		ll u = i;
		ll v = (((i * i * i) % pr) + 1) % pr;
		if(v == 0){
			v = pr;
		}
		p[fr(u)] = fr(v);
		dbg(u, v);
	}
	for(int i=1; i<=pr; ++i){
		p[i] = fr(i);
	}
	sort(p + 1, p + pr + 1);
	int cnt = 0, last = -1;
	for(int i=1; i<=pr; ++i){
		dbg(p[i]);
		if(last != p[i]){
			cnt++;
		}
		last = p[i];
	}
	cout << cnt;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	
	for(ll i=2; i<=1000000; ++i){
		if(ch[i]){
			continue;
		}
		for(ll j=i*2; j<=1000000; j+=i){
			ch[j] = 1;
		}
		prime.push_back(i);
	}
	dbg(prime.size());
	int q;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
//	while(1);
	return 0;
}
