/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Lazy
 * ALGO		: Data Struture + Searching
 * DATE		: 19 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

map<int, vector<int>> mp;

void solve(){
	int l, r, a;
	cin >> l >> r >> a;
	cout << upper_bound(all(mp[a]), r) - lower_bound(all(mp[a]), l);
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;	
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		mp[x].push_back(i);
	}
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
