#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k; cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int tmp=0,m=-1001,d=0;
	for(int i=0;i<n;i++){
		if(tmp+a[i]>=0) {tmp+=a[i]; d++;}
		else {tmp=0; d=0;}
		if(d>=k) m=max(m,tmp);
	}
	cout<<m;
	return 0;
}