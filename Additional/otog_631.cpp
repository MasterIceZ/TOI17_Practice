#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct A{
	int x, y;
};
A a[100100];

bool cmpx(A a, A b){
	return a.x < b.x;
}

bool cmpy(A a, A b){
	return a.y < b.y;
}

double calc(A a, A b){
	return sqrt(1.0 * (a.x - b.x) * (a.x - b.x) + 1.0 * (a.y - b.y) * (a.y - b.y));
}

double divide(A b[], int n){
	double ans = 2e9;
	if(n <= 3){
		for(int i=0; i<n-1; ++i){
			for(int j=i+1; j<n; ++j){
				ans = min(ans, calc(b[i], b[j]));
			}
		}
		return ans;
	}
	int mid = n >> 1;
	double dl = divide(b, mid);
	double dr = divide(b + mid, n - mid);
	double d = min(dl, dr);
	vector<A> strip;
	for(int i=0; i<n; ++i){
		if(abs(b[i].x - b[mid].x) < d){
			strip.push_back(b[i]);
		}
	}
	sort(strip.begin(), strip.end(), cmpy);
	for(int i=0; i<strip.size(); ++i){
		for(int j=1+i; j<strip.size() && strip[j].y - strip[i].y < d; ++j){
			d = min(d, calc(strip[i], strip[j]));
		}
	}
	return d;
}

void solve(){
	int n;
	double r, d;
	cin >> n >> r >> d;
	for(int i=0; i<n; ++i){
		cin >> a[i].x >> a[i].y;
	}
	sort(a, a + n, cmpx);
	double ans = divide(a, n);
	cout << (ans >= 2 * r * d ? "Y": "N");
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
