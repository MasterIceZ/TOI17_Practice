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

void solve(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(auto &x: v){
		cin >> x;
	}
	reverse(v.begin(), v.end());
	queue<pair<int, int>> q; // (val, idx)
	int it = 0;
	for(auto x: v){
		q.emplace(x, ++it);
	}
	int last = -1, cnt = 0, id = n + 1;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		if(id >= now.second){
			// Start New Round
			last = now.first;
			cnt++;
		}
		else{
			if(now.first - 1 != last){
				q.push(now);
			}
			else{
				last = now.first;
			}
		}
		id = now.second;
		dbg(now.first);
	}
	cout << cnt;
	return ;
}

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
//		solve();
		solve2();
		cout << "\n";
	}
	return 0;
}
