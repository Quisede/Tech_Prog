#pragma once
template <typename T>
class Node {
public:
	T data;
	Node* next;

	Node(T value) : data(T(value)), next(nullptr) {}
	~Node() {}
};