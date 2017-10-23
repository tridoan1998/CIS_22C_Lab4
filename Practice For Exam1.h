#ifndef Stack_H_
#define Stack_H_

#include <iostream>
#include <cstddef>
#include <assert.h>

using namespace std;

template <class listdata>
class List
{
private:
    Struct Node{
            listdata data;
            Node* linkprevious;
            Node* linknext;
            
            Node(listdata newData)
            {
                data = newData;
                linkprevious = NULL;
                linknext = NULL;
            }
        Node* start;
        Node* stop;
        Node* Iterator;
        int size;
    }
    public:
    /**Constructors and Destructors*/

    List();
    //Default constructor; initializes and empty list
    //Postcondition: display the empty list.

    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition: delete the list and free memory.

    List(const List& list);
    //Copy constructor. Initializes list to have the same elements as another list (makes a copy of the list object)
    //Postcondition: a copy of the linked list is made.


    /**Accessors*/

    listdata getStart() const;
    //Returns the data of the first element
    //Postcondition: Returns the first data in the list
    //Precondition: make sure the list is not empty.

    listdata getStop() const;
    //Returns the data of the last element
    //Postcondition: Returns the last data in the list
    //Precondition: make sure the list is not empty and the node point to NULL.

    listdata getIterator() const;
    //Returns the element currently pointed at by the iterator
    //Precondition: There is at least one element in the linked list

    bool isEmpty() const;
    //Determines whether a list is empty.
    //Postcondition: telling users if the list is empty or not.
    //Precondition: creating a list to check.

    bool offEnd() const;
    //Returns whether the iterator is off the end of the list, i.e. is NULL
    //Postcondition:
	//Precondition:

    int getSize() const;
    //Return the size of the list.
    //Postcondition: Returns the size of the list.
    //Precondition: creating a list to check.

    bool operator==(const List& list);
    //Compares this list to see if it contains the same data, in the same order as another list.

    /**Manipulation Procedures*/
    void removeStop();
    //Removes the value of the last data in the list
    //Precondition: 3 conditions. size is 0, size is 1, and size is greater than 1.
    //Postcondition: if size is 0 then print out error message. If there is only one node then make the node start and stop. Else remove the last item on the list.

    void removeStart();
    //Removes the value of the first data in the list
    //Precondition: 3 conditions. size is 0, size is 1, and size is greater than 1.
    //Postcondition: if size is0 then print out error message. If size is 1 delete the whole list and if size > 1 print out the list without its print item.

    void insertStop (listdata data);
    //Inserts a new data at the end of the list
    //If the list is empty, the new data becomes both first and last
    //Precondition: the list has size of 0 or higher.
    //Postcondition: print out the list with a new data.

    void insertStart(listdata data);
    //Inserts a new data at the start of the list
    //Precondition: the list has size of 0 or higher.
    //Postcondition: print out the list with a new data at the beginning. If the list is empty, the new data becomes both first and last

    void pointIterator();
    //Moves the iterator to the start of the list
    //If the list is empty, the iterator remains NULL
    //Postcondition: a new element is added after where iterator is located.
    //Precondition: There is an iterator.

    void insertIterator(listdata data);
    //Inserts an element after the node currently pointed to by the iterator
    //Precondition: the iterator is pointing to an element
    //Postcondition: a new element is added after where iterator is located

    void deleteIterator();
    //Removes the element currently pointed to by the iterator. Iterator then points to NULL.
    //Precondition: there is an element in the list and the iterator is pointing to it.
    //Postcondition: the element pointing by iterator is removed.

    void advanceIterator();
    //Moves the iterator up by one node towards stop
    //Precondition: has no effect if the iterator is offend or the list is empty
    //Postcondition: the iterator is pointing to the next element

    void reverseIterator();
	//Moves the iterator down by one node towards start.
    //Precondition:has no effect if the iterator is offend or the list is empty
    //Postcondition: the iterator is pointing to the previous element


    /**Additional List Operations*/
    void print() const;
    //Prints to the console the value of each data in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty
    //Prints a empty newline character if it's empty.

    void printNumberedList() const;
    //Prints the contents of the linked list to the screen in the format #: <element> followed by a newline
    //Similar to the print function but with the format #: <element> go along.

    private:
       struct Node {
           stackdata data;
           Node* linknext;
           Node* linkprevious;

           Node(stackdata ndata) {

                data = ndata;
                link = NULL;
                iterator = NULL;
            }

        };
        Node* iterator;
       Node* start;
       Node* stop;
       int size;

};

template <class listdata>
void List<listdata>::List()
{
    start = NULL;
    stop = NULL;
    iterator = NULL;
    size = 0;
}

template <class listdata>
void List<listdata>::List(const List& list)     //list here is the original list
{
    if(list.start == NULL)
        start = stop = iterator = NULL;
    else
    {
 //calling Node constructor
    start = new Node(list.start->data);
 //set a temporary node pointer to point at the first of the original list
    Node* temp  = list.start;
   //set iterator to point to first node of the new list
    iterator = start;    
    }
    while(temp->linknext !=NULL)
    {
        temp = temp->linknext; 
        iterator->linknext = new Node(temp->data)
        iterator->linknext->linkprevious = iterator;
        iterator = iterator->linknext;
    }
    stop = iterator;
    size = list.size;
}

