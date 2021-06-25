/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Diary
 * ALGO		: Dynamic Programming
 * DATE		: 24 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int dp[100100];

void solve(){
	int n, k, a, last = 1;
	cin >> n >> k >> a;
	dp[0] = 0;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		dp[last]++;
		last += x;
	}
	for(int i=1; i<=last; ++i){
		dp[i] += dp[i-1];
	}
	int ans1, ans2, nax = INT_MIN;
	ans1 = ans2 = 0;
	for(int i=1; i<last; ++i){
		unordered_map<int, int> mp;
		int it = 1;
		for(int j=i; j<last && it<=k; ++it, j+=a){
			mp[dp[j]]++;
		}
		int sz = mp.size();
		if(sz > nax){
			nax = sz;
			ans1 = i;
			ans2 = sz;
		}
	}
	cout << ans1 << " " << ans2;
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
