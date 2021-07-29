#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> row, col, frow, fcol;
map<pair<int, int>, int> ship;
long long ans = 0;
int n;

void add(int x, int y, int z){
	ans -= n - fcol[row[y]];
	ans -= n - frow[col[x]];
	if(row[y] != col[x]){
		++ans;
	}
	frow[row[y]]--;
	fcol[col[x]]--;
	row[y] ^= z;
	col[x] ^= z;
	frow[row[y]]++;
	fcol[col[x]]++;
	ans += n-fcol[row[y]];
	ans += n-frow[col[x]];
	if(row[y] != col[x]){
		--ans;
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int k, p, x, y, z, a, b, c, d;
	cin >> n >> k >> p;
	frow[0]= fcol[0] = n;
	for(int i=1; i<=k; ++i){
		cin >> x >> y >> z;
		ship[make_pair(x, y)] = z;
		add(x, y, z);
	}
	while(p--){
		cin >> a >> b >> c >> d;
		z = ship[make_pair(a, b)];
		ship.erase(make_pair(a, b));
		add(a, b, z);
		ship[make_pair(c, d)] = z;
		add(c, d, z);
		cout << ans << "\n";
	}
	return 0;
}
