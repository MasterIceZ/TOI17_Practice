/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Rabbit House
 * ALGO		: Breadth First Search
 * DATE		: 15 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int a[333][333], b[333][333];
bool visited[333][333];

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

void solve(){
	int r, c;
	cin >> r >> c;
	
	using T = pair<int, pair<int, int>>;
	priority_queue<T, vector<T>, greater<T>> pq;
	
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			cin >> a[i][j];
			b[i][j] = a[i][j];
			pq.emplace(a[i][j], make_pair(i, j));
		}
	}
	memset(visited, false, sizeof visited);
	while(!pq.empty()){
		T now = pq.top();
		pq.pop();
		if(visited[now.second.first][now.second.second]){
			continue;
		}
		visited[now.second.first][now.second.second] = true;
		for(int k=0; k<4; ++k){
			int ii = now.second.first + di[k], jj = now.second.second + dj[k];
			if(ii < 1 || jj < 1 || ii > r || jj > c){
				continue;
			}
			a[ii][jj] += max(0, now.first - a[ii][jj] - 1);
			pq.emplace(a[ii][jj], make_pair(ii, jj));
		}
	}
	ll ans = 0;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			ans += a[i][j] - b[i][j];
		}
	}
	cout << ans;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	for(int i=1; i<=q; ++i){
		cout << "Case # " << i << ": ";
		solve();
		cout << endl;
	}
	return 0;
}
