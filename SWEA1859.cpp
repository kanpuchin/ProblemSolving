//SW Expert Academy: 1859. 백만 장자 프로젝트

#include <iostream>

using namespace std;

int* arr;
int N;

int GetMaxIdx(int start_idx){
    int max = start_idx;
    for(int i=start_idx+1; i<N; i++){
        if(arr[i]>arr[max]) max = i;
    }
    return max;
}

long long GetProfit(int start_idx, int max_idx){
    long long spend = 0;
    for(int i=start_idx; i<max_idx; i++)
        spend += (long long)arr[i];
    if(max_idx < N-1){
        return (long long)arr[max_idx]*(max_idx-start_idx) - spend
                + GetProfit(max_idx+1, GetMaxIdx(max_idx+1));
    }
    else if(max_idx == N-1)
        return (long long)arr[max_idx]*(max_idx-start_idx) - spend;
}

int main(int argc, char** argv){
    int T;
    std::cin>>T;
    for(int i=1; i<=T; i++){
        std::cin>>N;
        arr = new int[N];
        for(int j=0; j<N; j++) std::cin>>arr[j];
        std::cout<<'#'<<i<<' '<<GetProfit(0,GetMaxIdx(0))<<std::endl;
        delete arr;
    }
    return 0;
}