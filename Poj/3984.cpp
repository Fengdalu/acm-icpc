#include <iostream>
#include <string.h>
using namespace std;
int map[5][5];
int state[5][5];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void dfs(int x,int y){
    int xx,yy;
    state[x][y]=1;
    if(x==4 && y==4) return; //跳出一层递归
    for(int i=0;i<4;i++){
        xx=x+dir[i][0];
        yy=y+dir[i][1];
        if(xx>=0 && xx<5 && yy>=0 && yy<5 && map[xx][yy]==0 && state[xx][yy]==0){
            dfs(xx,yy);
            return ;//跳出一层递归
        }
    }
}
void pdfs(int x,int y){
    int xx,yy;
    printf("(%d, %d)\n",x,y);
    if(x==4 && y==4) return ;//跳出一层递归
    for(int i=0;i<4;i++){
        xx=x+dir[i][0];
        yy=y+dir[i][1];
        if(xx>=0 && xx<5 && yy>=0 && yy<5 && state[xx][yy]==1){
            pdfs(xx,yy);
            return ; //跳出一层递归
        }
    }
}
int main(){
    memset(state,0,sizeof(state));
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            scanf("%d",&map[i][j]);
    dfs(0,0);
    pdfs(0,0);
    return 0;
}