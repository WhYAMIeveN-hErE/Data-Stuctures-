# Data-Stuctures-

LAB 1
1. Write a C++ menu-driven program to sort a given array in ascending order. Design proper functions, maintain boundary conditions, and follow coding best practices. The menus are as follows,

a.       Bubble Sort

b.      Selection Sort

c.       Insertion Sort

d.      Exit

 

2. Convert the sorting program into a header file and include it into a new cpp file. Write a C++ menu-driven program for linear and binary search in this new cpp file. Utilize any of the sorting functions in the included header file to sort the input array before performing a binary search. Design proper functions, maintain boundary conditions and follow coding best practices. The menu-driven program supports,

a.       Linear Search

b.      Binary Search

c.       Exit



LAB 2
1. Write a C++ menu-driven program to determine whether a number is a  Palindrome, Armstrong, or Perfect Number. Normal variable and array declarations are not allowed. Utilize dynamic memory allocation (DMA). Design proper functions, maintain boundary conditions, and follow coding best practices. The menu is as follows,

a.       Palindrome

b.      Armstrong Number

c.       Perfect Number

d.      Exit

 

2. Write a C++ menu-driven program that calculates and displays the area of a square, cube, rectangle, and cuboid. Consider length as the side value for the square and cuboid. Identify proper data members and member functions. Design and create an appropriate class for the given scenario.  Maintain proper boundary conditions and follow coding best practices. The menus are as follows,
 a) Square
 b) Cube
 c) Rectangle

 d) Cuboid
 e) Exit


LAB 3
A. Write a C++ menu-driven program to implement List ADT using an array of size 5. Maintain proper boundary conditions and follow good coding practices. The List ADT has the following operations,

1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Rotate
10. Exit


LAB 4
A. Write a C++ menu-driven program to implement List ADT using a singly linked list. Maintain proper boundary conditions and follow good coding practices. The List ADT has the following operations,

1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit

B. Write a C++ menu-driven program to implement List ADT using a singly linked list. You have a gethead() private member function that returns the address of the head value of a list. Maintain proper boundary conditions and follow good coding practices. The List ADT has the following operations,

1. Insert Ascending
2. Merge
3. Display
4. Exit

Option 1 inserts a node so the list is always in ascending order. Option 2 takes two lists as input, and merges two lists into a third list. The third list should also be in ascending order. Convert the file into a header file and include it in a C++ file. The second C++ consists of 3 lists and has the following operations,

1. Insert List1
2. Insert List2
3. Merge into List3
4. Display
5. Exit
The time complexity of operation 1 is O(n), operation 2 is O(m), and operation 3 should be done in O(n + m).


LAB 5
A. Write a C++ menu-driven program to implement List ADT using a doubly linked list with a tail. Maintain proper boundary conditions and follow good coding practices. The List ADT has the following operations, 
 
1. Insert Beginning 
2. Insert End 
3. Insert Position 
4. Delete Beginning 
5. Delete End 
6. Delete Position 
7. Search 
8. Display 
9. Exit 
 
What is the time complexity of each of the operations? (K4) 
 

B. Write a C++ menu-driven program to implement List ADT using a circular linked list. Maintain proper boundary conditions and follow good coding practices. The List ADT has the following operations,  
  
1. Insert Beginning  
2. Insert End  
3. Insert Position  
4. Delete Beginning  
5. Delete End  
6. Delete Position  
7. Search  
8. Display  
9. Exit  
  
What is the time complexity of each of the operations? (K4)  
  
C. An operating system allocates a fixed time slot CPU time for processes using a round-robin scheduling algorithm. The fixed time slot will be initialized before the start of the menu-driven program. Implement the round-robin scheduling algorithm using the circular linked list. Implement the program by including the appropriate header file. It consists of the following operations.  
  
1. Insert Process  
2. Execute  
3. Exit  
  
The "Insert Process" will get an integer time from the user and add it to the queue.  
  
The "Execute" operation will execute a deletion in the beginning operation and subtract the fixed time from the process. If the processing time falls below 0 then the process is considered to have completed its execution, otherwise, the remaining time after subtraction is inserted at the end of the circular linked list.  
  
What is the time complexity of each of the operations? (K4)   



LAB 6
A. Write a separate C++ menu-driven program to implement stack ADT using a character array of size 5. Maintain proper boundary conditions and follow good coding practices. Stack ADT has the following operations, 
 
1. Push 
2. Pop 
3. Peek 
4. Exit 
 
