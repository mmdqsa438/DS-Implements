#include<iostream>
#include<stdexcept>
#include<exception>

template <typename aType>
class myAvl{
private:
    typedef struct Node{
        aType value;
        int height = 0;
        int l_height= -1;
        int r_height= -1;
        Node* 
            parent= nullptr,
            left  = nullptr,
            right = nullptr;
    } Node;

    Node* root = nullptr;

    Node* create_node( aType value ){
        Node* tmp = new Node;
        tmp->value = value;
        return tmp;
    }
    Node* left_rotate( Node* current ) {}
    Node* right_rotate( Node* current ) {}

    int push( aType value, Node* current ){

        if(current==nullptr) 
            current = create_node(value);
            return current->height;

        if( value < current->value ){
            current->l_height = push(value,current->left);
            current->left->parent = current;
        }
        else if( value > current->value ){
            current->r_height = push(value,current->right);
            current->right->parent = current;
        }

        if(current->l_height > current->r_height) current->height = current->l_height+1;
        else current->height = current->r_height+1;

        // I. state 1:
        if(current->right!=nullptr){
            if(current->r_height - current->l_height == 2 &&
                current->right->r_height - current->right->l_height == 1 )
                    current = left_rotate(current);
        }
        // II. state 2:






        return current->height;





    }
public:
    // this is for forcing user to override < > = for his class type !
    myAvl(aType in_value){ 
        try{
            aType v1,v2;
            v1  > v2;
            v1  < v2;
            v1 == v2;
            v1 != v2;
            v1 <= v2;
            v1 >= v2;
            root = new Node;
            root->value = in_value;
        }
        catch( std::exception& e){
            throw std::runtime_error(std::string("input type has not overloaded boolean operations:  >, <, ==, !=, <=, >=\n"));
        }
        
    }
    ~myAvl(void){}

    void push( aType value){ push(value,root);}
};


