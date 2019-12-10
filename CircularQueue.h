#pragma once
//please note that this class is customized for the 8-entry ROB

#include <iostream>
#include <string>
using namespace std;

class CircularQueue {
private:
	int front;
	int rear;
	int arr[8];
	int itemCount;

public:
	CircularQueue() {
		itemCount = 0;
		front = -1;
		rear = -1;
		for (int i = 0; i < 8; i++) {
			arr[i] = 0;
		}
	}
	bool isEmpty() {
		if (front == -1 && rear == -1)
			return true;
		else
			return false;
	}
	bool isFull() {
		if ((rear + 1) % 8 == front)
			return true;
		else
			return false;
	}
	void enqueue(int val) {
		if (isFull()) {
			cout << "Queue full" << endl;
			return;
		}
		else if (isEmpty()) {
			rear = 0;
			front = 0;
			arr[rear] = val;

		}
		else {
			rear = (rear + 1) % 8;
			arr[rear] = val;

		}
		itemCount++;

	}

	int dequeue() {
		int x = 0;
		if (isEmpty()) {
			cout << "Queue is Empty" << endl;
			return x;
		}
		else if (rear == front) {
			x = arr[rear];
			rear = -1;
			front = -1;
			itemCount--;
			return x;
		}
		else {
			cout << "front value: " << front << endl;
			x = arr[front];
			arr[front] = 0;
			front = (front + 1) % 8;
			itemCount--;
			return x;
		}
	}

	int count() {
		return (itemCount);
	}

	void display() {
		cout << "All values in the Queue are - " << endl;
		for (int i = 0; i < 8; i++) {
			cout << arr[i] << "  ";
		}
	}

};
