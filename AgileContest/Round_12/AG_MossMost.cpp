/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Moss Most
 * ALGO		: Counting Sort
 * DATE		: 3 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

void solve2(){
	int n;
	cin >> n;
	unordered_map<int, int> cnt;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		cnt[x]++;
		if(cnt[x + 1] != 0){
			cnt[x + 1]--;
		}
	}
	int ans = 0;
	for(auto x: cnt){
		ans += x.second;
	}
	cout << ans;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve2();
		cout << "\n";
	}
	return 0;
}
