/*
 * AUTHOR	: Hydrolyzed~
 * TASK		:
 * CENTER	: RYW
 * DATE		: 26 Jun 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;


const int di[] = {1, 0, 0, -1};
const int dj[] = {0, -1, 1, 0};

int n, m;

char v[1010][1010];
ll dist[1010][1010];

char conV(int x){
	if(x == 0){
		return 'D';
	}
	if(x == 1){
		return 'L';
	}
	if(x == 2){
		return 'R';
	}
	return 'U';
}

void solve(){
	int r, c, a;
	cin >> r >> c >> a;
//	if(a % 2 == 1){
//		cout << "Can\'t do";
//		return ;
//	}
	int sti, stj;
	queue<pii> q;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			cin >> v[i][j];
			if(v[i][j] == 'P'){
				q.emplace(i, j);
				sti = i, stj = j;
			}
			dist[i][j] = -1;
		}
	}
	dist[sti][stj] = 0;
	while(!q.empty()){
		pii now = q.front();
		q.pop();
		for(int k=0; k<4; ++k){
			int ii = now.first + di[k], jj = now.second + dj[k];
			if(ii < 1 || jj < 1 || ii > r || jj > c){
				continue;
			}
			if(v[ii][jj] == '#'){
				continue;
			}
			if(dist[ii][jj] != -1){
				continue;
			}
			dist[ii][jj] = dist[now.first][now.second] + 1;
			q.emplace(ii, jj);
//			cout << "Test";
		}
	}
//	for(int i=1; i<=r; ++i){
//		for(int j=1; j<=c; ++j){
//			cout << dist[i][j] << " ";
//		}
//		cout << endl;
//	}
	int le = a;
	vector<int> ans;
	int i = sti, j = stj;
	while(le--){
		for(int k=0; k<4; ++k){
			int ii = i + di[k], jj = j + dj[k];
//			cout << "(" << ii << ", " << jj << ")" << endl;
			if(ii < 1 || jj < 1 || ii > r || jj > c){
				continue;
			}
			if(v[ii][jj] == '#'){
				continue;
			}
			if(dist[ii][jj] > le){
				continue;
			}
//			cout << conV(k) << " ";
			ans.push_back(k);
			i = ii, j = jj;
			break;
		}
	}
	if(ans.size() == a){
		for(auto x: ans){
			cout << conV(x);
		}
	}
	else{
		cout << "Can\'t do";
	}
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
