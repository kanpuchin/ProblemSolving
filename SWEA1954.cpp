// SW Expert Academy 1954. 달팽이 숫자

#include <iostream>
#include <string.h>

enum Direction { RIGHT, LEFT, DOWN, UP };

int arr[10][10];
int N;

void PrintOutArray(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            std::cout<<arr[i][j]<<' ';
        std::cout<<std::endl;
    }
}

Direction ChangeDirect(int r, int c, Direction d){
    switch(d){
        case RIGHT: if(c+1 >= N || arr[r][c+1] != 0) d = DOWN; break;
        case LEFT: if(c-1 < 0 || arr[r][c-1] != 0) d = UP; break;
        case DOWN: if(r+1 >= N || arr[r+1][c] != 0) d = LEFT; break;
        case UP: if(r-1 < 0 || arr[r-1][c] != 0) d = RIGHT; break;
        default: break;
    }
    return d;
}

void MakeSnailNum(){
    int r = 0;
    int c = 0;
    int num = 1;
    Direction direct = RIGHT;
    while(num <= N*N){
        arr[r][c] = num;
        direct = ChangeDirect(r, c, direct);
        switch(direct){
            case RIGHT: c++; break;
            case LEFT:  c--; break;
            case DOWN:  r++; break;
            case UP:    r--; break;
        }
        num++;
    }
}

int main(){
    int T;
    freopen("input.txt","r",stdin);
    std::cin>>T;
    for(int test_case=1; test_case<=T; test_case++){
        std::cin>>N;
        for(int i=0; i<N; i++) memset(arr[i], 0, sizeof(int)*10);
        MakeSnailNum();
        std::cout<<'#'<<test_case<<std::endl;
        PrintOutArray();
    }
    return 0;
}