
De Anza College CIS

Search this site
Home
CIS36A
CIS22C
CIS22A
Lab 4: Recursion with Your Linked List (100 pts)
Due Tuesday, October 24 at 11:20am on Canvas


Pair Programming Extra Credit Opportunity (5 pts)
If you and/or your partner has not done so already, watch the video and answer the questions on this worksheet (only one time per quarter).
Both partners fill in, sign and date the pair programming contract (once per assignment).
Upload the document(s) along with your Lab to Canvas.
Only ONE partner submits the lab assignment on Canvas. Please make sure both your names are on it.

For this assignment, you are going to add to (and revise) your List.h file that you wrote for Lab 2:

Part 1: Revise your List.h file from Lab 2
Look back over my comments on your Lab 2.
Make any changes to your code that I suggested.
Also, look over your own code as it is possible that I missed something the first time, but will not miss it when I look at your code again for this assignment.
Including other errors that might have been made in Lab 2, please make sure you check for the following:
Did you comment all of your functions in your List.h?
Did you set the linkprevious for the new nodes in the copy constructor?
Are you using assert for ALL or the preconditions for ALL of your functions?
Are you testing for the correct preconditions in your iterator functions (Hint: these should ALL be iterator != NULL)?
Did you remove the loop from removeStop and update the function to utilize the stop->linkprevious pointer?
I will again be looking over your List class and grading all of the functions, in addition to the ones you add below.
Please ask me if you are uncertain about something.

Part 1: Recursive Print (20 pts)

Please write the recursive List reverse print function, whose iterative version we wrote in class.
Below are the function signatures for the functions you are going to need:
   public:

        /**Additional Operations*/      

        void reversePrint() const;
        //Wrapper function that calls the reverse helper function to print a list in reverse
        //prints nothing if the List is empty



   private:
        void reversePrint(Node* node) const;
        //Helper function for the public reversePrint() function.
        //Recursively prints the data in a List in reverse.
     
Why do we need the private helper function here?
Since we are going to be reversing our list node by node, in a recursive fashion, we want to pass a one node at a time to our reverse function.
However, since our nodes are private, we cannot access them if we call the function inside of main.
Add these function signatures to your List.h file along with your other function prototypes inside the class definition.
Make sure that you place the reverse function inside the private portion of your List class definition and the print_reverse function prototype to the public portion of your List class definition.
Now, implement these two functions inside of List.h, under your section for additional operations.
Please do not implement the private helper function inside the class definition or you will lose points.
Important: Test each function carefully inside of your ListTest.cpp to make sure that it is working properly.


Part 2: Recursive Function to Determine if a List is in Sorted Order (20 pts)


Write a recursive function to determine whether or not a Linked List is in sorted order (smallest value to largest value).
Add the following function prototypes to your List class under the section for access functions, then implement the functions below the class definition:

    public:
        /**Access Functions*/      

        bool isSorted() const;

//Wrapper function that calls the isSorted helper function to determine whether 
//a list is sorted in ascending order.
//We will consider that a list is trivially sorted if it is empty.
//Therefore, no precondition is needed for this function



   private:
        bool isSorted(Node* node) const;
        //Helper function for the public isSorted() function.
        //Recursively determines whether a list is sorted in ascending order.


Part 3: Adding an Index to Your List Nodes (20 pts)
Next, you will add the following functions to your List.h.
We will use these functions to add an index to the  nodes in the List class.
Note that no other changes will be necessary to create an indexing system other than implementing these two functions.
Please do not add an additional field to your node struct for a node's index or an additional field in your List class.
These two functions will create the effect of an index without the need for an additional field in the Node struct.


/**Access Functions*/


int getIndex() const;
//Indicates the index of the Node where the iterator is currently pointing
//Nodes are numbered starting at 1 through the size of the list
//Pre: !offEnd()


/**Manipulation Procedures*/


void advanceToIndex(int index);
//Moves the iterator to the node whose index number is specified in the parameter
//Nodes are numbered starting at 1 through the size of the List
//Pre: size != 0
//Pre: index <= size
You can visualize the idea of the index with the below diagram

Note that in the above diagram, the a call to the getIndex function would return 2, as the iterator is pointing at the second node in the List.
Image of a linked list, whose nodes are numbered index 1 through 3

Part 4: Implementing Search as Part of Your List (40 pts)

Now, we are going to add two search functions to our List so that we can search for elements in our List.
The first of these functions is going to be a simple linear search function. 
Note that the pseudocode for the two functions is given in the class notes. 
If you are uncertain how to begin, the best approach would be to look at the notes from the Week 4 lessons.
You will need to add the following function prototype and function definition to your List.h:
/**Access Functions*/

int linearSearch(listdata data) const;
//Searchs the list, element by element, from the start of the List to the end of the List
//Returns the index of the element, if it is found in the List
//Does not call the indexing functions in the implementation
//Returns -1 if the element is not in the List
//Pre: length != 0
//Post: The iterator location has not been changed

You are also going to add a function to perform recursive binary search on your List.
Please note that you will receive no credit for your binarySearch function if it is not implemented recursively.
You will need to add the following public function prototype to your List.h:
public:

/**Access Functions*/


int binarySearch(listdata data) const;
//Returns the index where data is located in the List
//Calls the private helper function binarySearch to perform the search
//Pre: length != 0
//Pre: List is sorted (must test on a sorted list)
//Post: The iterator location has not been changed

private:

int binarySearch(int low, int high, listdata data) const;
//Recursively search the list by dividing the search space in half
//Returns the index of the element, if it is found in the List
//Returns -1 if the element is not in the List
//Post: The iterator location has not been changed

Important: For credit, you must implement the recursive version of binary search.

Recursive Binary Search Pseudocode 

Pre: A[] is sorted in increasing order
function binarySearch(A[1 ... n-1], value, low, high)
    if high < low
        return not found
    mid := low + (high-low)/2; //the midpoint formula
    if a[mid] := value
        return mid
    else if value < A[mid] //search the left half
        return binarySearch(A, value, low, mid-1)
    else //search the right half
        return binarySearch(A, value, mid+1, high)

Linear Search Pseudocode:

For each item in the list:
     if that item has the desired value
         stop the search and return the item's location.
 return -1.


What to Submit

Please submit your List.h file and your ListTest.cpp file
Note that you should have tested all preconditions, edge cases and "normal" cases of the functions that you have added to List.h in this Lab to receive full credit. -15 points for not testing thoroughly
No credit for the binary search function if you do not implement recursive binary search as show above.
Sign in|Recent Site Activity|Report Abuse|Print Page|Powered By Google Sites
