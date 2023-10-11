#include <ostream>

template <typename T> 
class Node {
    public:
	// Atributos
	T data;
	Node<T>* next;
	// Métodos
	Node(T data, Node<T>* next=nullptr);
    	friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
			out << node.data  << " ";
			return out;
	}
};
template <typename T>
Node<T>::Node(T data, Node<T>* next){
this->data = data;
this->next = next;
}
