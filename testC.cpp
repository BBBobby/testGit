#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <thread>
//#include "head2.h"
using namespace std;


class Node {
public:
	int val;
	Node* next;
	Node() :val(0), next(nullptr) {}
	Node(int v) : val(v), next(nullptr) {}
};

Node* findMid(Node* head) {
	Node* slow = head;
	Node* fast = head;
	while (fast->next && fast->next->next) {
		// cout << fast->val << endl;
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Node* mergeList(Node* head1, Node* head2) {
	Node* dummy = new Node();
	Node* cur = dummy;
	while (head1 && head2) {
		if (head1->val < head2->val) {
			cur->next = head1;
			head1 = head1->next;
		}
		else {
			cur->next = head2;
			head2 = head2->next;
		}
		cur = cur->next;
	}
	cur->next = head1 ? head1 : head2;

	Node* ans = dummy->next;
	delete dummy;
	return ans;
}

Node* sortList(Node* head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}

	Node* mid = findMid(head);
	Node* head2 = mid->next;
	mid->next = nullptr;

	return mergeList(sortList(head), sortList(head2));
}

class T {

public:
	T() { cout << "默认构造函数" << endl; }
	T(const T&) { cout << "拷贝构造函数" << endl; }
	T(T&&) noexcept { cout << "移动构造函数" << endl; }

	 int a = 0;

};

void t(int& a) {
	cout << "非const" << endl;

}
void t(const int& a) {
	cout << "const" << endl;
}

class Thre {
public:

	Thre() {
		cout << this << endl;
	}
	~Thre() {

	}
};

void del(int* p) {

}


int main()
{




	shared_ptr<int> p(new int(1));
	


	return 0;

}

