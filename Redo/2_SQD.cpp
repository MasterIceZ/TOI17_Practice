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

int a[MxN], cluster[SQ];

void solve(){
	char o;
	int n, q, x, y;
	cin >> n >> q;
	int sq = sqrt(n);
	while(q--){
		cin >> o >> x >> y;
		x--;
		if(o == 'U'){
			a[x] = y;
			cluster[x / sq] = -1e9;
			for(int i=(x/sq)*sq; i<(x*sq)*sq+sq; ++i){
				cluster[x / sq] = max(cluster[x / sq], a[i]);
			}
		}
		else{
			y--;
			int res = -1e9;
			for(int i=x; i<=y; ){
				if(i % sq == 0 && i +sq - 1 <= y){
					res = max(res, cluster[i / sq]);
					i += sq;
				}
				else{
					res = max(res, a[i]);
					i += 1;
				}
			}
			cout << res;
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
		cout << "\n";
	}
	return 0;
}
