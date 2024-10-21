DS Practical Qb

Q-1 STACK ADT 
#include<stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(){
    if(top==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(){
    if(isFull()){
        printf("\nStack Overflow\n");
    }
    else{
        int data;
        top++;
        printf("\nEnter data to insert : ");
        scanf("%d", &data);
        stack[top] = data;
    }
}

void pop(){
    if(isEmpty()){
        printf("\nStack Underflow\n");
    }
    else{
        printf("\nPopped element : %d\n", stack[top]);
        top--;
    }
}

void peek(){
    if(isEmpty()){
        printf("\nStack Underflow\n");
    }
    else{
        printf("\nElement at the top : %d\n", stack[top]);
    }
}

void display(){
    if(isEmpty()){
        printf("\nStack is empty\n");
    }
    else {
    printf("Stack Elements : \n");
    for(int i = top;i>=0;i--){
        printf(" %d \n", stack[i]);
    }
}
}

int main(){
    int choice;

    do{
        printf("******MENU*****");
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice");
            break;
        }
    }while(choice!=5);

    return 0;
}

Q-2 infix to postfix
#include <stdio.h>
#define MAX 50

char stack[MAX];
int top = -1;

int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char data){
        top++;
        stack[top] = data;

}

void pop(){
    top--;
}

char peek(){
    return stack[top];
}

int prec(char c){
    // to get priority of the operators
    switch (c)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    }
    return 0;
}

void convertToPost(char infix[20]){
    char postfix[20];
    int k = 0;
    int i =0;
    while(infix[i]!='\0'){
        char c = infix[i];
        if((c>='a'&&c<='z') || (c>='A'&&c<='Z') || (c>='0'&&c<='9')){
            postfix[k] = c;
            k++;
        }
        else if(c == '('){
            push('(');
        }
        else if(c == ')'){
            while (!isEmpty() && peek() != '('){
                postfix[k] = peek();
                k++;
                pop();
            }
            pop();
        }
        else{
            // popping out all the operators out of stack until an operator
            //with priority greator than the char is found
            while (!isEmpty() && (prec(c) < prec(peek()) || (prec(c) == prec(peek()) && c != '^'))){
                postfix[k] = peek();
                k++;
                pop();
            }
            push(c);
        }
        i++;
    }
    while (!isEmpty()){
        postfix[k] = peek();
        k++;
        pop();
    }
    postfix[k] = '\0';
    // printing the postfix expression
    printf("Postfix Expression is: ");
    puts(postfix);

}

void main(){
    char infix[20];
    char res[20];
    printf("Enter the infix infix expression : ");
    gets(infix);

    convertToPost(infix);
}

Q-3 postfix exal
#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 50

int top = -1;
int stack[MAX]; // Integer stack for operand storage during evaluation
char postfix[MAX]; // To store the postfix expression

