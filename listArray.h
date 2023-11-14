#include <ostream>
#include "list.h"
#define offrange throw std::out_of_range("Posición inválida!!");

template <typename T>
class ListArray : public List<T> {
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;
		void resize(int new_size);
	public:
		ListArray();
		~ListArray();
		T operator[](int pos);
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
			out << "List => [" << std::endl;
			if(list.n != 0) {
				for(int i=0;i<list.n;i++) 
					out << list.arr[i] << std::endl;
			}
			out << "]";
			return out;
		}

		void insert(int pos, T e) override;
        	void append(T e) override;
        	void prepend(T e) override;
        	T remove(int pos) override;
        	T get(int pos) override;
        	int search(T e) override;
        	bool empty() override;
        	int size() override;

};

template<typename T>
ListArray<T>::ListArray() : max{MINSIZE}, n{0} {
	arr = new T[MINSIZE];
	for(int i=0;i<MINSIZE;i++)
		arr[i] = -1;
}
template<typename T>
ListArray<T>::~ListArray() {
	delete[] arr;
}
template<typename T>
T ListArray<T>::operator[](int pos) {
	if(pos > (-1) && pos < max) 
		return arr[pos];
	else
		offrange;
}
template<typename T>
void ListArray<T>::resize(int new_size) {
	T* a = new T[new_size];
	int i = 0;
	while(i<n) {
		a[i] = arr[i];
		i++;
	}
	delete[] arr;
	while(i<new_size) {
		a[i] = -1;
		i++;
	}
	arr = a;
	max = new_size;
}
template<typename T>
void ListArray<T>::insert(int pos, T e) {
	if((pos < 0) || (pos > n)) {
		offrange;
	} else if(pos == n) {
		arr[pos] = e;
	} else {
		T aux;
		while(pos < n) {
			aux = arr[pos];
			arr[pos] = e;
			e = aux;
			pos++;
		}
		arr[pos] = e;
	}
	n++;
	if(n == max)
		resize(max+10);
}
template<typename T>
void ListArray<T>::append(T e) {
	insert(n, e);
}
template<typename T>
void ListArray<T>::prepend(T e) {
	insert(0, e);
}
template<typename T>
T ListArray<T>::remove(int pos) {
	T aux = arr[pos];
	if(pos < 0 || pos > (n-1)) {
		offrange;
	} else if(pos == (n-1)) {
		arr[pos] = -1;
	} else { 
		while(pos != n) {
			arr[pos] = arr[pos+1];
			pos++;
		}
	}
	n--;
	if((max - n) > 10) 
		resize(max-10);
	return aux;
}
template<typename T>
T ListArray<T>::get(int pos) {
	if(pos < (-1) || pos > (n-1)) 
		offrange;
	return arr[pos];
}
template<typename T>
int ListArray<T>::search(T e) {
	for(int i=0;i<n;i++) {
		if(arr[i] == e)
			return i;
		i++;
	}
	return -1;
}
template<typename T>
bool ListArray<T>::empty() {
	if(n != 0) 
		return false;
	else
		return true;
}
template<typename T>
int ListArray<T>::size() {
	return n;
}





