//가장 큰 정사각형
//처음 시도한 풀이: 접근 자체가 잘못됨

#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board){

    int answer = 0;
    int count1 = 0;
    int count2=0;

    for(int i=0; i<board.size(); i++){
        
        for(int j=0; j<board.size(); j++){
            if(board[i][j] == 1)
                count1++;
            else if(board[j][i] == 1)
                count2++;

        }
    }
    if(count1 == count2)
        answer=count1*count2;


    return answer;
}

//최종
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board){

    int answer = board[0][0];

    for(int i=1; i<board[0].size()){
        for(int j=1; j<board.size(); j++){

            if(board[i][j] == 1){
                board[i][j] = min(board[i][j-1], board[i-1][j]);
                board[i][j] = min(board[i][j], board[i-1][j-1])+1;

                answer= max(answer, board[i][j]);
            }
        }
    }

    return answer*answer;
}


//땅따먹기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector <int>> land){
    int answer=0;

    for(int i =1; i<land.size(); i++){
        for(int j=0; j<4; j++){

            int mx = 0;

            for(int k=0; k<4; k++){
                if(j!=k)    
                    mx=max(mx, land[i-1][k]);
            }
            land[i][j]+=mx;
        }
    }

    for(int i=0; i<4; i++)
        answer = max(answer, land[land.size()-1][i]);

    return answer;
}