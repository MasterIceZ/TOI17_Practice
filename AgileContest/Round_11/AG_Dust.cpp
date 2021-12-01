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

const int MxN = 200200;

struct Point{
	int x, y;
	bool operator < (const Point& o) const{
		if(x != o.x){
			return x < o.x;
		}
		return y < o.y;
	}
} a[MxN];

int minn[MxN], maxx[MxN];

void solve(){
	memset(minn, 0, sizeof minn);
	memset(maxx, 0, sizeof maxx);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i].x >> a[i].y;
	}
	sort(a + 1, a + n + 1);
	minn[1] = a[1].y;
	for(int i=2; i<=n; ++i){
		minn[i] = min(minn[i - 1], a[i].y);
	}
	maxx[n] = a[n].y;
	for(int i=n - 1; i>=1; --i){
		maxx[i] = max(maxx[i + 1], a[i].y);
	}
	int ans = 1;
	for(int i=1; i<n; ++i){
		if(minn[i] > maxx[i + 1]){
			ans++;
		}
	}	
	cout << ans;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
