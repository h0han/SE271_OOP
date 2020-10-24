////////////////////////////////////////////////////////////////////////////////
// SE271 - Assignment 2: Source file
// 1. Complete the implementation of VariableList
// 2. You can add your implementation only in "IMPLEMENT HERE" & "CHANGE HERE"
//    Do not touch other lines; but you can change main() for testing
////////////////////////////////////////////////////////////////////////////////
#include "hw2.h"

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// You may also want to have additional functions, 
// e.g., static functions or forward declaration of functions, Then
//
// IMPLEMENT HERE
struct node {   // node structure은 data region과 next region을 포함.
    int idata; 
    float fdata;
    string sdata;
    node* next;
};

//
// NOTE: DO NOT USE global, static variables
////////////////////////////////////////////////////////////////////////////////

// Constructors
VariableList::VariableList() {
    // IMPLEMENT HERE
    head = NULL;
    tail = NULL;
    size = 0;
}
VariableList::VariableList(const int* initialArray, const int size) {   // array에 있는 elem의 node화 필요
    // IMPLEMENT HERE
    int i;  // for loop
    for (i = 0; i < size; ++i) {

    }
    
}
VariableList::VariableList(const float* initialArray, const int size) {
    // IMPLEMENT HERE
}
VariableList::VariableList(const std::string* initialArray, const int size) {
    // IMPLEMENT HERE
}

// Destructor
// Note: Please delete(free) the memory you allocated 
VariableList::~VariableList() { //소멸자가 불릴 때 전체 node 삭제?
    // IMPLEMENT HERE
}

// Member functions
// add: Add the value at the end of the list
void VariableList::add(const int val) {
     //IMPLEMENT HERE
    node* tmp = new node;
    tmp->idata = val;
    tmp->next = NULL;

    if (head == NULL) {
        head = tmp;
        tail = tmp;
    }
    else {
        tail->next = tmp;
        tail = tail->next;
    }
    ++size;
    delete tmp;
}
void VariableList::add(const float val) {
    // IMPLEMENT HERE
    node* tmp = new node;
    tmp->fdata = val;
    tmp->next = NULL;

    if (head == NULL) {
        head = tmp;
        tail = tmp;
    }
    else {
        tail->next = tmp;
        tail = tail->next;
    }
    ++size;
    delete tmp;
}
void VariableList::add(const std::string& val) {
    // IMPLEMENT HERE
    node* tmp = new node;
    string str(val);
    tmp->sdata = str;
    tmp->next = NULL;

    if (head == NULL) {
        head = tmp;
        tail = tmp;
    }
    else {
        tail->next = tmp;
        tail = tail->next;
    }
    ++size;
    delete tmp;
}

// append: Copy all values of varList and append them at the end of the list
void VariableList::append(const VariableList& varList) {
    // IMPLEMENT HERE
    int list_size = varList.getSize();
    int i;  // for loop

    node* tmp = new node;
    for (i = 0; i < list_size; ++i) {
        
    }
}

// replace: replace the value at the given index in the list
bool VariableList::replace(const int idx, const int val) {
    // IMPLEMENT HERE
    int step = 0;
    if (idx < 0 | idx > size) {
        return false;
    }
    while (step == idx) {

    }
    return false; // CHANGE HERE
}
bool VariableList::replace(const int idx, const float val) {
    // IMPLEMENT HERE
    if (idx < 0 | idx > size) {
        return false;
    }
    return false; // CHANGE HERE
}
bool VariableList::replace(const int idx, const std::string& val) {
    // IMPLEMENT HERE
    if (idx < 0 | idx > size) {
        return false;
    }
    return false; // CHANGE HERE
}

// remove: remove the item at the given index in the list
bool VariableList::remove(const int idx) {
    // IMPLEMENT HERE
    if (idx < 0 | idx > size) {
        return false;
    }
    return false; // CHANGE HERE
}

// getSize: return the number of elements of the List
unsigned int VariableList::getSize() const {
    // IMPLEMENT HERE
    return size; // CHANGE HERE
}

// getType: return the data type for the value at the given index
DataType VariableList::getType(const int idx) const {
    // IMPLEMENT HERE
    if (idx < 0 | idx > size) {
        return false;
    }
    return DataType::NotAvailable; // CHANGE HERE
}

// getValue: copy the value to the variable
bool VariableList::getValue(const int idx, int& val) const {
    // IMPLEMENT HERE
    if (idx < 0 | idx > size) {
        return false;
    }
    return false; // CHANGE HERE
}
bool VariableList::getValue(const int idx, float& val) const {
    // IMPLEMENT HERE
    if (idx < 0 | idx > size) {
        return false;
    }
    return false; // CHANGE HERE
}
bool VariableList::getValue(const int idx, std::string& val) const {
    // IMPLEMENT HERE
    if (idx < 0 | idx > size) {
        return false;
    }
    return false; // CHANGE HERE
}

////////////////////////////////////////////////////////////////////////////////
// You may also want to implement additional, private member functions here
// NOTE: DO NOT USE global, static variables
//
// IMPLEMENT HERE
//
////////////////////////////////////////////////////////////////////////////////
