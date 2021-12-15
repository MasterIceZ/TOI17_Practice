/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi13_art
 * ALGO		: Fenwick Tree, Binary Search, Sweepline
 * DATE		: 14 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Fenwick{
	int tree[3003000];
	void update(int idx, int v){
		for(; idx <= 3000000; idx+=idx&-idx){
			tree[idx] += v;
		}
	}
	int read(int idx){
		int res = 0;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
	int lb(int cur){
		int l = 1, r = 1000000;
		int res = r;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(read(mid) <= cur){
				r = mid - 1;
				res = mid;
			}
			else{
				l = mid + 1;
			}
		}
		return res;
	}
	int ub(int cur){
		int l = 1, r = 1000000;
		int res = r;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(read(mid) < cur){
				r = mid - 1;
				res = mid;
			}
			else{
				l = mid + 1;
			}
		}
		return res;
	}
} fw;

void solve(){
	int n, t, s, h, w, o;
	cin >> n >> t;
	vector<tuple<int, int, int>> line;
	for(int i=1; i<=n; ++i){
		cin >> s >> h >> w >> o;
		line.emplace_back(s, h, o);
		line.emplace_back(s + w, h, -o);
	}
	int cou = 0;
	sort(line.begin(), line.end());
	for(int i=0; i<line.size(); ++i){
		fw.update(1, get<2>(line[i]));
		fw.update(get<1>(line[i]) + 1, get<2>(line[i]) * -1);
		int low = fw.lb(t), up = fw.ub(t);
		int amt = get<0>(line[i + 1]) - get<0>(line[i]);
		cou += amt * (up - low);
	}
	cout << cou;
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
