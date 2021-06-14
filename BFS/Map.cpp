/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Map
 * ALGO		: Breadth First Search
 * DATE		: 10 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int di[] = {0, 0, -1, 1}, dj[] = {1, -1, 0, 0};
int  n, m;
int dir(char x){
	if(x == 'U'){
		return 3;
	}
	return 1;
}

vector<pair<pair<int, int>, int>> g[50400];
bool visited[50400];

struct Node{
	int i, j, val;
	bool operator < (const Node& o) const{
		if(i == o.i){
			return j < o.j;
		}
		return i > o.i;
	}
};

Node tab[50400];

void solve(){
	cin >> n >> m;
	int sz = n * m - 1;
	for(int i=0; i<=sz; ++i){
		tab[i].val = i;
	}
	for(int i=1; i<=sz; ++i){
		int x, y;
		char o;
		cin >> x >> o >> y;
		g[x].emplace_back(make_pair(di[dir(o) - 1], dj[dir(o) - 1]), y);
		g[y].emplace_back(make_pair(di[dir(o)], dj[dir(o)]), x);
	}
	tab[0].i = 0, tab[0].j = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		visited[now] = true;
		for(auto x: g[now]){
			int vv = x.second, i = x.first.first, j = x.first.second;
			if(visited[vv]){
				continue;
			}
			tab[vv].i = tab[now].i + i;
			tab[vv].j = tab[now].j + j;
			q.push(vv);
		}
	}
	sort(tab, tab + sz + 1);
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cout << tab[i * m + j].val << " ";
		}
		cout << endl;
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
