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

vector<ll> prime = {2};
ll dp[333], p;
bool ch[111], visited[111];
vector<int> adj[111];

void dfs(int u){
	dbg(p, u);
	visited[u] = true;
	for(auto x: adj[u]){
		if(!visited[x]){
			dfs(x);
		}
	}
}

void solve(){
	int x;
	cin >> x;
	if(x > 20){
		return ;
	}
	cout << dp[x];
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	
	for(ll i=3; i*i<=100; i+=2){
		if(ch[i]){
			continue;
		}
		for(ll j=i*i; j<=100; j+=i){
			ch[j] = 1;
		}
	}
	for(ll i=3; i<=100; i+=2){
		if(!ch[i]){
			prime.push_back(i);
		}
		if(prime.size() == 20){
			break;
		}
	}
	for(int i=1; i<=prime.size(); ++i){
		p = prime[i - 1];
		for(ll j=1; j<=p; ++j){
			for(ll k=j+1; k<=p; ++k){
				if((j*j*j-k+1) % p == 0 || (k*k*k-j+1) % p == 0){
					adj[j].push_back(k);
					adj[k].push_back(j);
				}
			}
		}
		memset(visited, false, sizeof visited);
		int cnt = 0;
		for(int j=1; j<=p; ++j){
			if(!visited[j]){
				dfs(j);
				cnt++;
			}
		}
		dp[i] = cnt;
		for(int j=1; j<=p; ++j){
			adj[j].clear();
		}
	}
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
