/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi14_space
 * ALGO		: Breadth First Search
 * DATE		: 28 Oct 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

//char a[1010][1010];
//bool visited[1010][1010];
bitset<2010> a[10100];

const int di[] = {0, 0, 1};
const int dj[] = {-1, 1, 0};

int n, m, mini, minj;
int comet, planet, sphere;
queue<pair<int, int>> q;

void bfs(int i, int j){
	q.emplace(i, j);
//	cout << "DEBUG : (" << i << ", " << j << ")\n";
	int maxi = i, maxj = j, minnj = j;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		if(!a[now.first][now.second]){
			continue;
		}
		a[now.first][now.second] = 0;
		minnj = min(minnj, now.second);
		maxi = max(maxi, now.first);
		maxj = max(maxj, now.second);
		for(int k=0; k<3; ++k){
			int ii = di[k] + now.first;
			int jj = dj[k] + now.second;
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(!a[ii][jj]){
				continue;
			}
			q.emplace(ii, jj);
		}
	}
	if(maxi - mini != maxj - minnj){
//		cout << "COMET\n";
		comet++;
	}
	else if(maxi - mini == maxj - minj){
//		cout << "PLANET\n";
		planet++;
	}
	else{
//		cout << "SPHERE\n";
		sphere++;
	}
}

void solve(){
	cin >> m >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			char x;
			cin >> x;
			a[i][j] = x - '0';
		}
	}
	planet = comet = sphere = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j]){
				mini = i, minj = j;	
				bfs(i, j);
			}
		}
	}
	cout << planet << " " << sphere << " " << comet ;
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
