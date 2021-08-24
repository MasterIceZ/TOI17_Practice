/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Tigger 
 * ALGO		: Dynamic Programming
 * DATE		: 24 Aug 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int INF = 1e9 + 10;

int a[1010], dp[1010][1010], n;

int divide(int now, int last){
	if(now < 1 || now > n){
		return INF;
	}
	if(dp[now][last] != -1){
		return dp[now][last];
	}
	if(now == n){
		return a[now];
	}
	return dp[now][last] = a[now] + min(divide(last + now + 1, last + 1), divide(now - last, last));
}

void solve(){
	memset(dp, -1, sizeof dp);
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	cout << divide(2, 1);
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
