//#pragma once
///////////////////////////////////////////////////////////////
//// Object Oriented Programming - SE271 | Fall 2020 | Final //
//// Goal of Problem B1: Implement four derived classes
///////////////////////////////////////////////////////////////
//
//template<typename T>
//class Op {
//public:
//	virtual T run(T v1, T v2) = 0;
//};
//
//// ======================================== [Problem B-1] =======================================
//// Note: Problem B consists of two steps. Once done your implementation, proceed ProblemB2.h
//
//// In this problem, you will IMPLEMENT four classes, Add, Sub, Mul, and Div by deriving the Op class above (i.e., using inheritance)
//// Hint:
//// A. You can derive a base class implemented with template by
//// "template<typename T> class CLASSNAME : public BASE_CLASSNAME<T> { ... };"
//// B. You can implement each of the four classes only with several lines. (And they are very similar each other)
//
//// 1. Add
//// Implement a class, named "Add", which performs an addition for v1 and v2 when its "run" member function is called.
//// For example, "Add<int>().run(10, 20)" returns 30
//template<typename T> class Add : public Op<T> {
//	Add();
//	T run(T v1, T v2) {
//		T add = v1 + v2;
//		return add;
//	}
//};
//
//
//
//// 2. Sub
//// Implement a class, named "Sub", which performs a subtraction for v1 and v2 when its "run" member function is called.
//// For example, "Sub<int>().run(30, 20)" returns 10
//template<typename T> class Sub : public Op<T> {
//	Sub();
//	T run(T v1, T v2) {
//		T sub = v1 - v2;
//		return sub;
//	}
//};
//
//
//// 3. Mul
//// Implement a class, named "Sub", which performs a multiplication for v1 and v2 when its "run" member function is called.
//// For example, "Sub<int>().run(10, 10)" returns 100
//template<typename T> class Mul : public Op<T> {
//	Mul();
//	T run(T v1, T v2) {
//		T mul = v1 * v2;
//		return add;
//	}
//};
//
//
//
//// 4. Div
//// Implement a class, named "Div", which performs a division for v1 and v2 when its "run" member function is called.
//// For example, "Sub<int>().run(30, 10)" returns 3
//// At this moment, don't consider any conner case like division-by-zero
//template<typename T> class Div : public Op<T> {
//	Div();
//	T run(T v1, T v2) {
//		if (v2 == 0) {
//			std::cout << "division-by-zero error" << std::endl;
//			break;
//		}
//		T div = v1 + v2;
//		return div;
//	}
//};