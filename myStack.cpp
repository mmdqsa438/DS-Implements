/*-----------------------------------------------------------------------
-------------------------------------------------------------------------
This is an educational implementation of the "Stack" data structure,
in Dr. Morteza Keshtkaran's Data Structures class - Shiraz University - Fall 2025


This stack can be used by a novice user,
without the need for knowledge of how stacks work.

This stack structure :
1. implemented with an array
2. automatically tries to allocate more space for the stack if space is low.
3. halves the size of the stack, if more than three-quarters of it is unused.

Good luck...

-----------------------------------------------------------------------*/
#include <iostream>
using namespace std;

template< typename T >
class myStack {

private:
    
    int cap = 32 ,
        top = 0  ;        // first free cell & size
    
    T *stack ;
    //........................................
    bool reallocate( T * buffer,int size, int newcap ){
        
        T * tmp = new T[newcap];
        if( tmp == NULL ) return false ;
        
        for(int i=0; i<size; i++) tmp[i] = buffer[i];
        
        delete buffer;
        stack = tmp ;
        cap   = newcap ;
        return true;
    }
    //........................................
    
public:
    
    myStack( void ){
        stack = new T[cap];
    }

    ~myStack( void ){
        delete stack ;
    }

    bool push( int value ){
        
        if ( top >= cap ){ 
            if( reallocate( stack, top, cap*2 )==false ) 
                return false;
        }
        stack[top] = value;
        top++ ;
        return true ;
    }
    //........................................
    bool pop(void){
        
        if( top>=1 && top < cap/4 ){
            if( reallocate( stack, top, cap/2 )==false )
                return false;
        }
        else if(top<1) return false;
        
        top-- ;
        return true ;
    }
    //........................................
    bool topOf( int * cell ){
        
        if( top <=0 ) return false;
        
        *cell = stack[top-1];
        return true;
    }
    //........................................
    int size(void){ return top; }
    int capOf(void){ return cap; }
    bool empty(void){ return top>=1?false:true ; }
    void clear(void){ top=0; }
    //........................................
};

// int main(){
    
//     myStack<int> *st = new myStack<int>();
//     delete st;
// }
