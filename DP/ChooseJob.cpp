/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Choose Job
 * ALGO		: Dynamic Programming
 * DATE		: 10 Aug 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Segment{
	int st, ed, wi;
	bool operator < (const Segment& o) const{
		if(ed != o.ed){
			return ed < o.ed;
		}
		return st < o.st;
	}
};

Segment seg[100100];
int dp[100100], tmp[100100];

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> seg[i].st >> seg[i].ed >> seg[i].wi;
	}
	sort(seg + 1, seg + 1 + n);
	for(int i=1; i<=n; ++i){
		tmp[i] = seg[i].ed;
	}
	for(int i=1; i<=n; ++i){
		int id = lower_bound(tmp + 1, tmp + n + 1, seg[i].st) - (tmp + 1);
		dp[i] = max(dp[i - 1], dp[id] + seg[i].wi);
	}
	cout << dp[n];
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
