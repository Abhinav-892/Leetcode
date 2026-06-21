class TrieNode{
    public:
    char data ;
    unordered_map<char,TrieNode*> children ;
    bool isTerminal;

    TrieNode(char val){
        data = val ;
        isTerminal = false ;
    }
};
  
void insertWord(TrieNode* root, string word){
    if(word.length() == 0){
        root->isTerminal = true ;
        return ;
    }
 
 char ch = word[0] ;
 TrieNode* child ;

 if(root->children.find(ch) != root->children.end()){
    child = root->children[ch] ;
 } 
else{
    child = new TrieNode(ch) ;
    root->children[ch] = child ;
}
insertWord(child,word.substr(1)) ;
} 

bool searchWord(TrieNode* root,string word){
    
    if(word.length() == 0){
        return root->isTerminal ;
    }

   char ch = word[0] ;
   TrieNode* child ;

   if(root->children.find(ch) != root->children.end()){
    child = root->children[ch] ;
   }    
   else{
    return false ;
   }
     bool recursionKaAns = searchWord(child,word.substr(1)) ;
     return recursionKaAns ; 
}

bool searchPrefix(TrieNode* root, string word){
    if(word.length() == 0){
        return true ;
    }

    char ch = word[0] ;
    TrieNode* child ;

   if(root->children.find(ch) != root->children.end()){
    child = root->children[ch] ;
   }  
   else{
    return false ;
   }
   bool recursionKaAns = searchPrefix(child,word.substr(1)) ;
   return recursionKaAns ;
}

class Trie {
public:
    TrieNode* root ;
    Trie() {
        root = new TrieNode('-') ;
    }
    
    void insert(string word) {
        insertWord(root,word) ;
    }
    
    bool search(string word) {
        return searchWord(root,word) ;
    }
    
    bool startsWith(string prefix) {
        return searchPrefix(root,prefix) ;
    }
};
