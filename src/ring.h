#ifndef RING_H
#define RING_H

struct Point{
    int x;
    int y;
};
//Шаблон двусвязного кольца
template <typename T>
struct Node{
    T value;
    Node* next;
    Node* prev;
};

template <typename T>
class Ring
{
private:
    Node<T>* first;
    int size;
public:
    Ring() {
        first = nullptr;
        size=0;
    }

    Ring(const Ring& ring)
    {
        first = new Node<T>;
        this->first = ring.first;
        this->size=ring.size;
    }
    void popValue(T value) {
        //Удаляет заданный узел по значению
        Node<T>* target = getValue(value);
        Node<T>* next;
        Node<T>*prev;
        prev=target->prev;
        next=target->next;
        if (first == nullptr) {
            return;
        }

        if (target->next == target) {
            delete target;
            this->first = nullptr;
            size--;
        }
        else {
            prev->next = target->next;
            next->prev = target->prev;
            if (target == first) first = target->next;
            delete target;
            size--;
        }
    }

    ~Ring() {
        while (first) {
            popValue(first->value);
        }
    }


    void push(T value) {
        //Добавление в кольцо
        Node<T>* temp = new Node<T>;
        temp->value = value;
        size++;
        if (!first) {
            temp->next = temp->prev = temp;
            first = temp;
        }
        else {
            temp->next = first;
            temp->prev = first->prev;
            first->prev->next = temp;
            first->prev = temp;
        }
    }


    Node<T>* getValue(T value) {
        //Возвращает узел по значению
        Node<T>* temp = first->next;
        for (; temp!=first; temp=temp->next) {
            if (temp->value == value) return temp;
        }
    }

    Node<T>* getFirst()
    {
        return first;
    }

    Node<T>* getNext(Node<T>* current) {
        //Получить следующий элемент
        return current->next;
    }

    Node<T>* getNextN(Node<T>* current, int N)
    //Получить следующий через N элемент
    {
        for (int i = 0; i < N; i++) {
            current = getNext(current);
        }
        return current;
    }

    Node<T>* getPrev(Node<T>* current) {
        //Получить предыдущий элемент
        return current->prev;
    }

    Node<T>* getPrevN(Node<T>* current, int N) {
        //Получить предыдущий через N элемент
        for (int i = 0; i < N; i++) {
            current = getPrev(current);
        }
        return current;
    }
    int&getSize(){
        return size;
    }
    void deleteRing(){
        //Удаление кольца
        while(first){
            popValue(first->value);
        }
    }
};

#endif // RING_H
