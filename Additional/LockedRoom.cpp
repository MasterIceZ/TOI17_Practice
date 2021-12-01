/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Locked Room
 * ALGO		: Dijkstra
 * DATE		: 1 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Node{
	int i, j, w, state;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

const int MxN = 66;
int a[MxN][MxN];
int dist[4000][MxN][MxN];

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

void solve(){
	int n, sx, sy, ex, ey;
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}
	cin >> sx >> sy >> ex >> ey;
	priority_queue<Node> pq;
	pq.push({sx, sy, 0, 0});
	memset(dist, 0x3f, sizeof dist);
	dist[0][sx][sy] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(now.i == ex && now.j == ey && now.state % 2){
			cout << now.w;
			return ;
		}
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.i;
			int jj = dj[k] + now.j;
			if(ii < 1 || jj < 1 || ii > n || jj > n){
				continue;
			}
			int nxt = now.w + abs(a[ii][jj]);
			int nxt_state = now.state + (a[ii][jj] < 0);
			if(dist[nxt_state][ii][jj] > nxt){
				pq.push({ii, jj, nxt, nxt_state});
				dist[nxt_state][ii][jj] = nxt;
			}
		}
	}
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
