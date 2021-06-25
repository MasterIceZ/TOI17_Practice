/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Lazy
 * ALGO		: Data Structure
 * DATE		: 24 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

unordered_map<int, vector<int>> mp;

void solve(){
	int l, r, v;
	cin >> l >> r >> v;
	cout << upper_bound(all(mp[v]), r) - lower_bound(all(mp[v]), l); 
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
