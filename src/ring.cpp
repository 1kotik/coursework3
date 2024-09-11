#include "ring.h"

template <typename T>
Ring<T>::Ring(){
    first=nullptr;
}

template<typename T>
Ring<T>::Ring(const Ring& ring)
{
    first = new Node<T>;
    this->first=ring->first;
}

template <typename T>
Ring<T>::~Ring(){
    Node<T>*temp=first;
    for(;temp;temp=temp->next){
        temp=first;
        if(temp->next) first=temp->next;
        delete temp;
    }
}

template <typename T>
void Ring<T>::push(T value){
    Node<T>* temp= new Node<T>;
    temp->value=value;
    if(!first){
        temp->next=temp->prev=temp;
        first=temp;
    }
    else{
        temp->next = first;
        temp->prev = first->prev;
        first->prev->next = temp;
        first->prev = temp;
    }
}



template <typename T>
T& Ring<T>::getValue(T value){
    Node<T>* temp=first->next;
    for(;temp->next;temp!=first){
        if(temp->value==value) return temp->value;
    }
}

template<typename T>
Node<T> *Ring<T>::getFirst()
{
    return first;
}

template <typename T>
Node<T>* Ring<T>::getNext(Node<T>*current){
    return current->next;
}

template<typename T>
Node<T> *Ring<T>::getNextN(Node<T> *current, int N)
{
    for(int i=0;i<N;i++){
        current=getNext(current);
    }
    return current;
}

template<typename T>
Node<T>* Ring<T>::getPrev(Node<T>* current) {
    return current->prev;
}

template<typename T>
Node<T>* Ring<T>::getPrevN(Node<T>* current, int N) {
    for (int i = 0; i < N; i++) {
        current = getPrev(current);
    }
    return current;
}
