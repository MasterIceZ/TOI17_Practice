/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: KuthCoin
 * ALGO		: Dynamic Programming
 * DATE		: 16 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int coin[] = {0, 1, 5, 10, 25, 50};
const int MOD = 1e6 + 3;

int dp[100100] = {1};
void build(){
	const int MxN = 100000;
	for(int i=1; i<=5; ++i){
		for(int j=1; j<=MxN; ++j){
			if(j - coin[i] < 0){
				continue ;
			}
			dp[j] += dp[j - coin[i]];
			dp[j] %= MOD;
		}
	}
}

void solve(){
	int n;
	cin >> n;
	cout <<  dp[n];
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	build();
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
