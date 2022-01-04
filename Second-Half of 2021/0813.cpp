
//땅 따먹기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector <int>> land){
    int answer=0, max=0;

    for(int i =1; i<land.size(); i++){
        for(int j=0; j<4; j++){

            max = 0;

            for(int k=0; k<4; k++){
                if(j!=k)    
                    max=max(max, land[i-1][k]);
            }
            land[i][j]+=max;
        }
    }

    for(int i=0; i<4; i++)
        answer = max(answer, land[land.size()-1][i]);

    return answer;
}


/*
// 처음 시도한 방법
#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pcnt = 0, Pcnt = 0, ycnt = 0, Ycnt = 0, input=0;

    for(int i=0; i<s.size(); i++){
        if(s[i] == 80)
            Pcnt++;
        else if(s[i] == 112)
            pcnt++;
        else if(s[i] == 89)
            Ycnt++;
        else if(s[i] == 121)
            ycnt++;
    }

    if((pcnt == ycnt) || (Pcnt == Ycnt))
        answer = true;
    
    else if((pcnt != ycnt) || (Pcnt != Ycnt))
        answer = false;
    
    else 
        answer = true;

    return answer;
}
*/



#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int Pcnt = 0, Ycnt = 0;

    for(int i=0; i<s.size(); i++){
        if(s[i] == 80 || s[i] == 112)
            Pcnt++;
        else if(s[i] == 89 || s[i] == 121)
            Ycnt++;
    }
    
    if(Pcnt == Ycnt)
        answer = true;
    
    else 
        answer = false;

    return answer;
}

int main(){
    string s;

    cin >> s;

    cout << solution(s);
}
