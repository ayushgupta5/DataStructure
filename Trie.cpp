#include<bits/stdc++.h>
using namespace std;
struct Trie
{
    Trie *children[26];
    bool isEOW;
};
struct Trie *getNode()
{
    Trie *A=new Trie;
    A->isEOW=false;
    for(int i=0;i<26;i++) A->children[i]=NULL;
    return A;
};
void insert(Trie*root, string s)
{
    Trie *P=root;
    for(int i=0;i<s.size();i++)
    {
        int ind=s[i]-'a';
        if(!P->children[ind]) P->children[ind]=getNode();
        P=P->children[ind];
    }
    P->isEOW=true;
}
bool search(Trie *root,string s)
{
    Trie *P=root;
    for(int i=0;i<s.size();i++)
    {
        int ind=s[i]-'a';
        if(!P->children[ind]) return false;
        P=P->children[ind];
    }
    return (P!=NULL&&P->isEOW);
}
int main()
{
    int i,n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string s[n];
        string str;
        for(i=0;i<n;i++) cin>>s[i];
        Trie *root=getNode();
        for(i=0;i<n;i++) insert(root,s[i]);
        cin>>str;
        search(root,str)?cout<<"Yes\n":cout<<"No\n";
    }
}
