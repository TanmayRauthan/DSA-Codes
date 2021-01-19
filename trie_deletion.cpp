#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* child[26];
    bool isEnd;
};
Node* getNode()
{
    Node* temp=new Node;
    for(int i=0;i<26;i++)
        temp->child[i]=NULL;
    temp->isEnd=false;
    return temp;
}
void insert(Node *root,string s)
{
    Node *temp=root;
    for(int i=0;i<s.length();i++)
    {
        int index=s[i]-'a';
        if(!temp->child[index])
            temp->child[index]=getNode();
        temp=temp->child[index];
    }
    temp->isEnd=true;
}
bool search(Node *root,string key)
{
    Node *temp=root;
    for(int i=0;i<key.length();i++)
    {
        int index=key[i]-'a';
        if(!temp->child[index])
            return false;
        temp=temp->child[index];
    }
    if(temp->isEnd==true)
        return true;
    else
        return false;
}
bool isEmpty(Node *temp)
{
    for(int i=0;i<26;i++)
        if(temp->child[i])
            return false;
    return true;
}
Node* remove(Node *root,string key,int n)
{
    if(n==key.length())
    {
        root->isEnd=false;
        if(isEmpty)
        {
            delete(root);
            root=NULL;
            return NULL;
        }
        return root;
    }
    int index=key[n]-'a';
    root->child[index]=remove(root,key,n+1);
    if(isEmpty(root)&&root->isEnd==false)
    {
        delete(root);
        root=NULL;
    }
    return root;
}
int main()
{
    string s;int n;
    cin>>n;
    fflush(stdin);
    Node* root=getNode();
    for(int i=0;i<n;i++)
    {
        cin>>s;
        insert(root,s);
    }
    for(int i=0;i<n;i++)
    {
        cin>>s;
        if(search(root,s))
            cout<<"Found"<<endl;
        else
            cout<<"no"<<endl;
    }
    remove(root,"the",0);
    if(search(root,"the"))
            cout<<"Found"<<endl;
        else
            cout<<"no"<<endl;
}

