/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Range Special
 * ALGO		: Sliding Windows
 * DATE		: 11 Sep 2021
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

ll a[1000100], n;

ll create(ll nax){
	ll res = 0, rem = 0;
	deque<ll> Max, Min;
	for(ll i=1; i<=n; ++i){
		while(!Max.empty() && a[Max.back()] < a[i]){
			Max.pop_back();
		}
		while(!Min.empty() && a[Min.back()] > a[i]){
			Min.pop_back();
		}
		Max.push_back(i);
		Min.push_back(i);
		while(!Min.empty() && !Max.empty() && a[Max.front()] - a[Min.front()] > nax){
			if(Max.front() < Min.front()){
				rem = Max.front();
				Max.pop_front();
			}
			else{
				rem = Min.front();
				Min.pop_front();
			}
		}
		res += i - rem;
		dbg(i, res, rem);
	}
	return res;
} 

void solve(){
	ll p, q;
	cin >> n >> p >> q;
	for(ll i=1; i<=n; ++i){
		cin >> a[i];
	}
	cout << create(q) - create(p - 1);
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
