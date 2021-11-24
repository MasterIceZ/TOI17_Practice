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

struct SQD{
	int a[MxN], cluster[SQ];
	int sq;

	void init(int n){
		sq = sqrt(n);
	}
	void update(int idx, int v){
		a[idx] = v;
		cluster[idx / sq] = -1e9;
		for(int i=(idx/sq)*sq;  idx < (idx/sq)*sq+sq; ++i){
			cluster[idx / sq] = max(cluster[idx / sq], a[i]);
		}
	}
	int read(int l, int r){
		int res = -1e9;
		for(int i=l; i<=r; ){
			if(i % sq == 0 && i + sq - 1 <= r){
				res = max(res, cluster[i / sq]);
				res += sq;
			}
			else{
				res  = max(res, a[i]);
				res += 1;
			}
		}
	}
} dp;

void solve(){
	char o;
	int n, q, x, y;
	cin >> n >> q;
	dp.init(n);
	while(q--){
		cin >> o >> x >> y;
		if(o == 'U'){
			dp.update(x - 1, y);
		}
		else{
			cout << dp.read(x - 1, y - 1) << "\n";
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
