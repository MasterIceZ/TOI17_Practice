/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PZ_Township
 * ALGO		: Greedy
 * DATE		: 29 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve(){
	int n;
	cin >> n;
	priority_queue<int> pq;
	for(int i=0, x; i<n; ++i){
		cin >> x;
		pq.push(x);
	}
	int ans = 0;
	for(int i=1; i<=n; ++i){
		ans = max(ans, pq.top() + i);
		pq.pop();
	}
	cout << ans;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
