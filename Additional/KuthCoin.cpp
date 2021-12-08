/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int MOD = 1000003;

int dp[100100];
const int coin[] = {0, 1, 5, 10, 25, 50};

void solve(){
	int n;
	cin >> n;
	cout << dp[n];
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	dp[0] = 1;
	for(int i=1; i<=5; ++i){
		for(int j=1; j<=100000; ++j){
			if(j - coin[i] < 0){
				continue;
			}
			dp[j] += dp[j - coin[i]];
			dp[j] %= MOD;
		}
	}
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
