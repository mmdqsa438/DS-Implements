/*-----------------------------------------------------------------------
-------------------------------------------------------------------------
This is an educational implementation of the "Queue" data structure,
in Dr. Morteza Keshtkaran's Data Structures class - Shiraz University - Fall 2025


This Queue can be used by a novice user,
without the need for knowledge of how Queue work.

This Queue structure :
1. implemented with head-link-list consept...
2. automatically tries to allocate more space for the Q if space is low.
3. halves the size of the Q, if more than three-quarters of it is unused.
4. doesn't use "using namespace std;" !!!

Good luck...

-----------------------------------------------------------------------*/
template< typename T >
class myQueue {

private:
    
    typedef struct Node {                       // simple-link-list for Q imp...
        T value ;
        Node *next = nullptr ;
    } Node ;
    //........................................
    int q_size = 0;                                // first free cell & size of Q

    Node *q_head = nullptr,                     // it's a header of link-list which not use, and start of Q is always after it...
         *q_last = nullptr;
    //........................................
    bool free_node(Node *node){

        if( node == nullptr) 
            return false;

        free_node(node->next);
        delete node ;

        return true ;
    }
    //........................................
public:

    myQueue( void ){
        q_head = new Node ;                     // allocating header of Q
        q_last = q_head ;                       // Q is empty ...
    }
    //........................................
    ~myQueue(void){
        if(free_node(q_head)) delete q_head ;
    }
    //........................................
    bool push( T value ){

        Node *tmp = new Node;
        if( tmp == nullptr ) return false ;

        tmp->value   = value;
        q_last->next = tmp;
        q_last       = tmp;
        q_size++ ;

        return true ;
    }
    //........................................
    bool pop( void ){
        
        if( q_size == 0 ) return false ;

        if( q_size == 1 ){
            q_last = q_head ;
        }
        
        Node *tmp    = q_head->next ;
        q_head->next = tmp->next ;

        delete tmp ;
        q_size-- ;

        return true ;
    }
    //........................................
    bool front( T * cell ){
        
        if( q_size == 0 ) return false;
        
        *cell = q_head->next->value ;

        return true;
    }
    //........................................
    int get_size( void ){ 

        return q_size;
    }
    //........................................
    bool is_empty( void ){

        return q_size>0?false:true ; 
    }
    //........................................
    void clear( void ){

        // no need to check q_head's Null, it has defined by constractor
        free_node( q_head->next );
        q_last = q_head ;
    }
    //........................................
};


// void test_func(void){
//     myQueue<int> q ;
//     int a ;
//     std::cout << "size "<< q.size() << std::endl ;
//     std::cout << "front "<<q.front(&a) << std::endl ;
//     std::cout << "empty "<<q.is_empty() << std::endl ;
//     std::cout << "push "<<q.push(12) << std::endl ;
//     std::cout << "push "<<q.push(13) << std::endl ;
//     std::cout << "size "<<q.size() << std::endl ;
//     std::cout << "front "<<q.front(&a) << std::endl ;
//     std::cout << "pop "<<q.pop() << std::endl ;
//     std::cout << "front "<<q.front(&a) << std::endl ;
//     q.clear();
//     std::cout << "clear"<< std::endl ;
// }
// int main(){
//     test_func();
//     return 0 ;
// }
