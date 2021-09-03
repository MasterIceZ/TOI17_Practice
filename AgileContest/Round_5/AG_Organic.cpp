#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

const int MxN = 6e4 + 2;
vector<int> row[MxN], col[MxN];
int a[MxN], b[MxN];

void solve(){
	int r1, c1, r2, c2, cou = 0;
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	if(r2 - r1 < c2 - c1){
		for(int i=r1; i<=r2; ++i){
			cou += upper_bound(all(col[a[i]]), c2) - lower_bound(all(col[a[i]]), c1);
		}
	}
	else{
		for(int i=c1; i<=c2; ++i){
			cou += upper_bound(all(row[b[i]]), r2) - lower_bound(all(row[b[i]]), r1);
		}
	}
	printf("%d", cou);
	return ;
}

int fac(int val){
	int res = 1;
	for(int i=2; i * i <= val; ++i){
		int cou = 0;
		while(val % i == 0){
			++cou;
			val /= i;
		}
		if(cou & 1){
			res *= i;
		}
	}
	return res * val;
}

int main(){
	int r, c, q;
	scanf("%d %d %d", &r, &c, &q);
	for(int i=0; i<r; ++i){
		scanf("%d", &a[i]);
		a[i] = fac(a[i]);
		row[a[i]].push_back(i);
	}
	for(int i=0; i<c; ++i){
		scanf("%d", &b[i]);
		b[i] = fac(b[i]);
		col[b[i]].push_back(i);
	}
	while(q--){
		solve();
		printf("\n");
	}
	return 0;
}
