////////////////////////////////////////////////////////////////////////////////
// SE271 - Assignment 3: Source file
// 1. Complete the implementation of Ordered
// 2. Add a new class, OrderedSet, using class inheritance
////////////////////////////////////////////////////////////////////////////////
#include "hw3.h"

#include <iostream>
#include <limits>

Node::Node() : next(), data() {
    Node* next = NULL;
}

Ordered::Ordered() {
	m_size = 0;
	Node node = Node();
	head = NULL; tail = NULL;
}

Ordered::~Ordered() {
}

void Ordered::sort() { // for sorting the datas
    Node* pos_node = head; Node* _pos_node = head;// for represent position
    int i; int j; // for loop
    int tmp; int min_idx; // for sort
    int* data_array = new int[m_size];

    for (pos = 0; pos < m_size; ++pos) {
        data_array[pos] = pos_node->data;
        pos_node = pos_node->next;
    }
    for (i = 0; i < m_size - 1; ++i) {
        min_idx = i;
        for (j = i + 1; j < m_size; ++j) {
            if (data_array[min_idx] > data_array[j]) {
                min_idx = j;
            }
        }
        tmp = data_array[min_idx];
        data_array[min_idx] = data_array[i];
        data_array[i] = tmp;
    }
    for (pos = 0; pos < m_size; ++pos) {
        _pos_node->data = data_array[pos];
        _pos_node = _pos_node->next;
    }
}

void Ordered::add(int v) {
	Node* new_node = new Node();
	new_node->data = v;
	new_node->next = NULL;
    int i; int j; // for loop
    int tmp; int max_idx;

	if (m_size == 0) {
        head = new_node; tail = new_node;
	}
	else {
		tail->next = new_node; tail = tail->next;
	} ++m_size;
    sort();
}

void Ordered::remove(int index) {
    Node* pos_node = head;
    Node* del_node = new Node();

    if ((index < 0) || (index >= m_size)) {
        std::cout << "Out of index" << std::endl;
    }
    if (index == 0) {
        del_node = head; pos_node = head->next;
        delete del_node;
        head = pos_node; m_size--;
    }
    else if (index == m_size - 1) {
        for (pos = 0; pos < index - 1; ++pos) {
            pos_node = pos_node->next;
        }
        del_node = tail; tail = pos_node;
        delete del_node; m_size--;
    }
    else {
        for (pos = 0; pos < index - 1; ++pos) {
            pos_node = pos_node->next;
        }
        del_node = pos_node->next; pos_node->next = del_node->next;
        tail = pos_node->next;
        delete del_node; m_size--;
    }
    sort();
}

void Ordered::add(int* arr, int size) {
	for (int i = 0; i < size; ++i) { add(arr[i]); }
}

int Ordered::operator[](int index) {
    Node* pos_node = head;
    if ((index < 0) || (index >= m_size)) { return std::numeric_limits<int>::min(); }
    for (pos = 0; pos < index; ++pos) {
        pos_node = pos_node->next;
    }
    return pos_node->data;
}

bool Ordered::operator>>(int v) {
    Node* pos_node = head;
    for (pos = 0; pos < m_size; ++pos) {
        if (v == pos_node->data) { return true; }
        pos_node = pos_node->next;
    }
	return false;
}

OrderedSet::OrderedSet() {
    Node* pos_node = head;
    for (pos = 0; pos < m_size-1; ++pos) {
        if (pos_node->data == pos_node->next->data) { remove(pos); }
    }
}

OrderedSet::~OrderedSet() {
}