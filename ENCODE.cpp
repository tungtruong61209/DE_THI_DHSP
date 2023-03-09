#include <bits/stdc++.h>
using namespace std;

vector<int> fib;
void precompute_fibonacci(int limit) {
    while (fib.back()<=limit) fib.push_back(fib.back()+fib[fib.size()-2]);
}
int main() {
    fib.push_back(0);
    fib.push_back(1);
    int t; cin>>t;
    int Max=1;
    while (t--) {
        int n; cin>>n;
        if(n>Max) {precompute_fibonacci(n); Max=n;}
        int d=0;
        for(int i=fib.size()-1;i>0&&n>0;i--){
            if(fib[i]<=n){
                d++;
                n-=fib[i];
            }
        }
        cout<<d<<endl;
    }
    return 0;
}