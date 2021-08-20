/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Matrix Expo
 * ALGO		: Divide and Conquer
 * DATE		: 19 Aug 2021
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

struct Matrix{
	ll a[5][5];
};

ll MOD, n;

Matrix mul(Matrix a, Matrix b){
	Matrix tmp;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			tmp.a[i][j] = 0;
			for(int k=0; k<n; ++k){
				tmp.a[i][j] += a.a[i][k] * b.a[k][j];
				tmp.a[i][j] %= MOD;
			}
		}
	}
	return tmp;
}

Matrix dp[66], ans;

void solve(){
	ll b;
	cin >> n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin >> dp[0].a[i][j];
		}
	}
	cin >> b >> MOD;
	ans = dp[0];
	if(b == 0){
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				if(i == j){
					cout << (1 % MOD);
				}
				else{
					cout << 0 ;
				}
				cout << " ";
			}
			cout << "\n";
		}
		return ;
	}
	b -= 1;
	for(int i=1; i<=63; ++i){
		dp[i] = mul(dp[i - 1], dp[i - 1]);
	}
	for(int i=63; i>=0; --i){
		if(b & (1ll << i)){
			ans = mul(ans, dp[i]);
		}
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cout << ans.a[i][j] << " ";
		}
		cout << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
//		cout << endl;
	}
	return 0;
}
