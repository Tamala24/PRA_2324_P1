#include <ostream>
#include "list.h"

template <typename T>
class ListArray : public List<T> {
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE;
		void resize(int new_size);
	public:
		ListArray();
		~ListArray();
		T operator[](int pos);
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);

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
ListArray<T>::ListArray() {
	arr = new T[MINSIZE];
	max = MINSIZE;
	n = 0;
}
template<typename T>
ListArray<T>::~ListArray() {
	delete[] arr;
}
template<typename T>
T ListArray<T>::operator[](int pos) {
	if(pos > (-1) && pos < n) 
		return arr[pos];
	else
		throw std::out_of_range("Posición fuera del rango del array");
}
template<typename T>
std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
	for(int i=0;i<list.n;i++) {
		out << list.arr[i] << " ";
	}
	out << std::endl;
	return out;
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
	arr = a;
	max = new_size;
}
template<typename T>
void ListArray<T>::insert(int pos, T e) {
	if(pos < (-1) || pos > (n-1))
		throw std::out_of_range("Posición fuera del rango del array");
	if(pos == (n-1)) {
		arr[pos] = e;
	} else {
		while(pos < n) {
			arr[pos] ^= e;
			e ^= arr[pos];
			arr[pos] ^= e;
			pos++;
		}
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
	if(pos < (-1) || pos > (n-1)) 
		throw std::out_of_range("Posición fuera del rango del array");
	else if(pos == (n-1)) {
		arr[pos] = -1;
		n--;	
	} else 
		while(pos < (n-2)) {
			arr[pos] = arr[pos+1];
			pos++;
		}
	if(n < (max-20)) 
		resize(max-10);
	return aux;
}
template<typename T>
T ListArray<T>::get(int pos) {
	if(pos < (-1) || pos > (n-1)) 
		throw std::out_of_range("Posición fuera del rango del array");
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





