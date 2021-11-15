/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi6_schedule
 * ALGO		: Sweepline
 * DATE		: 15 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct EVP{
	int point, val, type;
	bool operator < (const EVP& o) const{
		if(point != o.point){
			return point < o.point;
		}
		return type < o.type;
	}
};

const int MxN = 500500;
bool dp[MxN];

void solve(){
	int n, q, k;
	cin >> n >> k >> q;
	vector<EVP> line;
	for(int i=1, s, e; i<=n; ++i){
		cin >> s >> e;
		line.push_back({s, i, 1});
		line.push_back({e + 1, i, 0});
	}
	sort(line.begin(), line.end());
	int cnt = 0;
	for(auto x: line){
		if(x.type){
			if(cnt < k){
				cnt += 1;
				dp[x.val] = true;
			}
		}
		else{
			if(dp[x.val]){
				cnt -= 1;
			}
		}
		dbg(cnt, x.type, x.val);
	}
	while(q--){
		int x;
		cin >> x;
		cout << (dp[x] ? "Y " : "N ");
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
