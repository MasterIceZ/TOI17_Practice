/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Minimum Requirement
 * ALGO		: Brute Force
 * DATE		: 19 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int l[11], a[11], s[11], t[11], q[11];
int n, m, x;

bool solve2(int i){
	for(int i=1; i<=n; ++i){
		cin >> q[i];
	}
	vector<int>w;
	int j = 0;
	for(int i=0; i<n; ++i){
		int l, r;
		l = 0, r = v.size();
	}
}

void solve(){
	cin >> n >> m >> x;
	for(int i=0; i<n; ++i){
		cin >> l[i];
	}
	for(int i=0; i<n; ++i){
		cin >> a[i];
	}
	for(int i=0; i<n; ++i){
		cin >> s[i];
	}
	for(int i=0; i<n; ++i){
		cin >> t[i];
	}
	sort(l, l+n);
	for(int i=1; i<=x; ++i){
		cout << (solve2(i)?"P":"F") << "\n";
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
