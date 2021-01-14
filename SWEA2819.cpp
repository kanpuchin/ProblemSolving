// SW Expert Academy: Problem no.2819 격자판의 숫자 이어붙이기

#include <iostream>

using namespace std;

int grid[4][4];
int arr[10000000];
int n = 0;
int T;

void MoveSixTime(int num, int r, int c, int times);

int NumofNumber(){
    int number = 0;
    for(int r=0; r<4; r++){
        for(int c=0; c<4; c++)
            MoveSixTime(number, r, c, 0);
    }

    return n;
}

void MoveSixTime(int num, int r, int c, int times){
    if(times > 6){
        if(arr[num] != T){
            arr[num] = T;
            n++;
        }
        
        return;
    }
    
    //상
    if(r>0)
        MoveSixTime((num * 10) + grid[r-1][c], r-1, c, times+1);

    //하
    if(r<3)
        MoveSixTime((num * 10) + grid[r+1][c], r+1, c, times+1);

    //좌
    if(c>0)
        MoveSixTime((num * 10) + grid[r][c-1], r, c-1, times+1);

    //우
    if(c<3)
        MoveSixTime((num * 10) + grid[r][c+1], r, c+1, times+1);
}

int main(int argc, char** argv)
{
	int test_case;
    int t;
	std::cin>>t;

	for(T = 1; T <= t; ++T)
	{
        for(int i=0; i<4; i++){     //격자판 입력
            for(int j=0; j<4; j++){
                cin >> grid[i][j];
            }
        }

        n = 0;

		std::cout<<"#"<<T<<" "<<NumofNumber()<<std::endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}