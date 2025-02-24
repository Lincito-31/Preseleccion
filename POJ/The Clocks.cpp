#include <iostream>
#include <vector>
using namespace std;
int nums[3][3];
vector<int> res;
vector<int> temp;
bool xd=true;
void operar(int x){
    switch (x)
    {
    case 1:
        nums[0][0]++;
        nums[0][1]++;
        nums[1][0]++;
        nums[1][1]++;
        break;
    case 2:
        nums[0][0]++;
        nums[0][1]++;
        nums[0][2]++;
        break;
    case 3:
        nums[0][1]++;
        nums[0][2]++;
        nums[1][1]++;
        nums[1][2]++;
        break;
    case 4:
        nums[0][0]++;
        nums[1][0]++;
        nums[2][0]++;
        break;
    case 5:
        nums[0][1]++;
        nums[1][0]++;
        nums[1][2]++;
        nums[2][1]++;
        nums[1][1]++;
        break;
    case 6:
        nums[0][2]++;
        nums[1][2]++;
        nums[2][2]++;
        break;
    case 7:
        nums[2][0]++;
        nums[2][1]++;
        nums[1][0]++;
        nums[1][1]++;
        break;
    case 8:
        nums[2][0]++;
        nums[2][1]++;
        nums[2][2]++;
        break;
    default:
        nums[2][2]++;
        nums[2][1]++;
        nums[1][2]++;
        nums[1][1]++;
        break;
    }
}

void solve(int op,int canti){
    if(op==9){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(nums[i][j]%4!=0){
                    return;
                }
            }
        }
        if(xd){
            res=temp;
            xd=false;
        }else{
            if(res.size()>temp.size()){
                res=temp;
            }
        }
        return;
    }
    solve(op+1,0);
    if(canti<3){
        operar(op+1);
        temp.push_back(op+1);
        solve(op,canti+1);
        temp.pop_back();
        operar(op+1);
        operar(op+1);
        operar(op+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> nums[i][j];
        }
    }
    solve(0,0);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}