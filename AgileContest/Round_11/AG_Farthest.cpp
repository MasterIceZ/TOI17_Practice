/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Farthest 25%
 * ALGO		: Brute Force
 * DATE		: 29 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 1e4 + 10;
int a[MxN];
int n;

unordered_map<int, priority_queue<int>> minn;
unordered_map<int, priority_queue<int, vector<int>, greater<int>>> maxx;
unordered_map<int, int> cnt, mark;

void solve(){
	int opr, l, r, x;
	cin >> opr;
	if(opr == 1){
		cin >> l >> r >> x;
		for(int i=l; i<=r; ++i){
			cnt[a[i]] = cnt[a[i]] - 1;
			a[i] += x;
			mark[i] = a[i];
			minn[a[i]].push(i);
			maxx[a[i]].push(i);
			cnt[a[i]] = cnt[a[i]] + 1;
		
		}
	}
	else{
		cin >> x;
		if(cnt[x] == 0){
			cout << "-1 0";
		}
		else{
			while(!minn[x].empty() && mark[minn[x].top()] != x){
				minn[x].pop();
			}
			while(!maxx[x].empty() && mark[maxx[x].top()] != x){
				maxx[x].pop();
			}
			cout << abs(maxx[x].top() - minn[x].top()) << " " << cnt[x] << "\n";
		}
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin  >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		minn[a[i]].push(i);
		maxx[a[i]].push(i);
		cnt[a[i]]++;
		mark[i] = a[i];
	}
	while(q--){
		solve();
	}
	return 0;
}
