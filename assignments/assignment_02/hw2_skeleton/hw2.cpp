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
Node::Node() {
    Node* next = NULL;
}
Node::Node(int ivalue) {
    type = 0;
    idata = ivalue;
    Node* next = NULL;
}
Node::Node(float fvalue) {
    type = 1;
    fdata = fvalue;
    Node* next = NULL;
}
Node::Node(string svalue) {
    type = 2;
    sdata = svalue;
    Node* next = NULL;
}

//
// NOTE: DO NOT USE global, static variables
////////////////////////////////////////////////////////////////////////////////

// Constructors
VariableList::VariableList() {
    // IMPLEMENT HERE
    step = 0;   // for getSize
    Node node = Node();
    head = NULL;
    tail = NULL;
}
VariableList::VariableList(const int* initialArray, const int size) {   // array에 있는 elem의 node화 필요
    int i;  // for loop
    for (i = 0; i < size; ++i) {
        add(initialArray[i]);
    }
}
VariableList::VariableList(const float* initialArray, const int size) {
    int i;  // for loop
    for (i = 0; i < size; ++i) {
        add(initialArray[i]);
    }
}
VariableList::VariableList(const std::string* initialArray, const int size) {
    int i;  // for loop
    for (i = 0; i < size; ++i) {
        add(initialArray[i]);
    }
}

// Destructor
// Note: Please delete(free) the memory you allocated 
VariableList::~VariableList() { //소멸자가 불릴 때 전체 node 삭제?
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
    }
    ++step;
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
    } 
    ++step;
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
    } 
    ++step;
}

// append: Copy all values of varList and append them at the end of the list
void VariableList::append(const VariableList& varList) {
    int list_size = varList.getSize();
    int pos;
    Node* pos_node = new Node();
    pos_node = head;

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
    Node* pos_node = new Node();
    pos_node = head;

    if ((idx < 0) || (idx > step)) {
        return false;
    }

    for (pos = 0; pos < idx; ++pos) {
        if (pos == idx) {
            if (pos_node->type == 0) {
                pos_node->idata = val;
            }
        }
        pos_node = pos_node->next;
    }
}
bool VariableList::replace(const int idx, const float val) {
    int pos;
    Node* pos_node = new Node();
    pos_node = head;

    if ((idx < 0) || (idx > step)) {
        return false;
    }

    for (pos = 0; pos < idx; ++pos) {
        if (pos == idx) {
            if (pos_node->type == 1) {
                pos_node->fdata = val;
            }
        }
        pos_node = pos_node->next;
    }
}
bool VariableList::replace(const int idx, const std::string& val) {
    int pos;
    Node* pos_node = new Node();
    pos_node = head;

    if ((idx < 0) || (idx > step)) {
        return false;
    }

    for (pos = 0; pos < idx; ++pos) {
        if (pos == idx) {
            if (pos_node->type == 2) {
                pos_node->sdata = val;
            }
        }
        pos_node = pos_node->next;
    }
}

// remove: remove the item at the given index in the list
bool VariableList::remove(const int idx) {
    int pos;
    Node* pos_node = new Node();
    pos_node = head;
    Node* del_node = new Node();

    if ((idx < 0) || (idx > step)) {
        return false;
    }

    if (idx == 0) {
        del_node = head;
        pos_node = head->next;
        delete del_node;
        head = pos_node;
    }

    if (idx == step) {
        for (pos = 0; pos < idx - 1; ++pos) {
            del_node = tail;
            tail = pos_node;
        }
        delete del_node;
    }

    for (pos = 0; pos < idx - 1; ++pos) {
        if (pos == idx - 1) {
            del_node = pos_node->next;
            pos_node = pos_node->next->next;
        }
        pos_node = pos_node->next;
        delete del_node;
    }
    step--;
}

// getSize: return the number of elements of the List
unsigned int VariableList::getSize() const {
    return step;
}

// getType: return the data type for the value at the given index
DataType VariableList::getType(const int idx) const {
    int pos;
    Node* pos_node = new Node();
    pos_node = head;

    if ((idx < 0) || (idx > step)) {
        return DataType::NotAvailable;
    }

    for (pos = 0; pos < idx; ++pos) {
        if (pos_node->type == 0) {
            return DataType::Integer;
        }
        else if (pos_node->type == 1) {
            return DataType::Float;
        }
        else if (pos_node->type == 2) {
            return DataType::Str;
        }
        else {
            return DataType::NotAvailable;
        }
        pos_node = pos_node->next;
    }
}

// getValue: copy the value to the variable
bool VariableList::getValue(const int idx, int& val) const {
    int pos;
    Node* pos_node = new Node();
    pos_node = head;

    if ((idx < 0) || (idx > step)) {
        return false;
    }

    for (pos = 0; pos < idx; ++pos) {
        if (pos_node->type == 0) {
            val = pos_node->idata;
            return true;
        }
        pos_node = pos_node->next;
    }
}
bool VariableList::getValue(const int idx, float& val) const {
    int pos;
    Node* pos_node = new Node();
    pos_node = head;

    if ((idx < 0) || (idx > step)) {
        return false;
    }

    for (pos = 0; pos < idx; ++pos) {
        if (pos_node->type == 1) {
            val = pos_node->fdata;
            return true;
        }
        pos_node = pos_node->next;
    }
}
bool VariableList::getValue(const int idx, std::string& val) const {
    int pos;
    Node* pos_node = new Node();
    pos_node = head;

    if ((idx < 0) || (idx > step)) {
        return false;
    }

    for (pos = 0; pos < idx; ++pos) {
        if (pos_node->type == 2) {
            val = pos_node->sdata;
            return true;
        }
        pos_node = pos_node->next;
    }
}

////////////////////////////////////////////////////////////////////////////////
// You may also want to implement additional, private member functions here
// NOTE: DO NOT USE global, static variables
//
// IMPLEMENT HERE
//
////////////////////////////////////////////////////////////////////////////////
