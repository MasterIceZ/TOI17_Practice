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

using ll = long long;

int p[300300], deg[300300];

int fr(int u){
	return u == p[u] ? u : p[u] = fr(p[u]);
}

void solve(){
	int n, m, q;
	
	cin >> n >> m >> q;
//	if(m != 0){
//		return ;
//	}
	for(int i=1; i<=n; ++i){
		p[i] = i;
		deg[i] = 1;
	}
	while(q--){
		int opr;
		cin >> opr;
		if(opr == 1){
			int x;
			cin >> x;
			cout << (deg[x] == 1 ? 0 : 2) << "\n";
		}
		else{
			int u, v;
			cin >> u >> v;
			int ru = fr(u), rv = fr(v);
			if(ru == rv){
				continue;
			}
			if(deg[ru] > deg[rv]){
				deg[ru] += deg[rv];
				p[rv] = ru;
			}
			else{
				deg[rv] += deg[ru];
				p[ru] = rv;
			}
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
