/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: JPeek
 * ALGO		: Breadth First Search
 * DATE		: 16 Aug 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int dist[10][333][333];
char a[333][333];

const int di[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int dj[] = {0, 0, 1, -1, -1, 1, 1, -1};
int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int r, c, q;
	cin >> r >> c >> q;
	queue<tuple<int, int, int>> q;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			cin >> a[i][j];
			if(a[i][j] == 'J'){
				for(int k=0; k<4; ++k){
					q.emplace(i, j, k);
				}
			}
		}
	}
	memset(dist, -1, sizeof dist);
	while(!q.empty()){
		tuple<int, int, int> now = q.front();
		q.pop();
		pair<int, int> pos = make_pair(get<0>(now), get<1>(now));
		int k = get<2>(now), dir;
		int w = dir[k][pos.first][pos.second];
		if(k == 0){
			dir = 2;
		}
		else if(k == 1){
			dir = 0;
		}
		else if(k == 2){
			dir = 6;
		}
		else{
			dir = 4;
		}
		for(int i=0; i<2; ++i){
			int ii = di[dir + i] + pos.first, jj = dj[dir + i] + pos.second;
			int nxt;
			if(k == 0){
				nxt = 1;
			}
			else if(k == 1){
				nxt = 0;
			}
			else if(k == 2){
				nxt = 3;
			}
			else{
				nxt = 4;
			}
			while(1){
				if(ii < 1 || jj < 1 || ii > r || jj > c){
					break;
				}
				if(a[ii][jj] == '#' || dist[nxt][ii][jj] != -1){
					break;
				}
				dist[nxt][ii][jj] = 
	}
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
