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



LAB 9
A. Utilize C++ STL to solve the following (K5),

Nene invented a new game based on an increasing sequence of integers a 
1
​
 ,a 
2
​
 ,...,a 
k
​
 .

In this game, initially n players are lined up in a row. In each of the rounds of this game, the following happens:

Nene finds the a 
1
​
 -th, a 
2
​
 -th,...,a 
k
​
 -th players in a row. They are kicked out of the game simultaneously. If the i-th player in a row should be kicked out, but there are fewer than i players in a row, they are skipped.
Once no one is kicked out of the game in some round, all the players that are still in the game are declared as winners.

For example, consider the game with a=[3,5] and n=5 players. Let the players be named player A, player B, ..., player E in the order they are lined up initially. Then,

Before the first round, players are lined up as ABCDE. Nene finds the 3-rd and the 5-th players in a row. These are players C and E. They are kicked out in the first round.
Now players are lined up as ABD. Nene finds the 3-rd and the 5-th players in a row. The 3-rd player is player D and there is no 5-th player in a row. Thus, only player D is kicked out in the second round.
In the third round, no one is kicked out of the game, so the game ends after this round.
Players A and B are declared as the winners.
Nene has not yet decided how many people would join the game initially. Nene gave you q integers n 
1
​
 ,n 
2
​
 ,...,n 
q
​
B.
There are n participants in a competition, participant i having a strength of s 
i
​
 .

Every participant wonders how much of an advantage they have over the other best participant. In other words, each participant i wants to know the difference between s 
i
​
  and s 
j
​
 , where j is the strongest participant in the competition, not counting i (a difference can be negative).   

So, they ask you for your help! For each i (1≤i≤n) output the difference between s 
i
​
  and the maximum strength of any participant other than participant i.   




C. Write a separate C++ menu-driven program to implement Tree ADT using a binary search tree. Maintain proper boundary conditions and follow good coding practices. The Tree ADT has the following operations, 
 
1. Insert 
2. Preorder 
3. Inorder 
4. Postorder 
5. Search 
6. Exit 
 
What is the time complexity of each of the operations? (K4) 

D. Add a "construct expression tree" method to the binary tree data structure from the previous lab code—import stack from the standard template library (STL) to construct the expression tree. Import the Tree ADT program into another program that gets a valid postfix expression, constructs, and prints the expression tree. It consists of the following operations. 
 
1. Postfix Expression 
2. Construct Expression Tree 
3. Preorder 
4. Inorder 
5. Postorder 
6. Exit 
 
What is the time complexity of each of the operations? (K4) 




LAB 10
A. Utilize C++ STL if needed. Write a C++ program to solve the following, 


Polycarp was presented with some sequence of integers a of length n (1 <= a_i <= n). A sequence can make Polycarp happy only if it consists of different numbers (i.e. distinct numbers).

In order to make his sequence like this, Polycarp is going to make some (possibly zero) number of moves.
In one move, he can:

* remove the first (leftmost) element of the sequence.

For example, in one move, the sequence [3, 1, 4, 3] will produce the sequence [1, 4, 3], which consists of different numbers.

Determine the minimum number of moves he needs to make so that in the remaining sequence all elements are different. In other words, find the length of the smallest prefix of the given sequence $a$, after removing which all values in the sequence will be unique.

B. Utilize C++ STL if needed. Write a C++ program to solve the following, 

Three guys play a game: first, each person writes down n
 distinct words of length 3
. Then, they total up the number of points as follows:

if a word was written by one person — that person gets 3 points,
if a word was written by two people — each of the two gets 1 point,
if a word was written by all — nobody gets any points.
In the end, how many points does each player have?
Input
The input consists of multiple test cases. The first line contains an integer t
 (1≤t≤100
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n
 (1≤n≤1000
) — the number of words written by each person.

The following three lines each contain n
 distinct strings — the words written by each person. Each string consists of 3
 lowercase English characters.

Output
For each test case, output three space-separated integers — the number of points each of the three guys earned. You should output the answers in the same order as the input; the i
-th integer should be the number of points earned by the i
-th guy.

C. Write a separate C++ menu-driven program to implement Priority Queue ADT using a max heap. Maintain proper boundary conditions and follow good coding practices. The Priority Queue ADT has the following operations, 
 
1. Insert 
2. Delete 
3. Display 
4. Search 
5. Sort (Heap Sort)  
6. Exit 

What is the time complexity of each of the operations? (K4) 


LAB 11
A. Write a separate C++ menu-driven program to implement Hash ADT with Linear Probing. Maintain proper boundary conditions and follow good coding practices. The Hash ADT has the following operations,

1. Insert
2. Delete
3. Search
4. Display
5. Exit

What is the time complexity of each of the operations? (K4)

B. Write a separate C++ menu-driven program to implement Hash ADT with Quadratic Probing. Maintain proper boundary conditions and follow good coding practices. The Hash ADT has the following operations,

1. Insert
2. Delete
3. Search
4. Display
5. Exit

What is the time complexity of each of the operations? (K4)

C. Write a separate C++ menu-driven program to implement Hash ADT with Separate Chaining. Maintain proper boundary conditions and follow good coding practices. The Hash ADT has the following operations,

1. Insert
2. Delete
3. Search
4. Exit

What is the time complexity of each of the operations? (K4)



LAB 12
A. Write a separate C++ menu-driven program to implement Graph ADT with an adjacency matrix. Maintain proper boundary conditions and follow good coding practices. The Graph ADT has the following operations,

1. Insert
2. Delete
3. Search
4. Display
5. Exit

What is the time complexity of each of the operations? (K4)

B. Write a separate C++ menu-driven program to implement Graph ADT with an adjacency list. Maintain proper boundary conditions and follow good coding practices. The Graph ADT has the following operations,

1. Insert
2. Delete
3. Search
4. Display
5. Exit

What is the time complexity of each of the operations? (K4)

C. Write a separate C++ menu-driven program to implement Graph ADT with the implementation for Prim’s algorithm, Kruskal’s algorithm, and Dijkstra’s algorithm. Maintain proper boundary conditions and follow good coding practices. (K3)






  
