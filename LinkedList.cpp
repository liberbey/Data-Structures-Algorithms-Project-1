#include "LinkedList.h"

LinkedList::LinkedList() {

    this->length = 0;
    this->head = NULL;
    this->tail = NULL;
}

LinkedList::LinkedList(const LinkedList& list){

    this->length = list.length;
    if(list.head){
        this->head = new Node(*(list.head));
    }
    Node* temp = list.head->next;
    Node* myP = this->head;
    for( ; temp->next != nullptr ; temp = temp->next ){
        Node* temp2 = new Node(*temp);
        myP->next = temp2;
        myP = myP->next;
    }
    this->tail = new Node(*temp);


}

LinkedList& LinkedList::operator=(const LinkedList& list){

    this->length = list.length;
    if(this->head){
        this->head = nullptr;
    }
    if(this->tail){
        this->tail = nullptr;
    }
    if(list.head){
        this->head = new Node(*(list.head));
    }
    Node* temp = list.head->next;
    Node* myP = this->head;
    for( ; temp->next != nullptr ; temp = temp->next ){
        Node* temp2 = new Node(*temp);
        myP->next = temp2;
        myP = myP->next;
    }
    this->tail = new Node(*temp);

    return *this;

}

LinkedList::LinkedList(LinkedList &&list) {

    this->length = list.length;
    this->head = move(list.head);
    this->tail = move(list.tail);

    list.length = 0;
    list.head = nullptr;
    list.tail = nullptr;

}

LinkedList& LinkedList::operator=(LinkedList &&list) {

    this->length = list.length;
    if(this->head){
        this->head = nullptr;
    }
    if(this->tail){
        this->tail = nullptr;
    }
    this->head = move(list.head);
    this->tail = move(list.tail);

    list.length = 0;
    list.head = nullptr;
    list.tail = nullptr;


    return* this;

}

void LinkedList::pushTail(string _name, float _amount) {

    Node* temp = new Node(_name, _amount);
    if(this->length == 0){
        this->head = temp;
        this->tail = temp;
    }
    else{
        this->tail->next = temp;
        this->tail = temp;
    }
    this->length++;


}

void LinkedList::updateNode(string _name, float _amount) {

    if(this->length == 0){
        return;
    }
    Node* temp = this->head;
    if(this->head == this->tail){
        if(this->head->name == _name){
            this->head->amount = _amount;
            return;
        }
        else{
            return;
        }
    }
    if(this->tail->name == _name){
        this->tail->amount = _amount;
        return;
    }
    while(temp->next != nullptr) {
        if (temp->name == _name) {
            temp->amount = _amount;
            return;
        }
        temp = temp->next;
    }

}

void LinkedList::printNodes() {


    if(this->length == 0){
        return;
    }
    if(this->length == 1){
        cout << this->head->name << "-" << this->head->amount << endl;
    }
    Node* temp = this->head;
    while(temp->next != nullptr) {
        cout << temp->name << "-" << temp->amount << endl;
        temp = temp->next;
    }
    cout << temp->name << "-" << temp->amount << endl;


}

LinkedList::~LinkedList() {

    delete this->head;

}