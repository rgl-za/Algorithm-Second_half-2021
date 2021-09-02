//숫자 문자열과 영단어
//처음 생각한 풀이
#include <string>
#include <vector>

using namespace std;

int solution(string s){
    int answer=0;
    string numbers[]={"zero","one", "two", "three", 
                     "four", "five", "six", "seven",
                     "eight", "nine"};
    
    int change[]={0,1,2,3,4,5,6,7,8,9};

    vector<string>::iterator it;

    for(int i=0; i<numbers.size(); i++){
        it=find(s.begin(),s.end(), numbers[i]);

        if(it!=s.end()){
            //return change[i];
            s.replace(s.find(s[i]), numbers[i].size(), change[i]);
        }
        
    }

    answer = stoi(s);
    

    return answer;
}


//수정한 풀이
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string num[] = { "0","1","2","3","4","5","6","7","8","9" };
    string s2[] = { "zero","one","two", "three","four","five","six","seven","eight","nine" };
    int j = 0;

    while (j < s.size()) {
        for (int i = 0; i < 10; i++) {
            if (s.find(s2[i]) != std::string::npos)
                s.replace(s.find(s2[i]), s2[i].size(), num[i]);
        }
        j++;
    }
    answer = stoi(s);

    return answer;
}




//다트게임
#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int idx=0;
    vector<int> scores;

    for(int i=0; i<dartResult.size(); i++){
        if(dartResult[i]=="S")
        else if(dartResult[i]=="D")
            scores[idx -1] = scores[idx-1]*scores[idx-1];
        else if(dartResult[i]=="T")
            scores[idx -1] = scores[idx-1]*scores[idx-1]*score[idx-1];
        else if (dartResult[i] == '*') {
			scores[idx - 1] = scores[idx - 1] * 2;
			
            if (idx > 1)
				scores[idx - 2] = scores[idx - 2] * 2;
		}
		else if (dartResult[i] == '#') {
			scores[idx - 1] = scores[idx - 1] * -1;
		}
		else {
			if (dartResult[i + 1] == '0') {
				scores.push_back(10);
				i++;
			}	
			else 
				scores.push_back(dartResult[i] - '0');
			
            idx++;
        }       
    }

    for(int i=0; i<scores.size(); i++){
        answer+=scores[i];
    }

    return answer;
}

//신규 아이디 추천
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string tmp = "";

    for(int i=0; i<new_id.size(); i++){
        new_id[i]=tolower(new_id[i]);
    }

    for(int i=0; i<new_id.size(); i++){
        if((new_id[i] >= 'a' && new_id[i] <= 'z')|| (new_id[i] >= '0' && new_id[i] <= '9') || (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')){
            answer += new_id[i];
        }
    }

    for(int i = 0; i < answer.size(); i++){
        if(answer[i] == '.'){
            int cnt = 0;
            
            for(int j = i + 1; j < answer.size(); j++){
                if(answer[j] == '.'){
                    cnt++;
                }
                else{
                    break;
                }
            }
            
            if(cnt > 0){
                tmp += '.';
                i += cnt;
            }
            else{
                tmp += answer[i];
            }
        }
        else{
            tmp += answer[i];
        }
    }

    
    if(tmp.front() == '.'){
        tmp.erase(tmp.begin());
    }
    if(tmp.back() == '.'){
        tmp.pop_back();
    }

    
    if(tmp.empty()){
        tmp = "a";
    }

    
    if(tmp.size() >= 16){
        tmp = tmp.substr(0, 15);
    }
    if(tmp.back() == '.'){
        tmp.pop_back();
    }

    
    while(tmp.size() <= 2){
        tmp.push_back(tmp.back());
    }
    
    return tmp;
}



int main(){
    string new_id;

    cin >> new_id;

    cout << solution(new_id);

}