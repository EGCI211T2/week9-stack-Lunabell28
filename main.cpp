#include<iostream>
#include<cstring>
using namespace std;

#include "stack.h"

int main(int argc, char **argv){
    int i, j;
    
    /* Exercise 1 - Bracket Matching */
    for(i=1; i<argc; i++){
        Stack s;
        bool valid = true;
        
        for(j=0; j<strlen(argv[i]); j++){
            if(argv[i][j]=='[' || argv[i][j]=='{' || argv[i][j]=='('){
                s.push(argv[i][j]);
            }
            else if(argv[i][j]==']' || argv[i][j]=='}' || argv[i][j]==')'){
                if(s.isEmpty()){
                    valid = false;
                    break;
                }
                
                char x = s.pop();
                
                // Check if brackets match
                if((argv[i][j]==']' && x!='[') || 
                   (argv[i][j]=='}' && x!='{') ||
                   (argv[i][j]==')' && x!='(')){
                    valid = false;
                    break;
                }
            }
        }
        
        // Check if all brackets were closed
        if(!s.isEmpty()){
            valid = false;
        }
        
        cout << "argv " << i << " " << (valid ? "correct" : "incorrect") << endl;
    }

    return 0;
}