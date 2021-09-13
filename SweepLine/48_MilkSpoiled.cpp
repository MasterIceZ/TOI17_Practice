#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	vector<pair<int, int>> line;
	for(int i=1; i<=n; ++i){
		int l, r;
		cin >> l >> r;
		line.emplace_back(l, 1);
		line.emplace_back(r + 1, -1);
	}
	line.emplace_back(0, 0);
	sort(line.begin(), line.end());
	int ans, coux, couy, couz;
	ans = couy = couz = 0;
	coux = n;
	int j;
	for(int i=1; i<line.size(); i = j){
		for(j=i; j<line.size() && line[i].first == line[j].first; ++j){
			if(line[j].second == 1){
				coux--, couy++;
			}
			else if(line[j].second == -1){
				couy--, couz++;
			}
		}
		ans = max(ans, coux * x + couy * y + couz * z);
	}
	cout << ans;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
