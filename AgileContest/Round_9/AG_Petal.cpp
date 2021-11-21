/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Petal
 * ALGO		: Heap, Dynamic Programming
 * DATE		: 18 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 1550;
int a[MxN], dp[55][MxN], pre[MxN][MxN];

priority_queue<int> lo;
priority_queue<int, vector<int>, greater<int>> hi;

void solve(){
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
//	Online Median -> memoi in pre
	for(int i=1; i<=n; ++i){
		int sum_l = 0, sum_h = 0;
		for(int j=i; j<=n; ++j){
			if(lo.empty()){
				lo.push(a[j]);
				sum_l += a[j];
			}
			else{
				if(a[j] <= lo.top()){
					if(lo.size() == hi.size()){
						lo.push(a[j]);
						sum_l += a[j];
					}
					else{
						sum_h += lo.top();
						sum_l += a[j] - lo.top();
						hi.push(lo.top());
						lo.pop();
						lo.push(a[j]);
					}
				}
				else{
					if(hi.size() < lo.size()){
						hi.push(a[j]);
						sum_h += a[j];
					}
					else if(a[j] < hi.top()){
						lo.push(a[j]);
						sum_l += a[j];
					}
					else{
						sum_l += hi.top();
						sum_h += a[j] - hi.top();
						lo.push(hi.top());
						hi.pop();
						hi.push(a[j]);
					}
				}
				pre[i][j] = sum_h - hi.size() * lo.top() + lo.size() * lo.top() - sum_l;
			}
			dbg(lo.size(), hi.size());
		}
		while(!lo.empty()){
			lo.pop();
		}
		while(!hi.empty()){
			hi.pop();
		}
	}
//	for(int i=1; i<=n; ++i){
//		for(int j=1; j<=n; ++j){
//			cout << pre[i][j] << " ";
//		}
//		cout << "\n";
//	}
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int k=1; k<=50; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=i; ++j){
				dp[k][i] = min(dp[k][i], dp[k - 1][j - 1] + pre[j][i]);
			}
		}
	}
	while(q--){
		int x;
		cin >> x;
		cout << dp[x][n] << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
