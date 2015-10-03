#include <stdlib.h>


typedef enum __QUEUE_STATUS {Q_SUCCESS, Q_FAILURE} QUEUE_STATUS;

typedef struct __Node Node;
typedef struct __Node{
	Node *next, *prev;
	int val;
} Node;

typedef struct __Queue{
	Node *head, *tail;
	int count;
} Queue;


QUEUE_STATUS
InitQueue(Queue *q){
	q->count = 0;
	return Q_SUCCESS;
}


Node *
NewItem(){
	return (Node *) malloc(sizeof(Node));
}


QUEUE_STATUS
FreeItem(Node *item){
	free(item);
	return Q_SUCCESS;
}


QUEUE_STATUS
AddQueue(Queue *q, Node *n){
	//first item
	if(q->count == 0){
		q->head = n;
		q->tail = n;
	}else{
		q->tail->next = n;
		n->prev = q->tail;
		q->tail = n;
	}
	
	//always increment count
	q->count++;
	//always point head.prev to tail and tail.next to head
	q->head->prev = q->tail;
	q->tail->next = q->head;

	return Q_SUCCESS;
}
