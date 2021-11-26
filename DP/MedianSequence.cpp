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

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 100100;
ll l[MxN * 2], r[MxN * 2], a[MxN];

void solve(){
	int n, med, cur, mid;
	cin >> n >> med;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		if(a[i] == med){
			mid = i;		
		}
	}
	int offset = 100000;
	l[offset] = r[offset] = 1;
	cur = 0;
	// ->
   	for(int i=mid+1; i<=n; ++i){
		if(a[i] < med){
			cur -= 1;
		}
		else{
			cur += 1;
		}
		l[offset + cur]++;
	}
	// <-
	cur = 0;
	for(int i=mid-1; i>=1; --i){
		if(a[i] < med){
			cur -= 1;
		}
		else{
			cur += 1;
		}
		r[offset + cur]++;
	}
	ll res = 0;
	for(int i=0; i<=offset*2; ++i){
		res += (l[i] * r[2 * offset - i]);
	}
	cout << res;
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
