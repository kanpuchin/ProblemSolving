/*
    SWEA 1928. Base64 Decoder
*/

#include <stdio.h>
#include <bitset>

#define FIRST   0xFF000000

int main(){
    int T;
    int c = 0;
    unsigned int buffer = 0;
    int buf_count = 0;
    int p;

    freopen("input.txt", "r", stdin);

    scanf("%d ", &T);

    for(int tc=1; tc<=T; tc++){
        printf("#%d ", tc);
        scanf("%c", &c);
        while(c != '\n'){
            if(buf_count == 4){
                //버퍼 비움
                --buf_count;
                while(buf_count > 0){
                    p = FIRST & buffer;
                    p = p >> 24;
                    printf("%c", p);
                    buf_count--;
                    buffer = buffer << 8;
                }
            }
            
                //아래쪽 여덟자리만 남겨놓고 비트를 청소해야함
            c = c & 255;
                //c를 아스키 코드에서 base64로 변환해야함
            if(c >= 65 && c <= 90)
                c -= 65;
            else if(c >= 97 && c <= 122)
                c -= 71;
            else if(c >= 48 && c <= 57)
                c += 4;
            else if(c == 43)
                c = 62;
            else if(c == 47)
                c = 63;
            c = c << (32 - (buf_count + 1)*6);
            buffer = c + buffer;
            ++buf_count;
            c = 0;
            
            scanf("%c", &c);
        }

        //마지막에 버퍼 비우기
        while(buf_count > 0){
            p = FIRST & buffer;
            p = p >> 24;
            printf("%c", p);
            buf_count--;
            buffer = buffer << 8;
        }

        printf("\n");
    }

    return 0;
}