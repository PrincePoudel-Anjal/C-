#include<iostream>
using namespace std;

int main(){
    int pos,value;
    int arr[] = {1,2,3,4};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter the position to insert:"; cin>>pos;
    cout<<"Enter the value to insert:"; cin>>value;
    int prev = arr[pos];
    int temp;
    for(int i=0;i<=length;i++){
        if(i<pos){continue;}
        else if(i==pos){arr[i] = value; continue;}
        temp = arr[i];
        arr[i] = prev;
        prev = temp;
    }
    cout<<endl<<endl;
    for(int i=0;i<=length;i++){
        cout<<arr[i];
    }
}