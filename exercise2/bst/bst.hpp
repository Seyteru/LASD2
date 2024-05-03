
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : virtual public ClearableContainer,virtual public DictionaryContainer<Data>, virtual public BinaryTree<Data>, public BinaryTreeLnk<Data>{
  // Must extend ClearableContainer,
  //             DictionaryContainer<Data>,
  //             BinaryTree<Data>,
  //             BinaryTreeLnk<Data>

private:

  // ...

protected:

  // using BinaryTreeLnk<Data>::???;
  using typename BinaryTreeLnk<Data>::NodeLnk;
  using BinaryTreeLnk<Data>::size;
  using BinaryTreeLnk<Data>::root;
  // ...

public:

  // Default constructor
  // BST() specifiers;

  BST() = default;

  /* ************************************************************************ */

  // Specific constructors
  // BST(argument) specifiers; // A bst obtained from a TraversableContainer
  // BST(argument) specifiers; // A bst obtained from a MappableContainer

  BST(const TraversableContainer<Data> &);
  BST(MappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  // BST(argument) specifiers;

  BST(const BST<Data> &);

  // Move constructor
  // BST(argument) specifiers;

  BST(BST<Data> &&);

  /* ************************************************************************ */

  // Destructor
  // ~BST() specifiers;

  ~BST();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  BST(const BST &);

  // Move assignment
  // type operator=(argument) specifiers;

  BST(BST &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  using BinaryTree<Data>::operator==;
  inline bool operator==(const BST &) const noexcept;
  using BinaryTree<Data>::operator!=;
  inline bool operator!=(const BST &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type Min(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type MinNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type RemoveMin(argument) specifiers; // (concrete function must throw std::length_error when empty)

  virtual const Data &Min() const;
  virtual Data MinNRemove();
  virtual void RemoveMin() const;

  // type Max(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type MaxNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type RemoveMax(argument) specifiers; // (concrete function must throw std::length_error when empty)

  virtual const Data &Max() const;
  virtual Data MaxNRemove();
  virtual void RemoveMax() const;

  // type Predecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  // type PredecessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
  // type RemovePredecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)

  virtual const Data &Predecessor() const;
  virtual Data PredecessorNRemove();
  virtual void RemovePredecessor() const;

  // type Successor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  // type SuccessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
  // type RemoveSuccessor(argument) specifiers; // (concrete function must throw std::length_error when not found)

  virtual const Data &Successor() const;
  virtual Data SuccessorNRemove();
  virtual void RemoveSuccessor() const;

  /* ************************************************************************ */

  // Specific member function (inherited from BinaryTree)

  // type Root(argument) specifiers; // Override BinaryTree member

  using BinaryTreeLnk<Data>::Root;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  // type Remove(argument) specifiers; // Override DictionaryContainer member

  bool Insert(const Data &) override;
  bool Insert(Data &&) override;
  bool Remove(const Data &) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member

  bool Exists(const Data &) const noexcept override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear(argument) specifiers; // Override ClearableContainer member

  void Clear() override;

protected:

  // Auxiliary functions, if necessary!

  // type DataNDelete(argument) specifiers;

  virtual DataNDelete(NodeLnk *);

  // type Detach(argument) specifiers;

  virtual NodeLnk *Detach(NodeLnk *&) noexcept;

  // type DetachMin(argument) specifiers;
  // type DetachMax(argument) specifiers;

  virtual NodeLnk *DetachMin(NodeLnk *&) noexcept;
  virtual NodeLnk *DetachMax(NodeLnk *&) noexcept;

  // type Skip2Left(argument) specifiers;
  // type Skip2Right(argument) specifiers;

  virtual NodeLnk *Skip2Left(NodeLnk *&) noexcept;
  virtual NodeLnk *Skip2Right(NodeLnk *&) noexcept;

  // type FindPointerToMin(argument) specifiers; // Both mutable & unmutable versions
  // type FindPointerToMax(argument) specifiers; // Both mutable & unmutable versions

  virtual NodeLnk *&FindPointerToMin(NodeLnk *&) noexcept;
  virtual const NodeLnk * const &FindPointerToMin(const NodeLnk * const &) const noexcept;
  virtual NodeLnk *&FindPointerToMax(NodeLnk *&) noexcept;
  virtual const NodeLnk * const &FindPointerToMax(const NodeLnk * const &) const noexcept;

  // type FindPointerTo(argument) specifiers; // Both mutable & unmutable versions

  virtual NodeLnk *&FindPointerTo(NodeLnk *&, const Data &) noexcept;
  virtual const NodeLnk * const &FindPointerTo(const NodeLnk * const &, const Data &) const noexcept;

  // type FindPointerToPredecessor(argument) specifiers; // Both mutable & unmutable versions
  // type FindPointerToSuccessor(argument) specifiers; // Both mutable & unmutable versions

  virtual NodeLnk **FindPointerToPredecessor(NodeLnk *&) noexcept;
  virtual const NodeLnk * const *FindPointerToPredecessor(const NodeLnk * const &) const noexcept;
  virtual NodeLnk **FindPointerToSuccessor(NodeLnk *&) noexcept;
  virtual const NodeLnk * const *FindPointerToSuccessor(const NodeLnk * const &) const noexcept;

};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
