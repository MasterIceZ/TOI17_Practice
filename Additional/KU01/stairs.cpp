#include<bits/stdc++.h>
using namespace std;

using ll = long long;

struct Event{
	int idx, val;
	bool operator < (const Event& o) const{
		return idx < o.idx;
	}
};

int qs[3][50500];
int a[50500];
vector<Event> line[3];

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> l;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=2; i<=n; ++i){
		int l = min(a[i], a[i - 1]) + 1;
		int r = max(a[i], a[i - 1]) - 1;
		if(l % 2){
			line[1].push_back({l, 1});
			line[0].push_bacl({l + 1, 1});
		}
		else{
			line[0].push_back({l, 1});
			line[1].push_back({l + 1, 1});
		}
		if(r % 2){
			line[1].push_back({r + 2 ,-1});
			line[0].push_back({r + 1 ,-1});
		}
		else{
			line[0].push_back({r + 2, -1});
			line[1].push_back({r + 1, -1});
		}
	}
	sort(all(line[1]));
	sort(all(line[0]));
	calc(1);
	calc(0);
	return 0;
}
