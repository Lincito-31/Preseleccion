#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
string s1,s2;
int sum1,sum2,nue;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(getline(cin,s1)){
        getline(cin,s2);
        sum1=sum2=0;
        for(int i=0;i<s1.size();i++){
            if('a'<=s1[i] && s1[i]<='z'){
                sum1+=s1[i]-'a'+1;
            }
            if('A'<=s1[i] && s1[i]<='Z'){
                sum1+=s1[i]-'A'+1;
            }
        }
        while(sum1>9){
            nue=0;
            while(sum1>0){
                nue+=sum1%10;
                sum1/=10;
            }
            sum1=nue;
        }
        for(int i=0;i<s2.size();i++){
            if('a'<=s2[i] && s2[i]<='z'){
                sum2+=s2[i]-'a'+1;
            }
            if('A'<=s2[i] && s2[i]<='Z'){
                sum2+=s2[i]-'A'+1;
            }
        }
        while(sum2>9){
            nue=0;
            while(sum2>0){
                nue+=sum2%10;
                sum2/=10;
            }
            sum2=nue;
        }
        cout << fixed << setprecision(2) << (double)min(sum1,sum2)*100/(double)max(sum1,sum2) << " %\n";
    }
}