#include<iostream>
using namespace std;


int fibonacci(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }

    int result = fibonacci(n-1) + fibonacci(n-2);
    return result;
}

int main(){
    int n = 6;
    int a = 0;
    int b = 1;
    int result; 

    for(int i=0;i<n;i++){
        result = fibonacci(i);
        cout<<result<<" "<<endl;
    }

}