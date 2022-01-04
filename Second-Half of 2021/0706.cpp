#include <iostream>

#define MAX_STRING 9999999
#define MAX_WORD 9999999

using namespace std;

char s[MAX_STRING+1], w[MAX_WORD+1];
int fail[MAX_WORD], result[MAX_WORD];
int n, m, r;

void getFail(){
    m=0;
    while(w[m])
        m++;
    for(int i=1, j=0; i<m; i++){
        while(j>0 && w[i]!=w[j])
            j=fail[j-1];

        if(w[i]==w[j])
            fail[i]=++j;
        else
            fail[i]=0;
    }
}

void kmp(){
    getFail();
    n=0, r=0;
    for(int i=0; i<MAX_WORD; i++)
        result[i]=0;

    while(s[n])
        n++;

    for(int i=1, j=0; i<n; i++){
        while(j>0 && s[i]!=w[j])
            j=fail[j-1];
            
        if(s[i]==w[j]){
            if(j==m-1){
                result[r++]=i-m+1;
                j=fail[j];
            }
            else
                j++;
        }
        else 
            j=0;
    }
}

int strcmp(const char* str1, const char* str2){
    int i=0, j=0;

    while(str1[i]!='\0' || str2[j]!='\0'){
        if(str1[i]!=str2[j])
            return str1[i]-str2[j];
        else{
            i++;
            j++;
        }
    }
    return 0;
}

int main(){
    cin >> s;
    
    cin >> w;
        
    kmp();
    if(r==0)
        cout << 0 << endl;
    else
        cout << 1 << endl;
    
    return 0;
}