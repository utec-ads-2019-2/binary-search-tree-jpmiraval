#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T> 
class Iterator {
    private:
        Node<T> *current;
        // De dónde has sacado stack? No está incluido 
        std::stack<Node<T>*> nodes;
    public:
        Iterator() {
            // TODO
            this->current = nullptr;
        }

        Iterator(Node<T> *node,bool bole): current{node} {
            if(!bole){
                while(node){
                    nodes.push(node);
                    node=node->left;
                }
            }
            else
            {
                while(node){
                    node=node->right;
                }
            }
            this->current=node;

        }

        Iterator<T>& operator=(const Iterator<T> &other) {          
            // TODO
            current = other.current;
            return *this;
        }

        bool operator!=(Iterator<T> other) {
            // TODO
            return current != other.current;
        }

        Iterator<T>& operator++() {
            // TODO
            auto topNode = nodes.top();
            nodes.pop();
            if (topNode->right) {
                nodes.push(topNode->right);
                while (nodes.top()->left) nodes.push(nodes.top()->left);
            }
            if (nodes.empty()) current = nullptr;
            else current = nodes.top();
        }

        Iterator<T>& operator--() {
            // TODO
            
            // :(
        }

        T operator*() {
            // TODO
            // Falta la excepción
            if (current) return current->data;
        }
};

#endif
