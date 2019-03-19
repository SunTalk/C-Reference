// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;
// self-referential structure                       
struct listNode {                                      
   char data; // each listNode contains a character 
   struct listNode *nextPtr; // pointer to next node

   friend bool operator==(const listNode& lhs, const listNode& rhs)
   {
      return lhs.data == rhs.data;
   }
}; 
typedef struct listNode ListNode; // synonym for struct listNode
typedef ListNode *ListNodePtr; // synonym for ListNode*

template<class Node>
struct node_wrap : public iterator<input_iterator_tag, Node>{

   Node *ptr;

   node_wrap(Node* p = nullptr): ptr(p){}

   char operator* () const {
    
      return ptr->data;
   }
   Node* operator->() const {return ptr;}

   node_wrap& operator++() {ptr = ptr->nextPtr; return *this;}
   bool operator==(const node_wrap& i) const
   {
        return ptr == i.ptr;
   } 
   bool operator!=(const node_wrap& i) const
   {
        return ptr != i.ptr;
   }
};

typedef node_wrap<ListNode> ListIter;



// prototypes
void insert(ListNodePtr *sPtr, char value);
char del(ListNodePtr *sPtr, char value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);

int main(void)
{ 
   ListNodePtr startPtr = NULL; // initially there are no nodes
   char item; // char entered by user

   insert(&startPtr, 'a');
   insert(&startPtr, 'b');
   insert(&startPtr, 'c');
   insert(&startPtr, 'd');

   printList(startPtr);
   ListIter start(startPtr), end(NULL);
   ListIter iter = find(start, end, 'c');

   printf("find %c\n", iter->data);
   // loop while user does not choose 3
   // while (choice != 3) { 

   //    switch (choice) { 
   //       case 1:
   //          printf("%s", "Enter a character: ");
   //          scanf("\n%c", &item);
   //          insert(&startPtr, item); // insert item in list
   //          printList(startPtr);
   //          break;
   //       case 2: // del an element
   //          // if list is not empty
   //          if (!isEmpty(startPtr)) { 
   //             printf("%s", "Enter character to be deld: ");
   //             scanf("\n%c", &item);

   //             // if character is found, remove it
   //             if (del(&startPtr, item)) { // remove item
   //                printf("%c deld.\n", item);
   //                printList(startPtr);
   //             } 
   //             else {
   //                printf("%c not found.\n\n", item);
   //             } 
   //          } 
   //          else {
   //             puts("List is empty.\n");
   //          } 

   //          break;
   //       default:
   //          puts("Invalid choice.\n");
   //          instructions();
   //          break;
   //    } // end switch

   //    printf("%s", "? ");
   //    scanf("%u", &choice);
   // } 

   // puts("End of run.");
} 

// display program instructions to user
void instructions(void)
{ 
   puts("Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to del an element from the list.\n"
      "   3 to end.");
} 

// insert a new value into the list in sorted order
void insert(ListNodePtr *sPtr, char value)
{ 
   ListNodePtr newPtr = new ListNode; // create node

   if (newPtr != NULL) { // is space available
      newPtr->data = value; // place value in node
      newPtr->nextPtr = NULL; // node does not link to another node

      ListNodePtr previousPtr = NULL;
      ListNodePtr currentPtr = *sPtr;

      // loop to find the correct location in the list       
      while (currentPtr != NULL && value > currentPtr->data) {
         previousPtr = currentPtr; // walk to ...               
         currentPtr = currentPtr->nextPtr; // ... next node 
      }                                          

      // insert new node at beginning of list
      if (previousPtr == NULL) { 
         newPtr->nextPtr = *sPtr;
         *sPtr = newPtr;
      } 
      else { // insert new node between previousPtr and currentPtr
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
      } 
   } 
   else {
      printf("%c not inserted. No memory available.\n", value);
   } 
} 

// del a list element
char del(ListNodePtr *sPtr, char value)
{ 
   // del first node if a match is found
   if (value == (*sPtr)->data) { 
      ListNodePtr tempPtr = *sPtr; // hold onto node being removed
      *sPtr = (*sPtr)->nextPtr; // de-thread the node
      free(tempPtr); // free the de-threaded node
      return value;
   } 
   else { 
      ListNodePtr previousPtr = *sPtr;
      ListNodePtr currentPtr = (*sPtr)->nextPtr;

      // loop to find the correct location in the list
      while (currentPtr != NULL && currentPtr->data != value) { 
         previousPtr = currentPtr; // walk to ...  
         currentPtr = currentPtr->nextPtr; // ... next node  
      } 

      // del node at currentPtr
      if (currentPtr != NULL) { 
         ListNodePtr tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free(tempPtr);
         return value;
      } 
   } 

   return '\0';
} 

// return 1 if the list is empty, 0 otherwise
int isEmpty(ListNodePtr sPtr)
{ 
   return sPtr == NULL;
} 

// print the list
void printList(ListNodePtr currentPtr)
{ 
   // if list is empty
   if (isEmpty(currentPtr)) {
      puts("List is empty.\n");
   } 
   else { 
      puts("The list is:");

      // while not the end of the list
      while (currentPtr != NULL) { 
         printf("%c --> ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;   
      } 

      puts("NULL\n");
   } 
} 




/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
