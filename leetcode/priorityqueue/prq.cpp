#include <bits/stdc++.h>
using namespace std;
int main(){
    //max heap
 priority_queue<int> p;
p.push(50);
p.push(56);
p.push(65);
p.push(67);
p.push(35);
p.push(78);
cout<<p.top()<<endl;
p.pop();
cout<<p.top()<<endl;
cout<<p.size()<<endl;
if(p.empty()){
    cout<<"NOOOOOOOOOO"<<endl;
}
else{
    cout<<"YESSSS"<<endl<<endl;
}
// min heap from prq
priority_queue<int,vector<int>,greater<int> > minheap;
minheap.push(50);
minheap.push(56);
minheap.push(65);
minheap.push(67);
minheap.push(35);
minheap.push(78);
cout<<minheap.top()<<endl;
minheap.pop();
cout<<minheap.top()<<endl;
return 0;
}