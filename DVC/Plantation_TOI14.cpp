/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Plantation TOI14
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

pair<int, int> a[100100];

bool cmpx(const pair<int, int> a, const pair<int, int> b){
	return a.first < b.first;
}

bool cmpy(const pair<int, int> a, const pair<int, int> b){
	return a.second < b.second;
}

double dist(pair<int, int> a, pair<int, int> b){
	double ret = sqrt(1.0 * (a.first - b.first) * (a.first - b.first) + 1.0 * (a.second - b.second) * (a.second - b.second));
	dbg(ret);
	return ret;
}

double divide(int l, int r){
	double ans = 2e9 + 10;
	if(r - l  + 1 <= 3){
		for(int i=l; i<=r; ++i){
			for(int j=i+1; j<=r; ++j){
				ans = min(ans, dist(a[i], a[j]));
			}
		}
		dbg(ans);
		return ans;
	}
	int mid = (l + r) >> 1;
	double dl = divide(l, mid);
	double dr = divide(mid + 1, r);
	double d = min(dl, dr);
	vector<pair<int, int>> strip;
	for(int i=l; i<=r; ++i){
		if(abs(a[i].first - a[mid].first) < d){
			strip.push_back(a[i]);
		}
	}
	sort(all(strip), cmpy);
	for(int i=0; i<strip.size(); ++i){
		for(int j=i+1; j<strip.size() && strip[j].second - strip[i].second < d; ++j){
			d = min(d, dist(strip[i], strip[j]));
		}
	}
	dbg(d);
	return d;
}

void solve(){
	int n, r, d;
	cin >> n >> r >> d;
	for(int i=1; i<=n; ++i){
		cin >> a[i].first >> a[i].second;
	}
	sort(a + 1, a + n + 1, cmpx);
	double ans = divide(1, n);
	cout << (ans >= 2 * r + d ? "Y" : "N");
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
