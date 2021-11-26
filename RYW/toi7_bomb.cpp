/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi7_bomb
 * ALGO		: Implementation
 * DATE		: 25 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Bomb{
	int x, y;
	bool operator < (const Bomb& o) const{
		if(x != o.x){
			return x > o.x;
		}
		return y < o.y;
	}
} a[1000100];

// `x` always decrease with incresing `y`

struct Real{
	int x, y;
	bool operator < (const Real& o) const{
		if(x != o.x){
			return x < o.x;
		}
		return y < o.y;
	}
};

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i].x >> a[i].y;
	}
	sort(a + 1, a + n + 1);
	vector<Real> v;
	int x = a[1].x, y = a[1].y;
	for(int i=1; i<=n; ++i){
		if(a[i].y >= y || a[i].x == x){
			y = a[i].y;
			v.push_back({a[i].x, a[i].y});
		}
	}
	sort(v.begin(), v.end());
	for(auto x: v){
		cout << x.x << " " << x.y << "\n";
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