template <class listdata>
void List<listdata>::~List()
{
    Node* b = start;
    Node* a = NULL;
    while(b != NULL)
    {
        b->linknext = a;
        delete b;
        b = a;
    }
}

template <class listdata>
listdata List<listdata>::getStart() const
{
    assert(!=0)     // enforce the precondition 
    return star->data;
}

template <class listdata>
listdata List<listdata>::getStart() const
{
    assert(!=0)
    return stop->data;
}

template <class listdata>
bool List<listdata>::isEmpty() const
{
    return == 0;
}

template <class listdata>
int List<listdata>::getSize() const
{
    return size;
}

template <class listdata>
bool List<listdata>::offEnd() const
{
    return iterator = NULL;
}

template <class listdata>
listdata List<listdata>::getIterator() const
{
    assert(!=0)
    return iterator->data;
}

template <class listdata>
void List<listdata>::insertStart(listdata data)
{
    if(size == 0)
    {
        Node* N = new Node(data);
        start = stop = N;
    }
    else
    {
    Node* N = new Node(data);
    N->linknext = start;
    start->linkprevious = N;
    start = N;
    }
    size++;
}

template <class listdata>
void List<listdata>::insertStop(listdata data)
{
    Node* N = new Node(data);
    if(size == 0)
        start = stop = N;
    else
    {
        stop->linknext = N;
        N->linkprevious = stop;
        stop = N;
    }
    size++;
}

template <class listdata>
void List<listdata>::removeStart()
{
        assert(!Empty())
        if(iterator == start)
            iterator = NULL;
        if(size ==1)
        {
            delete start;
            start = stop = NULL;
            size = 0;
        }
    else
    {
        Node* temp = start;
        start = start->linknext;
        start->linkprevious = NULL;
        delete temp;
        size--;
    }
}

template <class listdata>
void List<listdata>::removeStop()
{
    assert(!Empty);
    if(iterator == stop)
        iterator = NULL;
    if(size ==1 )
    {
        delete start;
        start = stop = NULL;
        size = 0;
    }
    else 
    {
        Node* temp = stop;
        stop = stop->linkprevious;
        stop->linknext = NULL;
        delete temp;
        size--;
    }
}

template <class listdata>
void List<listdata>::pointIterator()
{
    assert(!Empty)
    iterator = start;
}

template <class listdata>
void List<listdata>::advanceIterator()
{
    assert(!offEnd);
    iterator = iterator->linknext;
}

template <class listdata>
void List<listdata>::reverseIterator()
{
    assert(!offEnd);
    iterator = iterator->linkprevious;
}

template <class listdata>
void List<listdata>::insertIterator(listdata data)
{
    asset(!offEnd);
    if(iterator== stop)
        insertStop(data);
    else if (iterator == start)
        insertStart(data);
    else
    {
        Node* N = new Node(data);
        N->linknext = iterator->linknext;
        iterator->linknext->linkprevious = N;
        N->linkprevious = iterator;
        iterator->linknext = N;
        size++;
    }
}

template <class listdata>
void List<listdata>::removeIterator()
{
    if(iterator == stop)
        return removeStop();
    else if(iterator == start)
        return removeStart();
    else 
    {
        iterator->linknext->linkprevious = iterator->linkprevious;
        iterator->linkprevious->linknext = iterator->linknext;
        delete iterator;
        iterator = NULL;
        size--;
    }
}

template <class listdata>
void List<listdata>::printNumberedList() const
{
    assert(!empty);
    Node* temp = start;
    int numberlist = 0;
    while(temp != NULL)
    {
        numberlist++;
        cout << numberlist << temp->data << endl;
        temp = temo->linknext;
    }
}



template <class listdata>
void List<listdata>::reversePrint(Node* node) const
{
    Node* temp = node;
    if(temp== NULL)
    {
        cout << "" << endl;
        return;
    }
    else 
    {
        cout << temp->data << " ";
        reversePrint(temp->linkprevious);
    }
}

template <class listdata>
void List<listdata>::reversePrint(Node* node) const
{
    Node* temp = node;
    if(temp == NULL)
    {   
        cout << " " << endl;
        return;
    }
    else 
    {
        cout << temp->data << " ";
        return reveersePrint(temp->linkprevious);
    }
}

template <class listdata>
void List<listdata>::reversePrint() const
{
    reversePrint(stop);
}

template <class listdata>
bool List<listdata>::operator==(const List& list)
{
    if(size != list.size)
        return false;
    Node* temp1 = list;
    Node* temp2 = list.start;
    while(temp1 != NULL)
    {
        if(temp1->data != temp2->data)
            return false;
        temp1 = temp1->linknext;
        temp2 = temp2->linknext;
    }
    return true;
}


#endif /* QUEUE_H_ */
