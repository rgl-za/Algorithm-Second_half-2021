//내적
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    for(int i = 0; i < a.size(); i++) {
        answer += (a[i] * b[i]);
    }
    return answer;
}


//음양 더하기
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs){

    int answer = 0;

    for(int i=0; i<absolutes.size(); i++){

        if(signs[i]==true)
            answer+=absolutes[i];
        
        else
            answer-=absolutes[i];
    }
    return answer;
}


//행렬의 덧셈
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int> > answer;

    for(int i=0; i<arr1.size(); i++){
        for(int j=0; j<arr1[i].size(); j++){
           arr1[i][J]+=arr2[i][j];
           //answer+=arr1[i][j]+arr2[i][j];
           //answer.push_back(arr1[i][j]+arr2[i][j]);
           
        }
    }
    
    return arr1;
    //return answer;
}
