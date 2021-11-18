#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e;
int main(){
	int n, q, w, x, y, z;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> q >> w >> x >> y >> z;
		a += q;
		b += w;
		c += x;
		d += y;
		e += z;
	}
	int split = 0, cnt = 0;
	while(a + b + c + d + e != 0){
		if(a > 0 && split >= 8){
			a--;
			split -= 8;
		}
		else if(b > 0 && split >= 6){
			b--;
			split -= 6;
		}
		else if(c > 0 && split >= 4){
			c--;
			split -= 4;
		}
		else if(d > 0 && split >= 2){
			d--;
			split -= 2;
		}
		else if(e > 0 && split >= 1){
			e--;
			split -= 1;
		}
		else{
			split = 8;
			cnt++;
		}
	}
	cout << cnt;
    return 0;
}
