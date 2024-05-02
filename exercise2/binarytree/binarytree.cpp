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

    // Traverse and TraverseAuxiliary Functions
    template <typename Data>
    void BinaryTree<Data>::Traverse(TraverseFun traverseFun) const{
        PreOrderTraverse(traverseFun);
    }

    template <typename Data>
    void BinaryTree<Data>::PreOrderTraverse(TraverseFun traverseFun) const{
        if(!(this -> Empty())){
            PreOrderTraverse(traverseFun, Root());
        }
    }

    template <typename Data>
    void BinaryTree<Data>::PostOrderTraverse(TraverseFun traverseFun) const{
        if(!(this -> Empty())){
            PostOrderTraverse(traverseFun, Root());
        }
    }

    template <typename Data>
    void BinaryTree<Data>::InOrderTraverse(TraverseFun traverseFun) const{
        if(!(this -> Empty())){
            InOrderTraverse(traverseFun, Root());
        }
    }

    template <typename Data>
    void BinaryTree<Data>::BreadthTraverse(TraverseFun traverseFun) const{
        if(!(this -> Empty())){
            BreadthTraverse(traverseFun, Root());
        }
    }

    template <typename Data>
    void BinaryTree<Data>::PreOrderTraverse(TraverseFun traverseFun, Node &node) const{
        traverseFun(node.Element());
        if(node.HasLeftChild()){
            PreOrderTraverse(traverseFun, node.LeftChild());
        }
        if(node.HasRightChild()){
            PreOrderTraverse(traverseFun, node.RightChild());
        }
    }

    template <typename Data>
    void BinaryTree<Data>::PostOrderTraverse(TraverseFun traverseFun, Node &node) const{
        if(node.HasLeftChild()){
            PostOrderTraverse(traverseFun, node.LeftChild());
        }
        if(node.HasRightChild()){
            PostOrderTraverse(traverseFun, node.RightChild());
        }
        traverseFun(node.Element());
    }

    template <typename Data>
    void BinaryTree<Data>::InOrderTraverse(TraverseFun traverseFun, Node &node) const{
        if(node.HasLeftChild()){
            PostOrderTraverse(traverseFun, node.LeftChild());
        }
        traverseFun(node.Element());
        if(node.HasRightChild()){
            PostOrderTraverse(traverseFun, node.RightChild());
        }
    }

    template <typename Data>
    void BinaryTree<Data>::BreadthTraverse(TraverseFun traverseFun, Node &node) const{
        QueueVec<Node *> queue;
        queue.Enqueue(&node);
        Node *current = nullptr;
        while(!queue.Empty()){
            current = queue.HeadNDequeue;
            traverseFun(current -> Element());
            if(current -> HasLeftChild()){
                queue.Enqueue(&(current -> LeftChild()));
            }
            if(current -> HasRightChild()){
                queue.Enqueue(&(current -> RightChild()));
            }
        }
    }

    // Map and MapAuxiliary Functions
    template <typename Data>
    inline void MutableBinaryTree<Data>::Map(MapFun mapFun){
        PreOrderMap(mapFun);
    }

    template <typename Data>
    void MutableBinaryTree<Data>::PreOrderMap(MapFun mapFun){
        if(!(this -> Empty())){
            PreOrderMap(mapFun, Root());
        }
    }

    template <typename Data>
    void MutableBinaryTree<Data>::PostOrderMap(MapFun mapFun){
        if(!(this -> Empty())){
            PostOrderMap(mapFun, Root());
        }
    }

    template <typename Data>
    void MutableBinaryTree<Data>::InOrderMap(MapFun mapFun){
        if(!(this -> Empty())){
            InOrderMap(mapFun, Root());
        }
    }

    template <typename Data>
    void MutableBinaryTree<Data>::BreadthMap(MapFun mapFun){
        if(!(this -> Empty())){
            BreadthMap(mapFun, Root());
        }
    }

    template <typename Data>
    void MutableBinaryTree<Data>::PreOrderMap(MapFun mapFun, MutableNode &mutNode){
        mapFun(mutNode.Element());
        if(mutNode.HasLeftChild()){
            PreOrderMap(mapFun, mutNode.LeftChild());
        }
        if(mutNode.HasRightChild()){
            PreOrderMap(mapFun, mutNode.RightChild());
        }
    }

    template <typename Data>
    void MutableBinaryTree<Data>::PostOrderMap(MapFun mapFun, MutableNode &mutNode){
        if(mutNode.HasLeftChild()){
            PostOrderMap(mapFun, mutNode.LeftChild());
        }
        if(mutNode.HasRightChild()){
            PostOrderMap(mapFun, mutNode.RightChild());
        }
        mapFun(mutNode.Element());
    }

    template <typename Data>
    void MutableBinaryTree<Data>::InOrderMap(MapFun mapFun, MutableNode &mutNode){
        if(mutNode.HasLeftChild()){
            InOrderMap(mapFun, mutNode.LeftChild());
        }
        mapFun(mutNode.Element());
        if(mutNode.HasRightChild()){
            InOrderMap(mapFun, mutNode.RightChild());
        }
    }

    template <typename Data>
    void MutableBinaryTree<Data>::BreadthMap(MapFun mapFun, MutableNode &mutNode){
        QueueVec<MutableNode *> queue;
        queue.Enqueue(&mutNode);
        MutableNode *current = nullptr;
        while(!queue.Empty()){
            *current = queue.HeadNDequeue;
            mapFun(current -> Element());
            if(current -> HasLeftChild()){
                queue.Enqueue(&(current -> LeftChild()));
            }
            if(current -> HasRightChild()){
                queue.Enqueue(&(current -> RightChild()));
            }
        }
    }

    // PreOrderIterator
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
        std::swap(root, preIter.root);
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
        std::swap(root, preIter.root);
        return *this;
    }

    template <typename Data>
    bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data> &preIter) const noexcept{
        return (root == preIter.root && stk == preIter.stk);
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
        root = &binaryTree.Root();
        stk.Clear();
    }

    //PreOrderMutableIterator
    template <typename Data>
    inline BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(const MutableBinaryTree<Data> &mutBinaryTree){
        if(mutBinaryTree.Size() != 0){
            root = &mutBinaryTree.Root();
        }
    }

    template <typename Data>
    BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(const BTPreOrderMutableIterator<Data> &mutPreIter){
        stk = mutPreIter.stk;
        root = mutPreIter.root;
    }

    template <typename Data>
    BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(BTPreOrderMutableIterator<Data> &&mutPreIter) noexcept{
        std::swap(stk, mutPreIter.stk);
        std::swap(root, mutPreIter.root);
    }

    template <typename Data>
    BTPreOrderMutableIterator<Data> &BTPreOrderMutableIterator<Data>::operator=(const BTPreOrderMutableIterator<Data> &mutPreIter){
        stk = mutPreIter.stk;
        root = mutPreIter.root;
        return *this;
    }

    template <typename Data>
    BTPreOrderMutableIterator<Data> &BTPreOrderMutableIterator<Data>::operator=(BTPreOrderMutableIterator<Data> &&mutPreIter) noexcept{
        std::swap(stk, mutPreIter.stk);
        std::swap(root, mutPreIter.root);
        return *this;
    }

    template <typename Data>
    bool BTPreOrderMutableIterator<Data>::operator==(const BTPreOrderMutableIterator<Data> &mutPreIter) const noexcept{
        return (root == mutPreIter.root && stk == mutPreIter.stk);
    }

    template <typename Data>
    bool BTPreOrderMutableIterator<Data>::operator!=(const BTPreOrderMutableIterator<Data> &mutPreIter) const noexcept{
        return !(*this == mutPreIter);
    }

    template <typename Data>
    Data &BTPreOrderMutableIterator<Data>::operator*(){
        if(Terminated()){
            throw std::out_of_range("PreOrderMutableIterator Terminated");
        } else{
            return root -> Element();
        }
    }

    // PostOrderIterator
    template <typename Data>
    inline BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data> &binaryTree){
        root = &binaryTree.Root();
        while(root -> HasLeftChild() || root -> HasRightChild()){
            stk.Push(root);
            if(root -> HasLeftChild()){
                root = &root -> LeftChild();
            } else{
                root = &root -> RightChild();
            }
        }
    }

    template <typename Data>
    BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator<Data> &postIter){
        stk = postIter.stk;
        root = postIter.root;
    }

    template <typename Data>
    BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator<Data> &&postIter) noexcept{
        std::swap(stk, postIter.stk);
        std::swap(root, postIter.root);
    }
    
    template <typename Data>
    BTPostOrderIterator<Data> &BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data> &postIter){
        stk = postIter.stk;
        root = postIter.root;
        return *this;
    }

    template <typename Data>
    BTPostOrderIterator<Data> &BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data> &&postIter) noexcept{
        std::swap(stk, postIter.stk);
        std::swap(root, postIter.root);
        return *this;
    }

    template <typename Data>
    bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data> &postIter) const noexcept{
        return (root == postIter.root && stk == postIter.stk);
    }

    template <typename Data>
    bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator<Data> &postIter) const noexcept{
        return !(*this == postIter);
    }

    template <typename Data>
    Data &BTPostOrderIterator<Data>::operator*() const{
        if(Terminated()){
            throw std::out_of_range("PostOrderIterator Terminated");
        } else{
            return root -> Element();
        }
    }

    template <typename Data>
    bool BTPostOrderIterator<Data>::Terminated() const noexcept{
        return (root == nullptr && stk.Empty());
    }
    template <typename Data>
    BTPostOrderIterator<Data> &BTPostOrderIterator<Data>::operator++(){
        //ToDO
    }

    template <typename Data>
    void BTPostOrderIterator<Data>::Reset() noexcept{
        //ToDo
    }

    //PostOrderMutableIterator
    template <typename Data>
    inline BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(const MutableBinaryTree<Data> &mutBinaryTree){
        root = &mutBinaryTree.Root();
        while(root -> HasLeftChild() || root -> HasRightChild()){
            stk.Push(root);
            if(root -> HasLeftChild()){
                root = &root -> LeftChild();
            } else{
                root = &root -> RightChild();
            }
        }
    }

    template <typename Data>
    BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(const BTPostOrderMutableIterator<Data> &mutPostIter){
        stk = mutPostIter.stk;
        root = mutPostIter.root;
    }

    template <typename Data>
    BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(BTPostOrderMutableIterator<Data> &&mutPostIter) noexcept{
        std::swap(stk, mutPostIter.stk);
        std::swap(root, mutPostIter.root);
    }

    template <typename Data>
    BTPostOrderMutableIterator<Data> &BTPostOrderMutableIterator<Data>::operator=(const BTPostOrderMutableIterator<Data> &mutPostIter){
        stk = mutPostIter.stk;
        root = mutPostIter.root;
        return *this;
    }

    template <typename Data>
    BTPostOrderMutableIterator<Data> &BTPostOrderMutableIterator<Data>::operator=(BTPostOrderMutableIterator<Data> &&mutPostIter) noexcept{
        std::swap(stk, mutPostIter.stk);
        std::swap(root, mutPostIter.root);
        return *this;
    }

    template <typename Data>
    bool BTPostOrderMutableIterator<Data>::operator==(const BTPostOrderMutableIterator<Data> &mutPostIter) const noexcept{
        return (root == mutPostIter.root && stk == mutPostIter.stk);
    }

    template <typename Data>
    bool BTPostOrderMutableIterator<Data>::operator!=(const BTPostOrderMutableIterator<Data> &mutPostIter) const noexcept{
        return !(*this == mutPostIter);
    }

    template <typename Data>
    Data &BTPostOrderMutableIterator<Data>::operator*(){
        if(Terminated()){
            throw std::out_of_range("PostOrderMutableIterator Terminated");
        } else{
            return root -> Element();
        }
    }

    // InOrderIterator
    template <typename Data>
    inline BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data> &binaryTree){
        root = &binaryTree.Root();
        while(root -> HasLeftChild()){
            stk.Push(root);
            root = &root -> LeftChild();
        }
    }

    template <typename Data>
    BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data> &inIter){
        stk = inIter.stk;
        root = inIter.root;
    }

    template <typename Data>
    BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data> &&inIter) noexcept{
        std::swap(stk, inIter.stk);
        std::swap(root, inIter.root);
    }
    
    template <typename Data>
    BTInOrderIterator<Data> &BTInOrderIterator<Data>::operator=(const BTInOrderIterator<Data> &inIter){
        stk = inIter.stk;
        root = inIter.root;
        return *this;
    }

    template <typename Data>
    BTInOrderIterator<Data> &BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data> &&inIter) noexcept{
        std::swap(stk, inIter.stk);
        std::swap(root, inIter.root);
        return *this;
    }

    template <typename Data>
    bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator<Data> &inIter) const noexcept{
        return (root == inIter.root && stk == inIter.stk);
    }

    template <typename Data>
    bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator<Data> &inIter) const noexcept{
        return !(*this == inIter);
    }

    template <typename Data>
    Data &BTInOrderIterator<Data>::operator*() const{
        if(Terminated()){
            throw std::out_of_range("InOrderIterator Terminated");
        } else{
            return root -> Element();
        }
    }

    template <typename Data>
    bool BTInOrderIterator<Data>::Terminated() const noexcept{
        return (root == nullptr && stk.Empty());
    }
    template <typename Data>
    BTInOrderIterator<Data> &BTInOrderIterator<Data>::operator++(){
        if(!Terminated()){
            if(root.IsLeaf()){
                if(stk.Empty()){
                    root = nullptr;
                } else{
                    root = stk.TopNPop();
                }
            }
        }
    }

    template <typename Data>
    void BTInOrderIterator<Data>::Reset() noexcept{
        //ToDO
    }

    // InOrderMutableIterator
    template <typename Data>
    inline BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(const MutableBinaryTree<Data> &mutBinaryTree){
        root = &mutBinaryTree.Root();
        while(root -> HasLeftChild()){
            stk.Push(root);
            root = &root -> LeftChild();
        }
    }

    template <typename Data>
    BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(const BTInOrderMutableIterator<Data> &mutInIter){
        stk = mutInIter.stk;
        root = mutInIter.root;
    }

    template <typename Data>
    BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(BTInOrderMutableIterator<Data> &&mutInIter) noexcept{
        std::swap(stk, mutInIter.stk);
        std::swap(root, mutInIter.root);
    }

    template <typename Data>
    BTInOrderMutableIterator<Data> &BTInOrderMutableIterator<Data>::operator=(const BTInOrderMutableIterator<Data> &mutInIter){
        stk = mutInIter.stk;
        root = mutInIter.root;
        return *this;
    }

    template <typename Data>
    BTInOrderMutableIterator<Data> &BTInOrderMutableIterator<Data>::operator=(BTInOrderMutableIterator<Data> &&mutInIter) noexcept{
        std::swap(stk, mutInIter.stk);
        std::swap(root, mutInIter.root);
        return *this;
    }

    template <typename Data>
    bool BTInOrderMutableIterator<Data>::operator==(const BTInOrderMutableIterator<Data> &mutInIter) const noexcept{
        return (root == mutInIter.root && stk == mutInIter.stk);
    }

    template <typename Data>
    bool BTInOrderMutableIterator<Data>::operator!=(const BTInOrderMutableIterator<Data> &mutInIter) const noexcept{
        return !(*this == mutInIter);
    }

    template <typename Data>
    Data &BTInOrderMutableIterator<Data>::operator*(){
        if(Terminated()){
            throw std::out_of_range("InOrderMutableIterator Terminated");
        } else{
            return root -> Element();
        }
    }

    // BreadthIterator
    template <typename Data>
    inline BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data> &binaryTree){
        if(binaryTree.Size() != 0){
            root = &binaryTree.Root();
        }
    }

    template <typename Data>
    BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data> &breadthIter){
        que = breadthIter.que;
        root = breadthIter.root;
    }

    template <typename Data>
    BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data> &&breadthIter) noexcept{
        std::swap(que, breadthIter.que);
        std::swap(root, breadthIter.root);
    }
    
    template <typename Data>
    BTBreadthIterator<Data> &BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data> &breadthIter){
        que = breadthIter.que;
        root = breadthIter.root;
        return *this;
    }

    template <typename Data>
    BTBreadthIterator<Data> &BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data> &&breadthIter) noexcept{
        std::swap(que, breadthIter.que);
        std::swap(root, breadthIter.root);
        return *this;
    }

    template <typename Data>
    bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator<Data> &breadthIter) const noexcept{
        return (root == breadthIter.root && que == breadthIter.que);
    }

    template <typename Data>
    bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator<Data> &breadthIter) const noexcept{
        return !(*this == breadthIter);
    }

    template <typename Data>
    Data &BTBreadthIterator<Data>::operator*() const{
        if(Terminated()){
            throw std::out_of_range("BreadthIterator Terminated");
        } else{
            return root -> Element();
        }
    }

    template <typename Data>
    bool BTBreadthIterator<Data>::Terminated() const noexcept{
        return (root == nullptr && que.Empty());
    }
    template <typename Data>
    BTBreadthIterator<Data> &BTBreadthIterator<Data>::operator++(){
        if(!Terminated()){
            if(root -> HasLeftChild()){
                que.Enqueue(&root -> LeftChild());
            }
            if(root -> HasRightChild()){
                que.Enqueue(&root -> RightChild());
            }
            if(que.Empty()){
                root = nullptr;
            } else{
                root = que.HeadNDequeue();
            }
        }
    }

    template <typename Data>
    void BTBreadthIterator<Data>::Reset() noexcept{
        que.Clear();
        root = Root();
    }

    // BreadthMutableIterator
    template <typename Data>
    inline BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(const MutableBinaryTree<Data> &mutBinaryTree){
        if(mutBinaryTree.Size() != 0){
            root = &mutBinaryTree.Root();
        }
    }

    template <typename Data>
    BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(const BTBreadthMutableIterator<Data> &mutBreadthIter){
        que = mutBreadthIter.que;
        root = mutBreadthIter.root;
    }

    template <typename Data>
    BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(BTBreadthMutableIterator<Data> &&mutBreadthIter) noexcept{
        std::swap(que, mutBreadthIter.que);
        std::swap(root, mutBreadthIter.root);
    }

    template <typename Data>
    BTBreadthMutableIterator<Data> &BTBreadthMutableIterator<Data>::operator=(const BTBreadthMutableIterator<Data> &mutBreadthIter){
        que = mutBreadthIter.que;
        root = mutBreadthIter.root;
        return *this;
    }

    template <typename Data>
    BTBreadthMutableIterator<Data> &BTBreadthMutableIterator<Data>::operator=(BTBreadthMutableIterator<Data> &&mutBreadthIter) noexcept{
        std::swap(que, mutBreadthIter.que);
        std::swap(root, mutBreadthIter.root);
        return *this;
    }

    template <typename Data>
    bool BTBreadthMutableIterator<Data>::operator==(const BTBreadthMutableIterator<Data> &mutBreadthIter) const noexcept{
        return (root == mutBreadthIter.root && que == mutBreadthIter.que);
    }

    template <typename Data>
    bool BTBreadthMutableIterator<Data>::operator!=(const BTBreadthMutableIterator<Data> &mutBreadthIter) const noexcept{
        return !(*this == mutBreadthIter);
    }

    template <typename Data>
    Data &BTBreadthMutableIterator<Data>::operator*(){
        if(Terminated()){
            throw std::out_of_range("BreadthMutableIterator Terminated");
        } else{
            return root -> Element();
        }
    }

}
