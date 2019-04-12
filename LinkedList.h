#include "Node.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

namespace hw4{

  template <class T>
  class LinkedList{
  public:
    int Size();
    Node<T> *popFront();
    Node<T> *popBack();
    T peekFront();
    void insertFront(T newData); // push element to front of list
    void insertBack(T newData); // push element to back of list
    bool search(T keyValue); // search for key value
    void displayList();
    Node<T> *head=NULL; Node<T> *tail=NULL; // interior elements accessed from these nodes
  private:
    int size=0;
  };


  // returns size of the linked list
  template <class T>
  int LinkedList<T>::Size(){
    return size;
  }

  // returns and removes head of list
  template <class T>
  Node<T>* LinkedList<T>::popFront(){
    Node<T> *temp;
    // if list is empty, throw an improvised error
    if(size<=0){
      cout << "No elements in list to pop" << endl << "Exiting program...";
      exit(EXIT_FAILURE);
    }

    // sets head and tail to null if on final node
    else if(size==1){
      temp = head;
      head = NULL; tail = NULL;
      size--;
      return temp;
    }

    // if 2 or more nodes
    else{
      temp = head; // store prev head
      head = head->next; // new head is
      head->prev = NULL;
      temp->next = NULL;
      size--;
    }

  }

  template <class T>
  Node<T>* LinkedList<T>::popBack(){
    Node<T> *temp;
    // if list is empty, throw an improvised error
    if(size<=0){
      cout << "No elements in list to pop" << endl << "Exiting program...";
      exit(EXIT_FAILURE);
    }

    // sets head and tail to null if on final node
    else if(size==1){
      temp = head;
      head = NULL; tail = NULL;
      size--;
      return temp;
    }

    else{
      temp = tail;
      tail = tail->prev;
      tail->next = NULL;
      size--;
      return temp;
    }

  }

  template <class T>
  void LinkedList<T>::insertFront(T newData){
    // adding first element
    if(head==NULL){
      Node<T> *temp = new Node<T>;
      temp->data=newData;
      head = temp;
      tail = temp;
    }
    else{
      Node<T>* temp = new Node<T>; // make new node
      temp->data=newData; // put data in new node
      temp->next=head;head->prev=temp;
      head=temp; // assign new node as head
    }
    size++;
  }

  template <class T>
  void LinkedList<T>::insertBack(T newData){
    // adding first element
    if(head==NULL){
      Node<T> *temp = new Node<T>;
      temp->data=newData;
      head = temp;
      tail = temp;
    }
    else{
      Node<T> *temp = new Node<T>; // make new node
      temp->data=newData; // put data in new node
      tail->next=temp; temp->prev=tail; // connect the two nodes
      tail=temp; // assign new node as head
    }
    size++;
  }

  // search
  template <class T>
  bool LinkedList<T>::search(T keyValue){
    Node<T> *temp = head;
    for (int x=0; x<size;x++){
      if (temp->data==keyValue){
        cout<<"Key value "<<keyValue<<" found at index "<<x;
        return true;
      }
      temp=temp->next;
    }
    return false;
  }


  // prints list to user
  template <class T>
  void LinkedList<T>::displayList(){
    Node<T> *temp = head;
    if (head==NULL){cout << "List is empty. " << endl;return;} // if list is empty
    else{
      for(int x=0; x<size; x++){
        cout << temp->data<< " ";
        temp = temp->next;
      }
      cout<<endl;
    }
  }

  template <class T>
  T LinkedList<T>::peekFront(){
    if (size>0){
      return head->data;
    }
    else{
      cout << "No elements in list to peek" << endl << "Exiting program...";
      exit(EXIT_FAILURE);
    }
  }
}
