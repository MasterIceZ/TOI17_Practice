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

int l[11], a[11], s[11], t[11], q[15];
int n, m, x;

bool solve2(int i){
	for(int i=1; i<=n; ++i){
		cin >> q[i];
	}
	q[n+1] = m + 1;
	vector<int>nin;
	for(int i=1; i<=n; ++i){
		int l, r;
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
