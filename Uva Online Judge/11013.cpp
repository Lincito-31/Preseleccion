#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
string a[5];
int val[5],canti,resp=-1;
vector<int> contador;
char arr[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int checkvalue(){
    while(contador[0]&&contador[12]){
        int temp=contador[12];
        for(int i=12;i>0;i--){
            contador[i]=contador[i-1];
        }
        contador[0]=temp;
        canti++;
    }
    int maxi=0;
    vector<int> ressss;
    for(int i=0;i<13;i++){
        if(contador[i]>0){
            maxi++;
            contador[i]--;
        }else{
            if(maxi>0){
                ressss.push_back(maxi);
                maxi=0;
            }
        }
    }
    if(maxi>0){
        ressss.push_back(maxi);
        maxi=0;
    }
    for(int i=0;i<13;i++){
        if(contador[i]>0){
            maxi++;
            contador[i]--;
        }else{
            if(maxi>0){
                ressss.push_back(maxi);
                maxi=0;
            }
        }
    }
    if(maxi>0){
        ressss.push_back(maxi);
        maxi=0;
    }
    for(int i=0;i<13;i++){
        if(contador[i]>0){
            maxi++;
            contador[i]--;
        }else{
            if(maxi>0){
                ressss.push_back(maxi);
                maxi=0;
            }
        }
    }
    if(maxi>0){
        ressss.push_back(maxi);
        maxi=0;
    }
    for(int i=0;i<13;i++){
        if(contador[i]>0){
            maxi++;
            contador[i]--;
        }else{
            if(maxi>0){
                ressss.push_back(maxi);
                maxi=0;
            }
        }
    }
    if(maxi>0){
        ressss.push_back(maxi);
        maxi=0;
    }
    for(int i=0;i<13;i++){
        if(contador[i]>0){
            maxi++;
            contador[i]--;
        }else{
            if(maxi>0){
                ressss.push_back(maxi);
                maxi=0;
            }
        }
    }
    if(maxi>0){
        ressss.push_back(maxi);
        maxi=0;
    }
    if(ressss.size()==1){
        return 100;
    }else if(max(ressss[0],ressss[1])==4){
        return 10;
    }else if(max(ressss[0],ressss[1])==3 && min(ressss[0],ressss[1])==2){
        return 5;
    }else if(max({ressss[0],ressss[1],ressss[2]})==3){
        return 3;
    }else if(max({ressss[0],ressss[1],ressss[2]})==2 && ressss.size()==3){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4]){
        resp=-1;
        canti=0;
        contador.assign(13,0);
        for(int i=0;i<5;i++){
            if(a[i][0]>='2' && a[i][0]<='9'){
                val[i]=a[i][0]-'0'-1;
                
            }else if(a[i][0]=='A'){
                val[i]=0;
            }else if(a[i][0]=='J'){
                val[i]=10;
            }else if(a[i][0]=='T'){
                val[i]=9;
            }else if(a[i][0]=='Q'){
                val[i]=11;
            }else{
                val[i]=12;
            }
            contador[val[i]]++;
        }
        vector<int> cop(contador);
        int now=checkvalue()-1;
        now*=47;
        int suma=0;
        for(int i=0;i<13;i++){
            if(cop[i]>0){
                suma=-94;
                for(int j=0;j<13;j++){
                    contador=cop;
                    contador[i]--; 
                    contador[j]++;
                    suma+=checkvalue()*(4-cop[j]);
                }
                if(suma>now){
                    now=suma;
                    resp=i;
                }
            }
        }
        if(resp==-1){
            cout << "Stay\n";
        }else{
            for(int i=0;i<5;i++){
                if(a[i][0]==arr[resp]){
                    cout << "Exchange " << a[i] << '\n';
                    break;
                }
            }
        }
    }
}