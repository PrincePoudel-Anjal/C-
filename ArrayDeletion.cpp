#include<iostream>
using namespace std;

int main(){
    int pos;
    int arr[] = {1,2,3,4};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter the position to Delete:";
    cin>>pos;
    for(int i=0;i<length;i++){
        if(i>=pos){
            arr[i] = arr[i]+1;
        }
    }
    for(int i=0;i<length-1;i++){
        cout<<arr[i];
    }
}