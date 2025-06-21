#include <bits/stdc++.h>
using namespace std;
int a[3],x,n,y;
stack<int> st;
        queue<int> q;
        priority_queue<int> pq;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> n){
        while(!st.empty()){
            st.pop();
        }
        while(!q.empty()){
            q.pop();
        }
        while(!pq.empty()){
            pq.pop();
        }
        a[0]=a[1]=a[2]=1;
        while(n--){
            cin >> x >> y;
            if(x==1){
                if(a[0]){
                    st.push(y);
                }
                if(a[1]){
                    q.push(y);
                }
                if(a[2]){
                    pq.push(y);
                }
            }else{
                if(!st.empty()){
                    if(st.top()!=y){
                        a[0]=0;
                    }
                    st.pop();
                }else{
                    a[0]=0;
                }
                if(!q.empty()){
                    if(q.front()!=y){
                        a[1]=0;
                    }
                    q.pop();
                }else{
                    a[1]=0;
                }
                if(!pq.empty()){
                    if(pq.top()!=y){
                        a[2]=0;
                    }
                    pq.pop();
                }else{
                    a[2]=0;
                }
            }
        }
        if(a[0]+a[1]+a[2]==0){
            cout << "impossible\n";
        }else if(a[0]+a[1]+a[2]>=2){
            cout << "not sure\n";
        }else if(a[0]){
            cout << "stack\n";
        }else if(a[1]){
            cout << "queue\n";
        }else{
            cout << "priority queue\n";
        }
    }
}