What is the time complexity of each of the operations? (K4)

B. Write a separate C++ menu-driven program to implement stack ADT using a character singly linked list. Maintain proper boundary conditions and follow good coding practices. Stack ADT has the following operations, 
 
1. Push 
2. Pop 
3. Peek 
4. Exit 
 
What is the time complexity of each of the operations? (K4) 
 
C. Write a C++ menu-driven program to implement infix to postfix and postfix evaluation. Use the singly linked list (SLL) to implement the stack ADT as a header file. Maintain proper boundary conditions and follow good coding practices. The program has the following operations, 
 
1. Get Infix 
2. Convert Infix 
3. Evaluate Postfix 
4. Exit 
 
The Get Infix option gets a valid infix expression and stores it efficiently. 
The Convert Infix option converts the stored infix expression into a postfix expression. It prints the postfix expression at the end after conversion. 
The Evaluate Postfix expression calculates and prints the output of the converted infix expression.  
For the "Assignment" Operators, implement only for "=" operator. 

What is the time complexity of each of the operations? (K4) 

D. Write a C++ menu-driven program to get a string of '(' and ')' parenthesis from the user and check whether they are balanced. Identify the optimal ADT and data structure to solve the mentioned problem. You can consider all previous header files for the solution's implementation. Maintain proper boundary conditions and follow good coding practices. The program has the following operations, 
 
1. Check Balance 
2. Exit 
 
The Check Balance operations get a string of open and closed parentheses. Additionally, it displays whether the parenthesis is balanced or not. Explore at least two designs (solutions) before implementing your solution. 

 
What is the time complexity of each solution, and what is the optimal solution? Justify your answer. (K5) 



LAB 7
A. Write a separate C++ menu-driven program to implement Queue ADT using an integer array of size 5. Maintain proper boundary conditions and follow good coding practices. The Queue ADT has the following operations,

1. Enqueue
2. Dequeue
3. Peek
4. Exit

What is the time complexity of each of the operations? (K4)

B. Write a separate C++ menu-driven program to implement Circular Queue ADT using an integer array of size 5. Maintain proper boundary conditions and follow good coding practices. The Circular Queue ADT has the following operations,

1. Enqueue
2. Dequeue
3. Peek
4. Exit

What is the time complexity of each of the operations? (K4)

C. Write a separate C++ menu-driven program to implement Queue ADT using an integer-linked list. Maintain proper boundary conditions and follow good coding practices. The Queue ADT has the following operations,

1. Enqueue
2. Dequeue
3. Peek
4. Exit

What is the time complexity of each of the operations? (K4)

D. Take a string from the user that consists of the '+' symbol. Process the string such that the final string does not include the '+' symbol and the immediate left non-'+' symbol. Select and choose the optimal ADT. Implement the program by including the appropriate header file.

Eg: 
Input: 45fgd+++ab+c
Output: 45ac

What is the time complexity of each solution, and what ADT, and data structure will you use? What is the optimal solution? Justify your answer
 


LAB 8
A. Utilize C++ STL if needed. Write a C++ program to solve the following,

Polycarp was presented with some sequence of integers a of length n (1≤a 
i
​
 ≤n). A sequence can make Polycarp happy only if it consists of different numbers (i.e. distinct numbers).

In order to make his sequence like this, Polycarp is going to make some (possibly zero) number of moves.
In one move, he can:

remove the first (leftmost) element of the sequence.

For example, in one move, the sequence [3,1,4,3] will produce the sequence [1, 4, 3], which consists of different numbers.   

Determine the minimum number of moves he needs to make so that in the remaining sequence all elements are different. In other words, find the length of the smallest prefix of the given sequence a, after removing which all values in the sequence will be unique.   

Input

The first line of the input contains a single integer t (1≤t≤100) — the number of test cases.
The description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤2000) — the length of the sequence a.
The second line of each test case contains n integers a 
1
​
 ,a 
2
​
 ,…,a 
n
​
  (1≤a 
i
​
 ≤n).

Output

For each test case, output a single integer — the minimum number of moves Polycarp needs to make.

B. Write a separate C++ menu-driven program to implement Tree ADT using a character binary tree. Maintain proper boundary conditions and follow good coding practices. The Tree ADT has the following operations, 
 
1. Insert 
2. Preorder 
3. Inorder 
4. Postorder 
5. Search 
6. Exit 
 
What is the time complexity of each of the operations? (K4) 