// Function to check if the stack is full
int isFull(){
    return top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(){
    return top == -1;
}

// Function to push an integer onto the stack
void push(int data){
    if (!isFull()) {
        top++;
        stack[top] = data;
    } else {
        printf("Stack Overflow\n");
    }
}

// Function to pop an integer from the stack
int pop(){
    if (!isEmpty()) {
        int c = stack[top];
        top--;
        return c;
    } else {
        printf("Stack Underflow\n");
        return -1; // Return a sentinel value if stack is empty
    }
}

// Function to evaluate a postfix expression
int postEvaluate(){
    int i, a, b;
    for(i = 0; i < strlen(postfix); i++){
        if(postfix[i] >= '0' && postfix[i] <= '9'){ // If it's an operand (digit)
            // Convert char to int and push onto the stack
            push(postfix[i] - '0');
        } else {
            // Pop two operands from the stack
            a = pop();
            b = pop();
            // Apply the operator
            switch(postfix[i]){
                case '+':
                    push(b + a);
                    break;
                case '-':
                    push(b - a);
                    break;
                case '*':
                    push(b * a);
                    break;
                case '/':
                    push(b / a);
                    break;
                case '^':
                    push(pow(b, a));
                    break;
                case '%':
                    push(b % a);
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", postfix[i]);
                    break;
            }
        }
    }
    return pop(); // Return the result of the evaluation
}

int main(){
    printf("Enter a postfix expression: ");
    scanf("%s", postfix); // Input the postfix expression
    printf("Result: %d\n", postEvaluate()); // Evaluate and display the result

    return 0;
}

Q-4 Queue 
#include<stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int isEmpty(){
    if(front==-1 && rear==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(){
    if(rear==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enque(){
    if(isFull()){
        printf("\nQueue Overflow\n");
    }
    else{
        int data;
        printf("\nEnter data to insert : ");
        scanf("%d", &data);
        if(isEmpty()){
            front = rear = 0;
        }else{
            rear++;
        }
        queue[rear] = data;
    }
}

void deque(){
    int item;
    if(isEmpty()){
        printf("\nqueue Underflow\n");
    }
    else{
        printf("\nDequeued element : %d", queue[front]);
        if(front==rear){
            front = rear = -1;
        }
        else{
            front++;
        }
    }
}

void peek(){
    if(isEmpty()){
        printf("\nQueue Underflow\n");
    }
    else{
        printf("\nElement at the front : %d\n", queue[front]);
    }
}

void display(){
    if(isEmpty()){
        printf("\nQueue is empty\n");
    }
    else {
    printf("Queue Elements : \n");
    for(int i = front;i<=rear;i++){
        printf(" %d \n", queue[i]);
    }
}
}

int main(){
    int choice;

    do{
        printf("******MENU*****");
        printf("\n1. Enque\n2. Deque\n3. Peek\n4. Display\n5. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            enque();
            break;
        case 2:
            deque();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice");
            break;
        }
    }while(choice!=5);

    return 0;
}

Q-5 CirQ 
#include<stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int isEmpty(){
    if(front==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(){
    if(front == ((rear+1)%MAX)){
        return 1;
    }
    else{
        return 0;
    }
}

void enque(){
    if(isFull()){
        printf("\nQueue Overflow\n");
    }
    else{
        int data;
        printf("\nEnter data to insert : ");
        scanf("%d", &data);
        if(isEmpty()){
            front = rear = 0;
        }else{
            rear = (rear+1)%MAX;
        }
        queue[rear] = data;
    }
}

void deque(){
    int item;
    if(isEmpty()){
        printf("\nqueue Underflow\n");
    }
    else{
        printf("\nDequeued element : %d", queue[front]);
        if(front==rear){
            front = rear = -1;
        }
        else{
            front = (front+1)%MAX;
        }
    }
}

void peek(){
    if(isEmpty()){
        printf("\nQueue Underflow\n");
    }
    else{
        printf("\nElement at the front : %d\n", queue[front]);
    }
}

void display(){
    if(isEmpty()){
        printf("\nQueue is empty\n");
    }
    else {
    int i = front;
    printf("Queue Elements : \n");
    while(i!=rear){
        printf("\n %d", queue[i]);
        i = (i+1)%MAX;
    }
    printf("\n %d\n", queue[rear]);
}
}

int main(){
    int choice;

    do{
        printf("******MENU*****");
        printf("\n1. Enque\n2. Deque\n3. Peek\n4. Display\n5. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            enque();
            break;
        case 2:
            deque();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice");
            break;
        }
    }while(choice!=5);

    return 0;
}

Q-6 SLL ins
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next; // Pointer to the next node
} node;

node* head = NULL; // Initialize head to NULL

// Function to create a new node
node* createNode(int data) {
    node* newnode = (node*)malloc(sizeof(node)); // Allocate memory for a new node
    newnode->data = data; // Set node data
    newnode->next = NULL; // Initialize next to NULL
    return newnode;
}

// Function to create a linked list with n nodes
void createLinkedList(int n) {
    int data;
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        node* newnode = createNode(data); // Create a new node
        if (head == NULL) {
            head = newnode; // Set head if the list is empty
        } else {
            node* temp = head;
            while (temp->next != NULL) { // Traverse to the end
                temp = temp->next;
            }
            temp->next = newnode; // Link new node at the end
        }
    }
}

// Function to insert a node at the beginning
void insertAtBeginning(int data) {
    node* newnode = createNode(data); // Create a new node
    newnode->next = head; // Link new node to the current head
    head = newnode; // Update head to the new node
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    node* newnode = createNode(data); // Create a new node
    if (head == NULL) {
        head = newnode; // Set head if the list is empty
    } else {
        node* temp = head;
        while (temp->next != NULL) { // Traverse to the end
            temp = temp->next;
        }
        temp->next = newnode; // Link new node at the end
    }
}

// Function to insert a node before a specified node
void insertBefore(int specifiedData, int newData) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* newnode = createNode(newData); // Create a new node
    if (head->data == specifiedData) {
        newnode->next = head; // Insert before the head
        head = newnode; // Update head
        return;
    }

    node* temp = head;
    while (temp->next != NULL && temp->next->data != specifiedData) {
        temp = temp->next; // Traverse the list
    }

    if (temp->next == NULL) {
        printf("Node with data %d not found.\n", specifiedData);
    } else {
        newnode->next = temp->next; // Link new node to the next node
        temp->next = newnode; // Link temp node to the new node
    }
}

// Function to display the linked list
void displayList() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n"); // Indicate end of the list
}

int main() {
    int n, choice, data, specifiedData;

    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);
    createLinkedList(n); // Create linked list with n nodes

    do {
        printf("\n****** MENU ******\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert Before a Specified Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter the specified node data: ");
                scanf("%d", &specifiedData);
                printf("Enter data to insert before %d: ", specifiedData);
                scanf("%d", &data);
                insertBefore(specifiedData, data);
                break;
            case 4:
                displayList();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

Q-7 Sll del
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next; // Pointer to the next node
} node;

node* head = NULL; // Initialize head to NULL

// Function to create a new node
node* createNode(int data) {
    node* newnode = (node*)malloc(sizeof(node)); // Allocate memory for a new node
    newnode->data = data; // Set node data
    newnode->next = NULL; // Initialize next to NULL
    return newnode;
}

// Function to create a linked list with n nodes
void createLinkedList(int n) {
    int data;
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        node* newnode = createNode(data); // Create a new node
        if (head == NULL) {
            head = newnode; // Set head if the list is empty
        } else {
            node* temp = head;
            while (temp->next != NULL) { // Traverse to the end
                temp = temp->next;
            }
            temp->next = newnode; // Link new node at the end
        }
    }
}

