#include<iostream>
using namespace std;
#include<stack>
#include <cstring>

void displaystack(stack<char> s){
    while(s.top()){
        char  a = s.top();
        s.pop();
        cout<<a;
    }
}
int priority(char ch){
    if (ch == '^'){
        return 3;
    }
    else if(ch == '/' || ch == '*' ){
        return 2;
    }
    else if(ch == '+' || ch == '-' ){
        return 3;
    }
}

int main(){
    char infix[100];
    int pastP = 0;
    cout<<"Put your infix here:";
    cin>>infix;
    cout<<infix;
    stack<char> s;
    stack<char> symbol;
    cout<<endl;
    int length = strlen(infix);
    cout<<length<<endl;
    for(int i=0;i<length;i++){
        if(infix[i]>=65 && infix[i]<=90){
            s.push(infix[i]);
            continue;
        }
        int P = priority(infix[i]);
        char temp = symbol.top();
        pastP = priority(temp);
        char ch = '\0';
        if(infix[i] == ']' || infix[i] == ')' || infix[i] == '}'){
            while(ch != '(' || ch != '[' || ch != '{'){
                ch = symbol.top();
                if(ch == '(' || ch == '[' || ch == '{'){break;}
                symbol.pop();
                s.push(ch);                
            }            
        }
        if(pastP == P){
            char temp = symbol.top();
            symbol.pop();
            s.push(temp);
            symbol.push(infix[i]);
        }
        else if(pastP>P){
            while(pastP>P){
                int P = priority(infix[i]);
                char temp = symbol.top();
                pastP = priority(temp);
                s.push(temp);
                symbol.pop();
                symbol.push(infix[i]);
            }            
        }
        else{
            symbol.push(infix[i]);
        }
    }
    while(symbol.top()){
        char ch = symbol.top();
        s.push(ch);
        symbol.pop();
    }
    cout<<"\n\nPostfix:";
    displaystack(s); 
    return 0;   
}