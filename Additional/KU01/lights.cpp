#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int dp[1010];

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> dp[i];
	}
	sort(dp + 1, dp + n + 1);
	int sum = 0;
	for(int i=1; i<=n; ++i){
		dp[i] += dp[i - 1];
		sum += dp[i];
	}
	cout << sum * 2 << "\n";
	return 0;
}
