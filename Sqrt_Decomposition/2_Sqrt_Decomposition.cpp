/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Sqrt Decomposition
 * ALGO		: Square root decomposition
 * DATE		: 23 Nov 2021
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
	int n, q, x, y;
	cin >> n >> q;
	int sq = sqrt(n);
	for(int i=1; i<=q; ++i){
		cin >> o >> x >> y;
		x--;
		if(o == 'U'){
			a[x] = y;
			cluster[x / sq] = -1e9;
			for(int i=(x / sq) * sq; i < min(n, (x / sq) * sq + sq); ++i){
				cluster[x / sq] = max(cluster[x / sq], a[i]);
			}
		}
		else{
			y--;
			int maxx = -1e9;
			for(int i=x; i<=y; ){
				if(i % sq == 0 && i + sq - 1 <= y){
					maxx = max(maxx, cluster[i / sq]);
					i += sq;
				}
				else{
					maxx = max(maxx, a[i]);
					i += 1;
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
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
