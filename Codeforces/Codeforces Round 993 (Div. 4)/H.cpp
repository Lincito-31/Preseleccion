#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,q,dd,ss,aa,bb,a;
ll iM[2005][2005],M[2005][2005],jM[2005][2005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> q;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> a;
                M[i][j]=M[i][j-1]+a;
                iM[i][j]=iM[i][j-1]+j*a;
                jM[i][j]=jM[i-1][j]+i*a;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                M[i][j]+=M[i-1][j];
                iM[i][j]+=iM[i-1][j];
                jM[i][j]+=jM[i][j-1];
            }
        }
        while(q--){
            cin >> dd >> aa >> ss >> bb;
            ll res=M[ss][bb]-M[dd-1][bb]-M[ss][aa-1]+M[dd-1][aa-1];
            ll temp=jM[ss][bb]-jM[dd-1][bb]-jM[ss][aa-1]+jM[dd-1][aa-1]-(dd-1)*res;
            ll temp2=iM[ss][bb]-iM[dd-1][bb]-iM[ss][aa-1]+iM[dd-1][aa-1]-(aa-1)*res;
            ll fin=(bb-aa+1)*(temp-res)+temp2;
            cout << fin << " ";
        }
        cout << "\n";
    }
}