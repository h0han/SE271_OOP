////////////////////////////////////////////////////////////////////////////////
// SE271 - Assignment 3: Source file
// 1. Complete the implementation of Ordered
// 2. Add a new class, OrderedSet, using class inheritance
////////////////////////////////////////////////////////////////////////////////
#include "hw3.h"

#include <iostream>
#include <limits>

Node::Node(int val) {
	data = val;
	Node* next = NULL;
}

Ordered::Ordered() {
	m_size = 0;
}

Ordered::~Ordered() {
}

void Ordered::add(int v) {
	Node* new_node = new Node(v);
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