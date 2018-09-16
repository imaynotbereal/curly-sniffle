#include<iostream>
#include<cassert>
using namespace std;

class Node {
public:
    int data;
    Node * next;
    Node(int d = 0): data(d), next(NULL) {};
    ~Node() { cout<<endl<<"destroying node with data"<<data<<endl; }
};

class LinkedList {
    unsigned long length;
public:
    Node * head;
    LinkedList(): head(NULL), length(0) {}
    ~LinkedList();
    // Insert at begining if position is not specified
    void add(int data, int pos = 1);
    void print();
    void erase(int pos = 1);
    unsigned long size();
};

void LinkedList::add(int data, int pos) {
    Node * newNode = new Node(data);
    if (!newNode) {
        throw "Error allocating memory";
    }

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        Node * iter = head;
        int i = 1;
        while (i < pos - 1)) {
           iter = iter->next;
           i++;
        }

        newNode->next = iter->next;
        iter->next = newNode;
    }
    length++;
}

void LinkedList::erase(int pos) {
    Node * newNode = head;
    assert(pos <= length);

    if (pos == 1) {
        newNode = head->next;
        delete head;
        head = newNode;
    } else {
        Node * iter = head;
        int i = 1;
        while ((i < pos - 1) && (iter->next != NULL)) {
           iter = iter->next;
           i++;
        }
        if (iter->next == NULL) {
            return; 
        }

        newNode = iter->next;
        iter->next = newNode->next;
        delete newNode;
    }
    length--;

}

void LinkedList::print() {
    if (this->head == NULL) {
        return; 
    }
    
    Node * newNode = this->head;
    
    cout <<endl<<"list: ";
    do {
        cout << newNode->data<< " ";
        newNode = newNode->next;
    } while(newNode != NULL);

}


LinkedList::~LinkedList() {
    cout <<endl<<"destroying linked list"<<endl;
    for (Node *newNode = head; newNode != NULL; newNode = newNode->next) {
        delete newNode; 
    }
}

unsigned long LinkedList::size() {
    return length;
}

int main() {

    LinkedList list;
    list.add(6, 1);
    list.add(7, 2);
    list.add(8, 3);
    list.add(9, 4);
    list.add(10, 5);
    list.print();
    cout<<endl<<"size(): "<<list.size();

    list.add(15, 3);
    list.print();
    cout<<endl<<"size(): "<<list.size();

    list.erase(3);
    list.print();
    cout<<endl<<"size(): "<<list.size();

    list.erase(3);
    list.print();
    cout<<endl<<"size(): "<<list.size();

    list.erase(3);
    list.print();
    cout<<endl<<"size(): "<<list.size();

    list.erase(1);
    list.print();
    cout<<endl<<"size(): "<<list.size();

    list.erase(1);
    list.print();
    cout<<endl<<"size(): "<<list.size();

    return 0;
}
