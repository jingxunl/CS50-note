# Data Structures Summary

## Arrays
- Insertion is bad — lots of shifting to fit an element in the middle.
- Deletion is bad — lots of shifting after removing an element (in the middle).
- Searching is great — random access, constant time.
- Relatively easy to sort.
- Relatively small size-wise.
- Stuck with fixed size, no flexibility.

## Linked Lists
- Insertion is easy — just tack onto the front.
- Deletion is easy — once you find the element, just change the pointer and free the node.
- Searching is bad — have to rely on linear search.
- Relatively difficult to sort — unless you are willing to compromise on super-fast insertion and instead sort as you construct. (not great for sorting data.)
- Relatively small size-wise. (not as small as array duu to the storage of pointer of next.)

## Hash Tables
- Insertion is a two-step process — hash, then add.
- Deletion is easy — once you find the element.
- Searching is on average better than with linked lists because you have the benefit of a real-world constant factor.
    - Both linked list and hash table are $O(n)$, but the real-time will be faster when using hash table.
- Not an ideal data structure if sorting is the goal — just use an array.
- Can run the gamut of size. (probably waste lots of space.)

## Tries
- Insertion is complex but constant time — a lot of dynamic memory allocation, but gets easier as you go.
- Deletion is easy — just need to free a node.
- Searching is fast — $O(1)$, not quite as fast as arrays, but almost. (Only depends on the length of the data.)
- Already sorted — sorted as you build in almost all situations.
- Rapidly becomes huge — even with very little data present, not great if space is at a premium.