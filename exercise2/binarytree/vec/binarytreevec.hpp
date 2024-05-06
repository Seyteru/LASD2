
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public MutableBinaryTree<Data>{
  // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  // ...
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;
  using BinaryTree<Data>::size;

  struct NodeVec : virtual MutableNode{ // Must extend MutableNode

  private:

    // ...

  protected:

    // ...

  public:

    NodeVec() = default;

    ~NodeVec();

    Data &Element() noexcept override;
    const Data &Element() const noexcept override;

    bool IsLeaf() const noexcept override;
    bool HasLeftChild() const noexcept override;
    bool HasRightChild() const noexcept override;

    NodeVec &LeftChild() const override;
    NodeVec &RightChild() const override;
    NodeVec &LeftChild() override;
    NodeVec &RightChild() override;

    Data element;
    Vector<NodeVec*> *pvec = nullptr;
    ulong idxNode;

  };

  Vector<NodeVec*> vec;

public:


  // Default constructor
  // BinaryTreeVec() specifiers;

  BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a TraversableContainer
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a MappableContainer

  BinaryTreeVec(const TraversableContainer<Data> &);
  BinaryTreeVec(MappableContainer<Data> &&) noexcept;

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeVec(argument) specifiers;

  BinaryTreeVec(const BinaryTreeVec<Data> &);

  // Move constructor
  // BinaryTreeVec(argument) specifiers;

  BinaryTreeVec(BinaryTreeVec<Data> &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeVec() specifiers;

  ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  BinaryTreeVec &operator=(const BinaryTreeVec<Data> &);

  // Move assignment
  // type operator=(argument) specifiers;

  BinaryTreeVec &operator=(BinaryTreeVec<Data> &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  bool operator==(const BinaryTreeVec<Data> &) const noexcept;
  bool operator!=(const BinaryTreeVec<Data> &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)

  NodeVec &Root() const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  // type Root() specifiers; // Override MutableBinaryTree member (throw std::length_error when empty)

  NodeVec &Root() override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member

  void Clear() override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)

  // type BreadthTraverse(arguments) specifiers; // Override BreadthTraversableContainer member

  using typename TraversableContainer<Data>::TraverseFun;
  virtual void BreadthTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  // type BreadthMap(arguments) specifiers; // Override BreadthMappableContainer member

  using typename MappableContainer<Data>::MapFun;
  virtual void BreadthMap(MapFun) override;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
