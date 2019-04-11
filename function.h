#pragma once

struct link {
	void* data;
	link* next = nullptr;
};

struct linkList {
	link* headLink;
	int length = 0;
	link* operator [] (int dataPoint) const {
		link* hold = headLink;
		for (int i = 0; i < dataPoint; i++) {
			hold = hold->next;
		}
		return hold;
	}
	void add(void* data) {
		length++;
		link* dataL = new link;
		dataL->data = data;
		dataL->next = headLink;
		headLink = dataL;
	}
};

#define end(name, displayName) return nullptr;\
 }};\
name displayName;

class function
{
public:
	function() {};
	virtual void* operator () (linkList* arrguments = nullptr) { return nullptr; }
};

#define Function(name, code) \
\
class name : public function\
{\
public:\
	name() {};\
	void* operator () (linkList* arrguments = nullptr) {code return nullptr;}\
};\
name name;


