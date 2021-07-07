#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

struct Node{
	int i, j, cnt, last;
	bool operator < (const Node& o) const{
		return cnt > o.cnt;
	}
};

const int di[] = {0, -1, 1};
const int dj[] = {1, 0, 0};

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, st;
	cin >> n >> m >> st;
	vector<vector<char>> a(n+2, vector<char>(m+2));
	vector<vector<vector<int>>> cnt(n+2, vector<vector<int>>(m+2, vector<int>(4, 1e9 + 7)));
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	priority_queue<Node> pq;
	pq.push({st, 1, 0, 0});
	cnt[st][1][0] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(now.j == m){
			cout << now.cnt << "\n";
			return 0;	
		}
		for(int k=0; k<3; ++k){
			int ii = now.i + di[k], jj = now.j + dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > m || a[ii][jj] == '#'){
				continue;
			}
			int mkr = 0;
			if(now.last != k){
				mkr++;
			}
			int newCnt = now.cnt + mkr;
			if(cnt[ii][jj][now.last] > newCnt){
				cnt[ii][jj][now.last] = newCnt;
				pq.push({ii, jj, cnt[ii][jj][now.last], k});
			}
		}
	}
	cout << -1 ;
	return 0;
}
