#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    Node<T> *root;

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

        bool insert(T data) {
            // TODO
             auto temp = new Node<T>();
            temp->data = data;
            if (root == nullptr)
                root = temp;
            else {
                Node<T> *parent = nullptr;
                Node<T> *current = root;
                while(current) {
                    parent = current;
                    if (data <= current->data)
                        current = current->left;
                    else
                        current = current->right;
                }
                if (data <= parent->data)
                    parent->left = temp;
                else
                    parent->right = temp;
            }
            nodes++;
        }

        bool remove(T data) {
            // TODO
            if(find(data)){
                nodes--;
                auto temp = root;
                while(temp){
                    if(temp->data == data){
                        break;
                    }else{
                        if(data <= temp->data){
                        temp = temp->left;
                        }else{
                            temp = temp->right;
                        }
                    }
                }
                while(temp->right){
                    temp->data = temp->right->data;
                    temp = temp->right;
                }
                if(temp->left){
                    temp->data = temp->left->data;
                    temp->left = nullptr;
                }
                
                
                
        }else{
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
