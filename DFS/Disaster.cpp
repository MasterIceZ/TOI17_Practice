/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Disaster TOI9
 * ALGO		: Depth First Search
 * DATE		: 6 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

vector<pair<int, int>> adj[33];
int deg[33], vis[33][33], ans[333];

int k(char s){
	return s - 'A';
}

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		string a;
		cin >> a;
		int u = k(a[0]), v = k(a[1]);
		
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
