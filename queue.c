#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

typedef struct element {
    /* Pointer to array holding string.
     * This array needs to be explicitly allocated and freed
     */
    char *value;
    struct element *next;
} element_t;

typedef struct {
    element_t *head; /* Linked list of elements */
    element_t *tail;
    size_t size;
} queue_t;
/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t)) ; 
    if ( q != NULL ) 
        q->head = NULL ;
        q->tail = NULL ;
        q->size = 0 ;
        returm q ;
    else return NULL ;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    if ( q != NULL ) return ;
    
    element_t *cur = q->head ;
    element_t *cur_next = NULL ;
    
    if ( !q ) {
        free(0)
        return ;
    }
    
    while( cur != NULL ) {
        cur_next = cur-> next ;
        free(cur->value) ;
        free(cur) ;
        cur = cur_next ;
    }
    
    free(q) ;
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */

bool q_insert_head(queue_t *q, char *s)
{
    element_t *new ;
    new = malloc( sizeof( elemnet_t ) ) ;
    if ( ! new ) return false ;
    
    new->value = malloc( sizeof( char ) ) ;
    if ( ! new->value ) {
        free( new->value ) ;
        return false ;
    }
    
    strcpy( new->value, s ) ;
    new->next = NULL ;
    
    if ( q->head = NULL ) {
        q->head = new ;
        q->tail = new ;
    }
    
    else {
        new->next = q->head ;
        q->head = new ;
    }
    
    q->size ++ ;
    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{   
    if( ! q ) return false ;
    
    element_t *new ;
    new = malloc( sizeof( element_t ) ) ;
    if ( ! new ) return false ;
    new->value = malloc( sizeof( char ) ) ;
    if ( !new->value ) {
        free( new ) ;
        return false ;
    }
    
    strcpy( new->value, s ) ;
    new->next = NULL ;
    
    if ( q->tail ) {
        q->head = new ;
        q->tail = new ;
    }
    
    else {
        tail->next = new ;
        tail = tail->next ;
    }
        
    q->size ++ ;    
    return true;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    if ( !q || !sp || !q->head->value ) return false ;
    
    element_t *tmp = q->head ;
    q->head = tmp->next ;
    strcpy( sp, tmp->value, bufsize = -1 ) ;
    if ( q->head == NULL ) q->tail = NULL ;
    q->size -- ;
    
    free( tmp->value ) ;
    free( tmp ) ;
    
    
    
    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
size_t q_size(queue_t *q)
{
    if ( !q || !q->head ) return 0 ;
    return q->size ;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    if ( !q || !q->head ) return ;
    
    char *sp ;
    size_t bufsize
    queue_t *tmp = malloc(sizeof(queue_t)) ; 
    while ( q_size != 0 ) {
        q_remove_head( q, sp, bufsize ) ;
        q_insert_head( tmp, sp ) ;
    }
    
    q->head = tmp->head ;
    q->tail = tmp->tail ;
    q->size = tmp ->size ;
    free( tmp->value ) ;
    free( tmp ) ;
    
}

/*
 * The function's sorting algorithm should be merge sort.
 */


queue_t* sortList(queue_t* head) {
    //If List Contain a Single or 0 Node
    if(head == NULL || head ->next == NULL)
        return head;
        
        
    queue_t *temp = NULL;
    queue_t *slow = head;
    queue_t *fast = head;
        
    // 2 pointer appraoach / turtle-hare Algorithm (Finding the middle element)
    while(fast !=  NULL && fast -> next != NULL) {
        temp = slow;
        slow = slow->next;          //slow increment by 1
        fast = fast ->next ->next;  //fast incremented by 2   
    }   
    
    temp -> next = NULL;            //end of first left half
        
    queue_t* l1 = sortList(head);    //left half recursive call
    queue_t* l2 = sortList(slow);    //right half recursive call
        
    return mergelist(l1, l2);         //mergelist Function call
            
}
    
    //MergeSort Function O(n*logn)
queue_t* mergelist(ListNode *l1, ListNode *l2) {
    queue_t *ptr = malloc(sizeof(queue_t)) ;
    queue_t *curr = ptr;
        
    while(l1 != NULL && l2 != NULL) {
        if(l1->val <= l2->val) {
            curr -> next = l1;
            l1 = l1 -> next;
        }
        
        else {
            curr -> next = l2;
            l2 = l2 -> next;
        }
        
        curr = curr ->next;
     }
        
     //for unqual length linked list
        
    if(l1 != NULL) {
        curr -> next = l1;
        l1 = l1->next;
    }
        
    if(l2 != NULL) {
        curr -> next = l2;
        l2 = l2 ->next;
    }
        
    return ptr->next;
}
/*
void Merge( element_t *L_start, element_t *L_end,
           element_t *R_start, element_t *R_end, element_t *Output) {
  vector<element_t> tmp;
  element_t *L_walk = L_start, *R_walk = R_start;
  while (L_walk != L_end || R_walk != R_end) {
    if (L_walk != L_end && (R_walk == R_end || strcmp( L_walk->value, R_walk->value ) < 0  ) )  // (**)
      tmp.push_back(*L_ptr++);
    else
      tmp.push_back(*R_ptr++);
  }
  // 再把合併好的資料抄回去。
  for (const auto &data : tmp) *Output++ = data;
}

void merge_sort(element_t **head)
{
    
    queue *reverse ;
    

}*/

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    if (!q || !q->head)
        return;

    merge_sort(&q->head);
    element_t *walk = q->head;
    while (walk->next)
        walk = walk->next;

    q->tail = walk;
}
