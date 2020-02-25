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
            cout<<"Key "<<key<<" already there\n";
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
        cout<<"Items\n";
        for(int i=0;i<node.size();i++){
            cout<<"("<<node[i]->key<<","<<node[i]->value<<")\n";
        }
    }
    void keys(){
        cout<<"Keys\n";
        for(int i=0;i<node.size();i++){
            cout<<"["<<node[i]->key<<",";
        }
        cout<<"]\n";
    }
    void values(){
        cout<<"Values\n";
        for(int i=0;i<node.size();i++){
            cout<<"["<<node[i]->value<<",";
        }
        cout<<"]\n";
    }
    
    int get(string k){
        for(int i=0;i<node.size();i++){
            if(node[i]->key==k){
                cout<<"Value with Key "<<k<<" "<<node[i]->value<<endl;
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
    
    Dictionary operator+ (Dictionary &dict) {
    	Dictionary currentDictionary = *this;
    	Dictionary unionDictionary;
    	for(int i=0;i<currentDictionary.node.size();i++)
    		unionDictionary.add(currentDictionary.node[i]->key,currentDictionary.node[i]->value);
    	for(int i=0;i<dict.node.size();i++) {
    		if(unionDictionary.in(dict.node[i]->key)) {
    			cout<<"Key cannot be same !"<<endl;
    			continue;
    		}
    		else
    			unionDictionary.add(dict.node[i]->key,dict.node[i]->value);
    	}
    	return unionDictionary;
    }
};


int main()
{
    Dictionary *d1=new Dictionary();
    d1->add("Neil",52);
    d1->add("John",42);
    d1->add("Jane",56);
    d1->add("Cecily",12);
    d1->get("g");
    d1->items();
    cout<<endl;
    cout<<"Get function for key 'Neil' will work as below"<<endl;
    d1->get("Neil");
    cout<<endl;
    cout<<"Delete function for key 't' which is not present in the Dictionary will work as below"<<endl;
    d1->del("t");
    cout<<endl;
    cout<<"Delete function for key 'Neil' which is present in the Dictionary will work as below"<<endl;
    d1->del("Neil");
    d1->items();
    cout<<endl;
	
	Dictionary *d2 = new Dictionary();
	d2->add("Chicago",5);
	d2->add("NY",15);
	d2->add("LA",55);
	Dictionary unionDirectory = *d1 + *d2;
	cout<<"Union of the directories is "<<endl;
	unionDirectory.items();
    
    return 0;
}