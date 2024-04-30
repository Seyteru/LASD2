#include "binarytree.hpp"

namespace lasd {

    //Node Operator==
    template <typename Data>
    bool BinaryTree<Data>::Node::operator==(const Node &node) const noexcept{
        bool result = true;
        if(Element() == node.Element()){
            if(HasLeftChild() && node.HasLeftChild()){
                resul= (LeftChild() == node.LeftChild());
            } 
            elseif(HasLeftChild() || node.HasLeftChild()){
                result = false;
            }
            if(result){
                if(HasRightChild() && node.HasRightChild()){
                    result = (RightChild() == node.RightChild());
                }
                else if(HasRightChild() || node.HasRightChild()){
                    result = false;
                }
            }
        } else{
            result = false;
        }
        return result;
    }

    template <typename Data>
    bool BinaryTree<Data>::Node::operator!=(const Node &node) const noexcept{
        return !(*this == node);
    }

    template <typename Data>
    bool BinaryTree<Data>::operator==(const BinaryTree<Data> &binaryTree) const noexcept{
        if(!(this->Empty()) && !(binaryTree.Empty())){
            return (Root() == binaryTree.Root());
        }
        else if((this->Empty()) && (binaryTree.Empty())){
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    bool BinaryTree<Data>::operator!=(const BinaryTree<Data> &binaryTree) const noexcept{
        return !(*this == binaryTree);
    }

    template <typename Data>
    void BinaryTree<Data>::Traverse(TraverseFun traverseFun) const{
        PreOrderTraverse(traverseFun);
    }

    template <typename Data>
    void BinaryTree<Data>::PreOrderTraverse(TraverseFun traverseFun) const{

    }

    template <typename Data>
    void BinaryTree<Data>::PostOrderTraverse(TraverseFun traverseFun) const{

    }

    template <typename Data>
    void BinaryTree<Data>::InOrderTraverse(TraverseFun traverseFun) const{

    }

    template <typename Data>
    void BinaryTree<Data>::BreadthTraverse(TraverseFun traverseFun) const{

    }

    template <typename Data>
    inline void MutableBinaryTree<Data>::Map(MapFun mapFun){
        PreOrderMap(mapFun);
    }

    template <typename Data>
    void MutableBinaryTree<Data>::PreOrderMap(MapFun mapFun){

    }

    template <typename Data>
    void MutableBinaryTree<Data>::PostOrderMap(MapFun mapFun){

    }

    template <typename Data>
    void MutableBinaryTree<Data>::InOrderMap(MapFun mapFun){

    }

    template <typename Data>
    void MutableBinaryTree<Data>::BreadthMap(MapFun mapFun){
        
    }

    template <typename Data>
    inline BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data> &binaryTree){
        if(binaryTree.Size() != 0){
            root = &binaryTree.Root();
        }
    }

    template <typename Data>
    BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data> &preIter){
        stk = preIter.stk;
        root = preIter.root;
    }

    template <typename Data>
    BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data> &&preIter) noexcept{
        std::swap(stk, preIter.stk);
        std:.swap(root, preIter.root);
    }
    
    template <typename Data>
    BTPreOrderIterator<Data> &BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data> &preIter){
        stk = preIter.stk;
        root = preIter.root;
        return *this;
    }

    template <typename Data>
    BTPreOrderIterator<Data> &BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data> &&preIter) noexcept{
        std::swap(stk, preIter.stk);
        std:.swap(root, preIter.root);
        return *this;
    }

    template <typename Data>
    bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data> &preIter) const noexcept{
        if(stk == preIter.stk && root == preIter.root){
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator<Data> &preIter) const noexcept{
        return !(*this == preIter);
    }

    template <typename Data>
    Data &BTPreOrderIterator<Data>::operator*() const{
        if(Terminated()){
            throw std::out_of_range("PreOrderIterator Terminated");
        } else{
            return root -> Element();
        }
    }

    template <typename Data>
    bool BTPreOrderIterator<Data>::Terminated() const noexcept{
        return (root == nullptr && stk.Empty());
    }
    template <typename Data>
    BTPreOrderIterator<Data> &BTPreOrderIterator<Data>::operator++(){
        if(!Terminated()){
            if(root-> HasLeftChild()){
                if(root -> HasRightChild()){
                    stk.Push(&root -> RightChild());
                }
                root = &root -> LeftChild();
            } else{
                if(root -> HasRightChild()){
                    root = &root -> RightChild();
                } else{
                    if(stk.Empty()){
                       root = nullptr; 
                    } else{
                        root = stk.TopNPop();
                    }
                }
            }
        } else{
            root = nullptr;
            throw std::out_of_range("PreOrderIterator Terminated ");
        }
        return *this;
    }

    template <typename Data>
    void BTPreOrderIterator<Data>::Reset() noexcept{
        
    }
}
