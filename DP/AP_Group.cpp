/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AP_Group
 * ALGO		: Dynamic Programming
 * DATE		: 17 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve(){
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for(int i=0; i<n; ++i){
		cin >> a[i].first >> a[i].second;
		a[i].second *= -1;
	}
	sort(all(a));
	vector<int>dp(n+1);
	int sz = 0;
	for(int i=0; i<n; ++i){
		int idx = upper_bound(dp.begin(), dp.begin() + sz, a[i].second) - dp.begin();
		sz += (idx == sz);	
		dp[idx] = a[i].second;
	}
	cout << sz;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
