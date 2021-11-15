/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi13_timerswitch
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

const int MxN = 5000500;
char t[2 * MxN], p[MxN];
int pi[MxN];

void solve(){
	int n;
	cin >> n >> (p + 1);
	strcpy(t + 1, p + 1);
	strcat(t + 1, p + 1);
	for(int i=2, j=0; i<=n; ++i){
		while(j > 0 && p[i] != p[j + 1]){
			j = pi[j];
		}
		if(p[i] == p[j + 1]){
			j++;
		}
		pi[i] = j;
	}
	dbg(to_vector(pi, 1, n));
	for(int i=2, j=0; i<=2*n; ++i){
		while(j > 0 && t[i] != p[j + 1]){
			j = pi[j];
		}
		if(t[i] == p[j + 1]){
			j++;
		}
		if(j == n){
			cout << i - j;
			return ;
		}
		dbg(j);
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
