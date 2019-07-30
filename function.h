#pragma once
#include <iostream>
namespace Func {
	struct link {
		void* data;
		link* next = nullptr;
	};

	struct LinkList {
		link* headLink;
		int length = 0;

		LinkList() {};
		~LinkList() {
			link* hold = headLink;
			link* last;
			for (int i = 0; i < length; i++) {
				last = hold;
				hold = hold->next;
				delete last->data;
				delete last;
			}
		};
		template <typename... Args>
		LinkList(Args... args) {
			setup(args...);
		};
		template <typename T, typename... Args>
		void setup(T first, Args... rest) {
			T* temp = new T;
			*temp = first;
			add((void*)temp);
			setup(rest...);
		}
		template <typename T>
		void setup(T first) {
			T* temp = new T;
			*temp = first;
			add((void*)temp);
		}

		void* get(int dataPoint) const {
			if (dataPoint >= length) {
				throw "out of range Linked list";
			}
			link* hold = headLink;
			for (int i = 0; i < dataPoint; i++) {
				hold = hold->next;
			}
			return hold->data;
		}
		void add(void* data) {
			length++;
			link* dataL = new link;
			dataL->data = data;
			dataL->next = headLink;
			headLink = dataL;
		}
	};

	#define Func_arg(place,type) *((type*)(args->get(place)))
	////////////////////////////////////////////////////////////////////////////////////////////

	class FUNCTION
	{
	public:
		FUNCTION() {};
		virtual void* operator () (LinkList* args = nullptr) { return nullptr; }
	};

	////////////////////////////////////////////////////////////////////////////////////////////
	#define Func_Function(name) \
	class name : public Func::FUNCTION\
	{\
	public:\
		name() {};\
		void* operator () (Func::LinkList* args = nullptr) { \

	#define Func_end(name) \
	 return nullptr;\
	 }}name;
}
