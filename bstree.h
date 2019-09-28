#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    Node<T> *root;
	
	private:
	Node<T> *removeNode(Node<T> * node, T data) {
        if (!node)
            return node;
        else if (data > node->data)
            node->right = removeNode(node->right, data);
        else if (data < node->data)
            node->left = removeNode(node->left, data);
        else {
            if (!node->right) {
                auto temp = node->left;
                delete node;
                return temp;
            }
            else if (!node->left) {
                auto temp = node->right;
                delete node;
                return temp;
            }
            auto minDataNode = findMinDataNode(node->right);
            node->data = minDataNode->data;
            node->right = removeNode(node->right, minDataNode->data);
        }
        return node;
    }

    public:
        BSTree() : root(nullptr), nodes(0) {};

        bool find(T data) { 
            // TODO
            auto temp = new Node<T>();
            temp->data = data;
            auto current = root;
            while (current) {
                if (data == current->data)
                    return true;
                else
                    if (data <= current->data)
                        current = current->left;
                    else
                        current = current->right;
            }
            return false;
        } 

        bool remove(T data) {
            if (find(data) and root) {
                root = removeNode(root, data);
                --nodes;
                return true;
            }
            return false;
        }

        size_t size() {
            // TODO
            return nodes;
        }
    
        size_t height(Node<T>* node){
            if(!node) return 0;
            size_t left=height(node->left);
            size_t right=height(node->right);
            return 1+((right<left)?left:right);
        }

        size_t height() {
            return height(root);
           
        }

        void traversePreOrder(Node<T> * Pointer) {
            // TODO
            if (Pointer == nullptr) return;
            cout << Pointer->data << " ";
            traversePreOrder(Pointer->left);
            traversePreOrder(Pointer->right);
        }

        void traverseInOrder(Node<T> *Pointer) {
            // TODO
            if (Pointer == nullptr) return;
            traverseInOrder(Pointer->left);
            cout << Pointer->data << " ";
            traverseInOrder(Pointer->right);
        }

        void traversePostOrder(Node<T> *Pointer) {
            // TODO
            if (Pointer == nullptr) return;
            traversePostOrder(Pointer->left);
            traversePostOrder(Pointer->right);
            cout << Pointer->data << " ";
        }

        Iterator<T> begin() {
            // TODO
            if (!this->root) { return Iterator<T>(); }
            return Iterator<T>(this->root);
        }

        Iterator<T> end() { 
            // TODO
            return Iterator<T>();
        }
    
    void delete(Node<T>*node){
        if (root == nullptr) return;

	  deleteTree(node->left);
	  deleteTree(node->right);

	  delete node;
    }

        ~BSTree() {
            // TODO
            delete(root);
        }
};

#endif
