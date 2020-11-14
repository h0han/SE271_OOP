////////////////////////////////////////////////////////////////////////////////
// SE271 - Assignment 3: Source file
// 1. Complete the implementation of Ordered
// 2. Add a new class, OrderedSet, using class inheritance
////////////////////////////////////////////////////////////////////////////////
#include "hw3.h"

#include <iostream>
#include <limits>

Node::Node() : head(), tail(), next(), data() {
    Node* next = NULL;
}

Ordered::Ordered() {
	m_size = 0;
	Node node = Node();
	head = NULL;
	tail = NULL;
}

Ordered::~Ordered() {
}

void Ordered::add(int v) {
	Node* new_node = new Node();
	new_node->data = v;
	new_node->next = NULL;

	if (m_size == 0) {
		new_node->head = NULL;
		new_node->tail = NULL;
	}
	else {
		tail->next = new_node;
		tail = tail->next;
	} ++m_size;
}

void Ordered::remove(int index) {
    int pos;
    Node* pos_node = head;
    Node* del_node = new Node();

    if ((index < 0) || (index >= m_size)) {
        std::cout << "Out of index" << std::endl;
    }

    if (index == 0) {
        del_node = head;
        pos_node = head->next;
        delete del_node;
        head = pos_node;
        m_size--;
    }

    else if (index == m_size - 1) {
        for (pos = 0; pos < index - 1; ++pos) {
            pos_node = pos_node->next;
        }
        del_node = tail;
        tail = pos_node;
        delete del_node;
        m_size--;
    }

    else {
        for (pos = 0; pos < index - 1; ++pos) {
            pos_node = pos_node->next;
        }
        del_node = pos_node->next;
        pos_node->next = del_node->next;
        tail = pos_node->next;
        delete del_node;
        m_size--;
    }
}

void Ordered::add(int* arr, int size) {
	int i = 0; // for loop
	for (i; i < size; ++i) {
		add(arr[i]);
	}
}

int Ordered::operator[](int index) {
	return std::numeric_limits<int>::min();
}

bool Ordered::operator>>(int v) {
	return false;
}