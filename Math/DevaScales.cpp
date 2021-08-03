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
	while(n > 1){
		v.push_back(n % 3);
		n /= 3;
	}
	if(n != 0){
		v.push_back(n);
	}
	v.push_back(0);
	ll cnt = 0, ans = 0;
	for(int i=0; i<v.size(); ++i){
		if(v[i] == 3){
			v[i + 1] += 1;
		}
		else if(v[i] == 2){
			ans += power[i];
			cnt += 1;
			v[i + 1] += 1;
		}
		else if(v[i] == 1){
			cnt += 1;
		}
	}
	cout << cnt << " " << m + ans;
//	cout << cnt << " " << ans;
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
