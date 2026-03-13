#include<iostream>
using namespace std;

#include "stack.h"
#include <cstring>

/*
int main(int argc, char **argv){
    Stack s;

    char tl;
    int match = 1;

    for(j = 0; j < strlen(argv[i]); j++) {
      switch (argv[i][j]) 
      {
        
      }
      if(match == 0) break;

    }
    if(match == 0) cout << "incorrect:mismatch";
    else if() cout << "incorrecrt:too many open parentheses" << endl;
    else cout << "correct" << endl;

  return 0;
}
// Use for loop along with switch statement

  Exercise 2
 printf("Checking the parentheses in argv arguments\n");

   

    
     for(j=0;j<strlen(argv[i]);j++){
       // Use stack to help with the parentheses





  }

  


   return 0;
}
*/

int main(int argc, char **argv) 
{
  for(int i=1;i<argc;i++){

    Stack s;
    bool error=false; // Boolean for error status flags

    for(int j=0;j<strlen(argv[i]);j++) // using strlen to find the length of string
    {

        if(argv[i][j]=='[' || argv[i][j]=='{')
            s.push(argv[i][j]);

        else if(argv[i][j]==']' || argv[i][j]=='}'){

            if(s.isEmpty()){ // if stack is empty and the argv is a closing parenthesis return incorrect
                error=true;
                break;
            }

            char x=s.pop(); // Otherwise pop earlier data to compare 

            if((argv[i][j]==']' && x!='[') ||
               (argv[i][j]=='}' && x!='{')){
                error=true; // incorrect if not a complete bracket
                break; 
            }
        }
    }

    if(error) // use error flags to determine the output for each argv
        cout<<"argv "<<i<<" incorrect"<<endl;
    else if(!s.isEmpty())
        cout<<"argv "<<i<<" incorrect: too many open parenthesis"<<endl;
    else
        cout<<"argv "<<i<<" correct"<<endl;
}
}