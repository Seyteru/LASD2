
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : virtual public MutableBinaryTree<Data>{
  // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  // using BinaryTree<Data>::???;
  using BinaryTree<Data>::size;
  // ...

  struct NodeLnk : public MutableNode<Data>{ // Must extend MutableNode

  private:

    // ...

  protected:

    // ...

  public:

    NodeLnk() = default;
    NodeLnk(const Data &);

    ~NodeLnk();

    Data element;
    NodeLnk *right = nullptr;
    NodeLnk *left = nullptr;

    Data &Element() noexcept override;
    const Data &Element() const noexcept override;

    bool IsLeaf() const noexcept override;
    bool HasLeftChild() const noexcept override;
    bool HasRightChild() const noexcept override;

    NodeLnk &LeftChild() const override;
    NodeLnk &RightChild() const override;
    NodeLnk &LeftChild() override;
    NodeLnk &RightChild() override;

  };

  NodeLnk *root = nullptr;

public:

  // Default constructor
  // BinaryTreeLnk() specifiers;

  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeLnk(argument) specifiers; // A binary tree obtained from a TraversableContainer
  // BinaryTreeLnk(argument) specifiers; // A binary tree obtained from a MappableContainer

  BinaryTreeLnk(const TraversableContainer<Data> &);
  BinaryTreeLnk(MappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeLnk(argument) specifiers;

  BinaryTreeLnk(const BinaryTreeLnk<Data> &);

  // Move constructor
  // BinaryTreeLnk(argument) specifiers;

  BinaryTreeLnk(BinaryTreeLnk<Data> &&);

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeLnk() specifiers;

  ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  BinaryTreeLnk &operator=(const BinaryTreeLnk<Data> &);

  // Move assignment
  // type operator=(argument) specifiers;

  BinaryTreeLnk &operator=(BinaryTreeLnk<Data> &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  bool operator==(const BinaryTreeLnk<Data> &) const noexcept;
  bool operator!=(const BinaryTreeLnk<Data> &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)

  NodeLnk &Root() const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  // type Root() specifiers; // Override MutableBinaryTree member (throw std::length_error when empty)

  NodeLnk &Root() override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member

  void Clear() override;

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
