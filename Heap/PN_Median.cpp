/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Median
 * ALGO		: Data Structure
 * DATE		: 5 Aug 2021
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

#define dec(x) fixed << setprecision(1) << (double)(x)

using ll = long long;

void solve(){
	priority_queue<ll> mx;
	priority_queue<ll, vector<ll>, greater<ll>> mn;
	ll n, x;
	double med;
	cin >> n >> x;
	cout << dec(x) << "\n";
	mx.push(x);
	med = (double)x;
	for(ll i=2; i<=n; ++i){
		cin >> x;
		dbg(x);
		if(mx.size() > mn.size()){
			if(x > med){
				mn.push(x);
			}
			else{
				mn.push(mx.top());
				mx.pop();
				mx.push(x);
			}
			med = (double)(mx.top() + mn.top()) / 2; 
		}
		else if(mx.size() == mn.size()){
			if(x < med){
				mx.push(x);
				med = (double)mx.top();
			}
			else{
				mn.push(x);
				med = (double)mn.top();
			}
		}
		else{
			if(x > med){
				mx.push(mn.top());
				mn.pop();
				mn.push(x);
			}
			else{
				mx.push(x);
			}
			med = (double)(mx.top() + mn.top()) / 2;
		}
		cout << dec(med) << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
//		cout << endl;
	}
	return 0;
}
