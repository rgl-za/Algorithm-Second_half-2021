
// 두개 뽑아서 더하기
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for(int i=0; i<numbers.size(); i++){
        for(int j=i+1; j<numbers.size(); j++){
            answer.push_back(numbers[j]+numbers[i]);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    //중복원소 지우기 
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    

    return answer;
}


//약수 개수 덧셈
#include <string>
#include <vector>

using namespace std;

int solution(int left, int right){
    int answer = 0;
    int count=0;

    for(int i=left; i<=right; i++){
        for(int j=1; j<=i; j++){
            if(i%j==0){
                count++;
            }

        }
        if(count%2==0){
            answer+=i;
        }
        else
            answer-=i;
    }
    return answer;
}



//시저암호
#include <string>
#include <vector>

using namespace std;

string solution(string s, const int n){
    string answer ="";

    for(char& c: s){
        if(islower(c)){ //소문자라면
            if(!islower(c+= n%26))//소문자가 아니라면
                c-=26;
        }
        else if(isupper(c)){ //대문자라면
            if(!isupper(c+=n%26)) //대문자가 아니라면
                c-=26;
        }
    }
    
     return s;
}
