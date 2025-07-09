#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int a,b,c,d,e,f,side,con;
char companies[]={'A','B','C'};
int main(){
    cin >> a >> b >> c >> d >> e >> f;
    side=max({a,b,c,d,e,f});
    if(a<b){
        swap(a,b);
    }
    if(c<d){
        swap(c,d);
    }
    if(e<f){
        swap(e,f);
    }
    if(a==side){
        con++;
    }
    if(c==side){
        con++;
    }
    if(e==side){
        con++;
    }
    if(con==3){
        if(b+d+f==side){
            cout << side << '\n';
            for(int i=0;i<b;i++){
                for(int j=0;j<side;j++){
                    cout << companies[0];
                }
                cout << '\n';
            }
            for(int i=0;i<d;i++){
                for(int j=0;j<side;j++){
                    cout << companies[1];
                }
                cout << '\n';
            }
            for(int i=0;i<f;i++){
                for(int j=0;j<side;j++){
                    cout << companies[2];
                }
                cout << '\n';
            }
        }else{
            cout << -1;
        }
    }else if(con==1){
        if(c==side){
            swap(companies[0],companies[1]);
            swap(a,c);
            swap(d,b);
        }
        if(e==side){
            swap(companies[0],companies[2]);
            swap(a,e);
            swap(b,f);
        }
        if(b+c==side){
            if(b+e==side){
                if(d+f==side){
                    cout << side << '\n';
                    for(int i=0;i<b;i++){
                        for(int j=0;j<side;j++){
                            cout << companies[0];
                        }
                        cout << '\n';
                    }
                    for(int i=0;i<c;i++){
                        for(int j=0;j<d;j++){
                            cout << companies[1];
                        }
                        for(int j=0;j<f;j++){
                            cout << companies[2];
                        }
                        cout << '\n';
                    }
                    /*
                    b*a
                    c*d / e*f
                    */
                }else{
                    cout << -1;
                }
            }else if(b+f==side){
                if(d+e==side){
                    cout << side << '\n';
                    for(int i=0;i<b;i++){
                        for(int j=0;j<side;j++){
                            cout << companies[0];
                        }
                        cout << '\n';
                    }
                    for(int i=0;i<c;i++){
                        for(int j=0;j<d;j++){
                            cout << companies[1];
                        }
                        for(int j=0;j<e;j++){
                            cout << companies[2];
                        }
                        cout << '\n';
                    }
                    /*
                    b*a
                    c*d / f*e
                    */
                }else{
                    cout << -1;
                }
            }else{
                cout << -1;
            }
        }else if(b+d==side){
            if(b+e==side){
                if(c+f==side){
                    cout << side << '\n';
                    for(int i=0;i<b;i++){
                        for(int j=0;j<side;j++){
                            cout << companies[0];
                        }
                        cout << '\n';
                    }
                    for(int i=0;i<d;i++){
                        for(int j=0;j<c;j++){
                            cout << companies[1];
                        }
                        for(int j=0;j<f;j++){
                            cout << companies[2];
                        }
                        cout << '\n';
                    }
                    /*
                    b*a
                    d*c / e*f
                    */
                }else{
                    cout << -1;
                }
            }else if(b+f==side){
                if(c+e==side){
                    /*
                    b*a
                    d*c / f*e
                    */
                   cout << side << '\n';
                   for(int i=0;i<b;i++){
                        for(int j=0;j<side;j++){
                            cout << companies[0];
                        }
                        cout << '\n';
                    }
                    for(int i=0;i<d;i++){
                        for(int j=0;j<c;j++){
                            cout << companies[1];
                        }
                        for(int j=0;j<e;j++){
                            cout << companies[2];
                        }
                        cout << '\n';
                    }
                }else{
                    cout << -1;
                }
            }else{
                cout << -1;
            }
        }else{
            cout << -1;
        }
    }else{
        cout << -1;
    }
}