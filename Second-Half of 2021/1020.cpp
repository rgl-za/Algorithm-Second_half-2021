#include <iostream>
#include <string>

using namespace std;

struct query{
    string operation;
    int branchNum;
};

struct input_data{
    int n;
    query * queries;
};

void solution(int n, query * queries){
    
    for(int i = 1; i<=n; i++){
        queries[i].branchNum=i;
        if(queries[i].operation == "merge"){
            delete []queries;
        }
        cout << queries[i].branchNum;
    }
    
}

void process_stdin(input_data & inputData){
    cin >> inputData.n;

    inputData.queries = new query[inputData.n];

    for(int i = 0; i<inputData.n; i++){
        cin >> inputData.queries[i].operation; 

        if(inputData.queries[i].operation == "merge"){
            cin >> inputData.queries[i].branchNum;
        }
    }
    
}

int main(){
    input_data inputData;
    process_stdin(inputData);

    solution(inputData.n, inputData.queries);

    return 0;
}