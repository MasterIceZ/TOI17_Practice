/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Deva Scales
 * ALGO		: Math
 * DATE		: 1 Aug 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " : " << (x) << "\n"

using ll = long long;

ll power[30];

void solve(){
	power[0] = 1;
	for(int i=1; i<=20; ++i){
		power[i] = power[i-1] * 3;
	}
	ll m, n;
	cin >> n;
	vector<ll> v;
	m = n;
	while(n > 0){
		v.push_back(n % 3);
		n /= 3;
	}
	ll cnt = 0, ans = 0;
	for(int i=0; i<v.size(); ++i){
		if(v[i] == 1){
			cnt++;
			ans += power[i];
		}
		if(v[i] == 2 && v[i + 1] != 2){
			cnt += 2;
//			cout << "Power : " << power[i + 1] << " " << power[i] << "\n";
			ans += power[i + 1];
//			ans -= power[i + 1];
		}
//		cout << "ANS : " << cnt << " " << ans << "\n";
		dbg(cnt);
		dbg(ans);
	}
	cout << cnt << " " << ans;
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
