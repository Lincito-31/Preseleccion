#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int t,n;
ll k,sum,maxi;
string st;
bool xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        maxi=sum=xd=0;
        cin >> n >> k;
        vll nums(n),psum(n,0),ssum(n,0),res(n,0);
        cin >> st;
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        for(int i=0;i<n;i++){
            if(st[i]=='0'){
                sum=0;
            }else{
                sum=max(nums[i],sum+nums[i]);
            }
            maxi=max(maxi,sum);
        }
        if(maxi>k){
            cout << "No\n";
            continue;
        }else if(maxi==k){
            cout << "Yes\n";
            for(int i=0;i<n;i++){
                if(st[i]=='0'){
                    nums[i]=-1e18;
                }
                cout << nums[i] << ' ';
            }
            cout << '\n';
            continue;
        }
        psum[0]=nums[0];
        for(int i=1;i<n;i++){
            if(st[i]=='1'){
                psum[i]=psum[i-1]+nums[i];
            }
        }
        ssum[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(st[i]=='1'){
                ssum[i]=ssum[i+1]+nums[i];
            }
        }
        for(int i=0;i<n;i++){
            if(st[i]=='0'){
                ll iz,de;
                maxi=0;
                for(int j=i+1;j<n;j++){
                    if(st[j]=='0'){
                        res[i]+=maxi;
                        iz=maxi;
                        maxi=0;
                        break;
                    }else{
                        maxi=max(maxi,psum[j]);
                    }
                }
                if(maxi>0){
                    res[i]+=maxi;
                    iz=maxi;
                    maxi=0;
                }
                for(int j=i-1;j>=0;j--){
                    if(st[j]=='0'){
                        res[i]+=maxi;
                        de=maxi;
                        maxi=0;
                        break;
                    }else{
                        maxi=max(maxi,ssum[j]);
                    }
                }
                if(maxi>0){
                    res[i]+=maxi;
                    de=maxi;
                    maxi=0;
                }
                if(iz&&de || res[i]<=k){
                    st[i]='1';
                    nums[i]=k-res[i];
                    xd=true;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(st[i]=='0'){
                nums[i]=-1e18;
            }
        }
        if(xd){
            cout << "Yes\n";
            for(int i=0;i<n;i++){
                cout << nums[i] << ' ';
            }
            cout << '\n';
        }else{
            cout << "No\n";
        }
    }
}