#include "dna.h"
#include<bits/stdc++.h>
using namespace std;

const int MxN = 1e5 + 10;
int ac[MxN], at[MxN], ct[MxN], ca[MxN], ta[MxN], tc[MxN];

void init(string a, string b){
	for(int i=1; i<=a.size(); ++i){
		ac[i] = ac[i-1] + (a[i-1] == 'A' && b[i-1] == 'C');
		at[i] = at[i-1] + (a[i-1] == 'A' && b[i-1] == 'T');
		ct[i] = ct[i-1] + (a[i-1] == 'C' && b[i-1] == 'T');
		ca[i] = ca[i-1] + (a[i-1] == 'C' && b[i-1] == 'A');
		ta[i] = ta[i-1] + (a[i-1] == 'T' && b[i-1] == 'A');
		tc[i] = tc[i-1] + (a[i-1] == 'T' && b[i-1] == 'C');
	}
	return ;
}

int get_distance(int l, int r){
	int AC = ac[r + 1] - ac[l];
	int AT = at[r + 1] - at[l];
	int CA = ca[r + 1] - ca[l];
	int CT = ct[r + 1] - ct[l];
	int TA = ta[r + 1] - ta[l];
	int TC = tc[r + 1] - tc[l];
	int ans = 0, nin;
	// AC
	nin = min(AC, CA);
	ans += nin;
	AC -= nin, CA -= nin;
	
	// AT
	nin = min(TA, AT);
	ans += nin;
	AT -= nin, TA -= nin;
	
	// CT
	nin = min(CT, TC);
	ans += nin;
	CT -= nin, TC -= nin;
	
	if(AT + TA + AC + CA + CT + TC == 0){
		return ans;
	}
	if(TC != 0 && CA != 0 && AT != 0){
		if(TC != CA || CA != AT){
			return -1;
		}
		else{
			return ans + 2 * TC;
		}
	}
	if(CT != 0 && TA != 0 && AC != 0){
		if(CT != AC || AC != TA){
			return -1;
		}
		else{
			return ans + 2 * CT;
		}
	}
	return -1;
}
