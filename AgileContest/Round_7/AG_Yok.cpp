/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Yok
 * ALGO		: 
 * DATE		: 9 Oct 2021
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

struct Square{
	int a, b, c, d;
};

void solve(){
	int n, m, k, a, b, c, d;
	cin >> n >> m >> k;
	vector<Square> v;
	for(int i=1; i<=n; ++i){
		cin >> a >> b >> c >> d;
		v.push_back({a, b, c, d});
	}
	while(m--){
		int cnt = 0, xx, y;
		cin >> xx >> y;
		for(auto x: v){
			cnt += (x.a <= xx && x.c >= xx && x.b <= y && x.d >= y);
		}
		cout << cnt << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
