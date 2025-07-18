#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,p,a;
bool card_els[100000];
int main(){
    freopen("cardgame.in","r",stdin);
    freopen("cardgame.out","w",stdout);
    cin >> n;
    vector<int> round1(n/2),round2(n/2);
    for(int i=0;i<n/2;i++){
        cin >> a;
        card_els[--a]=true;
        round1[i]=a;
    }
    for(int i=0;i<n/2;i++){
        cin >> a;
        card_els[--a]=true;
        round2[i]=a;
    }
    sort(ALL(round1));
    sort(ALL(round2));
    vector<int> card,fir(n/2),sec(n/2);
    for(int i=0;i<2*n;i++){
        if(!card_els[i]){
            card.push_back(i);
        }
    }
    for(int i=0;i<n/2;i++){
        sec[i]=card[i];
    }
    for(int i=0;i<n/2;i++){
        fir[i]=card[i+n/2];
    }
    int l=n/2-1;
    for(int i=n/2-1;i>=0;i--){
        if(fir[l]>round1[i]){
            p++;
            l--;
        }
    }
    l=0;
    for(int i=0;i<n/2;i++){
        if(sec[l]<round2[i]){
            p++;
            l++;
        }
    }
    cout << p;
}