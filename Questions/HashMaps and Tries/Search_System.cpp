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
void storeAns(TrieNode*lastChar,string word,vector<string>&ans,string &prefix){
    //Base Case:
    if(lastChar->isTerminal){
        //push word in ans 
        ans.push_back(prefix + word);
        //no return as we have to check for children of lastChar
    }
    for(char ch ='a';ch <='z';ch++){
        int index = ch - 'a'; //yaha pe gadbad kiya tha !!
        TrieNode* nextChild = lastChar->children[index]; 
        if(nextChild){
            //child exists
            word.push_back(nextChild->value);
            //baki Recursion :
            storeAns(nextChild,word,ans,prefix);
            //backTracking to remove the ch from word
            word.pop_back();
        }
    }
}
void findPrefixString(TrieNode*root,string word,vector<string>&ans,string &prefix){
    //Base Case:
    if(word.length() == 0){
        //store ans :
        TrieNode* lastChar = root;
        storeAns(lastChar,word,ans,prefix);
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode*child;
    if (root->children[index])
    {
        child = root->children[index];
    }
    else{
        return; //prefix doesnt exists
    }
    findPrefixString(child,word.substr(1),ans,prefix);
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

//     cout << "Insertion Done" << endl; 
//     if(searchWord(root, "loved") ) {
//         cout << "Found" << endl;
//    }
//     else {
//         cout << "Not Found" << endl;
//    }
//    deleteWord(root, "loved");

//    if(searchWord(root, "loved") ) {
//     cout << "Found" << endl;
//    }
//    else {
//     cout << "Not Found" << endl;
//    }
    string word = "c";//"car";
    string prefix = word;
    vector<string>ans;
    findPrefixString(root,word,ans,prefix);
    for(auto i: ans) {
        cout << i << " ";
    }
    cout << endl;

//     for(int i=0; i<ans.size(); i++) {
//         cout << i << " -> ";
//         for(auto str: ans[i]) {
//             cout << str <<", ";
//         }
//     cout << endl;
//   }
    return 0;
}