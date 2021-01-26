/*  SW Expert Academy: 1244. 최대 상금
    210120: PASS
    210126: cin, cout -> scanf, printf
            Parse 함수 개선
                기존: 여섯 자리 다 받고 0 개수 세서 그만큼 앞으로 당김
                개선: 1의 자리부터 자릿수만큼만 받고 순서 SWAP
                (정수 타입 변수는 Exclusive OR 연산 3번으로 변수끼리 값 바꾸기 가능)
            MaxPrizeMoney 함수 개선
                불필요한 변수 삭제, index로 접근
            변수 d (자릿수 저장) 전역변수로 수정
            미사용 함수(MakeInt) 삭제
            불필요 함수(DigitCheck) 삭제. 바로 SameNumSort 호출
            코드 길이는 줄었지만 메모리와 실행시간은 늘어남
            메모리: 12,552 kb -> 4 ~ 12,548 kb
            실행시간: 6 ms -> 4 ~ 6 ms
            (메모리 할당 상태에 따라 다른듯)
*/

#include <algorithm>
#include <stdio.h>
#define SWAP(a,b) a^=b; b^=a; a^=b;

int arr[6];
int digit[10][10];
int N, d;
int mark[10];
int sameNumFlag;

void Parse(){
    d = 0;
    while(N != 0){
        arr[d++] = N%10; N=N/10;
    }
    for(int i=0; i<d/2; i++){
        SWAP(arr[i], arr[d-1-i]);
    }
}

bool NowIsBest(){   //오름차순으로 정렬해서 뒤에서부터 비교
    int i;
    int tmp[d];
    bool result = true;
    for(i=0; i<d; i++){
        tmp[i] = arr[i];
    }
    std::sort(tmp, tmp+d);      //오름차순 정렬
    for(i=0; i<d; i++){
        if(tmp[d-i-1] != arr[i])
            result = false;
    }
    return result;
}

bool SameNumExist(){
    for(int j=0; j<d; j++){
        if(mark[arr[j]]>1)
            sameNumFlag = 1;
    }
    return true;
}

void SameNumSort(int big){
    int s[10];
    int i, j;
    int count = 0;
    for(i=0; i<10; i++){
        if(digit[big][i])
            count++;
    }
    if(count<2)
        return;
    j=0;
    for(i=0; i<10; i++){
        if(digit[big][i])
            s[j++] = digit[big][i];
    }
    std::sort(s, s+count);  //오름차순 정렬
    i=9; j=0;
    while(i>=0 && j<count){
        if(digit[big][i])
            digit[big][i] = s[j++];
        i--;
    }
    for(i=0; i<10; i++){
        if(digit[big][i])
            arr[digit[big][i]] = i;
    }
}

void MaxPrizeMoney(int times){
    int t = times;  //남은 교환 횟수
    int count = 0;
    int idx = 0;        //정렬해야하는 인덱스
    int max_idx;
    while(count < times){
        if(NowIsBest()==true){
            if(sameNumFlag == 1 || (times-count)%2==0)
                break;
            else { SWAP(arr[d-1], arr[d-2]); break; }
        }
        max_idx = d-1;
        for(int i=d-2; i>=idx; i--){
            if(arr[i] > arr[max_idx])
                max_idx = i;
        }
        if(idx == max_idx){   //바꿀 필요 X
            idx++; continue;
        }
        SWAP(arr[max_idx], arr[idx]);
        digit[arr[idx]][arr[max_idx]] = max_idx;
        idx++; count++;
    }

    for(int i=0; i<10; i++){
        SameNumSort(i);
    }
    return;
}

int main(){
    int T, times;
    freopen("input.txt","r",stdin);
    scanf("%d", &T);
    for(int test_case=1; test_case<=T; test_case++){
        scanf("%d", &N);
        for(int i=0; i<6; i++) arr[i] = 0;
        sameNumFlag = 0;
        for(int i=0; i<10; i++) mark[i] = 0;
        Parse();
        for(int i=0; i<d; i++) mark[arr[i]]++;
        SameNumExist();
        for(int i=0; i<10; i++){ 
            for(int j=0; j<10; j++) digit[i][j] = 0; 
        }
        scanf("%d", &times);
        MaxPrizeMoney(times);
        printf("#%d ", test_case);
        for(int i=0; i<d; i++)
            printf("%d", arr[i]);
        printf("\n");
    }

    return 0;
}