#include <bits/stdc++.h>
using namespace std;
string s;
bool xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(getline(cin, s)){
        if(xd){
            cout << '\n';
        }
        xd=true;
        string nue="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                continue;
            }
            nue.push_back(s[i]);
        }
        s=nue;
        nue="";
        bool lol=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='+' || s[i]=='*' || s[i]=='/' || s[i]=='-'){
                if(lol){
                    nue.push_back(s[i]);
                    lol=false;
                }else{
                    if(s[i]=='-'){
                        nue.push_back(s[i]);
                    }
                }
            }else{
                lol=true;
                nue.push_back(s[i]);
            }
        }
        s=nue;
        nue="";
        // */
        lol=false;
        int a=-1000000;
        bool nega=false;
        vector<int> nums;
        for(int i=0;i<s.size();i++){
            if(!lol && s[i]=='-'){
                nega=true;
            }else if(s[i]>='0' && s[i]<='9'){
                if(a==-1000000){
                    a=0;
                }
                lol=true;
                a*=10;
                a+=s[i]-48;
            }else{
                if(nega){
                    nega=false;
                    a*=-1;
                }
                if(a!=-1000000){
                    nums.push_back(a);
                }
                a=-1000000;
                lol=false;
                nue.push_back(s[i]);
            }
        }
        s=nue;
        nue="";
        lol=false;
        while(nums.size()>1){
            lol=false;
            for(int i=0;i<nums.size();i++){
                cout << nums[i] << ' ' << s[i] << ' ';
            }
            for(int i=nums.size();i<s.size();i++){
                cout << s[i];
            }
            cout << '\n';
            for(int i=0;i<s.size();i++){
                if(s[i]=='*' || s[i]=='/'){
                    if(s[i]=='*'){
                        nums[i]*=nums[i+1];
                    }else{
                        nums[i]/=nums[i+1];
                    }
                    nums.erase(nums.begin()+i+1);
                    s.erase(s.begin()+i);
                    lol=true;
                    break;
                }
            }
            if(lol){
                continue;
            }
            for(int i=0;i<s.size();i++){
                if(s[i]=='+' || s[i]=='-'){
                    if(s[i]=='+'){
                        nums[i]+=nums[i+1];
                    }else{
                        nums[i]-=nums[i+1];
                    }
                    nums.erase(nums.begin()+i+1);
                    s.erase(s.begin()+i);
                    lol=true;
                    break;
                }
            }
        }
        for(int i=0;i<nums.size();i++){
            cout << nums[i] << ' ' << s[i] << ' ';
        }
        for(int i=nums.size();i<s.size();i++){
            cout << s[i];
        }
        cout << '\n';
    }
}