//SW Expert Academy: 1206

#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];
int length;

int GetView(){
    int view = 0;
    int cmp, clear;
    for(int i=2; i<length-2; i++){
        cmp = max(max(arr[i-2],arr[i-1]),max(arr[i+1],arr[i+2]));
        clear = arr[i] - cmp;
        if(clear < 0)
            continue;
        else 
            view += clear;
    }
    return view;
}

int main(){
    freopen("input.txt","r",stdin);
    for(int i=1; i<=10; i++){
        std::cin>>length;
        for(int j=0; j<length; j++)
            std::cin>>arr[j];
        std::cout<<'#'<<i<<' '<<GetView()<<std::endl;
    }
    return 0;
}