using namespace std;


namespace hw4{

  /*template <class T>
  class Node{
  public:
    Node(T newData);
    Node *prev; Node *next;
    T data;
  };

  template <class T>
  Node<T>::Node(T newData){
    *prev = NULL;
    *next = NULL;
    data = newData;
  }*/
  template<class T>
  struct Node{
    T data;
    Node *prev; Node *next;
  };
}
