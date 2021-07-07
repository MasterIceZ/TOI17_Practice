/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_ComeHome
 * ALGO		: Disjoined Set Union
 * DATE		: 5 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int p[300030];
bool visited[300030];

int root(int u){
	if(u == p[u]){
		return u;
	}
	return p[u] = root(p[u]);
}

void solve(){
	int n, l;
	cin >> n >> l;
	for(int i=1; i<=l; ++i){
		p[i] = i;
	}
	while(n--){
		int u, v;
		cin >> u >> v;
		int ru = root(u), rv = root(v);
		bool ok = false;
		if(!visited[u]){
			ok = visited[u] = true;
			p[ru] = rv;
		}
		else if(!visited[v]){
			ok = visited[v] = true;
			p[rv] = ru;
		}
		else if(!visited[ru]){
			ok = visited[ru] = true;
			p[ru] = rv;
		}
		else if(!visited[rv]){
			ok = visited[rv] = true;
			p[rv] = ru;
		}
		cout << (ok ? "Yes" : "No") << endl;
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
