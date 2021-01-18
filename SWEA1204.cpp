//SW Expert Academy 1204. 최빈수 구하기

#include <iostream>

using namespace std;

int arr[101];

int GetMode(){
    int mode = 0;
    for(int k=1; k<101; k++){ if(arr[k]>=arr[mode]) mode = k; }
    return mode;
}

int main(){
    int T, t;
    std::cin>>T;
    for(int test_case=1; test_case<=T; test_case++){
    	std::cin>>t;
        for(int i=0; i<101; i++) arr[i] = 0;
        int score;
        for(int j=0; j<1000; j++){ std::cin>>score; (arr[score])++; }
        std::cout<<'#'<<t<<' '<<GetMode()<<std::endl;
    }
    return 0;
}