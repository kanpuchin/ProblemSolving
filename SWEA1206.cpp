/*  SW Expert Academy: 1206
    210116: PASS
    210125: 함수 삭제, for문 내 알고리즘 삽입
            STL max 함수 대신 MAX 매크로 정의해서 사용
            =>  메모리 12,540 kb -> 12,544 kb
                실행시간 30 ms -> 8 ms
*/

#include <iostream>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main(){
    int arr[1000] = {0,};
    int length;
    freopen("input.txt","r",stdin);
    for(int i=1; i<=10; i++){
        std::cin>>length;
        for(int j=0; j<length; j++)
            std::cin>>arr[j];
        int view = 0;
        int cmp, clear;
        for(int i=2; i<length-2; i++){
            cmp = MAX(MAX(arr[i-2],arr[i-1]),MAX(arr[i+1],arr[i+2]));
            clear = arr[i] - cmp;
            if(clear <= 0)
                continue;
            view += clear;
        }
        printf("#%d %d\n", i, view);
    }
    return 0;
}