#include "SurveyClass.h"

SurveyClass::SurveyClass() {


    this->members = new LinkedList();
}

SurveyClass::SurveyClass(const SurveyClass &other) {

    this->members = other.members;

}

SurveyClass& SurveyClass::operator=(const SurveyClass &list) {

    if(this->members){
        delete this->members;
    }
    this->members = list.members;
    return* this;

}

SurveyClass::SurveyClass(SurveyClass &&other) {

    this->members = move(other.members);
    other.members = nullptr;

}

SurveyClass& SurveyClass::operator=(SurveyClass &&list) {

    if(this->members){
        delete this->members;
    }
    this->members = move(list.members);
    list.members = nullptr;
    return* this;
}

void SurveyClass::handleNewRecord(string _name, float _amount) {



    if(this->members->length == 0){

        this->members->pushTail(_name, _amount);

        return;
    }
    Node* temp = this->members->head;
    if(this->members->length == 1){
        if(this->members->head->name == _name){
            this->members->head->amount = _amount;

            return;
        }
        else{
            this->members->pushTail(_name, _amount);

            return;
        }
    }

    if(this->members->tail->name == _name){
        this->members->tail->amount = _amount;

        return;
    }


    while(temp->next != nullptr) {

        if (temp->name == _name) {
            temp->amount = _amount;

            return;
        }
        temp = temp->next;
    }

    this->members->pushTail(_name, _amount);


}

float SurveyClass::calculateMinimumExpense() {

    if(this->members->length == 0){
        return 0;
    }
    if(this->members->length == 1){
        return this->members->head->amount;
    }
    Node* temp = this->members->head;
    float min = this->members->head->amount;

    while(temp->next != nullptr){
        if(temp->amount < min){
            min = temp->amount;
        }
        temp = temp->next;
    }
    if(this->members->tail->amount < min){
        min = this->members->tail->amount;
    }

    return min;
}

float SurveyClass::calculateMaximumExpense() {

    if(this->members->length == 0){
        return 0;
    }
    if(this->members->length == 1){
        return this->members->head->amount;
    }
    Node* temp = this->members->head;
    float max = this->members->head->amount;

    while(temp->next != nullptr){
        if(temp->amount > max){
            max = temp->amount;
        }
        temp = temp->next;
    }
    if(this->members->tail->amount > max){
        max = this->members->tail->amount;
    }

    return max;
}

float SurveyClass::calculateAverageExpense() {

    int count = 0;
    float sum = 0;
    if(this->members->length == 0){
        return 0;
    }
    if(this->members->length == 1){
        return this->members->head->amount;
    }
    Node* temp = this->members->head;
    while(temp->next != nullptr){
        count++;
        sum+= temp->amount;
        temp = temp->next;
    }
    count++;
    sum+= temp->amount;
    float average = sum/(float)count;
    int temp1 = (int)(average*100);
    return ((float)temp1/(float)100);

}


SurveyClass::~SurveyClass() {

}