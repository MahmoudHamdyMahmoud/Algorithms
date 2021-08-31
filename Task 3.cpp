#include <stdio.h>
#include <stdlib.h>

/*Creating two stacks*/
int stack1[10], stack2[10];
int top1=-1, top2=-1;
int count=0;
/*Function to make push for stack 1*/
void push1(int val){
	stack1[++top1] = val;
}
/*Function to make push for stack 2*/
void push2(int val){
	stack2[++top2] = val;
}
/*Function to make pop for stack 1*/
int pop1(){
	return (stack1[top1--]);
}
/*Function to make pop for stack 2*/
int pop2(){
	return (stack2[top2--]);
}
/*Function to make enqueue for queue using stack*/
void enqueue_st(){
	int val;
	printf("Please enter an element: ");
	scanf("%d", &val);
	push1(val);
	count++;
}
/*Function to make dequeue for queue using stack*/
void dequeue_st(){
	int i;
	for(i=0;i<=count;i++){
		push2(pop1());
	}
	pop2();
	count--;
	for(i=0;i<=count;i++){
		push1(pop2());
	}
}

/*Function to display the queue using stack*/
void display_st(){
	int i;
	for(i=0;i<=top1;i++){
		printf("%d", stack1[i]);
	}
}

/*Function to create queue using stack*/
void create()
{
    top1 = top2 = -1;
}
/*Creating Single linked list*/
struct node{
	int data;
	struct node* next;
};
/*Creating Queue using Linked List*/
struct queue{
	struct node *front, *rear;
};
/*Function to make an enqueue*/
void enqueue(queue* q, int val){
	struct node* temp = new node;
	temp->data = val;
	if (q->front == NULL) {
		q->front = temp;
	}
	else {
		q->rear->next = temp;
	}	
	q->rear = temp;
	q->rear-> next = q-> front;
}
/*Function to check if the queue is empty*/
int empty(queue *q){
	if (q->front == NULL) {
        printf("Queue is empty");
        return 0;
    }
}
/*Function to make a dequeue */
int dequeue(queue* q)
{
    empty(q);
    int value;
    if (q->front == q->rear) {
        value = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }
    else 
    {
        struct node* temp = q->front;
        value = temp->data;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }
  
    return value;
}
/*Function to display the linked list*/
void display(struct queue* q) {
	struct node* temp = q -> front;
	printf("\nElements in Queue are: ");
	while (temp->next != q->front){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d ", temp->data);
}
/*Function to know the front*/ 	
int front(queue* q){
	printf("\nThe front is: %d", q->front->data);
}
/*Function to know the rear*/ 	
int rear(queue* q){
	printf("\nThe rear is: %d", q->rear->data);
}

/* The main programm */
int main()
{
	/*Implement the queue using linked list*/
	queue* q = new queue;
	q->front = q->rear = NULL;
	enqueue(q, 5);
	enqueue(q, 4);
	enqueue(q, 2);
	enqueue(q, 22);
	enqueue(q, 13);
	display(q);
	front(q);
	rear(q);
	dequeue(q);
	dequeue(q);
	display(q);
	front(q);
	rear(q);
	enqueue(q, 15);
	enqueue(q, 32);
	dequeue(q);
	display(q);
	front(q);
	rear(q);
	/*Implement the queue using stack*/
	int ch;
 
    printf("\n\n1 - Enqueue element into queue");
    printf("\n2 - Dequeu element from queue");
    printf("\n3 - Display from queue");
    printf("\n4 - Exit");
    create();
    while (1)
    {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue_st();
            break;
        case 2:
            dequeue_st();
            break;
        case 3:
            display_st();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
	return 0;
}

