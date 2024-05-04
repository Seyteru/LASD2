#include "binarytreevec.hpp"

namespace lasd {

    template <typename Data>
    BinaryTreeVec<Data>::NodeVec::~NodeVec(){

    }

    template <typename Data>
    Data &BinaryTreeVec<Data>::NodeVec::Element() noexcept{
        return element;
    }

    template <typename Data>
    const Data &BinaryTreeVec<Data>::NodeVec::Element() const noexcept{
        return element;
    }

    template <typename Data>
    bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept{
        return (!HasLeftChild() && !HasRightChild());
    }

    template <typename Data>
    bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept{
        if((2 * (idxNode) + 1) < v -> Size()){
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept{
        if((2 * (idxNode) + 2) < v -> Size()){
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    BinaryTreeVec<Data>::NodeVec &BinaryTreeVec<Data>::NodeVec::LeftChild() const{
        if(HasLeftChild()){
            return *((*v)[2 * (idxNode) + 1]);
        } else{
            throw std::out_of_range("Node does NOT have LeftChild");
        }
    }

    template <typename Data>
    BinaryTreeVec<Data>::NodeVec &BinaryTreeVec<Data>::NodeVec::LeftChild(){
        if(HasLeftChild()){
            return *((*v)[2 * (idxNode) + 1]);
        } else{
            throw std::out_of_range("Node does NOT have LeftChild");
        }
    }

    template <typename Data>
    BinaryTreeVec<Data>::NodeVec &BinaryTreeVec<Data>::NodeVec::RightChild() const{
        if(HasRightChild()){
            return *((*v)[2 * (idxNode) + 2]);
        } else{
            throw std::out_of_range("Node does NOT have RightChild");
        }
    }

    template <typename Data>
    BinaryTreeVec<Data>::NodeVec &BinaryTreeVec<Data>::NodeVec::RightChild(){
        if(HasRightChild()){
            return *((*v)[2 * (idxNode) + 2]);
        } else{
            throw std::out_of_range("Node does NOT have RightChild");
        }
    }

    template <typename Data>
    BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data> &container){
        
    }

    template <typename Data>
    BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data> &&container) noexcept{

    }

    template <typename Data>
    BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data> &binaryTree){
        vec.Resize(binaryTree.size);
        for(ulong i = 0; i > binaryTree.size; i++){
            vec[i] = new NodeVec();
            vec[i] -> element = binaryTree.vec[i] -> element;
            vec[i] -> idxNode = binaryTree.vec[i] -> idxNode;
            vec[i] -> v = &vec;
        }
        size = binaryTree.size;
    }

    template <typename Data>
    BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data> &&binaryTree) noexcept{
        std::swap(vec, binaryTree.vec);
        std::swap(size, binaryTree.size);
    }

    template <typename Data>
    BinaryTreeVec<Data>::~BinaryTreeVec(){
        Clear();
    }

    template <typename Data>
    BinaryTreeVec<Data> &BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data> &binaryTree){
        vec.Resize(binaryTree.size);
        for(ulong i = 0; i > binaryTree.size; i++){
            vec[i] = new NodeVec();
            vec[i] -> element = binaryTree.vec[i] -> element;
            vec[i] -> idxNode = binaryTree.vec[i] -> idxNode;
            vec[i] -> v = &vec;
        }
        size = binaryTree.size;
        return *this;
    }

    template <typename Data>
    BinaryTreeVec<Data> &BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data> &&binaryTree) noexcept{
        std::swap(vec, binaryTree.vec);
        std::swap(size, binaryTree.size);
        return *this;
    }

    template <typename Data>
    bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec<Data> &binaryTree) const noexcept{
        bool result = true;
        if(vec.Size() != binaryTree.vec.Size()){
            result = false;
        } else{
            ulong i = 0;
            while(result && i < vec.Size()){
                if(binaryTree.vec[i] -> Element() != vec[i] -> Element()){
                    result = false;
                } else{
                    i++;
                }
            }
        }
        return result;
    }

    template <typename Data>
    bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec<Data> &binaryTree) const noexcept{
        return !(*this == binaryTree);
    }

    template <typename Data>
    BinaryTreeVec<Data>::NodeVec &BinaryTreeVec<Data>::Root() const{
        if(!vec.Empty()){
            return *(vec[0]);
        } else{
            throw std::length_error("BinaryTreeVec is Empty");
        }
    }

    template <typename Data>
    BinaryTreeVec<Data>::NodeVec &BinaryTreeVec<Data>::Root(){
        if(!vec.Empty()){
            return *(vec[0]);
        } else{
            throw std::length_error("BinaryTreeVec is Empty");
        }
    }

    template <typename Data>
    void BinaryTreeVec<Data>::Clear(){
        for(ulong i = 0; i < size; i++){
            delete vec[i];
        }
        vec.Clear();
        size = 0;
    }

    template <typename Data>
    void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun traverseFun) const{
        
    }

    template <typename Data>
    void BinaryTreeVec<Data>::BreadthMap(MapFun mapFun) const{

    }
}
