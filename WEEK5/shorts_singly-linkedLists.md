# Shorts: Singly-linked lists

* This allows us to grow and shrink a collection of values with no waste space

* Structs, give us "containers" for holding variables of different data types, typically.

* A linked list **node** is a special struct that contains a value of any datatype, and a pointer.

* This have an special way to define in code, since we need a temporary name to point at the next node.

## Coding the datatype

```c
typedef struct sllist
{
    VALUE val;
    struct sllist* next;
}
sllnode;
```
- Now we can refer at it as *sllnode*

* In order to work with linkedd lists effectievely, there are a number of operations that we need to understand:
    1. Create a linked list when it doesn´t already exist.
    <br>
    1. Search through a linked list to find an element.
    <br>
    1. Insert a new node into the linked list.
    <br>
    1. Delete a single element from a linked list.
    <br>
    1. Delete an entire linked list.

## Create a linked list
```c
    sllnode* create(VALUE val);
```
- This would be the prototype, finally passing in one argument val(some arbitrary datatype). And returning me a pointer, to a singly pointer, which we need it to point to that list when we are done.

* **Steps involved:**
    1. Dynamically allocate space for a new sllnode.
    1. Check to make sure we didn´t run out of memory.
    1. Initialize the node´s val field
    1. Initialize the node´s next field.
    1. Return a pointer to the newly created sllnode.

## Search through a linked list to find an element

* A prototype for this function may look like this:

```c
bool find(sll node* head, VALUE val);
```
- The first argument, being a pointer to tge first element of the linked list(You may need to keep track of this, even put in a global variable, when crated a list, we always always want to keep track of the very first element of the list, that way we can follow the whole chain without having to keep pointers intact to every single element)

- The second is the random value datatype that we are looking for, inside of the nodes in the list.

* **Steps involved:**
    1. Create a traversal pointer pointing to the list´s head.(a duplicate of the first element, we don´t need to malloc more for trav next since its a new pointer poitning to the same thing)
    1. If the current node´s val field is what we´re looking for, report success.
    1. If not, set the traversal pointer to the next pointer in the list and go back to step b.
    1. If you´ve reached the end of the list, report a failure.


**note** Its not necessary to keep any sort since we don´t keep track of where we actually are, which element we´re at using since they don´t have indexes, just the pointer to the first element. Not random access is allowed.

## Insert a new node into the linked list.

* We cant keep creating new lists, so the way to add new nodes to our previous lists is this prototype
```c
    sllnode* insert(sllnode* head, VALUE val);
```
- This case is conformed by passing two arguments, the head pointer(which keeps track of the first element) and then de value you want to add the list, returning a pointer to the new head of the linked list

* **Steps involved:**
    1. Dynamically allocate space for a new sllnode.
    1. Check to make sure we didn´t run out of memory.
    1. Populate and insert the node *at the beginning of the linked list*. (Cuz we have the pointer at the beginning)
    1. Return a pointer to the new head of the linked list.
        *note* We connect our last node we created to the list first, otherwise we would be orphaning the rest of the list, breaking the chain.
        ```c
        list = insert(list, 12);
        ```

## Delete an entire linked list.

* We´ve malloc a lot of space already, we need to free it once we´re done.

 ```c
void destroy(sllnode* head);
```
* **Steps involved:**

    1. If you´ve reached the null pointer, stop.
    1. Delete *the rest of the list.*
    1. Free the current node.
 ```c
destroy(list);
```

- For every not null pointer node, we call the destroy function, getting rid of the next element, following the other node chain till we reach the a null value at which our list will be pointing. Then back to the first step, **stop**. Once we *destroyed* the last element with a value pointer, our function will be deleting the rest of the list from right to left, from the last element to the first.
*note* if yo free the first element, the head, we aint got any way to refer to that list and a leak memory could happen.



## Delete a single element from a linked list.

* Recalling that this is a chain, if we delete a node in the middle of the list, since that node was connected to the rest of the list, we need a way to connect the backward element, this is possible using *double link lists* 