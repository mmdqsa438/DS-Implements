#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <vector>
#include <iostream>
#define INFINIT 1e6
#endif
//-----------------------------------------------------------------------
template <typename hType>
class myMaxHeap{

private:
    typedef struct {
        int key;
        hType value;
    }Node;
    
    std::vector<Node> h_buffer;
    Node min_pr;
    int f_first;                   // free first place ...
    //......................
    
    void down_heapify( int root_index ){
        if( root_index > f_first/2 || root_index==0 ) 
            return;
        
        Node tmp = h_buffer[root_index];
        int next = root_index*2;
            
        if( tmp.key < h_buffer[next].key ){
            h_buffer[root_index] = h_buffer[next];
            h_buffer[next]       = tmp;
            down_heapify(next);
            
        }else if( tmp.key < h_buffer[++next].key ){
            h_buffer[root_index] = h_buffer[next];
            h_buffer[next]       = tmp;
            down_heapify(next);
        
        }else return;
    //......................    
    }
    
    void up_heapify( int current_index ){
        if( current_index==0 )
            return;
            
        Node tmp = h_buffer[current_index];
        
        int parent = current_index-1/2;
        if( current_index % 2 == 0 )
            parent = current_index/2;
            
        if( parent==0 ) return;
        if( tmp.key > h_buffer[parent].key ){
            h_buffer[current_index] = h_buffer[parent];
            h_buffer[parent]        = tmp;
            up_heapify(parent);
        }
    }
    //...................... 
    
    
public:
    
    //......................
    myMaxHeap(void){
    
        Node head;
        head.key = INFINIT;      // never change...
        h_buffer.push_back(head);
        
        f_first = 1;
        min_pr.key = INFINIT;    // min priority never be use, since more than 2 key exist...
    }
    //...................... 
    
    void push( hType value, int priority ){
    
        Node data = {priority,value};
        
        h_buffer.push_back( data );
        up_heapify( f_first );
        f_first++ ;
        
        if( min_pr.key > priority ){
            min_pr = data;
        }
    }
    //......................
    
    void pop(void){
        if( is_empty() ){
        min_pr.key = INFINIT ;
        return;
        }
        
        f_first-- ;
        h_buffer[1] = h_buffer[f_first];
        h_buffer.pop_back();
        down_heapify(1);
    }
    //......................
    
    int front( hType * cell ){                     // return priority key and put the value into cell and -1 if is empty...
        if( f_first <= 1 ) return -1;
        *cell = h_buffer[1].value;
        return h_buffer[1].key;
    }
    //......................
    
    bool is_empty(void){
        return f_first<=1?true:false;
    }
    //......................
    
    int h_size(void){
        return f_first-1;
    }
    
    //......................
    hType min_priority_value(void){
        return min_pr.value;
    }
    int min_priority_key(void){
        if(f_first==1)
            min_pr.key = INFINIT;
        return min_pr.key;
    }
    //......................
};
