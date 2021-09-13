/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Art TOI13
 * ALGO		: Sweepline
 * DATE		: 13 Sep 2021
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

int hi[1000100];

const int MxR = 3003000;

int lower(int nax){
	int l = 1, r = 1000000;
	while(l <= r){
		int mid = (l + r) / 2;
		if(hi[mid] <= nax){
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	return l;
}

int upper(int nax){
	int l = 1, r = 1000000;
	while(l <= r){
		int mid = (l + r) / 2;
		if(hi[mid] < nax){
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	return l;
}

void solve(){
	int n, t;
	cin >> n >> t;
	assert(n <= 5000);
	vector<tuple<int, int, int>> line;
	for(int i=1; i<=n; ++i){
		int s, h, w, o;
		cin >> s >> h >> w >> o;
		assert(h <= 1000000);
		line.emplace_back(s, h, o);
		line.emplace_back(s + w, h, -o);
	}
	sort(all(line));
	int cou = 0;
	for(int i=0; i<line.size(); ++i){
		for(int j=1; j<=get<1>(line[i]); ++j){
			hi[j] += get<2>(line[i]);
		}
		int lb = lower(t), ub = upper(t);
//		int lb = 1, ub = 1;
		int amt = get<0> (line[i + 1]) - get<0> (line[i]);
		cou += (ub - lb) * (amt);
		dbg(lb, ub, amt);
//		for(int j=0; j<=100; ++j){
//			if(hi[j] == t){
//				cou += get<0>(line[i + 1]) - get<0>(line[i]);
//			}
//		}
	}
	cout << cou;
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
