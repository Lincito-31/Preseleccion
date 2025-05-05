/*
ID: simplem2
TASK: transform
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int n;
char mat[10][10],nue[10][10],temp[10][10];
void rotate90(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i][j]=mat[n-j-1][i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=temp[i][j];
        }
    }
}
void reflect(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i][j]=mat[i][n-j-1];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=temp[i][j];
        }
    }
}
bool check(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]!=nue[i][j]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf(" %c",&mat[i][j]);

        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf(" %c",&nue[i][j]);
        }
    }
    rotate90();
    if(check()){
        printf("1\n");
        return 0;
    }
    rotate90();
    if(check()){
        printf("2\n");
        return 0;
    }
    rotate90();
    if(check()){
        printf("3\n");
        return 0;
    }
    rotate90();
    reflect();
    if(check()){
        printf("4\n");
        return 0;
    }
    rotate90();
    if(check()){
        printf("5\n");
        return 0;
    }
    rotate90();
    if(check()){
        printf("5\n");
        return 0;
    }
    rotate90();
    if(check()){
        printf("5\n");
        return 0;
    }
    rotate90();
    reflect();
    if(check()){
        printf("6\n");
        return 0;
    }
    printf("7\n");
}
