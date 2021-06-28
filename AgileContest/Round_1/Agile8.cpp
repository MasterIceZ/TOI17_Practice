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

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;

int n, m;
char a[300300];

const int MOD = 1e9 + 7;

void modd(ll &ans){
	ans %= MOD;
	ans += MOD;
	ans %= MOD;
}

void solve(){
	ll ans = 0, n;
	cin >> (a+1);
	n = strlen(a + 1);
	for(int i=1; i<=n; ++i){
		if(a[i] == a[i-1]){
			continue;
		}
		ans += n * 25;
		modd(ans);
	}
	ll cnt = 1;
	for(int i=2; i<=n; ++i){
		if(cnt == 1){
			if(a[i] == a[i-1]){
				continue;
			}
			++cnt;
		}
		else{
			if(a[i] == a[i-2]){
				++cnt;
				continue;
			}
			ans -= cnt * (cnt - 1) / 2;
			modd(ans);
			cnt = (a[i] == a[i-1] ? 1 : 2);
		}
	}
	ans -= cnt * (cnt - 1) / 2;
	modd(ans);
	cout << ans; 
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
