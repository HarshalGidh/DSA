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
    cout << "recieved word: " << word << " for insertion " << endl;
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

    cout << "Insertion Done" << endl; 
    if(searchWord(root, "loved") ) {
        cout << "Found" << endl;
   }
    else {
        cout << "Not Found" << endl;
   }
   deleteWord(root, "loved");

   if(searchWord(root, "loved") ) {
    cout << "Found" << endl;
   }
   else {
    cout << "Not Found" << endl;
   }
    return 0;
}