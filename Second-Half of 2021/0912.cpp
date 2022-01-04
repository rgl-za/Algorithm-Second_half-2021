//올바른 괄호
#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s){
    stack<char>stack;
    bool answer = true;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '(')
            stack.push('(');
        else{
            if(!stack.empty() && stack.top() == '(')
                stack.pop();
            else
                stack.push(')');
        }
    }

    if(stack.empty())
        return true;
    else
        return false;
}


//JadenCase 문자열 만들기
//처음 시도한 풀이
//공백 기준으로 문자를 자르고 앞 글자를 대문자로 변환하려고 했으나 한꺼번에 들어와서 해결이 안됨
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    istringstream ss(s);
    string stringBuffer;
    vector<string> x;

    while(getline(ss, stringBuffer, ' ')){
        x.push_back(stringBuffer);
        toupper(stringBuffer);
    }

    for(int i=0; i<x.size(); i++){
        answer+=(x[i]);
        answer+="\n";
    }

    


    return answer;
}

//최종 풀이
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";

    int i = 1;
    s[0] = toupper(s[0]);

    while(s[i] != '\n'){
        if(s[i] == ' ')
            s[i+1] = toupper(s[i+1]);
        else if(s[i] >= 65 && s[i] <= 90 && s[i-1] != ' ')
            s[i] = tolower(s[i]);
        i+=1;
    }

    return s;
}

int main(){
    string s = "for the last week";

    cout << solution(s);
}



//숫자의 표현
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum;

    for(int i=1; i<=n; i++){
        sum=0;
        for(int j=i; j<=n; j++){
            sum +=j;
            if(sum == n){
                answer++;
                break;
            }
            else if (sum > n)
                break;
        }
    }

    return answer;
}

int main(){
    int n=15;
    cout << solution(n);
}


//다음 큰 숫자
//처음 시도한 풀이: 이진수 변환부터 오류난 걸로 추정

#include <string>
#include <vector>
#include <iostream>

using namespace std;


int binary(int n){
    int temp =0;
    for(int i=1; n>0; i*=10){
        int binary = n%2;
        temp+=binary*i;
        n/=2;
    }
    return temp;
}

int count(int temp){
    temp = binary(n);
    int cnt = 0;
    for(int i=0; i<temp.sizeof(); i++){
        if(i==1)
            cnt++;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    for(int i=0; i>n; i++){
        if(count(i) == count(n))
            answer = i;
            break;
    }
    return answer;
}

//최종 풀이
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int binary(int n){
    int count = 0;

    while(1){
        if(n%2!=0)
            count++;
        n/=2;

        if(n == 2 || n == 1){
            count++;
            break;
        }
    }
    return count;
}

int solution(int n){
    int count = binary(n);

    n++;

    while(1){
        if(count == binary(n))
            return n;
        n++;
    }
}

int main(){
    int n = 78;

    cout << solution(n);
}


//최솟값 구하기
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B){
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int i=0; i<A.size(); i++){
        answer+=A[A.size()-1-i]*B[i];
        /*A(내림차순으로 정렬된 벡터) * B(오름차순으로 정렬된 벡터)
        형태로 만들어준 뒤, 순서대로 쌍을 곱해주가*/
    }

    return answer;
}
