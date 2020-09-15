#include <bits/stdc++.h>
using namespace std;

// KMP algorithm: search Pattern in Text
// T: Text
// P: Pattern

void ComputeFailureFunction(string pattern, int failure[]){
    int q = failure[0] = -1; // q indicates the position of matched char in pattern

    for(int i=1; i<pattern.length(); i++){
        while( (q >= 0) && (pattern[q+1] != pattern[i]) ) // next char does not match
            q = failure[q];
        
        if(pattern[q+1] == pattern[i]) // next char matches
            q = q + 1;
        
        failure[i] = q;
    }
}

void KMP(string text, string pattern){
    int n = text.length();
    int m = pattern.length();
    int failure[m];

    ComputeFailureFunction(pattern, failure);

    // i indicates the current position of text (no looking back!)
    // q indicates the position of matched char in pattern
    for(int i=0, q=-1; i<n; i++){
        while( (q >= 0) && (pattern[q+1] != text[i]) ) // next char does not match
            q = failure[q];

        if(pattern[q+1] == text[i]) // next char matches
            q = q + 1;
        
        if(q == m-1){
            cout<<"Pattern occurs with shift: "<< i - (m-1) << endl;
            q = failure[q]; // look for the next match
        }
    }
}

int main(){
    string text = "ababacababaababaa";
    string pattern = "ababaa";

    KMP(text, pattern);

    return 0;
}