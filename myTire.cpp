#include <iostream>
#include <vector>
#define EPSILON '.'
#define ALPHABET 26


class myTire{
private:
    typedef struct Node {
        char label;
        bool is_valid = false;
        Node* parent;
        Node* childs[ALPHABET]= {nullptr};
    } Node ;
    Node* root;
    //--------------------------------------
    bool word_is_valid( std::string word ){
        for( char character: word )
            if( (character<='a' || character>='z') &&
                (character<='A' || character>='Z') )
                    return false;
        return true;
    }
    //--------------------------------------
    int decode_char( char character ){
        if( character>='a' && character<='z' ) return character - 'a';
        else if( character>='A' && character<='Z' ) return character - 'A';
        return -1;
    }
    //--------------------------------------
    Node* creat_node( Node* parent, char character ){
        Node* tmp = new Node();
        tmp->parent = parent;
        tmp->label  = character;
        return tmp;
    }
    void free(Node* current ){
        if(current==nullptr) 
            return;
        for(Node* node: current->childs)
            free(node);
        delete current;
    }
    //--------------------------------------
    bool remove_node( Node* current ){
        if( current->is_valid || current==root ) return false;
        for( Node* node: current->childs ){
            if(node!=nullptr) return false;
        }
        current->parent->childs[decode_char(current->label)] = nullptr;
        delete current;
        return true;
    }
    //--------------------------------------
    bool pop( Node* current, std::string word, int index ){
        // basic step ...
        if( index >= word.length() ){
            current->is_valid = false;
            return remove_node(current);
        }
        int code = decode_char( word.at(index));
        if(current->childs[code]==nullptr) 
            return false;
            
        if( pop( current->childs[code], word, index+1 ))
            return remove_node(current);
        return false;
    }
//=========================================
public:
    myTire(void){
        root = new Node();
        root->parent = nullptr;
        root->label  = EPSILON;
        // root->childs = std::vector<Node*>(26);
    }
    ~myTire(void){
        free(root);
    }
    //--------------------------------------
    bool search( std::string word ){

        Node* current = root;
        int code = -1;
        for( char character : word ){

            code = decode_char(character);
            if( code<0 ) return false;

            if( current->childs[code]==nullptr) return false;
            current = current->childs[code];
        }
        if( current->is_valid ) return true;
    }
    //--------------------------------------
    bool push( std::string word ){

        if( ! word_is_valid(word) ) return false; 
        // Teta(w) for checking if word has invalid character, 
        //then don't allocate memory and return without inserting 

        Node* current = root;
        int code = -1;
        for(char character: word){
            
            code = decode_char(character);
            if( current->childs[code]==nullptr){
                current->childs[code] = creat_node( current, character );
            }
            current = current->childs[code];
        }
        current->is_valid = true;
        return true;
        // Teta(w) for iteration on the word for inserting
    }
    //-----------------------------------------
    void pop( std::string word ){

        if( ! word_is_valid(word) ) return; 
        // Teta(w) for checking if word has invalid character!
        pop(root,word,0);
        return;
    }
    //--------------------------------------
    bool is_empty(void){ 
        for(Node* node: root->childs) 
            if(node!=nullptr) return false;
        return true;
    }
};

