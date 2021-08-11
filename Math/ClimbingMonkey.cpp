/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Climbing Monkey
 * ALGO		: Math
 * DATE		: 5 Aug 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct  A{
	int i, h;
	bool operator < (const A& o) const{
		if(h != o.h){
			return h < o.h;
		}
		return i < o.i;
	}
};

int val[200020];

void solve(){
	int n, m, k, now;
	cin >> m >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> val[i];
	}
	vector<A> opr;
	for(int i=1, x, y; i<=k; ++i){
		cin >> x >> y;
		opr.push_back({x, y});
	}
	cin >> now;
	sort(all(opr));
	for(int i=k-1; i>=0; --i){
		swap(val[opr[i].i], val[opr[i].i + 1]);
	}
	int ans = val[now], ans2 = 0;
	for(int i=0; i<k; ++i){
		int l = opr[i].i, r = l + 1;
		if(now > 1 && i > 0 && opr[i].h == opr[i-1].h && now - 1 == opr[i - 1].i + 1){
			ans2 = max(ans2, val[now - 2]);
		}
		else{
			ans2 = max(ans2, val[now - 1]);
		}
		ans2 = max(ans2, val[now + 1]);
		if(now == l){
			now = r;
		}
		else if(now == r){
			now = l;
		}
		swap(val[l], val[r]);
	}
	cout << max(ans, ans2) << "\n";
	cout << (ans2 > ans ? "USE" : "NO");
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
