#include<iostream>
using namespace std;
#include <stack>


void hanoi(int n, stack<char>& A, stack<char>& B, stack<char>& C,char s,char h,char t) {
    if(n==1){
        char disk = A.top();
        C.push(disk);
        A.pop();
        cout<<"Move "<<disk<<" from "<<s<<" To "<<t<<endl;
        return;
    }
    // move n-1 part to Helper

    hanoi(n-1,A,C,B,s,t,h);

    char disk = A.top();
    C.push(disk);
    A.pop();
    cout<<"Move "<<disk<<" from "<<s<<" To "<<t<<endl;

    // move from Helper to Destination

    hanoi(n-1,B,A,C,h,s,t);
}

int main(){
    stack<char> A;
    A.push('1');
    A.push('2');
    A.push('3');
    A.push('4');
    A.push('5');

    stack<char> B;
    stack<char> C;
    int n = A.size();

    char s = 'A';
    char h = 'B';
    char t = 'C';

    hanoi(n,A,B,C,s,h,t);

}