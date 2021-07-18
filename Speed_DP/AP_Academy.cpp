/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AP_Academy
 * ALGO		: Dynamic Programming
 * DATE		: 16 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int st[1000100], ed[1000100];
void solve(){
	int s, f;
	cin >> s >> f;
	cout << st[f] - ed[s - 1];
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, s, f, nax;
	cin >> n;
	nax = 0;
	for(int i=1; i<=n; ++i){
		cin >> s >> f;
		st[s]++, ed[f]++;
		nax = max({nax, f, s});
	}
	for(int i=1; i<=1000000; ++i){
		st[i] += st[i-1], ed[i] += ed[i-1];
	}
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
