/******************************************************************************

Author - Tanmay Deshpande
REDID - 824646024

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
struct Node 
{ 
    public: 
    string key; 
    int value; 
      
    Node(string key, int value) 
    { 
        this->value = value; 
        this->key = key; 
    } 
}; 

class Dictionary{
    vector<Node*> node;
    
    public:
    void add(string key,int value){
        if(in(key)){
            cout<<"Key already there\n";
        }
        
        else{
            Node *n=new Node(key,value);
            node.push_back(n);
        }
    }
    
    bool in(string key){
        for(int i=0;i<node.size();i++){
            if(node[i]->key==key){
                return true;
            }
        }
        return false;
    }
    
    void items(){
        for(int i=0;i<node.size();i++){
            cout<<"("<<node[i]->key<<","<<node[i]->value<<")\n";
        }
    }
    void keys(){
        for(int i=0;i<node.size();i++){
            cout<<"["<<node[i]->key<<",";
        }
        cout<<"]\n";
    }
    void values(){
        for(int i=0;i<node.size();i++){
            cout<<"["<<node[i]->value<<",";
        }
        cout<<"]\n";
    }
    
    int get(string k){
        for(int i=0;i<node.size();i++){
            if(node[i]->key==k){
                cout<<node[i]->value;
                return node[i]->value;
            }
        }
        return -1;
    }
    void del(string key){
        bool flag=false;
        for(int i=0;i<node.size();i++){
            if(node[i]->key==key){
                node.erase(node.begin()+i);
                flag=true;
                cout<<"Deletion successful\n";
            }
        } 
        if(!flag)
            cout<<"Key does not exist\n";
    }
};

int main()
{
    Dictionary *d=new Dictionary();
    d->add("Neil",52);
    d->add("John",42);
    d->add("Jane",56);
    d->add("Cecily",12);
    d->get("g");
    d->get("Neil");
    d->items();
    d->del("t");
    d->items();
    
    return 0;
}