/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Pair TOI7
 * ALGO		: Divide and Conquer
 * DATE		: 21 Aug 2021
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

double ans = 0, dp[100100];
int a[100100], b[100100];

void merge(int l, int r){
	int mid = (l + r) / 2;
	dp[l - 1] = 0;
	for(int i=l; i<=r; ++i){
		dp[i] = dp[i - 1] + a[i];
	}
	int i = l, j = mid + 1, k = l;
	while(i <= mid && j <= r){
		if(a[i] <= a[j]){
			b[k++] = a[i++];
		}
		else{
			ans += (mid - i + 1) * a[j] + (dp[mid] - dp[i - 1]); 
			dbg(ans);
			b[k++] = a[j++];
		}
	}
	while(i <= mid){
		b[k++] = a[i++];
	}
	while(j <= r){
		b[k++]=  a[j++];
	}
	for(int i=l; i<=r; ++i){
		a[i] = b[i];
	}
	return ;
}

void mergesort(int l, int r){
	if(l >= r){
		return ;
	}
	int mid = (l + r) / 2;
	mergesort(l, mid);
	mergesort(mid + 1, r);
	merge(l, r);
	return ;
}

void solve(){
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i=0; i<n; ++i){
		cin >> v[i].second >> v[i].first;
	}
	sort(all(v));
	for(int i=1; i<=n; ++i){
		a[i] = v[i - 1].second;
	}
	mergesort(1, n);
	cout << fixed << setprecision(0) << ans;
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
