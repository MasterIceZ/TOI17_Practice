/*
 * AUTHOR	: Hydrolyzed~
 * TASK		:
 * CENTER	: RYW
 * DATE		: 26 Jun 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

struct Node{
	int v, w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

struct Edge{
	int v, w, x;
};

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;

int n, m;

ll sq(ll a){
	ll l = 1, r = a;
	while(l <= r){
		 ll mid = (l + r) / 2;
		 if(mid * mid == a){
			 return mid;
		 }
		 if(mid <= a / mid){
			 l = mid + 1;
		 }
		 else{
			 r = mid - 1;
		 }
	 }
	 return l - 1;
 }

void solve(){
	ll l, r;
	cin >> l >> r;
	cout << sq(r) + sq(r/2) - sq(l-1) - sq((l-1)/2);
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	ll n, q;
	cin >> n >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
