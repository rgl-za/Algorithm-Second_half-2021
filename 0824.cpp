//체육복
//처음 생각한 풀이
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> student(n);

    for(int i=0; i<lost.size(); i++){
        for(int j=0; j<reserve.size(); j++){
            if(lost[i]+1 == reserve[j]){
                student.push_back(reserve[j]);
                student.push_back(lost[i]+1);
            }
            else if(lost[i]-1 == reserve[j]){
                student.push_back(reserve[j]);
                student.push_back(lost[i]-1);
            }
        }    
    }

    sort(student.begin(), student.end());
    student.erase(unique(student.begin(),student.end()),student.end());

    for(int i=0; i<student.size(); i++){
        answer++;
    }

    return answer;
}

//최종 풀이
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> students(n,1);

    for(int i=0; i<reserve.size(); i++){
        students[reserve[i]-1]++;
    }
    for(int i=0; i<lost.size(); i++){
        students[lost[i]-1]--;
    }
    for(int i = 0; i < n; i++){
        if(students[i]==0 && students[i-1]==2){
            students[i-1]--;
            students[i]++;
        }
        if(students[i]==0 && students[i+1]==2){
            students[i+1]--;
            students[i]++;
        }
    }
    for(int i=0; i<students.size(); i++){
        if(students[i]>0){
            answer++;
        }
    }
    return answer;
}

//폰켓몬
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums){
    int answer = 0;

    vector<int> mine(nums.size()/2);

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());

    if(nums.size()<=mine.size()){
        //굳이 쓸 필요 없었던 과정
        /*
        for(int i=0; i<nums.size(); i++){
            mine.push_back(nums[i]);
        }
        for(int i=0; i<mine.size(); i++){
            answer++;
        }
        */
        answer=num.size();
    }
    if(nums.size()>mine.size()){
        answer=mine.size();
    }

    return answer;
}

// int main(){
//     vector< int> arr1 = { 3, 1, 2, 3 };
    
//     cout << solution(arr1);
// }

//모의고사
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers){
    vector<int> answer;

    vector<int> num1={1,2,3,4,5};
    vector<int> num2={2,1,2,3,2,4,2,5};
    vector<int> num3={3,3,1,1,2,2,4,4,5,5};

    int score[3]={0};

    for(int i=0; i<answers.size(); i++){
    
        if(answers[i]==num1[i%5])
            score[0]++;
        if(answers[i]==num2[i%8])
            score[1]++;
        if(answers[i]==num3[i%10])
            score[2]++;
    }

    int maximum = max(score[0], max(score[1], score[2]));

    /*
    //score를 배열로 만들어서 생략할 수 있음
    if(maximum == score1)
        answer.push_back(1);
    
    if(maximum == score2)
        answer.push_back(2);
    
    if(maximum == score3)
        answer.push_back(3);
    */
    for(int i=0; i<3; i++){
        if(maximum==score[i])
            answer.push_back(i+1);
    }

    return answer;
}