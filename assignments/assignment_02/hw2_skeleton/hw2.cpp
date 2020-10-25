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
Node::Node() : idata(), fdata(), sdata(), type(), next() {
    Node* next = NULL;
    }
Node::Node(int ivalue) : idata(), fdata(), sdata(), type(), next() {
    type = 0;   // getType에서 integer type을 추론하기 위해 설정한 변수
    idata = ivalue;
    Node* next = NULL;
}
Node::Node(float fvalue) : idata(), fdata(), sdata(), type(), next() {
    type = 1;   // getType에서 float type을 추론하기 위해 설정한 변수
    fdata = fvalue;
    Node* next = NULL;
}
Node::Node(string svalue) : idata(), fdata(), sdata(), type(), next() {
    type = 2;   // getType에서 string type을 추론하기 위해 설정한 변수
    sdata = svalue;
    Node* next = NULL;
}

//
// NOTE: DO NOT USE global, static variables
////////////////////////////////////////////////////////////////////////////////

// Constructors
VariableList::VariableList() {
    step = 0;   // for getSize
    Node node = Node();
    head = NULL;
    tail = NULL;
}
VariableList::VariableList(const int* initialArray, const int size) {   // array에 있는 elem의 node화 필요
    int i;  // for loop
    step = 0;   // for getSize
    for (i = 0; i < size; ++i) {
        add(initialArray[i]);
    }
}
VariableList::VariableList(const float* initialArray, const int size) {
    int i;  // for loop
    step = 0;   // for getSize
    for (i = 0; i < size; ++i) {
        add(initialArray[i]);
    }
}
VariableList::VariableList(const std::string* initialArray, const int size) {
    int i;  // for loop
    step = 0;   // for getSize
    for (i = 0; i < size; ++i) {
        add(initialArray[i]);
    }
}

// Destructor
// Note: Please delete(free) the memory you allocated 
VariableList::~VariableList() { // 각 함수 자체적으로 메모리를 소멸하도록 하여 Destructor는 따로 구현하지 않았습니다.
    // IMPLEMENT HERE
}

// Member functions
// add: Add the value at the end of the list
void VariableList::add(const int val) {
    Node* new_node = new Node(val);
    new_node->idata = val;
    new_node->next = NULL;

    if (step == 0) {
        head = new_node;
        tail = new_node;
    }
    else {
        tail->next = new_node;
        tail = tail->next;
    } ++step;
}
void VariableList::add(const float val) {
    Node* new_node = new Node(val);
    new_node->fdata = val;
    new_node->next = NULL;

    if (step == 0) {
        head = new_node;
        tail = new_node;
    }
    else {
        tail->next = new_node;
        tail = tail->next;
    } ++step;
}
void VariableList::add(const std::string& val) {
    Node* new_node = new Node(val);
    new_node->sdata = val;
    new_node->next = NULL;

    if (step == 0) {
        head = new_node;
        tail = new_node;
    }
    else {
        tail->next = new_node;
        tail = tail->next;
    } ++step;
}

// append: Copy all values of varList and append them at the end of the list
void VariableList::append(const VariableList& varList) {
    int list_size = varList.getSize();
    int pos;
    Node* pos_node = varList.head;

    for (pos = 0; pos < list_size; ++pos) {
        if (pos_node->type == 0) {
            add(pos_node->idata);
        }
        else if (pos_node->type == 1) {
            add(pos_node->fdata);
        }
        else if (pos_node->type == 2) {
            add(pos_node->sdata);
        }
        pos_node = pos_node->next;
    }
}

// replace: replace the value at the given index in the list
bool VariableList::replace(const int idx, const int val) {
    int pos;
    Node* pos_node = head;

    if ((idx < 0) || (idx >= step)) {
        return false;
    }

    for (pos = 0; pos < idx; ++pos) {
        pos_node = pos_node->next;
    }
    pos_node->type = 0;
    pos_node->idata = val;
    return true;
}
bool VariableList::replace(const int idx, const float val) {
    int pos;
    Node* pos_node = head;

    if ((idx < 0) || (idx >= step)) {
        return false;
    }

    for (pos = 0; pos < idx; ++pos) {
        pos_node = pos_node->next;
    }
    pos_node->type = 1;
    pos_node->fdata = val;
    return true;
}
bool VariableList::replace(const int idx, const std::string& val) {
    int pos;
    Node* pos_node = head;

    if ((idx < 0) || (idx >= step)) {
        return false;
    }

    for (pos = 0; pos < idx; ++pos) {
        pos_node = pos_node->next;
    }
    pos_node->type = 2;
    pos_node->sdata = val;
    return true;
}

// remove: remove the item at the given index in the list
bool VariableList::remove(const int idx) {
    int pos;
    Node* pos_node = head;
    Node* del_node = new Node();

    if ((idx < 0) || (idx >= step)) {
        return false;
    }

    if (idx == 0) {
        del_node = head;
        pos_node = head->next;
        delete del_node;
        head = pos_node;
        step--;
        return true;
    }

    else if (idx == step - 1) {
        for (pos = 0; pos < idx - 1; ++pos) {
            pos_node = pos_node->next;
        }
        del_node = tail;
        tail = pos_node;
        delete del_node;
        step--;
        return true;
    }

    else {
        for (pos = 0; pos < idx-1; ++pos) {
            pos_node = pos_node->next;
        }
        del_node = pos_node->next;
        pos_node->next = del_node->next;
        tail = pos_node->next;
        delete del_node;
        step--;
        return true;        
    }
    return false;
}

// getSize: return the number of elements of the List
unsigned int VariableList::getSize() const {
    return step;
}

// getType: return the data type for the value at the given index
DataType VariableList::getType(const int idx) const {
    int pos;
    Node* pos_node = head;

    if ((idx < 0) || (idx >= step)) {
        return DataType::NotAvailable;
    }

    for (pos = 0; pos < idx; ++pos) {
        pos_node = pos_node->next;
    }
    if (pos_node->type == 0) return DataType::Integer;
    else if (pos_node->type == 1) return DataType::Float;
    else if (pos_node->type == 2) return DataType::Str;
    else return DataType::NotAvailable;
}

// getValue: copy the value to the variable
bool VariableList::getValue(const int idx, int& val) const {
    int pos;    // for loop
    Node* pos_node = head;  // produce position node chase existing nodes

    if ((idx < 0) || (idx >= step)) {
        return false;
    }

    for (pos = 0; pos < idx; ++pos) {
        pos_node = pos_node->next;
    }
    if (pos_node->type == 0) {
        val = pos_node->idata;
        return true;
    }
}
bool VariableList::getValue(const int idx, float& val) const {
    int pos;
    Node* pos_node = head;

    if ((idx < 0) || (idx >= step)) {
        return false;
    }

    for (pos = 0; pos < idx; ++pos) {
        pos_node = pos_node->next;
    }
    if (pos_node->type == 1) {
        val = pos_node->fdata;
        return true;
    }
}
bool VariableList::getValue(const int idx, std::string& val) const {
    int pos;
    Node* pos_node = head;

    if ((idx < 0) || (idx >= step)) {
        return false;
    }

    for (pos = 0; pos < idx; ++pos) {
        pos_node = pos_node->next;
    }
    if (pos_node->type == 2) {
        val = pos_node->sdata;
        return true;
    }
}

////////////////////////////////////////////////////////////////////////////////
// You may also want to implement additional, private member functions here
// NOTE: DO NOT USE global, static variables
//
// IMPLEMENT HERE
//
////////////////////////////////////////////////////////////////////////////////
