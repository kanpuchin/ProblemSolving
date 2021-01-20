// SW Expert Academy: 1244. 최대 상금

#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>

int arr[6];
int digit[10][10];
int N;
int mark[10];
int sameNumFlag;

int Parse(int N){
    int i;
    for(i=0; i<6; i++){
        arr[i] = (int)(N/pow(10,6-i-1))%10;
    }
    int zero = 0;
    i = 0;
    while(arr[i++] == 0){
        zero++;
    }
    if(zero != 0){
        for(i=zero; i<6; i++){
            arr[i-zero] = arr[i];
            arr[i] = 0;
        }
    }
    if(N>99999)     return 6;
    else if(N>9999) return 5;
    else if(N>999)  return 4;
    else if(N>99)   return 3;
    else if(N>9)    return 2;
    else            return 1;
}

bool NowIsBest(int d){
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

bool SameNumExist(int d){
    for(int j=0; j<d; j++){
        if(mark[arr[j]]>1)
            sameNumFlag = 1;
    }
    return true;
}

int MakeInt(int d){
    int n = 0;
    for(int i=0; i<d; i++){
        n += arr[i]*pow(10,d-i-1);
    }
    return n;
}

void SameNumSort(int big){
    int s[10];
    int i, j;
    int count = 0;
    for(i=0; i<10; i++){
        if(digit[big][i]>0)
            count++;
    }
    if(count<2)
        return;
    j=0;
    for(i=0; i<10; i++){
        if(digit[big][i]>0)
            s[j++] = digit[big][i];
    }
    std::sort(s, s+count);  //오름차순 정렬
    i=9; j=0;
    while(i>=0 && j<count){
        if(digit[big][i]>0){
            digit[big][i] = s[j++];
        }
        i--;
    }
    for(i=0; i<10; i++){
        if(digit[big][i]){
            arr[digit[big][i]] = i;
        }
    }
}

void DigitCheck(int d){
    int before;
    for(int i=0; i<10; i++){
        SameNumSort(i);
    }
}

void MaxPrizeMoney(int times, int d){
    int t = times;  //교환 횟수 역카운트
    int count = 0;
    int idx = 0;        //정렬된 자리 기록
    int max, max_idx;
    int change, change_idx;
    while(count < times){
        if(NowIsBest(d)==true){
            if(sameNumFlag == 1 || (times-count)%2==0){
                break;
            }
            else {
                int tmp = arr[d-1];
                arr[d-1] = arr[d-2]; 
                arr[d-2] = tmp;
                break;
            }
        }
        max = arr[d-1];
        max_idx = d-1;
        for(int i=d-2; i>=idx; i--){
            if(arr[i] > max) {
                max_idx = i;
                max = arr[i];
            }
        }
        change_idx = idx++;
        if(change_idx == max_idx){
            continue;
        }
        change = arr[change_idx];
        
        arr[change_idx] = max;
        arr[max_idx] = change;

        digit[max][change] = max_idx;

        count++;
    }

    DigitCheck(d);
    return;
}

int main(){
    int T, times, d;

 //   freopen("input.txt","r",stdin);

    std::cin>>T;

    for(int test_case=1; test_case<=T; test_case++){
        std::cin>>N;

        for(int i=0; i<6; i++) arr[i] = 0;
        sameNumFlag = 0;
        for(int i=0; i<10; i++) mark[i] = 0;
        d = Parse(N);
        for(int i=0; i<d; i++) mark[arr[i]]++;
        SameNumExist(d);

        for(int i=0; i<10; i++){ 
            for(int j=0; j<10; j++) digit[i][j] = 0; 
        }

        std::cin>>times;
        MaxPrizeMoney(times, d);
        std::cout<<'#'<<test_case<<' ';
        for(int i=0; i<d; i++)
            std::cout<<arr[i];
        std::cout<<std::endl;
    }

    return 0;
}