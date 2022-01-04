//크레인 인형뽑기 게임
 #include <iostream>
 #include <vector>
 #include <stack>

 using namespace std;

 int solution(vector<vector<int> > board, vect<int>moves){
     int answer = 0;

     stack<int> pick;

     for(int i=0; i<moves.size(); i++){
         int check = moves[i]-1;
        
         for(int j=0; j<board.size(); j++){
             if(board[j][check] != 0){
                 if(!pick.empty() && pick.top() == board[j][check]){
                     pick.pop();
                     answer += 2;
                 }
                 else
                     pick.push(board[j][check]);
                 board[j][check]=0;
                 break;
             }
         }
     }
 return answer;
 }


//K번째 수
 #include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>
 using namespace std;

 vector<int> solution(vector<int> array, vector<vector<int>> commands) {
     vector<int> answer;

     for(int i=0; i<commands.size(); i++){
         vector<int> pick;

         for(int j=commands[i][0]-1; j<commands[i][1]; j++)
             pick.push_back(array[j]);

         sort(pick.begin(), pick.end());

         answer.push_back(pick.at(commands[i][2]-1));
     }
 return answer;
 }


