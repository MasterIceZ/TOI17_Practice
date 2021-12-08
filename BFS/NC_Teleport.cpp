/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int MxN = 101100;

vector<int> adj[MxN];
int dist[MxN];

void solve(){
	int n, a, t;
	cin >> n >> a >> t;
	for(int i=1; i<=t; ++i){
		for(int j=1, x; j<=a; ++j){
			cin >> x;
			adj[i + n].push_back(x);
			adj[x].push_back(i + n);
		}
	}
	memset(dist, -1, sizeof dist);
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while(!q.empty()){
		int now = q.front();
//		cerr << "DBG : " << now << "\n";
		q.pop();
		for(auto x: adj[now]){
			if(dist[x] != -1){
				continue;
			}
			q.push(x);
			dist[x] = dist[now] + 1;
		}
	}
	cout << (dist[n] == -1 ? -1 : 1 + (dist[n] >> 1));
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
