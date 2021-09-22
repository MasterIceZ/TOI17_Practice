#include<bits/stdc++.h>
using namespace std;

using ll = long long;

pair<ll, ll> qs[1001000];
ll dp[1001000];

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	ll k, l;
	cin >> n >> k >> l;
	for(int i=1; i<=n; ++i){
		ll x, y;
		cin >> x >> y;
		qs[i].first += qs[i - 1].first + x;
		qs[i].second += qs[i - 1].second + y;
	}
	deque<pair<ll, ll>> deq;
	deq.emplace_back(0, 0);
	for(int i=1; i<=n; ++i){
		while(!deq.empty() && (qs[i].first - qs[deq.front().first].first > k || qs[i].second - qs[deq.front().first].second > l)){
			deq.pop_front();
		}
		ll valn = dp[i - 1] - qs[i].first - qs[i].second;
		while(!deq.empty() && deq.back().second <= valn){
			deq.pop_back();
		}
		deq.emplace_back(i, valn);
		dp[i] = deq.front().second + qs[i].first + qs[i].second;
	}
	cout << dp[n];
	return 0;
}
