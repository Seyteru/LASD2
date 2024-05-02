#include "binarytreelnk.hpp"

namespace lasd {

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data &data){
        element = data;
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk::~NodeLnk(){
        if(left != nullptr){
            delete left;
        }
        if(right != nullptr){
            delete right;
        }
    }

    template <typename Data>
    inline Data &BinaryTreeLnk<Data>::NodeLnk::Element() noexcept{
        return element;
    }

    template <typename Data>
    inline const Data &BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept{
        return element;
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept{
        return (!HasLeftChild() && !HasRightChild());
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept{
        return (left != nullptr);
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept{
        return (right != nullptr);
    }
    

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk &BinaryTreeLnk<Data>::NodeLnk::LeftChild(){
        if(HasLeftChild()){
            return *left;
        } else{
            throw std::out_of_range("Node does NOT have LeftChild");
        }
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk &BinaryTreeLnk<Data>::NodeLnk::RightChild(){
        if(HasLeftChild()){
            return *right;
        } else{
            throw std::out_of_range("Node does NOT have RightChild");
        }
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk &BinaryTreeLnk<Data>::NodeLnk::LeftChild() const{
        if(HasLeftChild()){
            return *left;
        } else{
            throw std::out_of_range("Node does NOT have LeftChild");
        }
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk &BinaryTreeLnk<Data>::NodeLnk::RightChild() const{
        if(HasLeftChild()){
            return *right;
        } else{
            throw std::out_of_range("Node does NOT have RightChild");
        }
    }

    template <typename Data>
    inline BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data> &container){
        //Use TraverseFun
    }

    template <typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data> &&){
        //Use MapFun
    }

    template <typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data> &binaryTree){
        root = binaryTree.root;
        size = binaryTree.size;
    }
    template <typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data> &&binaryTree){
        std::swap(root, binaryTree.root);
        std::swap(size, binaryTree.size);
    }

    template <typename Data>
    BinaryTreeLnk<Data>::~BinaryTreeLnk(){
        Clear();
    }

    template <typename Data>
    BinaryTreeLnk<Data> &BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data> &binaryTree){
        root = binaryTree.root;
        size = binaryTree.size;
        return *this;
    }

    template <typename Data>
    BinaryTreeLnk<Data> &BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data> &&binaryTree) noexcept{
        std::swap(root, binaryTree.root);
        std::swap(size, binaryTree.size);
        return *this;
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data> &binaryTree) const noexcept{
        if(size != binaryTree.size){
            return false;
        } else{
            return (Root() == binaryTree.Root());
        }
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data> &binaryTree) const noexcept{
        return !(*this == binaryTree);
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk &BinaryTreeLnk<Data>::Root() const{
        if(size != 0){
            return *root;
        } else{
            throw std::length_error("Binary Tree is Empty")
        }
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk &BinaryTreeLnk<Data>::Root(){
        if(size != 0){
            return *root;
        } else{
            throw std::length_error("Binary Tree is Empty")
        }
    }

    template <typename Data>
    void BinaryTreeLnk<Data>::Clear(){
        if(size != 0){
            delete root;
            root = nullptr;
            size = 0;
        }
    }
}