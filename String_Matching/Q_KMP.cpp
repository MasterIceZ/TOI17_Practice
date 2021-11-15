/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Q_KMP
 * ALGO		: KMP
 * DATE		: 14 Nov 2021
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

const int MxN = 1000100;
char t[MxN], p[MxN];
int pi[MxN];

void solve(){
	cin >> (t + 1) >> (p + 1);
	int n = strlen(t + 1), m = strlen(p + 1);
	for(int i=2, j=0; i<=m; ++i){
		while(j > 0 && p[i] != p[j + 1]){
			j = pi[j];
		}
		if(p[i] == p[j + 1]){
			j++;
		}
		pi[i] = j;
	}
	for(int i=1, j = 0; i<=n; ++i){
		while(j > 0 && p[j + 1] != t[i]){
			j = pi[j];
		}
		if(p[j + 1] == t[i]){
			j++;
		}
		if(j == m){
			cout << "Lucky" ;
			return ;
		}
	}
	cout << "Unlucky";
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
