#ifndef stack_h
#define stack_h
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class MalformedExpression {
  public:
    MalformedExpression(string);
    string getMessage();

  private:
    string msg;
};

template<class T>
class Node {

  public:
    Node();
    Node(T, Node<T>*);
    ~Node();

    Node<T>* getNext();
    T getData();
    void setNext(Node<T>*);
    void setData(T);

  private:
    T val;
    Node<T>* next;
};

template<class T>
class Stack {
  public:
    Stack();
    ~Stack();

    // The push method pushes an item on the stack.
    void push(T item);
    T pop();
    bool isEmpty();
    T top();

  private:
    Node<T>* head;
};

template<class T>
Stack<T>& operator<<(Stack<T>&, T);

template<class T>
Stack<T>& operator>>(Stack<T>&, T&);

template<class T>
Node<T>::Node() {
  this->next = nullptr;
}

template<class T>
Node<T>::Node(T x, Node<T>* next) {
  val = x;
  this->next = next;
}

template<class T>
Node<T>::~Node() {

#ifdef debug
  cout << "Deleting Node " << this->val << endl;
#endif

  if (next == nullptr)
    return;

  try {
    delete next;
  } catch(...) {}
}

template<class T>
void Node<T>::setNext(Node<T>* next) {
  this->next = next;
}

template<class T>
Node<T>* Node<T>::getNext() {
  return next;
}

template<class T>
void Node<T>::setData(T val) {
  this->val = val;
}

template<class T>
T Node<T>::getData() {
  return val;
}

template<class T>
Stack<T>::Stack() {
  Node<T>* head = nullptr;
}

template<class T>
Stack<T>::~Stack() {
  try {

#ifdef debug
    cout << "Deleting Stack" << endl;
#endif

    delete head;
  } catch (...) {}
}

template<class T>
void Stack<T>::push(T item) {

   Node<T>* tmp;

   try {
      tmp = new Node<T>(item, nullptr);
      head = new Node <T>(item, head);
   } catch (std::bad_alloc* exc) {
      cerr << "Out of Memory when pushing item" << endl;
   }
}

template<class T>
T Stack<T>::pop() {

   if (this->isEmpty())
     throw new MalformedExpression("Malformed Expression");

   T item = head->getData();
   Node<T>* newFront = head->getNext();
   Node<T>* toDelete = head;
   head = newFront;
   toDelete->setNext(nullptr);
   delete toDelete; // reclaims heap space
   return item;
}

template<class T>
bool Stack<T>::isEmpty() {
    return head == nullptr;
}
template<class T>
T Stack<T>::top(){
    return head->getData();
}

template<class T>
Stack<T>& operator<<(Stack<T>& q, T x) {
  q.push(x);

  return q;
}

template<class T>
Stack<T>& operator>>(Stack<T>& q, T& x) {
  x = q.pop();

  return q;
}



#endif

