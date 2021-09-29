/* In a singly linked list represented by :
struct Node{
  int data;
  struct Node* next;
}
Implement func: struct Node* MoveNodes(struct Node* head, int x);

The function accepts a pointer to the start of the linked list, 'head' and an integer 'x' as an argument.
Arrange the linked list in such a way that all nodes smaller than 'x' comes before nodes greater or equal to 'x'
and return the modified linked list.
** if list is empty return NULL (or none in python)
** do not create a new linked list just modify and return
** preserve the original relative order of the moved nodes

Example 1 : 2 -> 6 -> 3 -> 5 -> 1 -> 7
x: 5
output: 2 -> 3 -> 1 -> 6 -> 5 -> 7
*/
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};
 
Node *newNode(int data)
{
    struct Node* new_node = new Node;
    new_node->data  = data;
    new_node->next = NULL;
    return new_node;
}
 

struct Node* MoveNodes(struct Node *head, int x)
{
       // write code here
    struct Node *smallerHead = NULL, *smallerLast = NULL;
    struct Node *greaterLast = NULL, *greaterHead = NULL;
    struct Node *equalHead = NULL, *equalLast = NULL;
 
   
    while (head != NULL)
    {
        if (head->data == x)
        {
            if (equalHead == NULL)
                equalHead = equalLast = head;
            else
            {
                equalLast->next = head;
                equalLast = equalLast->next;
            }
        }

        else if (head->data < x)
        {
            if (smallerHead == NULL)
                smallerLast = smallerHead = head;
            else
            {
                smallerLast->next = head;
                smallerLast = head;
            }
        }
        else 
        {
            if (greaterHead == NULL)
                greaterLast = greaterHead = head;
            else
            {
                greaterLast->next  = head;
                greaterLast = head;
            }
        }
 
        head = head->next;
    }

    if (greaterLast != NULL)
        greaterLast->next = NULL;

    if (smallerHead == NULL)
    {
        if (equalHead == NULL)
            return greaterHead;
        equalLast->next = greaterHead;
        return equalHead;
    }

    if (equalHead == NULL)
    {
        smallerLast->next = greaterHead;
        return smallerHead;
    }

    smallerLast->next = equalHead;
    equalLast->next = greaterHead;
    return  smallerHead;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
 
//read only
int main()
{
   //  custom input 
    struct Node* head = newNode(10);
    head->next = newNode(4);
    head->next->next = newNode(5);
    head->next->next->next = newNode(30);
    head->next->next->next->next = newNode(2);
    head->next->next->next->next->next = newNode(50);
 
    int x = 3;
    head = partition(head, x);
    printList(head);
    return 0;
}
