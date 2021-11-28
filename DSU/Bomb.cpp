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

struct Point{
	int x, y, idx;
};

bool cmpx(Point a, Point b){
	if(a.x != b.x){
		return a.x < b.x;
	}
	return a.y < b.y;
}

bool cmpy(Point a, Point b){
	if(a.y != b.y){
		return a.y < b.y;
	}
	return a.x < a.y;
}

const int MxN = 100100;
int p[MxN];
Point a[MxN];
bool visited[MxN];

int fr(int u){
	return u == p[u] ? u: p[u] = fr(p[u]);
}

void solve(){
	int n, m, k, l, q, N;
	cin >> n >> m >> k >> l;
	for(int i=1, x, y; i<=k; ++i){
		p[i] = i;
		cin >> x >> y;
		a[i] = {x, y, i};
	}
	sort(a + 1, a + k + 1, cmpx);
	for(int i=2; i<=k; ++i){
		if(a[i].x == a[i - 1].x && a[i].y - a[i - 1].y <= l){
			p[fr(a[i].idx)] = fr(a[i - 1].idx);
		}
	}
	sort(a + 1, a + k + 1, cmpy);
	for(int i=2; i<=k; ++i){
		if(a[i].y == a[i - 1].y && a[i].x - a[i - 1].x <= l){
			p[fr(a[i].idx)] = fr(a[i - 1].idx);
		}
	}
	for(int i=1; i<=k; ++i){
		p[i] = fr(i);
	}
	cin >> q;
	while(q--){
		memset(visited, false, sizeof visited);
		cin >> N;
		int cnt = 0;
		for(int i=1, x; i<=N; ++i){
			cin >> x;
			int rx = p[x];
			if(!visited[rx]){
				visited[rx] = true;
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
