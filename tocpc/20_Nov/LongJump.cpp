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

void solve(){
	int n, m, w;
	cin >> n >> m >> w;
	assert(w == 0);
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	int res = -1;
	if((sx == 1 && sy == 1) || (sx == 1 && sy == m) || (sx == n && sy == 1) || (sx == n && sy == m)){
		if(sx == ex || sy == ey){
			res = 1;
		}
		else{
			res = 2;
		}
	}
	else if(sx == 1 || sx == n){
		if(sy == ey){
			res = 1;
		}
		else{
			res = -1;
		}
	}
	else if(sy == 1 || sy == m){
		if(sx == ex){
			res = 1;
		}
		else{
			res = -1;
		}
	}
	cout << res;
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
