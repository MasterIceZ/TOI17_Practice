#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()

struct Point{
	int type, x1, y1, y2;
	bool operator < (const Point& o) const{
		if(x1 != o.x1){
			return x1 < o.x1;
		}
		return type < o.type;
	}
};

int tree[100100], ans[100100];
void update(int idx, int val){
	for(; idx<=100000; idx+=idx&-idx){
		tree[idx] += val;
	}
}
int read(int idx){
	int res = 0;
	for(; idx; idx-=idx& -idx){
		res += tree[idx];
	}
	return res;
}

int main(){
	int n, m, k, a, b, c, d;
	scanf("%d %d %d", &n, &m, &k);
	vector<Point> event;
	for(int i=1; i<=n; ++i){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		a++, b++, c++, d++;
		event.push_back({1, a, b, d});
		event.push_back({-1, c + 1, b, d});
	}
	for(int i=1; i<=m; ++i){
		scanf("%d %d", &a, &b);
		a++, b++;
		event.push_back({3, a, b, i});
	}
	sort(event.begin(), event.end());
	for(auto x: event){
		if(x.type != 3){
			update(x.y1, x.type);
			update(x.y2 + 1, -x.type);
		}
		else{
			ans[x.y2] = read(x.y1);
		}
	}
	for(int i=1; i<=m; ++i){
		printf("%d\n", ans[i]);
	}
	return 0;
}
