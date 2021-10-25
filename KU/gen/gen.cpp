#include<bits/stdc++.h>
using namespace std;

#include "genlib.h"

int main(int argc, char* argv[]){
	startGen(argv, 1);
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
	int s = atoi(argv[3]);
	cout << 1 << "\n";
	cout << n << " " << m << " "<< s << "\n";
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cout << rand_int(0, 10) << " ";
		}
		cout << "\n";
	}
	return 0;
}
