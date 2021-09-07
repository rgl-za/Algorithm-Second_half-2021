//유클리드 호제법
int gcd(int a, int b){
    int c;

    while(b != 0){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}


//n개의 최소공배수
//처음 시도한 코드: 실행시간 초과
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr){
    int answer = 0;

    for(int i=0; i<arr.size(); i++){

        int temp;

        while(arr[i]!=0){
            temp=arr[i]%arr[i+1];
            answer*=arr[i]/temp;
        }
        if(arr[i]==0)
            answer=0;
    }

    return answer;
}


//에러
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr){
    int answer = 1;

    for(int i=0; i<arr.size(); i++){

        int temp=0;
        
        if(arr[i]==0)
            answer=0;

        else{
            temp=arr[i]%arr[i+1];
            answer*=arr[i]/temp;
        }
    }

    return answer;
}

// 최종 코드
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    int c;
    while(b != 0){
        c = a%b;
        a=b;
        b=c;
    }
    return a;
}
int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int solution(vector<int> arr) {
    int answer = 0;
    int temp = 1;

    for(int i=0; i<arr.size(); i++)
        temp = lcm(temp,arr[i]);
    
    answer = temp;
    return answer;
}


//최댓값과 최솟값
//처음 시도한 풀이
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    //istringstream ss(s);
    vector<string> words;
    vector<int> temp;
    string word;
    int max, min;
    string result1, result2, result;

    while (getline(ss, words, ' ')){
        words.push_back(word);
    }
    //여기서 안먹음
    stringstream ss(s);
    ss.str(s);
    while(ss >> word)
        words.push_back(word);

    for(int i=0; i<words.size(); i++){
        answer=words[i];
        // temp.push_back(stoi(words[i]));
    }
    
    // int size=sizeof(answer)/sizeof(int);
    for(int i=0; i<answer.size(); i++){
        // min = min(answer,answer+answer.size());
        // max = max(answer,answer+answer.size());
    }
    max=temp[0];
    min=temp[0];
    for(int i=1; i<temp.size(); i++){
        if(temp[i]>max)
            max = answer[i];
        if(temp[i]<min)
            min = answer[i];
    }
    result1 = to_string(min);
    result2= to_string(max);

    result = result1+" "+result2;

    return result;
    return answer;
}

int main(){
    string s;
    cin >> s;
    cout << solution(s);
}


//최종 통과
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<string> words;
    vector<int> temp;
    string result, result1, result2;
    int max, min;

    istringstream ss(s);
    string word;

    while(getline(ss, word, ' ')){
        words.push_back(word);
    }

    for(int i=0; i<words.size(); i++){
        temp.push_back(stoi(words[i]));
    }

    max = temp[0];
    min = temp[0];

    for(int i=0; i<temp.size(); i++){
        if(temp[i]>max)
            max=temp[i];
        if(temp[i]<min)
            min=temp[i];
    }
    result1=to_string(min);
    result2=to_string(max);

    answer=result1+" "+result2;

    return answer;
}