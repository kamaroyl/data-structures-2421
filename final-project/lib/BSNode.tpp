template<typename T>
BSNode<T>::BSNode(): left(nullptr), right(nullptr), parent(nullptr), data(nullptr), isSecondary(false){
}

template<typename T>
BSNode<T>::BSNode(T* data): left(nullptr), right(nullptr), parent(nullptr), data(data), isSecondary(true) { 
}

template<typename T>
BSNode<T>::~BSNode() {
    delete this->left;
    delete this->right;
    delete this->parent;
    if(!this->isSecondary) {
        delete this->data;
    }
}

template<typename T>
void BSNode<T>::setData(T* data) {
    this->data = data;
}

template<typename T>
void BSNode<T>::setLeft(BSNode<T>* left) {
    this->left = left;
}

template<typename T>
void BSNode<T>::setRight(BSNode<T>* right) {
    this->right = right;
}

template<typename T>
void BSNode<T>::setParent(BSNode<T>* parent) {
    this->parent = parent;
}

template<typename T>
void BSNode<T>::setIsSecondary(bool isSecondary) {
    this->isSecondary = isSecondary;
}

template<typename T>
T* BSNode<T>::getData() {
    return this->data;
}

template<typename T>
BSNode<T>* BSNode<T>::getLeft() {
    return this->left;
}

template<typename T>
BSNode<T>* BSNode<T>::getRight() {
    return this->right;
}

template<typename T>
BSNode<T>* BSNode<T>::getParent() {
    return this->parent;
}

template<typename T>
void printNode(BSNode<T>* node){
    std::cout << (*node->getData());
}
