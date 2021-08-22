/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Tri Inversion
 * ALGO		: Divide and Conquer
 * DATE		: 22 Aug 2021
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

pair<int, int> a[100100], b[100100];
ll r[100100], l[100100];

void mergesort(int L, int R){
	if(L >= R){
		return ;
	}
	int mid = (L + R) >> 1;
	mergesort(L, mid);
	mergesort(mid + 1, R);
	int i = L, j = mid + 1, k = L;
	while(i <= mid && j <= R){
		if(a[i].first <= a[j].first){
			b[k] = a[i];
			r[a[i].second] += j - (mid + 1);
			dbg(r[a[i].second]);
			++k, ++i;
		}
		else{
			b[k] = a[j];
			l[a[j].second] += mid - (i - 1);
			dbg(l[a[j].second]);
			++k, ++j;
		}
	}
	while(i <= mid){
		b[k] = a[i];
		r[a[i].second] += R - mid;
		++k, ++i;
	}
	while(j <= R){
		b[k] = a[j];
		++k, ++j;
	}
	for(int i=L; i<=R; ++i){
		a[i] = b[i];
	}
}

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i].first;
		a[i].second = i;
	}
	mergesort(1, n);
	ll ans = 0;
	for(int i=1; i<=n; ++i){
		ans += r[i] * l[i];
		r[i] = 0, l[i] = 0;
	}
	cout << ans;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
