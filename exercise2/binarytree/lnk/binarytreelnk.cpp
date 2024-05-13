#include "binarytreelnk.hpp"

namespace lasd {

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data &data){
        element = data;
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data &&data) noexcept{
        element = std::move(data);
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
    BinaryTreeLnk<Data>::MutableNode &BinaryTreeLnk<Data>::NodeLnk::LeftChild(){
        if(HasLeftChild()){
            return *left;
        } else{
            throw std::out_of_range("Node does NOT have LeftChild");
        }
    }

    template <typename Data>
    BinaryTreeLnk<Data>::MutableNode &BinaryTreeLnk<Data>::NodeLnk::RightChild(){
        if(HasLeftChild()){
            return *right;
        } else{
            throw std::out_of_range("Node does NOT have RightChild");
        }
    }

    template <typename Data>
    const BinaryTreeLnk<Data>::Node &BinaryTreeLnk<Data>::NodeLnk::LeftChild() const{
        if(HasLeftChild()){
            return *left;
        } else{
            throw std::out_of_range("Node does NOT have LeftChild");
        }
    }

    template <typename Data>
    const BinaryTreeLnk<Data>::Node &BinaryTreeLnk<Data>::NodeLnk::RightChild() const{
        if(HasLeftChild()){
            return *right;
        } else{
            throw std::out_of_range("Node does NOT have RightChild");
        }
    }

    template <typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data> &container){
        size = container.Size();
        QueueLst<NodeLnk**> que;
        que.Enqueue(&root);
        container.Traverse(
            [&que](const Data &data){
                NodeLnk *&curr = *que.HeadNDequeue();
                curr = new NodeLnk(data);
                que.Enqueue(&curr -> left);
                que.Enqueue(&curr -> right);
            }
        );
    }

    template <typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data> &&container){
        size = container.Size();
        QueueLst<NodeLnk**> que;
        que.Enqueue(&root);
        container.Map(
            [&que](const Data &data){
                NodeLnk *&curr = *que.HeadNDequeue();
                curr = new NodeLnk(std::move(data));
                que.Enqueue(&curr -> left);
                que.Enqueue(&curr -> right);
            }
        );
    }

    template <typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data> &binaryTree){
        size = binaryTree.size;
        root = CreateTree(binaryTree.root);
    }

    template <typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data> &&binaryTree) noexcept{
        std::swap(root, binaryTree.root);
        std::swap(size, binaryTree.size);
    }

    template <typename Data>
    BinaryTreeLnk<Data>::~BinaryTreeLnk(){
        Clear();
    }

    template <typename Data>
    BinaryTreeLnk<Data> &BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data> &binaryTree){
        Clear();
        if(!binaryTree.Empty()){
            size = binaryTree.size;
            root = CreateTree(binaryTree.root);
        }
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
    const BinaryTreeLnk<Data>::Node &BinaryTreeLnk<Data>::Root() const{
        if(size != 0){
            return *root;
        } else{
            throw std::length_error("Binary Tree is Empty");
        }
    }

    template <typename Data>
    BinaryTreeLnk<Data>::MutableNode &BinaryTreeLnk<Data>::Root(){
        if(size != 0){
            return *root;
        } else{
            throw std::length_error("Binary Tree is Empty");
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

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk *BinaryTreeLnk<Data>::CreateTree(const TraversableContainer<Data> &container, ulong idx, NodeLnk *root){
        Vector<Data> vec(container);
        if(idx < container.Size()){
            root = new NodeLnk(vec[idx]);
            root -> left = CreateTree(container, (idx * 2) + 1, root -> left);
            root -> right = CreateTree(container, (idx * 2) + 2, root -> right);
        }
        vec.Clear();
        return root;
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk *BinaryTreeLnk<Data>::CreateTree(MappableContainer<Data> &&container, ulong idx, NodeLnk *root){
        Vector<Data> vec(std::move(container));
        if(idx < container.Size()){
            root = new NodeLnk(std::move(vec[idx]));
            root -> left = CreateTree(container, (idx * 2) + 1, root -> left);
            root -> right = CreateTree(container, (idx * 2) + 2, root -> right);
        }
        return root;
    }

    template<typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::CreateTree(NodeLnk *root){
        NodeLnk* tempNode = new NodeLnk();
        tempNode -> element = root -> Element();
        if(root -> HasLeftChild())
        tempNode -> left = CreateTree (root -> left);
        if(root -> HasRightChild())
        tempNode -> right = CreateTree (root -> right);
        return tempNode;
    }

}