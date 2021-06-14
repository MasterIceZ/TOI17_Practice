/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: TOI8 Elec 
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve(){
	int k, n;
	cin >> n >> k;
	vector<int>v(n);
	for(auto &x: v){
		cin >> x;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(v[0], 0);
	int vv = 0;
	for(int i=1; i<n; ++i){
		while(!pq.empty() && i - pq.top().second > k){
			pq.pop();
		}
		vv = pq.top().first + v[i];
		pq.emplace(vv ,i);
	}
	cout << vv;
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
