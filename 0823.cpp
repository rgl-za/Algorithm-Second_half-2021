
//가운데 글자 가져오기
//좀 더 효울적인 로직이 있을 것 같은데...
#include <iostream>
#include <string>

using namespace std;

string solution(string s){

    string answer ="";

    int num=0;

    for(int i=0; i<s.size(); i++){
        
        if(s.size()%2!=0){
            num=s.size()/2;

            answer=s[num];
        }
        else{
            num=s.size()/2;
            answer=s[num-1];
            answer+=s[num];
        }

    }

    return answer;
}


//이상한 문자 만들기
#include <string>

using namespace std;

string solution(string s){
    int index=0;

    for(int i=0; i<s.size(); i++){
        if(s[i]== ' '){
            index=0;
            
            continue;
        }

        if(index%2)
            s[i] = tolower(s[i]);

        else
            s[i] = toupper(s[i]);

        index++;
    }
    return s;
}


//문자열 다루기 기본
#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

bool solution(string s){
    bool answer = true;

    int count =0;

    if(s.length() !=4 && s.length() !=6)
        answer=false;

    else{
        for(int i=0; i<s.length(); i++){
            if(!isdigit(s[i])){
                answer = false;
                break;
            }
        }
    }
    return answer;
}


//문자열 내림차순으로 배치하기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s){
    string answer="";


    for(int i=0; i<s.size(); i++){
        answer.push_back(s[i]);
    }

    sort(answer.rbegin(), answer.rend());

    return answer;
}


//서울에서 김서방 찾기
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul){
    string answer="";

    for(int i=0; i<seoul.size(); i++){
        if(seoul[i]=="Kim"){
            answer="김서방은 "+to_string(i)+"에 있다";
            break;
        }
    }

    return answer;
}
