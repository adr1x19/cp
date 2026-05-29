#include<bits/stdc++.h>
#include<string.h>
using namespace std;


class TrieNode
{
    public:
        TrieNode* children[26];
        bool isleaf;
        
        TrieNode() {

            isleaf=false;
            for(int i=0;i<26;i++){
                children[i]=nullptr;

            }
        }
    
};


//insertion in trie

TrieNode* insert(TrieNode *head, string &s){
    
    int n=s.size();
    
    TrieNode* temp=head;

    for(int i=0;i<n;i++){
        
        int c=s[i]-'a';
        cout<<"the character"<<(int)c<<" was inserted"<<endl;
        if(temp->children[c]==nullptr){
            
            temp->children[c]= new TrieNode();
            temp=temp->children[c];
        }
        else{
            temp=temp->children[c];

        }
        
    }
    temp->isleaf=true;
    return head;


}

bool search_trie(TrieNode* head,string f){
    
    TrieNode *temp=head;

    int n=f.size();
    int i=0;

    while(i<n){

        if(temp->children[(int)f[i]-'a']!=nullptr){
            temp=temp->children[(int)f[i]-'a'];

        }
        else{
            return false;

        }
        i++;
    }
    if(temp->isleaf==true) return true;
    return  false;
    


}
int main(){
    string s="abp";
    TrieNode* head=new TrieNode();
    
    head=insert(head,s);

    if((head->children[0])==nullptr){
        cout<<"not inserted"<<endl;
        

    }
    
    if(search_trie(head,"ab"))
    {
        cout<<"found"<<endl;
        
    }
    else{
        cout<<"not found"<<endl;
        
    }
    return 0;

    

}

