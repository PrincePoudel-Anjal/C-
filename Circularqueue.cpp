#include<iostream>
using namespace std;
#include <vector>


class Circularqueue{
public: 
    int* arr;  
    int f,r;
    int capacity;
    int currentsize;
    
    Circularqueue(int size){
        capacity = size;
        arr = new int[capacity];
        f = 0;
        r = -1;
        currentsize = 0;
    }
    
    void push(int a){      
        if(currentsize==capacity){
            return;
        }  
        r = (r+1)%capacity;   //increase rear by 1
        arr[r] = a; 
        currentsize += 1;       
    }

    void pop(){
        if(r==-1){return;}
        f = (f+1)%capacity;
        currentsize--;
    } 
    void display(){
        for(int i=0;i<currentsize;i++){
            cout<<arr[i+f]<<"->";
        }
    }
};

int main(){
    Circularqueue queue(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);
    queue.pop();
    queue.push(50);
    queue.display();

}