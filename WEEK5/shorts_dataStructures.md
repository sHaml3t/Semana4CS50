# SHORTS: Data Structures

* How could we choose the data structure necessary for our programs? 

## Arrays.

* Insertion is bad - lots of shifting  to fit an element in middle.
* Deletion us bad - lots of shifting after removing an element.
* Look up is great - random access, constant time.
* Relatively easy to sort.
* Stuck with a fixed size, no flexibility.

## Linked lists.

* Insertion is easy - just tack onto the front
* Deletion is easy - once you find the element
* Look up is bad - have to rely on linear search
* Relatively difficult to sort - unless you´re willing to compromise on a super-fast insertion and instead sort as you construct
* Relatively small size-wise (not as small as arrays)

## Hash tables.
* Insertion is a two-step process-hash, then add *(first we need to run our data though a hash function to get a hash code, and then we insert the element into the hash table at that location)*
* Deletion is easy - once you find the element 
* Lookup is on average better then with linked lists because you have the benefit of a real-world constant factor.
* Not an ideal data structure if sorting is the goal - just use an array.
* Can run the gamut of size.

## Trie.

* Insertion is complex - a lot of dynamic memory allocation.
* Deletion is easy - just free a node
* Lookup is fast - not quite as fast as an array, but almost
* Already sorted - sorts as you build in almost all situations
* Rapidly becomes huge, even with a very little data present, not great if space is at premium