#include <vector>
#include <iostream>
using namespace std;

/*============================================================================
This implement of linked-list let user save head / tail by it self and in class too,
Because of this, if user lost the head/tail in his/her code, can restore them by class methods,
Or let user change head or tail of list manually.
-> this can make secure-coding more challengeable.
Good luck !
*/
class SingleLinkedList {

private:
	
	int size = 0 ;
	//.....................................
	struct Node {
		int value;
		Node *next;
	};
	//.....................................
	struct Node * createNode( int value ){

		struct Node * newNode = new Node;

		if( newNode!=NULL ){
			newNode->value = value;
			newNode->next  = NULL ;
		}
		return newNode;
	}

//----------------------------------------
public:

	struct Node *head=NULL, *tail=NULL;

	//....................................
	struct Node * createList( int value ){

		head = createNode( value );
		tail = head ;

		if(head!=NULL) size++ ;
		return head;
	}
	/*....................................
	Priority in adding to head of list is by user-head.
	if can't add to the first of list return a False &
	if add it, will return True and user can find new head-ptr in head-var.
	*/
	bool addToHead( struct Node * user_head, int value){

		Node * tmp = createNode(value);
		if( !tmp ) return false ;

		tmp->next = user_head;
		head 	  = tmp ;
		size++ ;
		return true ;
	}
	//....................................

	bool addToTail( struct Node * user_tail, int value){

		Node * tmp = createNode(value);
		if( !tmp ) return false ;

		user_tail->next = tmp ;
		tail 			= tmp ;
		size++ ;
		return true ;
	}
	//....................................
	struct Node * delFromHead( struct Node * user_head ){

		head = user_head->next ;
		delete user_head ;
		size-- ;
		return head ;
	}
	//....................................
	struct Node * delFromTail( struct Node * user_head ){

		if( !user_head->next->next ){

			tail = user_head ;
			delete user_tail->next ;
			size-- ;
		}
		else delFromTail( user_head->next );
		return user_head ;
	}
	//....................................
	bool findValue( struct Node * user_head, int value ){

		if( user_head->value==value ) return true ;
		else if ( user_head->next==NULL ) return false;
		else return findValue( user_head->next,value );
	}
	//....................................
	int getSize(void){ return size ; }

	//....................................
	bool isEmpty( struct Node * user_head ){

		if( !user_head->next || size<1 ) return true;
		else return false;
	}
	//....................................
	void clear( struct Node * user_head ){

		if( !user_head ){
			head = NULL;
			tail = NULL;
			size = 0 ;
			return ;
		}
		clear( user_head->next );
		delete user_head ;
		return ;
	}
	//....................................
	bool addToIndex( struct Node * user_head, int value ){ 
		; 
	}

	//....................................
	bool delFromIndex( struct Node * user_head, int value ){ 
		;
	}
	//....................................

};

//============================================================================
//============================================================================
class DoubleLinkedList {

private:
	
	int size ;

	struct Node {
		int value;
		Node *next;
		Node *prev;
	};


public:

	// ... in implement queue!

};