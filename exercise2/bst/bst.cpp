#include "bst.hpp"

namespace lasd {

    template <typename Data>
    BST<Data>::BST(const TraversableContainer<Data> &container){
        
    }

    template <typename Data>
    BST<Data>::BST(MappableContainer<Data> &&container){
        
    }

    template <typename Data>
    BST<Data>::~BST(){
        Clear();
    }

    template <typename Data>
    BST<Data> &BST<Data>::operator=(const BST &binaryTree){
        BinaryTreeLnk<Data>::operator=(binaryTree);
        return *this;
    }

    template <typename Data>
    BST<Data> &BST<Data>::operator=(BST &&binaryTree) noexcept{
        BinaryTreeLnk<Data>::operator=(std::move(binaryTree));
        return *this;
    }

    template <typename Data>
    inline bool BST<Data>::operator==(const BST &binaryTree) const noexcept{
        return *this == binaryTree;
    }

    template <typename Data>
    inline bool BST<Data>::operator!=(const BST &binaryTree) const noexcept{
        return *this != binaryTree;
    }

    template <typename Data>
    const Data &BST<Data>::Min() const{
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            return FindPointerToMin(root) -> element;
        }
    }

    template <typename Data>
    Data BST<Data>::MinNRemove(){
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            NodeLnk *min = DetachMin(root);
            Data tempMinData = min -> element;
            delete min;
            return tempMinData;
        }
    }

    template <typename Data>
    void BST<Data>::RemoveMin() const{
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            delete DetachMin(root);
        }
    }

    template <typename Data>
    const Data &BST<Data>::Max() const{
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            return FindPointerToMax(root) -> element;
        }
    }

    template <typename Data>
    Data BST<Data>::MaxNRemove(){
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            NodeLnk *max = DetachMax(root);
            Data tempMaxData = max -> element;
            delete max;
            return tempMaxData;
        }
    }

    template <typename Data>
    void BST<Data>::RemoveMax() const{
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            delete DetachMax(root);
        }
    }

    template <typename Data>
    const Data &BST<Data>::Predecessor(const Data &data) const{
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            NodeLnk *predecessor = FindPointerToPredecessor(root, data);
            if(predecessor != nullptr){
                return predecessor -> element;
            } else{
                throw std::length_error("Predecessor does NOT Exist");
            }
        }
    }

    template <typename Data>
    Data BST<Data>::PredecessorNRemove(const Data &data){
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            NodeLnk *predecessor = FindPointerToPredecessor(root, data);
            if(predecessor != nullptr){
                Data predecessorData = predecessor -> element;
                Remove(predecessorData);
                return predecessorData;
            } else{
                throw std::length_error("Predecessor does NOT Exist");
            }
        }
    }

    template <typename Data>
    void BST<Data>::RemovePredecessor(const Data &data) const{
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            NodeLnk *predecessor = FindPointerToPredecessor(root, data);
            if(predecessor != nullptr){
                const Data &predecessorData = predecessor -> element;
                Remove(predecessorData);
            } else{
                throw std::length_error("Predecessor does NOT Exist");
            }
        }
    }

    template <typename Data>
    const Data &BST<Data>::Successor(const Data &data) const{
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            NodeLnk *Successor = FindPointerToSuccessor(root, data);
            if(Successor != nullptr){
                return Successor -> element;
            } else{
                throw std::length_error("Successor does NOT Exist");
            }
        }
    }

    template <typename Data>
    Data BST<Data>::SuccessorNRemove(const Data &data){
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            NodeLnk *successor = FindPointerToPredecessor(root, data);
            if(successor != nullptr){
                Data successorData = successor -> element;
                Remove(successorData);
                return successorData;
            } else{
                throw std::length_error("Predecessor does NOT Exist");
            }
        }
    }

    template <typename Data>
    void BST<Data>::RemoveSuccessor(const Data &data) const{
        if(BinaryTreeLnk<Data>::Empty()){
            throw std::length_error("BST is Empty");
        } else{
            NodeLnk *successor = FindPointerToPredecessor(root, data);
            if(successor != nullptr){
                const Data &successorData = successor -> element;
                Remove(successorData);
            } else{
                throw std::length_error("Predecessor does NOT Exist");
            }
        }
    }

    template <typename Data>
    bool BST<Data>::Insert(const Data &data){
        NodeLnk *&node = FindPointerTo(root, data);
        if(node == nullptr){
            node = new typename BinaryTreeLnk<Data>::NodeLnk(data);
            size++;
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    bool BST<Data>::Insert(Data &&data) noexcept{
        NodeLnk *&node = FindPointerTo(root, data);
        if(node == nullptr){
            node = new typename BinaryTreeLnk<Data>::NodeLnk(data);
            node -> Element() = std::move(data);
            size++;
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    bool BST<Data>::Remove(const Data &data){
        if(Exists(data)){
            delete Detach(FindPointerTo(root, data));
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    bool BST<Data>::Exists(const Data &data) const noexcept{
        return (FindPointerTo(root, data) != nullptr);
    }

    template <typename Data>
    void BST<Data>::Clear(){
        BinaryTreeLnk<Data>::Clear();
    }

    template <typename Data>
    Data BST<Data>::DataNDelete(NodeLnk *node){
        
    }

    template <typename Data>
    BST<Data>::NodeLnk *BST<Data>::Detach(NodeLnk *&node) noexcept{
        if(node != nullptr){
            if(node -> left == nullptr){
                return Skip2Right(node);
            }
            else if(node -> right == nullptr){
                return Skip2Left(node);
            } else{
                NodeLnk *detachMax = DetachMax(node -> left);
                std::swap(node -> element, detachMax -> element);
                return detachMax;
            }
        }
        return nullptr;
    }

    template <typename Data>
    BST<Data>::NodeLnk *BST<Data>::DetachMin(NodeLnk *&node) noexcept{
        return Skip2Right(FindPointerToMin(node));
    }

    template <typename Data>
    BST<Data>::NodeLnk *BST<Data>::DetachMax(NodeLnk *&node) noexcept{
        return Skip2Left(FindPointerToMax(node));
    }

    template <typename Data>
    BST<Data>::NodeLnk *BST<Data>::Skip2Left(NodeLnk *&node) noexcept{
        NodeLnk *left = nullptr;
        if(node != nullptr){
            std::swap(left, node -> left);
            std::swap(left, node);
            size--;
        }
        return left;
    }

    template <typename Data>
    BST<Data>::NodeLnk *BST<Data>::Skip2Right(NodeLnk *&node) noexcept{
        NodeLnk *right = nullptr;
        if(node != nullptr){
            std::swap(right, node -> right);
            std::swap(right, node);
            size--;
        }
        return right;
    }

    template <typename Data>
    BST<Data>::NodeLnk *&BST<Data>::FindPointerToMin(NodeLnk *&node) noexcept{
        return const_cast<NodeLnk *&>(static_cast <const BST<Data> *> (this) -> FindPointerToMin(node));
    }

    template <typename Data>
    const BST<Data>::NodeLnk * const &BST<Data>::FindPointerToMin(const NodeLnk * const &node) const noexcept{
        if(node != nullptr){
            if(node -> left != nullptr){
                return FindPointerToMin(node -> left);
            }
        }
        return node;
    }

    template <typename Data>
    BST<Data>::NodeLnk *&BST<Data>::FindPointerToMax(NodeLnk *&node) noexcept{
        return const_cast<NodeLnk *&>(static_cast <const BST<Data> *> (this) -> FindPointerToMax(node));
    }

    template <typename Data>
    const BST<Data>::NodeLnk * const &BST<Data>::FindPointerToMax(const NodeLnk * const &node) const noexcept{
        if(node != nullptr){
            if(node -> right != nullptr){
                return FindPointerToMax(node -> right);
            }
        }
        return node;
    }

    template <typename Data>
    BST<Data>::NodeLnk *&BST<Data>::FindPointerTo(NodeLnk *&node, const Data &data) noexcept{
        return const_cast<NodeLnk *&>(static_cast <const BST<Data> *> (this) -> FindPointerTo(node, data));
    }

    template <typename Data>
    const BST<Data>::NodeLnk * const &BST<Data>::FindPointerTo(const NodeLnk * const &node, const Data &data) const noexcept{
        if(node != nullptr){
            if(data != node -> element){
                if(data > node -> element){
                    return FindPointerTo(node -> right, data);
                } else{
                    return FindPointerTo(node -> left, data);
                }
            }
        }
        return node;
    }

    template <typename Data>
    BST<Data>::NodeLnk **BST<Data>::FindPointerToPredecessor(NodeLnk *&node, const Data &data) noexcept{
        return const_cast<NodeLnk **>(static_cast <const BST<Data> *> (this) -> FindPointerToPredecessor(node, data));
    }

    template <typename Data>
    const BST<Data>::NodeLnk * const *BST<Data>::FindPointerToPredecessor(const NodeLnk * const &node, const Data &data) const noexcept{
        NodeLnk * const * current = &node;
        NodeLnk * const * predecessor = nullptr;
        while(*current != nullptr){
            if(data > (*current) -> element){
                predecessor = current;
                current = &((*current) -> right);
            } else{
                current = &((*current) -> left); 
            }
        }
        if(predecessor != nullptr){
            return *predecessor;
        } else{
            return *current;
        }
    }

    template <typename Data>
    BST<Data>::NodeLnk **BST<Data>::FindPointerToSuccessor(NodeLnk *&node, const Data &data) noexcept{
        return const_cast<NodeLnk **>(static_cast <const BST<Data> *> (this) -> FindPointerToSuccessor(node, data));
    }

    template <typename Data>
    const BST<Data>::NodeLnk * const *BST<Data>::FindPointerToSuccessor(const NodeLnk * const &node, const Data &data) const noexcept{
        NodeLnk * const * current = &node;
        NodeLnk * const * successor = nullptr;
        while(*current != nullptr){
            if(data < (*current) -> element){
                successor = current;
                current = &((*current) -> left);
            } else{
                current = &((*current) -> right);
            }
        }
        if(successor != nullptr){
            return *successor;
        } else{
            return *current;
        }
    }
}
