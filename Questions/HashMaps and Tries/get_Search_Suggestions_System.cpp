#include<iostream>
#include<string.h>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
class TrieNode{
    public:
        char value;
        // TrieNode* children[26];
        map<char,TrieNode*> children;
        bool isTerminal;
        
        TrieNode(char word){
            this->value = word;
            isTerminal = false;
        }
};
void insertWord(TrieNode* root,string word){
   // cout << "recieved word: " << word << " for insertion " << endl;
    //Base Case :
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode*child;
    if(root->children[index]){
        child = root->children[index];
    }
    else{
        //create child:
        child = new TrieNode(ch);
        root->children[index] = child;
    }
    //Baki Recursion :
    insertWord(child,word.substr(1));
}
bool searchWord(TrieNode* root,string word){
    //Base Case
    if(word.length() == 0){
        return root->isTerminal; //if Node is marked terminated returns true(word found) else it return false(not found)
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root->children[index]){
        child = root->children[index];//char present
    }
    else{
        return false; //char not found so word not present
    }
    //Baki Recursion
   // bool recursionKaAns = searchWord(child,word.substr(1));
    return searchWord(child,word.substr(1)); //recursionKaAns;
}
void deleteWord(TrieNode*root,string word){
    //Base Case:
    if(word.length() == 0){
        root->isTerminal = false;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode*child;
    if(root->children[index]){
        child = root->children[index];
    }
    else{
        cout<<"Word Not Found in Trie"<<endl;
    }
    //Baki Recursion 
    deleteWord(child,word.substr(1));
}


void storeSuggestion(TrieNode*lastChar,string word,vector<string>&suggestions){
    //Base Case:
    if(lastChar->isTerminal){
        //push word in ans 
        suggestions.push_back(word);
        //no return as we have to check for children of lastChar
    }
    for(char ch ='a';ch <='z';ch++){
        int index = ch - 'a'; //yaha pe gadbad kiya tha !!
        TrieNode* nextChild = lastChar->children[index]; 
        if(nextChild){
            //child exists
            word.push_back(nextChild->value);
            //baki Recursion :
            storeSuggestion(nextChild,word,suggestions);
            //backTracking to remove the ch from word
            word.pop_back();
        }
    }
}
vector<vector<string>> getSuggestions(TrieNode*root,string input){
    TrieNode*prev = root;
    vector<vector<string>> ans;
    string word = "";
    for(int i = 0;i < input.size();i++){
        char ch = input[i];
        int index = ch - 'a';
        TrieNode*next = prev->children[index];
        if(next == NULL){
            break; //char not presnt in trie so cant find its child
        }
        else{
            //char present in trie , store it in word 
            word.push_back(next->value);
            //now store Suggestion :
            vector<string>suggestions;
            storeSuggestion(next,word,suggestions);
            ans.push_back(suggestions);
            //now move prev pointer to next child , 
            prev = next;
        }
    }
    return ans;
}
int main(){
    TrieNode* root = new TrieNode('-');
    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "com");
    insertWord(root, "lover");
    insertWord(root, "loved");
    insertWord(root, "load");
    insertWord(root, "lov");
    insertWord(root, "bat");
    insertWord(root, "cat");
    insertWord(root, "car");

    string input = "loa";
    vector<vector<string>> ans = getSuggestions(root,input) ;
    for(int i=0; i<ans.size(); i++) {
        cout << i <<" -> ";
        for(auto str: ans[i]) {
            cout << str <<", ";
        }
    cout << endl;
  }
    return 0;
}