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

int a[100100];

void solve(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	ll ans = 0;
	unordered_map<int, int> mp;
	int it1 = 1, it2 = 1;
	while(it2 <= n){
		mp[a[it2]]++;
		it2++;
		while(mp.size() >= k){
			mp[a[it1]]--;
			if(mp[a[it1]] == 0){
				mp.erase(a[it1]);
			}
			ans += n - it2 + 2;
			it1++;
		}
	}
	cout << ans;
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
