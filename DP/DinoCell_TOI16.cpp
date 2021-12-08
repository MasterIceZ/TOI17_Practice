/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi16_dinocell
 * ALGO		: Math, Brute Force, Dynamic Programming
 * DATE		: 3 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 1e7 + 10;
bitset<MxN> factor;
int qs[MxN]; // Prefix Sum 0
int a[1000100], k, dp[1000100];

// dp[i] -> difference of (+) and (-)

void solve(){
	int z, n;
	cin >> z >> k >> n;
	vector<int> prime;
	int tmp = k, sq = sqrt(k);
	for(int i=2; i<=sq; ++i){
		if(tmp % i == 0){
			prime.push_back(i);
			while(tmp % i == 0){
				tmp /= i;
			}
		}
	}
	if(tmp != 1){
		prime.push_back(tmp);
	}
	factor.set();
	for(auto x: prime){
		for(int i=x; i<k; i+=x){
			factor[i] = false;
		}
	}
	for(int i=1; i<k; ++i){
		qs[i] = qs[i - 1] + factor[i];
	}
	int full = qs[k - 1];
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		dp[i] = a[i] - 2 * (full * (a[i] / k) + qs[a[i] % k]);
		dbg(dp[i]);
	}
	int ans = 0, minn = 1e9 + 10, maxx = -1e9 - 10;
	for(int i=1; i<=n; ++i){
		if(i > 1){
			ans = max({ans, abs(dp[i] + minn), abs(dp[i] + maxx)});
		}
		int x = dp[i];
		if(factor[a[i] % k]){
			x++;
		}
		else{
			x--;
		}
		minn = min(minn, -x);
		maxx = max(maxx, -x);
	}
	cout << ans;
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
