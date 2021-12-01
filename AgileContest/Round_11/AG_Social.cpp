/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Social Credit
 * ALGO		: Disjoint Set Union
 * DATE		: 29 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Point{
	int x, y, idx;
} a[100100];

bool cmpx(Point a, Point b){
	if(a.x != b.x){
		return a.x < b.x;
	}
	return a.y < b.y;
}

bool cmpy(Point a, Point b){
	if(a.y != b.y){
		return a.y < b.y;
	}
	return a.x < b.x;
}

int p[100100];
bitset<100100> used;

int fr(int u){
	return u == p[u] ? u: p[u] = fr(p[u]);
}

void solve(){
	int n, m, k, l;
	cin >> n >> m >> k >> l;
	for(int i=1; i<=k; ++i){
		cin >> a[i].x >> a[i].y;
		a[i].idx = i;
		p[i] = i;
	}
	sort(a + 1, a + k + 1, cmpx);
	for(int i=2; i<=k; ++i){
		if(a[i].x == a[i - 1].x && a[i].y - a[i - 1].y <= l){
			p[fr(a[i].idx)] = fr(a[i - 1].idx);
		}
	}
	sort(a + 1, a + k + 1, cmpy);
	for(int i=2; i<=k; ++i){
		if(a[i].y == a[i - 1].y && a[i].x - a[i - 1].x <= l){
			p[fr(a[i].idx)] = fr(a[i - 1].idx);
		}
	}
	for(int i=1; i<=k; ++i){
		fr(i);
	}
	int q;
	cin >> q;
	while(q--){
		used = 0;
		int o, x, cnt = 0;
		cin >> o;
		while(o--){
			cin >> x;
			int rx = p[x];
			if(!used[rx]){
				cnt++;
				used[rx] = true;
			}
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
	}
	return 0;
}
