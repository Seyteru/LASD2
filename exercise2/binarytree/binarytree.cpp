
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
        
    }

    template <typename Data>
    bool BinaryTree<Data>::operator!=(const BinaryTree<Data> &binaryTree) const noexcept{
        return !(*this == binaryTree);
    }

    template <typename Data>
    inline BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data> &binaryTree){
        if(!binaryTree.Empty()){
            
        }
    }

}
