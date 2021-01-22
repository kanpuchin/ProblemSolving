// SW Expert Academy 1249. 보급로

#include <iostream>
#include <queue>

using namespace std;

int map[100][100];
int costInfo[100][100];
int N;
int move_r[4] = {-1,1,0,0};
int move_c[4] = {0,0,-1,1};
//[0]=상, [1]=하, [2]=좌, [3]=우

queue<pair<int,int>> q; //first=row, second=col
queue<pair<int,int>> bq;

void Enqueue(pair<int,int> current, pair<int,int> next){
    if(next.first<0 || next.second<0 || next.first>N-1 || next.second>N-1)
        return;
    else if(costInfo[current.first][current.second] + map[next.first][next.second]
            >= costInfo[next.first][next.second])
        return;
    q.push(next);
}

void GetMinTime(){
    int i;
    bq.push(make_pair(0,0));
    pair<int,int> before;
    pair<int,int> now;
    while(!bq.empty()){
        before = bq.front(); bq.pop();
        for(i=0; i<4; i++)
            Enqueue(before, make_pair(before.first+move_r[i],before.second+move_c[i]));
        while(!q.empty()){
            now = q.front(); q.pop();
            if(costInfo[before.first][before.second] + map[now.first][now.second]
                < costInfo[now.first][now.second]){
                costInfo[now.first][now.second]
                   = costInfo[before.first][before.second] + map[now.first][now.second];
            }
            bq.push(now);
        }
    }
}

int main(){
    int T;
    std::cin>>T;

    for(int test_case=1; test_case<=T; test_case++){
        std::cin>>N;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++)
                scanf("%1d", &map[i][j]);
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++)
                costInfo[i][j] = 9999;
        }
        costInfo[0][0] = 0;
        GetMinTime();
        printf("#%d %d \n", test_case, costInfo[N-1][N-1]);
    }

    return 0;
}