/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 100100;
const int SQ = 400;
int cluster[SQ], a[MxN];

void solve(){
	char o;
	int n, q, u, v;
	cin >> n >> q;
	int sq = sqrt(n);
	for(int i=1; i<=q; ++i){
		cin >> o >> u >> v;
		if(o == 'U'){
			u--;
			a[u] = v;
			cluster[u / sq] = -1e9;
			for(int i=(u/sq)*sq; i<min((u / sq) * sq + sq, n); ++i){
				cluster[u / sq] = max(cluster[u / sq], a[i]);
			}
		}
		else{
			int maxx = -1e9;
			u--, v--;
			for(int i=u; i<=v;){
				if(i % sq == 0 && i + sq - 1 <= v){
					maxx = max(maxx, cluster[i / sq]);
					i += sq;
				}
				else{
					maxx = max(maxx, a[i]);
					i++;
				}
			}
			cout << maxx << "\n";
		}
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	while(q--){
		solve();
	}
	return 0;
}
