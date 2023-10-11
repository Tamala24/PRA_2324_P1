#include <ostream>
#include "list.h"
#include "Node.h"
#define offrange throw std::out_of_range("Posición inválida!!");

template <typename T>
class ListLinked : public List<T> {

    private:
	Node<T>* first;
	int n;

    public:
	ListLinked();
	~ListLinked();
	T operator[](int pos);
	friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
		out << "List => [" << std::endl;
		if(list.n > 0) {
			Node<T>* aux = list.first;
			while(aux != nullptr) {
				out << aux->data << std::endl;
				aux = aux->next;
			}
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

template <typename T>
ListLinked<T>::ListLinked(){
	n = 0;
	first = nullptr;
}
template <typename T>
ListLinked<T>::~ListLinked(){
	Node<T>* aux;
	while(first != nullptr) { 
		aux = first->next;
		delete first;
		first = aux;
	}
}
template <typename T>
T ListLinked<T>::operator[](int pos) {
	/*if((pos < 0) || (pos > (n-1)))
		offrange;
	if(pos == 0)
		return first->data;
	else {
		Node<T>* aux = first;
		for(int i=0;i!=pos;i++) {
			aux = aux->next;
		}
		return aux->data;
	}*/
	return get(pos);
}
template <typename T>
void ListLinked<T>::insert(int pos, T e) {
	if((pos < 0) || (pos > n)) {
		offrange;
	} else if(empty()) {
		first = new Node(e);
	} else if(pos == n) {
		Node<T>* aux = first->next;
		for(int i=0;i<pos;++i)
			aux=aux->next;
		aux->next = new Node(e);
	} else {
		Node<T>* aux = first;
		Node<T>* next = first->next;
		for(int i=0;i<pos;i++) { 
			aux = next;
			next = next->next;
		}
		aux->next = new Node(e,next);
	}
}
template <typename T>
void ListLinked<T>::append(T e) {
	insert(n, e);
}
template <typename T>
void ListLinked<T>::prepend(T e) {
	insert(0, e);
}
template <typename T>
T ListLinked<T>::remove(int pos) {
	if((pos < 0) || (pos > (n-1)) || empty()) {
		offrange;
	} else if(pos == 0) {
		Node<T>* aux = first->next;
		T a = first->data;
		delete first;
		first = aux;
		return a;
	} else {
		Node<T>* paux = first;
		Node<T>* del = first->next;
		for(int i=0;i<pos;++i) { 
			paux = del;
			del = del->next;
		}
		T a = del->data;
		paux->next = del->next;
		delete del;
		return a;
	}
}
template <typename T>
T ListLinked<T>::get(int pos) {
	if((pos < 0) || (pos > (n-1)) || empty())
		offrange;
	if(pos == 0)
		return first->data;
	else {
		Node<T>* aux = first->next;
		for(int i=0;i<pos;++i) 
			aux = aux->next;
		return aux->data;
	}
}
template <typename T>
int ListLinked<T>::search(T e) {
	Node<T>* aux = first;
	int i = 0;
	while(aux != nullptr) {
		if(aux->data == e)
			return i;
		aux = aux->next;
		i++;
	}
	return -1;
}
template <typename T>
bool ListLinked<T>::empty() {
	if(n == 0)
		return true;
	else
		return false;
}
template <typename T>
int ListLinked<T>::size() {
	return n;
}
