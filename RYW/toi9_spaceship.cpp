/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi9_space ship
 * ALGO		: Brute Force 
 * DATE		: 26 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct A{
	int x, y, z, a, b, c;
} s[11];

int n, m;
bool visited[11];
int res = 1e9 + 10;

int power(int n){
	return n * n;
}

void rec(int x, int y, int z, int a, int b, int c, int cost){
	for(int i=1; i<=m; ++i){
		if(visited[i]){
			continue;
		}
		visited[i] = true;
		int cst = cost + power(x - s[i].x) + power(y - s[i].y) + power(z - s[i].z);
		if(a + s[i].a >= n && b + s[i].b >= n && c + s[i].c >= n){
			res = min(res, cst);
		}
		else{
			rec(s[i].x, s[i].y, s[i].z, a + s[i].a, b + s[i].b, c + s[i].c, cst);
		}
		visited[i] = false;
	}
}

void solve(){
	int a, b, c;
	cin >> n >> a >> b >> c >> m;
	for(int i=1; i<=m; ++i){
		cin >> s[i].x >> s[i].y >> s[i].z >> s[i].a >> s[i].b >> s[i].c;
	}
	rec(a, b, c, 0, 0, 0, 0);
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
