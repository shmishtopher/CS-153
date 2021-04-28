/**
 * CS 153 PROGRAM ASSIGNMENT #11
 * 
 * This source file describes a primitive
 * linked list data structure
 *
 * @author    Modified by Christopher Schmitt
 * @version   5.10.2019
 */


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


struct NODE
{
  struct NODE *link;
  int value;
};


typedef struct NODE Node;


Node *insertFirst(Node **ptrToHeadPtr, int val)
{
  Node *node = (Node *) malloc(sizeof(Node));
  node->value = val;
  node->link = *ptrToHeadPtr;
  *ptrToHeadPtr = node;
  return node;
}


void traverse(Node *p)
{
  while (p != NULL)
  {
    printf("%d ", p->value);
    p = p->link;
  }
}


void freeList(Node *p)
{
  Node *temp;
  while (p != NULL)
  {
    temp = p;
    p = p->link;
    free(temp);
  }
}


/** 
 * This function counts the number of times a value appears in a linked list
 * @param {Node *} start - a pointer to node
 * @param {int} target - the value to test against
 * @returns {int} - a number of times "target" appears
 */
int countTarget(Node *start, int target)
{
  int length = 0;
  while (start != NULL)
  {
    if (start->value == target)
      length += 1;
    start = start->link;
  }
  return length;
}


/**
 * This functio deletes the first node of a linked list and returns the new head.
 * @param {Node **} head - a pointer to the head pointer
 * @returns {Node *} - the new head
 */
Node *deleteFirst(Node **head)
{
  if (*head == NULL)
    return NULL;
  
  Node *temp = *head;
  *head = (*head)->link;
  free(temp);

  return *head;
}


/**
 * This funtion appends a new node to the linked list
 * @param {Node **} head - A pointer to the head pointer
 * @param {int} val - The value to put in the new node
 * @returns {Node *} - A pointer to the new node
 */
Node *insertLast(Node **head, int val)
{
  Node *newNode = (Node *) malloc(sizeof(Node));

  if (newNode == NULL)
    return newNode;
  
  if (*head == NULL)
    *head = newNode;
  else
  {
    Node *current = *head;
    while (current->link != NULL)
      current = current->link;
    current->link = newNode;
  }

  newNode->value = val;
  newNode->link = NULL;

  return newNode;
}


/**
 * This function deletes the last element of a linked list
 * @param {Node **} head - a pointer the the head pointer
 * @returns {Node *} - the last element of the list
 */
Node *deleteLast(Node **head)
{
  if (*head == NULL)
    return NULL;

  if ((*head)->link == NULL)
  {
    Node *temp = *head;
    *head = NULL;
    free(temp);
    return NULL;
  }
  
  Node *current = *head;
  while (current->link->link != NULL)
    current = current->link;
  
  Node *temp = current->link;
  current->link = NULL;
  free(temp);

  return current;
}


int main()
{
  Node *HeadPtr = NULL;

  insertFirst(&HeadPtr, 0);
  insertFirst(&HeadPtr, 2);
  insertFirst(&HeadPtr, 4);
  insertFirst(&HeadPtr, 6);
  insertFirst(&HeadPtr, 8);

  traverse(HeadPtr);
  printf("\n");

  deleteFirst(&HeadPtr);
  traverse(HeadPtr);
  printf("\n");

  insertLast(&HeadPtr, 8);
  traverse(HeadPtr);
  printf("\n");

  deleteLast(&HeadPtr);
  traverse(HeadPtr);
  printf("\n");
    
  return 0;
}