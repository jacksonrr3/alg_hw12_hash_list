#pragma once


template <typename T>
class Node {
	T _item;
	Node* _next;

public:
	Node(const T& item) {
		_next = nullptr;
		_item = item;
	}

	Node(const T item, Node<T>* next) {
		_next = next;
		_item = item;
	}

	~Node() {}

	T getItem() const {
		return _item;
	}

	void setItem(const T item) {
		_item = item;
	}

	Node<T>* getNext() {
		return _next;
	}

	void setNext(Node<T>* next) {
		_next = next;
	}

	//friend class Queue;
};


template <typename T>
class List {
	Node<T>* _head;
	Node<T>* _tail;

public:
	List() {
		_head = nullptr;
		_tail = nullptr;
	}

	~List() {
		while (_tail != nullptr) {
			Node<T>* node = _head;
			_head = node->getNext();
			delete node;
		}
	}

	Node<T>* search_node(const T& value) {
		Node<T>* temp_node = _head;
		while (temp_node != nullptr) {
			if (temp_node->getItem() == value) { break; }
			temp_node = temp_node->getNext();
		}
		return temp_node;
	}


	int remove_node(Node<T>* node) {
		if (node == _head) {
			_head = _head->getNext();
			return 0;
		}
		else {
			Node<T>* temp_node = _head;
			while (temp_node->getNext() != node) {
				temp_node = temp_node->getNext();
			}
			temp_node->setNext(node->getNext());
			delete node;
		}

	}


	bool isEmpty() const {
		return _head == nullptr;
	}

	Node<T>* getHead() const {
		return _head;
	}

	void enqueue(const T& item) {
		Node<T>* node = new Node<T>(item);
		if (isEmpty()) {
			_head = node;
			_tail = node;
		}
		else {
			_tail->setNext(node);
			_tail = node;
		}
	}

	T dequeue() {
		if (isEmpty()) return 0;
		T item = _head->getItem();
		Node<T>* temp_head = _head;
		_head = _head->getNext();
		delete temp_head;
		return item;
	}

	void change_value(Node<T>* node, const T& item) {
		node->setItem(item);
	}

};


