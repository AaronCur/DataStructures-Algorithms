Q3. Add a new member function to the SLinkedList class with the following declaration:

###void splice(InputIterator position,list<T> & x);

Transfers all elements from list x into *this. The elements are inserted before the element
pointed to by the first argument (position). The list container x becomes empty after the
operation.
This can be achieved quite simply by calling the insertBefore() function from Q1 for each
element in x.
Note that x is an STL list, so don’t forget to #include <list>
It is assumed that iterator position is always valid (i.e. you do not need to check if position
is valid inside your function splice). Test your function thoroughly. 