// Function to delete a node at the beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    node* temp = head;
    head = head->next; // Move head to the next node
    free(temp); // Free the memory of the original head node
    printf("Node at the beginning deleted.\n");
}

// Function to delete a node at the end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (head->next == NULL) { // If there's only one node
        free(head);
        head = NULL;
        printf("Node at the end deleted.\n");
        return;
    }
    node* temp = head;
    while (temp->next->next != NULL) { // Traverse to the second last node
        temp = temp->next;
    }
    free(temp->next); // Free the last node
    temp->next = NULL; // Set the second last node's next to NULL
    printf("Node at the end deleted.\n");
}

// Function to delete a node before a specified node
void deleteBefore(int specifiedData) {
    if (head == NULL || head->next == NULL) {
        printf("List is too short to perform this operation.\n");
        return;
    }
    if (head->next->data == specifiedData) { // If the node before the specified node is head
        deleteAtBeginning(); // Simply delete the first node
        return;
    }
    node* temp = head;
    while (temp->next->next != NULL && temp->next->next->data != specifiedData) {
        temp = temp->next;
    }
    if (temp->next->next == NULL) {
        printf("Node with data %d not found in the list.\n", specifiedData);
    } else {
        node* toDelete = temp->next; // Node to delete is just after `temp`
        temp->next = toDelete->next; // Link temp's next to the node after toDelete
        free(toDelete); // Free the node
        printf("Node before %d deleted.\n", specifiedData);
    }
}


