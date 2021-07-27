/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Peatt Punch
 * ALGO		: Stack
 * DATE		: 21 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int a[100100], n;

void solve(){
	int x;
	cin >> x;
	cout << (n - (upper_bound(a, a + n, x) - a));
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> n >> q;
	stack<pair<int, int>> st;
	for(int i=0, x, pw; i<n; ++i){
		cin >> x;
		while(!st.empty() && st.top().first >= x){
			st.pop();
		}
		if(st.empty()){
			pw = 0;
		}
		else{
			pw = max(st.top().second, x - st.top().first);
		}
		a[i] = pw;
		st.emplace(x, pw);
	}
	sort(a, a+n);
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
