#include "LinkedList.h"
#include "Student.h"
using namespace std;

namespace hw4{

  template <class T>
  class Queueue{
  public:
    T dequeue(); // removes element
    void enqueue(T newData); // adds element
    void displayQueue(); // prints all elements
    int getSize(); // returns size of queue
    T peekFront(); // looks at top of queue (needed for checking if new students come)
    LinkedList<T> queueList; // queue elements stored and accessed through linked list
  };

  // removing element from queue
  template <class T>
  T Queueue<T>::dequeue(){
    Node<T> *temp = queueList.head; // storing memory address
    queueList.popFront(); // removing first element
    return temp->data; // outputting data
  }

  // adding element to queue
  template <class T>
  void Queueue<T>::enqueue(T newData){
    queueList.insertBack(newData);
  }

  // printing all elements in queue
  template <class T>
  void Queueue<T>::displayQueue(){
    queueList.displayList();
  }

  // returns size of queue
  template <class T>
  int Queueue<T>::getSize(){
    return queueList.Size();
  }

  // returns value of front of queue
  template <class T>
  T Queueue<T>::peekFront(){
    if (queueList.Size()>0){return queueList.head->data;}
    else {
    cout << "No elements in list to pop" << endl << "Exiting program...";
    exit(EXIT_FAILURE);
    }
  }
}
