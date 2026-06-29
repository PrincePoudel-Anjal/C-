#include<iostream>
using namespace std;
#include <vector>

void enqueue(vector<int>& queue,int a){
    queue.push_back(a);
    
}
void dequeue(vector<int>& queue){
    queue.erase(queue.begin()-1,queue.begin());
    
}
int peek(vector<int>& queue){
    return queue[0];
}
int rear(vector<int>& queue){
    int length = queue.size();
    return queue[length-1];
}

int main(){
   vector<int> queue;
   enqueue(queue,10);
   enqueue(queue,20);
   enqueue(queue,30);
   
   for(auto i:queue){
        cout<<endl;
        cout<<i<<endl;
   }
   cout<<endl<<"Peek is:";
   int x = peek(queue);
   cout<<x;

   cout<<endl<<"rear is:";
   int y = rear(queue);
   cout<<y;

   dequeue(queue);

   for(auto i:queue){
        cout<<endl;
        cout<<i<<endl;
   }
}