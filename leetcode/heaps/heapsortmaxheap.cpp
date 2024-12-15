#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[],int i,int n){
        int la=i;
        int left=2*la;
        int right=2*la+1;
        if(left<=n&&arr[la]<arr[left]){
            la=left;
        }
        if(right<=n&& arr[la]<arr[right])
        la=right;

        if(la!=i){
            swap(arr[la],arr[i]);
            heapify(arr,la,n);
        }
    }
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size++;
        int ind=size;
        arr[ind]=val;
        while(ind>1){
            int p=ind/2;
            if(arr[ind]>arr[p]){
                swap(arr[p],arr[ind]);
                ind=p;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl; 
    }
    void sortheap(){
        int t=size;
        while(size>1){
            swap(arr[1],arr[size]);
            size--;
            heapify(arr,1,size);
        }
        size=t;
        print();
    }
};
int main(){
    
heap h;
h.insert(50);
h.insert(56);
h.insert(65);
h.insert(67);
h.insert(35);
h.insert(78);
h.print();
h.sortheap();
return 0;
}