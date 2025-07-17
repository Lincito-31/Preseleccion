#include <bits/stdc++.h>
using namespace std;
int n,a;
double prob[1000000],sum,prod=1,maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ifstream fin("cowdate.in");
    ofstream fout("cowdate.out");
    fin >> n;
    for(int i=0;i<n;i++){
        fin >> a;
        prob[i]=(double)a*0.000001;
    }
    int l=0,r=0;
    while(r<n){
        if(r<n && sum<1){
            sum+=prob[r]/(1-prob[r]);
            prod*=1-prob[r];
            r++;
        }else{
            sum-=prob[l]/(1-prob[l]);
            prod/=1-prob[l];
            l++;
        }
        //cout << sum << '\n';
        maxi=max(maxi,prod*sum);
    }
    fout << (int)(maxi*1000000);
}