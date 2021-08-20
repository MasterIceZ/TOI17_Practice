/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Inversion Count
 * ALGO		: Divide and Conquer
 * DATE		: 20 Aug 2021
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

ll a[100100], b[100100], cnt = 0;

void merge(int l, int r){
	int mid = (l + r) >> 1;
	int i = l, j = mid + 1, k = l;
	while(i <= mid && j <= r){
		if(a[i] <= a[j]){
			b[k++] = a[i++];
		}
		else{
			b[k++] = a[j++];
			cnt += mid - i + 1;
		}
	}
	while(i <= mid){
		b[k++] = a[i++];
	}
	while(j <= r){
		b[k++] = a[j++];
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
	int mid = (l + r) >> 1;
	mergesort(l, mid);
	mergesort(mid+1, r);
	merge(l, r);
	return ;
}

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	mergesort(1, n);
	cout << cnt;
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
