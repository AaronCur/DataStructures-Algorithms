### Q4. Create a std::list of integers and populate it with 20 random numbers between 1 and 10
(don’t seed the random number generator to ensure you always have the same sequence of
numbers). Create another list of the same type called dest but leave it empty.
Using the list::splice() member function, move all the nodes in the list starting from:
the last occurrence of 2 (not including 2) to the next occurrence of 4 (not including 4)
to the start of dest.
In the event that 4 does not exist, move all the nodes from the last occurrence of 2 onwards (to the
end) to the start of dest.
Hint: You will need to use the STL find algorithm and reverse iterators in your solution. 