#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

ll a[22];
bool ok = true;

ll divide(int level, ll val){
	ll cur = (2 * val) + 1 - a[level];
	if(cur <= 1){
		ok = false;
		return -1;
	}
	if(level == 1){
		return cur;
	}
	return divide(level - 1, cur / 2) + divide(level - 1, cur - cur / 2);
}

void solve(){
	ll k, w;
	cin >> k >> w;
	for(int i=1; i<k; ++i){
		cin >> a[i];
	}
	ll val = divide(k - 1, w);
	if(!ok || val <= 1){
		cout << -1;
	}
	else{
		cout << val;
	}
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
