#ifndef FILTER_HPP
#define FILTER_HPP

#include <vector>

template <typename T>
class Filter {
    private:
        std::vector<void (*function)(BSTree<T>* treePtr)> filters; //set of filter functions

    public:
        void addFilter(void (*function(BSTree<T>*treePtr) filter); //add filter to vector
        BSTree<T>* filter(BSTree<T>* tree); //filter a bstree based on currently accumulated filters.return pointer to new BSTree

};
#endif
