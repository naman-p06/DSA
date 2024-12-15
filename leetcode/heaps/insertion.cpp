#include <bits/stdc++.h>
using namespace std;
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
    void delet(){
        if(size==0)
        cout<<"No element"<<endl;

        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size){
            int left=2*i;
            int right=2*i+1;

            if(left<size&& right<size){
                if(arr[i]<arr[left] ){
                    if(arr[left]<arr[right] ){
                        swap(arr[i],arr[right]);
                        i=right;
                    }
                    else{
                        swap(arr[i],arr[left]);
                        i=left;
                    }
                }
                else{
                    if(arr[i]<arr[right]){
                        swap(arr[i],arr[right]);
                        i=right;
                    }
                    else{
                        return;
                    }
                }
            }
            else if (left<size )
            {
                if(arr[i]<arr[left]){
                    swap(arr[i],arr[left]);
                        i=left;
                }
                else{
                    return;
                }
            }
            else if (right<size )
            {
                if(arr[i]<arr[right]){
                    swap(arr[i],arr[right]);
                        i=right;
                }
                else{
                    return;
                }
            }
        }
    }

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
};
int main(){
 
return 0;
}