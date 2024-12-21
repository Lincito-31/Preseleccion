#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int t,n;
int main(){
    scanf("%d",&t);
    while(t--){
        int cha=0;
        scanf("%d",&n);
        vector<string> nums(n);
        map<string,int> cant;
        for(int i=0;i<n;i++){
            cin >> nums[i];
            cant[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(cant[nums[i]]==1){
                continue;
            }
            cha++;
            cant[nums[i]]--;
            for(int j=0;j<10;j++){
                nums[i][0]=(char)(48+j);
                if(cant[nums[i]]==0){
                    cant[nums[i]]++;
                    break;
                }
            }
        }
        printf("%d\n",cha);
        for(int i=0;i<n;i++){
            cout << nums[i] << "\n";
        }
    }
}