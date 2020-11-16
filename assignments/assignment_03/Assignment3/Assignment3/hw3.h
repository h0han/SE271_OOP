#pragma once
////////////////////////////////////////////////////////////////////////////////
// SE271 - Assignment 3: Header file
// 1. Complete the implementation of Ordered
// 2. Add a new class, OrderedSet, using class inheritance
// 3. You can add your implementation only in "IMPLEMENT HERE"
//    Do not touch other lines
////////////////////////////////////////////////////////////////////////////////
#ifndef __SE271_HW3__
#define __SE271_HW3__

// IMPLEMENT HERE (something if needed)
class Node {
public:
	int data;
	Node* next;

	Node();
};
//////////////////////////////////////
// DO-NOT-TOUCH: Section Start      //
class Ordered {
protected:
	int m_size = 0;

public:
	Ordered();
	virtual ~Ordered();
	virtual void add(int v);
	virtual void add(int* arr, int size);
	virtual void remove(int index);

	virtual int size() { return m_size; }
	virtual int operator[](int index);
	virtual bool operator>>(int v);


	Ordered(const Ordered&) = delete;
	Ordered& operator=(const Ordered&) = delete;

	// DO-NOT-TOUCH: Section End       //
	/////////////////////////////////////

	// IMPLEMENT HERE: Complete the Ordered class 
	Node* head;
	Node* tail;
	virtual void sort();
	virtual Node* find(int v);
};

// IMPLEMENT HERE: implement OrderedSet here using class inheritance
class OrderedSet : public Ordered{ 
public:
	void add(int v);
	void add(int* arr, int size);
};
#endif