// Function to display the linked list
void displayList() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n"); // Indicate end of the list
}

int main() {
    int n, choice, data, specifiedData;

    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);
    createLinkedList(n); // Create linked list with n nodes

     do {
        printf("\n****** MENU ******\n");
        printf("1. Delete at Beginning\n");
        printf("2. Delete at End\n");
        printf("3. Delete Before a Specified Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deleteAtBeginning();
                break;
            case 2:
                deleteAtEnd();
                break;
            case 3:
                printf("Enter the specified node data: ");
                scanf("%d", &specifiedData);
                deleteBefore(specifiedData);
                break;
            case 4:
                displayList();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

Q-8 no of nodes 
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* head = NULL;

void createLinkedList(int n) {
    int data, i;
    node* temp;
    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

void insertBefore(int specifiedData, int newData) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = newData;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->data == specifiedData) { // Insert before the first node
        newNode->next = head;
        head = newNode;
        return;
    }

    node* temp = head;
    while (temp->next != NULL && temp->next->data != specifiedData) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Node with data %d not found.\n", specifiedData);
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int countNodes() {
    int count = 0;
    node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


void sortLinkedList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* i;
    node* j;
    int tempData;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                // Swap data
                tempData = i->data;
                i->data = j->data;
                j->data = tempData;
            }
        }
    }
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, n, specifiedData, newData;

    do {
        printf("\n****** MENU ******\n");
        printf("1. Create Linked List with n Nodes\n");
        printf("2. Insert Before a Specified Node\n");
        printf("3. Count Number of Nodes\n");
        printf("4. Sort Linked List in Ascending Order\n");
        printf("5. Display List (Forward Traversal)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                createLinkedList(n);
                break;
            case 2:
                printf("Enter the specified node data: ");
                scanf("%d", &specifiedData);
                printf("Enter the new data to insert: ");
                scanf("%d", &newData);
                insertBefore(specifiedData, newData);
                break;
            case 3:
                printf("Number of nodes: %d\n", countNodes());
                break;
            case 4:
                sortLinkedList();
                printf("Linked list sorted in ascending order.\n");
                break;
            case 5:
                displayList();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

Q-9 search 
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} node;

// Function to create a linked list with n nodes
node* createLinkedList(int n) {
    node* head = NULL;
    node* temp = NULL;
    int data;

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

void insertAtEnd(node** head, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int countNodes(node* head) {
    int count = 0;
    node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


int searchElement(node* head, int target) {
    node* temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == target) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1; // Element not found
}


void displayList(node* head) {
    node* temp = head;

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    node* head = NULL;
    int choice, n, data, target;

    do {
        printf("\nMenu:\n");
        printf("1. Create Linked List with n Nodes\n");
        printf("2. Insert at End\n");
        printf("3. Count Number of Nodes\n");
        printf("4. Search for an Element\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                head = createLinkedList(n);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &target);
                int position = searchElement(head, target);
                if (position != -1) {
                    printf("Element found at position %d\n", position);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 5:
                displayList(head);
                break;
            case 6:

                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

Q-10 to Q-12 CLL

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* head = NULL;

void createCLL(int n) {
    node* temp;
    node* newnode;
    int data;

    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newnode = (node*)malloc(sizeof(node));
        newnode->data = data;
        newnode->next = NULL;

        if (head == NULL) {  // For the first node
            head = newnode;
            newnode->next = head;
            temp = head;
        } else {  // For subsequent nodes
            temp->next = newnode;
            newnode->next = head;  // Point last node to head to make it circular
            temp = newnode;
        }
    }
}

void insertAtBeginning(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;

    if (head == NULL) {  // If the list is empty
        head = newnode;
        newnode->next = head;  // Single node points to itself
    } else {
        node* temp = head;

        // Traverse to the last node
        while (temp->next != head) {
            temp = temp->next;
        }

        newnode->next = head;  // New node points to current head
        temp->next = newnode;   // Last node points to the new node
        head = newnode;         // Update head to the new node
    }

    printf("Node inserted at the beginning.\n");
}


void insertAtEnd(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;  // Single node points to itself
    } else {
        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;  // Traverse to the last node
        }
        temp->next = newnode;   // Link last node to new node
        newnode->next = head;   // Link new node to head
    }
    printf("Node inserted at the end.\n");
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {  // Only one node in the list
        free(head);
        head = NULL;
        printf("Node deleted at the beginning.\n");
        return;
    }

    node* temp = head;
    node* last = head;

    // Traverse to the last node
    while (last->next != head) {
        last = last->next;
    }

    head = head->next;   // Move head to the next node
    last->next = head;   // Update last node's next to the new head

    free(temp);
    printf("Node deleted at the beginning.\n");
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {  // Only one node in the list
        free(head);
        head = NULL;
        printf("Node deleted at the end.\n");
        return;
    }

    node* temp = head;
    node* prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;  // Traverse to the last node
    }

    prev->next = head;  // Second-last node now points to head
    free(temp);         // Free the last node

    printf("Node deleted at the end.\n");
}

int countNodes() {
    if (head == NULL) {
        return 0;
    }

    node* temp = head;
    int count = 0;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);  // Traverse until we reach the head again

    return count;
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* temp = head;
    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);  // Traverse until we reach the head again

    printf("(head)\n");
}

int main() {
    int choice, n, data;

    do {
        printf("\n****** MENU ******\n");
        printf("1. Create Circular Linked List with n Nodes\n");
        printf("2. Insert at End\n");
        printf("3. Delete at Beginning\n");
        printf("4. Delete at End\n");
        printf("5. Count No of Nodes\n");
        printf("6. Display (Forward Traversal)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                createCLL(n);
                break;
            case 2:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                deleteAtBeginning();
                break;
            case 4:
                deleteAtEnd();
                break;
            case 5:
                printf("Number of nodes: %d\n", countNodes());
                break;
            case 6:
                display();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

Q-13 stack ll
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *createNode(){
    node *n;
    n = (node *)malloc(sizeof(node *));
    if(n == NULL){
    printf("OVERFLOW");
    return NULL;
    }
    printf("\nEnter data:");
    scanf("%d", &n->data);
    n->next = NULL;
    return n;
}

node *top = NULL;

void push() {
    node* n = createNode();
    n->next = top;
    top = n;
    printf("%d pushed to the stack \n", n->data);
}

void pop() {
    if(top==NULL){
    printf("Stack underflow");
    return;
    }
    node* temp = top;
    top = top->next;
    printf("%d popped from the stack.", temp->data);
    free(temp);
}

void peek(){
    if(top==NULL){
    printf("Stack underflow");
    return;
    }
    printf("Element at top is %d ", top->data);
}

void display() {
    if(top == NULL){
    printf("Stack is empty\n");
    return;
    }
    node *temp = top;
    printf("stack elements : \n");
    while(temp != NULL){
    printf("%d\n", temp->data);
    temp = temp->next;
    }
}

int main(){
    int choice = 0;
    while(1){
        printf("\nMenu\n");
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            case 5:
            exit(0);
            default:
            printf("Invalid choice !");
        }
    }
    return 0;
}

Q-14 queue ll
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;


typedef struct queue {
    struct node* front;
    struct node* rear;
}queue;

node *createNode(){
    node *n;
    n = (node *)malloc(sizeof(node *));
    if(n == NULL){
        printf("OVERFLOW");
        return NULL;
    }
    printf("\nEnter data:");
    scanf("%d", &n->data);
    n->next = NULL;
    return n;
}

queue* initializeQueue() {
    queue* q = (queue *)malloc(sizeof(queue *));
    if (q == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(queue* q) {
    node* n = createNode();
    if (q->rear == NULL) {
        q->front = n;
        q->rear = n;
    } else {
        q->rear->next = n;
        q->rear = n;
    }
    printf("%d enqueued into the queue\n", n->data);
}

void dequeue(queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty, cannot dequeue\n");
        return;
    }
    node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    printf("%d dequeued from the queue\n", temp->data);
    free(temp);
}

void display(queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main () {
    int choice=0;
    queue* q = initializeQueue();
    while(choice != 4) {
        printf("\n\nMenu");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter your choice \n");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
            enqueue(q);
            break;
            case 2:
            dequeue(q);
            break;
            case 3:
            display(q);
            break;
            case 4:
            printf("Exiting....");
            break;
            default:
            printf("Please Enter valid choice ");
        };
    }
}

Q-15 to Q-18 BST 
#include<stdio.h> 
#include<stdlib.h>

typedef struct node {
    struct node* left;
    int data;
    struct node* right;
} node;

node *root = NULL;

node* createNode(int data){
    node* n;

    n = (node*)malloc(sizeof(node));
    if(n != NULL){
        n->data = data;
        n->left = NULL;
        n->right = NULL;

        return n;
    }
}

node* insert(node* root, int data){
    node* n;
    n = createNode(data);

    if(root == NULL){
        root = n;
    } else {
        if(data > root->data){
            root->right = insert(root->right, data);
        } else {
            root->left = insert(root->left, data);
        }
    }
    return root;
}

void inorder(node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

node* findMin(node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

node* findMax(node* root){
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

node* search(node* root, int key){
    if(root == NULL || root->data == key){
        return root;
    } else {
        if(key < root->data){
            return search(root->left, key);
        } else {
            return search(root->right, key);
        }
    }
}

node* delete(node* root, int key){
    if(root == NULL){
        return root;
    } else {
        if(key < root->data){
            root->left = delete(root->left, key);
        } else if(key > root->data){
            root->right = delete(root->right, key);
        } else {
                if(root->left == NULL){
                    node* temp = root->right;
                    free(root);
                    return temp;
                } else if(root->right == NULL){
                    node* temp = root->left;
                    free(root);
                    return temp;
                }
                node* temp = findMin(root->right);
                root->data = temp->data;
                root->right = delete(root->right, temp->data);
        }
        return root;
    }
}

void display(node* root){
    int c;
    printf("\nEnter order of traversal:\n1. Preorder\n2. Postorder\n3. Inorder\n");
    scanf("%d", &c);

    switch(c){
        case 1:
            preorder(root);
            break;
        case 2:
            postorder(root);
            break;
        case 3:
            inorder(root);
            break;
    }
}

int countNodes(node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countInternalNodes(node* root){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return 0;
    }
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

int countLeafNodes(node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int height(node* root){
    if(root == NULL){
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void main(){
    int ch, data, nodes, intNodes, leafNodes, h;

    while(1){
        printf("\nBST Operations:\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Count no. of nodes\n6. Count no. of leaf nodes\n7. Count no. of Internal Nodes\n8. Height of tree\n9. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("Enter data you want to insert:");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Node inserted\n");
                break;
            case 2:
                printf("Enter element you want to search:");
                scanf("%d", &data);
                if(search(root, data) == NULL){
                    printf("Element not found.\n");
                } else {
                    printf("Element found.\n");
                }
                break;
            case 3:
                printf("Enter element you want to delete:");
                scanf("%d", &data);
                root = delete(root, data);
                break;
            case 4:
                display(root);
                break;
            case 5:
                nodes = countNodes(root);
                printf("Total no. of nodes = %d", nodes);
                break;
            case 6:
                leafNodes = countLeafNodes(root);
                printf("Total no. of leaf nodes = %d", leafNodes);
                break;
            case 7:
                intNodes = countInternalNodes(root);
                printf("Total no. of internal nodes = %d", intNodes);
                break;
            case 8:
                h = height(root);
                printf("Height of tree = %d", h);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

Q-19 and Q-20 DFS BFS 
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int stack[MAX_SIZE];

int front = -1, rear = -1, top = -1;

void enqueue(int data)
{
    if (rear == MAX_SIZE - 1)
    {
    printf("Queue is full\n");
    }
    else
    {
    if (front == -1)
    {
    front = 0;
    }
    rear++;
    queue[rear] = data;
    }
}
int dequeue()
{
    int data;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        data = queue[front];
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
        return data;
    }
}

void push(int data)
{
    if (top == MAX_SIZE - 1)
    {
    printf("Stack is full\n");
    }
    else
    {
    top++;
    stack[top] = data;
    }
}

int pop()
{
    int data;
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        data = stack[top];
        top--;
        return data;
    }
}

bool isStackEmpty()
{
    return top == -1;
}

int graph[10][10];
int visited[10];
int n;

void bfs(int start)
{
    enqueue(start);
    visited[start] = 1;
    printf("BFS Traversal: ");
    while (front != -1)
    {
        int current = dequeue();
        printf("%d ", current);
        for (int i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfs(int start)
{
    visited[start] = 1;
    printf("DFS Traversal: \n");
    printf("%d \n");

    for (int j = 0; j < n; j++)
    {
        if (visited[j] == 0 && graph[start][j] == 1)
        {
            dfs(j);
        }
    }
}

int main()
{
    int choice, start;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the starting node: ");
    scanf("%d", &start);
    printf("1. BFS\n");
    printf("2. DFS\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0; // Reset visited array for both BFS and DFS
    }
    switch (choice)
    {
        case 1:
        bfs(start);
        break;
        case 2:
        dfs(start);
        break;
        default:
        printf("Invalid choice.\n");
    }
    return 0;
}
 
Q-21 hashng
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int hash(int key) {
    return key % SIZE;
}

void insert(int hashTable[], int key, int *count) {
    if (*count != SIZE) {
        int index = hash(key);

        while (hashTable[index] != -1) {
            index = (index + 1) % SIZE;
        }

        hashTable[index] = key;
        (*count)++;
    } else {
        printf("Hash table is full.\n");
    }
}

int search(int hashTable[], int key) {
    int index = hash(key);

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (index + 1) % SIZE;
    }

    return -1;
}

void display(int hashTable[]) {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; ++i) {
        if (hashTable[i] != -1) {
            printf("Index %d: %d\n", i, hashTable[i]);
        } else {
            printf("Index %d: -\n", i);
        }
    }
}


int main() {
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        hashTable[i] = -1;
    }

    int choice, key, count = 0;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(hashTable, key, &count);
                break;

            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                int searchResult = search(hashTable, key);
                if (searchResult != -1) {
                    printf("Element %d found at index %d in the hash table.\n", key, searchResult);
                } else {
                    printf("Element %d not found in the hash table.\n", key);
                }
                break;

            case 3:
                display(hashTable);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

Q-22 quad 
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int hash(int key) {
    return key % SIZE;
}

void insert(int hashTable[], int key, int *count) {
    if (*count != SIZE) {
        int index = hash(key);
        int i = 1;

        while (hashTable[index] != -1) {
            index = (hash(key) + i * i) % SIZE;
            i++;
        }

        hashTable[index] = key;
        (*count)++;
    } else {
        printf("Hash table is full.\n");
    }
}

int search(int hashTable[], int key) {
    int index = hash(key);
    int i = 1;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (hash(key) + i * i) % SIZE;
        i++;
    }

    return -1;
}

void display(int hashTable[]) {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; ++i) {
        if (hashTable[i] != -1) {
            printf("Index %d: %d\n", i, hashTable[i]);
        } else {
            printf("Index %d: -\n", i);
        }
    }
}


int main() {
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        hashTable[i] = -1;
    }

    int choice, key, count = 0;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(hashTable, key, &count);
                break;

            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                int searchResult = search(hashTable, key);
                if (searchResult != -1) {
                    printf("Element %d found at index %d in the hash table.\n", key, searchResult);
                } else {
                    printf("Element %d not found in the hash table.\n", key);
                }
                break;

            case 3:
                display(hashTable);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
