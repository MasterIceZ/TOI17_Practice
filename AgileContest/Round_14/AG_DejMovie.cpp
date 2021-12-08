/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 100100;
int a[MxN], b[MxN];
int carry[MxN];

void solve(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=k; ++i){
		cin >> b[i];
	}
	int l = 1, r = n + 1;
	while(l < r){
		int mid = (l + r) >> 1;
		memset(carry, 0, sizeof carry);
		for(int i=1; i<=mid; ++i){
			if(a[i] != 0){
				carry[a[i]] = i;
			}
		}
		bool ok = true;
		int read = 0, sub = 0;
		for(int i=1; i<=mid; ++i){
			if(carry[a[i]] == i){
				if(read >= b[a[i]]){
					read -= b[a[i]];
					sub++;
				}
				else{
					ok = false;
					break;
				}
			}
			else{
				read++;
			}
		}
		if(ok && sub == k){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	cout << (r == n + 1 ? -1: l);
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
