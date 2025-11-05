/*-----------------------------------------------------------------------
-----------------------------------------------------------------------
This is an educational implementation 
of the stack data structure.
By means of an array and usable 
by a novice user, 
without requiring knowledge of how the stack works.

This stack structure 
is implemented with an array 
and automatically attempts to allocate
more space for the stack if space is low.

It also halve the size if 
more than three-quarters of the stack is unused.

Good luck...

-----------------------------------------------------------------------*/
#include <iostream>
using namespace std;

class myStack {

private:
    
    int cap    = 32 ,
        *stack = new int[cap],
        top    = 0;        // first free cell & size
    //........................................
    bool reallocate( int * buffer,int size, int newcap ){
        
        int * tmp = new int[newcap];
        if( tmp == NULL ) return false ;
        
        for(int i=0; i<size; i++) tmp[i] = buffer[i];
        
        delete buffer;
        stack = tmp ;
        cap   = newcap ;
        return true;
    }
    //........................................
    
public:
    
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
//int main(){;}
