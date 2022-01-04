
//키패드 누르기
//내가 생각한 풀이... 왜 아무도 스택으로 안풀죠?
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(vector<int> numbers, string hand){

    string answer="";

    stack<int> left;
    stack<int> right;

    vector<int>l={1,4,7};
    vector<int>r={3,6,9};

    for(int i=0; i<numbers.size(); i++){

    }


    for(int i=0; i<numbers.size(); i++){
        //for(int j=0; j<3; j++)
            if(numbers[i]=l[i]){
                left.push(i);
                answer+="L";
            }
            else if(numbers[i]=r[i]){
                right.push(i);
                answer+="R";
            }
            else if(numbers[i]!=l[i] && numbers[i]!=r[i]){
                if(numbers[i]-left.top()>numbers[i]-right.top()){
                    right.push(i);
                    answer+="R";
                }
                else if(numbers[i]-left.top()<numbers[i]-right.top()){
                    left.push(i);
                    answer+="L";
                }
                else if(numbers[i]-left.top()==numbers[i]-right.top()){
                    if(hand=="right"){
                        right.push(i);
                        answer+="R";
                    }
                    else{
                        left.push(i);
                        answer+="L";
                    }
                }
            }
        }

    return answer;

}


//참고한 풀이
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftHand = 10, rightHand = 12, leftDist = 0, rightDist = 0;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer += "L";
            leftHand = numbers[i];
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer += "R";
            rightHand = numbers[i];
        }
        else
        {
            if(numbers[i] == 0)
                numbers[i] = 11;
            int tmp_l = abs(leftHand - numbers[i]);
            int tmp_r = abs(rightHand - numbers[i]);
            
            leftDist = (tmp_l / 3) + (tmp_l % 3);
            rightDist = (tmp_r / 3) + (tmp_r % 3);
            
            if(leftDist == rightDist)
            {
                if(hand == "right")
                {
                    answer += "R";
                    rightHand = numbers[i];
                }
                else
                {
                    answer += "L";
                    leftHand = numbers[i];
                }
            }
            else if(leftDist < rightDist)
            {
                answer += "L";
                leftHand = numbers[i];
            }
            else
            {
                answer += "R";
                rightHand = numbers[i];
            }
        }
    }
    return answer;
}



//소수찾기: 유클리드 호제법 사용
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v(n+1);
  
    for(int i=2; i<v.size(); i++)
        v[i]=i;
    
    for(int i=2; i<=n; i++){
        if(v[i] == 0)
            continue;
        
        for(int j= i*2; j<=n; j=j+i){
            v[j]=0;
        }
    }

    for(int i=2; i<=n; i++){
        if(v[i] != 0)
            answer++;
    }
    
    return answer;
}

int main(){

    cout<<solution(10);
}
