#include <ostream>
#include "list.h"

template <template T>
class ListArray : public List<T> {
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE;
	public:
		ListArray() {};
		~ListArray();
		T operator[](int pos);
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);
		void resize(int new_size);

		void insert(int pos, T e) override;
        	void append(T e) override;
        	void prepend(T e) override;
        	T remove(int pos) override;
        	T get(int pos) override;
        	int search(T e) override;
        	bool empty() override;
        	int size() override;

};	
