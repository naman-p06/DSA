#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int da){
        this->data=da;
        this->left=NULL;
        this->right=NULL;
    }
};
void insert(node*& root,int a){
    if(root==NULL){
        root=new node(a);
        return;
    }
    if(root->data>a){
        insert(root->left,a);
    }
    if(root->data<=a){
        insert(root->right,a);
    }
}
void input(node* &root){
    int a;
    cin>>a;
    while(a!=-1){
        insert(root,a);
        cin>>a;
    }
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node* find(int a,node*root){
    if(root==NULL){
        return NULL;
    }
    if(root->data==a){
        return root;
    }
    node* ans=NULL;
    if(root->data>a){
         ans=find(a,root->left);
    }
    if(ans!=NULL)
    return ans;
    else{
        
    }
}
void check(node* root,int a,int & ans){
    if(root==NULL){
        return;
    }
    if(root->data<a){
        if(root->data>ans)
        ans=root->data;
    check(root->right,a,ans);
    }
    else{
        check(root->left,a,ans);
    }
}
void inorderpredecessor(int a,node* root,int &ans){
    
    if(a>root->data){
        ans=root->data;
        check(root->right,a,ans);
    }
    if(a<=root->data){
        check(root->left,a,ans);
    }
}
int main(){
node* root=NULL;
cout<<"building bst from inputs"<<endl;
input(root);
inorder(root);
cout<<endl<<"find inorder precessor of ";
int a;
cin>>a;
int ans=-1;
while(a!=-1){
ans=-1;
inorderpredecessor(a,root,ans);
cout<<"the pred is "<<ans<<endl;
cout<<"find inorder precessor of ";
cin>>a;
}
return 0;
}
