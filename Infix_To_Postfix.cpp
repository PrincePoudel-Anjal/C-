#include<iostream>
using namespace std;
#include<stack>
#include <cstring>

void displaystack(stack<char> s){
    while(!s.empty()){
        char  a = s.top();
        s.pop();
        cout<<"\n"<<a<<endl;
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
        return 1;
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
    char ch = '\0';

    cout<<endl;
    int length = strlen(infix);
    cout<<length<<endl;
    for(int i=0;i<length;i++){
        cout<<i;
        if(infix[i]>= 'A' && infix[i]<= 'Z'){
            s.push(infix[i]);
            continue;
        }
        
        if(infix[i] == ')'){
            char c = '\0';            
            while(!symbol.empty() && symbol.top() != '('){
                c = symbol.top();
                if(c == '('){break;}
                symbol.pop();
                s.push(c);            
            }            
        }
        else if(infix[i] == '('){
            continue;
        }
        if(symbol.empty()){
            symbol.push(infix[i]);
            continue;
        }

        int P = priority(infix[i]);
        cout<<"\nPriority is:"<<P<<endl;

        if(!symbol.empty()){
        char temp = symbol.top();
        pastP = priority(temp); 
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
    while(!symbol.empty()){
        char ch = symbol.top();
        s.push(ch);
        symbol.pop();
    }
    cout<<"\n\nPostfix:";
    displaystack(s); 
    return 0;   
}