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

const int MxN = 1e6 + 10;
int dp[MxN];
bitset<MxN> ok;
vector<int> prime;

int divide(int n){
	if(dp[n] != -1){
		return dp[n];
	}
	dp[n] = 1;
	for(auto x: prime){
		if(n % x == 0){
			int res = divide(x);
			dp[n] *= res;
		}
	}
	return dp[n];
}

void solve(){
	int n;
	cin >> n;
	cout << divide(n);
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	
	memset(dp, -1, sizeof dp);
	for(int i=2; i<=1000000; ++i){
		if(ok[i]){
			continue;
		}
		prime.push_back(i);
		for(int j=i*2; j<=1000000; j+=i){
			ok[j] = true;
		}
	}

	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
