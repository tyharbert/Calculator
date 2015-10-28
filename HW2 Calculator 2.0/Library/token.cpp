// Tyler Harbert

#include "token.hpp"

// Node Class
Node::Node(Token data, Node* next){
    this->data = data;
    this->next = next;
}

// Linked List Class
TokenStream::TokenStream(){
    this->head = this->tail = this->current = NULL;
    this->length = 0;
}

TokenStream::TokenStream(Token data){
    Node* n = new Node(data, NULL);
    this->head = this->tail = n;
    this->current = NULL;
    this->length = 1;
}

// destructor
TokenStream::~TokenStream(){
    Node* current = this->head;
    while(current != NULL){
        Node* next = current->next;
        delete current;
        current = next;
    }
    
    this->head = NULL;
    this->tail = NULL;
    this->current = NULL;
}

// insert at tail
void TokenStream::add_t(Token data){
    this->length++;
    Node* n = new Node(data,NULL);
    
    // if the head and the tail are NULL make them both the new node
    if (this->head == NULL && this->tail == NULL){
        this->head = this->tail = n;
        return;
    }
    
    // if the head and tail are the same then make the new node the next of the head
    if (this->head == this->tail)
        this->head->next = n;

    // make the new node the next for the tail then make it the tail
    this->tail->next = n;
    this->tail = n;
}

// insert at head
void TokenStream::add_h(Token data){
    this->length++;
    Node* n = new Node(data,this->head);
    
    // if the head and the tail are NULL make them both the new node
    if (this->head == NULL && this->tail == NULL){
        this->head = this->tail = n;
        return;
    }
    
    // make the new node the head
    this->head = n;
}

// gets the next list item
Token TokenStream::get(bool reset){
    if (reset || this->current == NULL || this->current == this->tail)
        this->current = this->head;
    else
        this->current = this->current->next;
    
    return this->current->data;
}

// gets the current list item
Token TokenStream::peek(){
    if (this->current == NULL)
        this->current = this->head;
    
    return this->current->next->data;
}