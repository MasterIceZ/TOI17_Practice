/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_No Pants
 * ALGO		: Matrix Exponential
 * DATE		: 2 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

double a[255];
int n;

struct Matrix{
	double a[255][255];
};

Matrix x;

Matrix mul(Matrix a, Matrix b){
	Matrix tmp;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			tmp.a[i][j] = 0.0;
			for(int k=0; k<n; ++k){
				tmp.a[i][j] += a.a[i][k] * b.a[k][j];
			}
		}
	}
	return tmp;
}

Matrix val;

Matrix dp[22], ans;

void solve(){
	int t;
	cin >> n >> t;
	for(int i=0; i<n; ++i){
		cin >> a[i];
		val.a[i][i] = a[i];
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin >> dp[0].a[i][j];
		}
	}	
	ans = dp[0];
	for(int i=1; i<=20; ++i){
		dp[i] = mul(dp[i - 1], dp[i - 1]);
		dbg(i);
	}
	t--;
	for(int i=20; i>=0; --i){
		if(t & (1 << i)){
			ans = mul(ans, dp[i]);
			dbg(i);
		}
	}
	ans = mul(val, ans);
	vector<double> ans2;
	for(int i=0; i<n; ++i){
		double tmp = 0.0;
		for(int j=0; j<n; ++j){
			tmp += ans.a[j][i];
			dbg(ans.a[j][i]);
		}
		ans2.push_back(tmp);
		dbg(tmp);
	}
	for(auto x: ans2){
		cout << fixed << setprecision(2) << x << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
