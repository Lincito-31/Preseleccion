#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int N,t;
ll ev,tot;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> t;
    int arr[N];
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    if(t==1){
        cout << 7;
    }else if(t==2){
        if(arr[0]>arr[1]){
            cout << "Bigger";
        }else if(arr[0]==arr[1]){
            cout << "Equal";
        }else{
            cout << "Smaller";
        }
    }else if(t==3){
        cout << arr[0]+arr[1]+arr[2]-max({arr[0],arr[1],arr[2]})-min({arr[0],arr[1],arr[2]});
    }else if(t==4){
        for(int i=0;i<N;i++){
            tot+=arr[i];
        }
        cout << tot;
    }else if(t==5){
        for(int i=0;i<N;i++){
            if(arr[i]%2==0){
                ev+=arr[i];
            }
        }
        cout << ev;
    }else if(t==6){
        for(int i=0;i<N;i++){
            cout << (char)(arr[i]%26+'a');
        }
    }else{
        int i=0;
        while(true){
            if(arr[i]>=N){
                cout << "Out";
                break;
            }else if(arr[i]==N-1){
                cout << "Done";
                break;
            }else if(arr[i]==-1e9){
                cout << "Cyclic";
                break;
            }
            int ante=i;
            i=arr[i];
            arr[ante]=-1e9;
        }
    }
}