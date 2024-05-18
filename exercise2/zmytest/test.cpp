
#include <iostream>
#include <string.h>
#include <string>
#include <typeinfo>
#include <stdlib.h>   
#include <time.h>       
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>  

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/dictionary.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"

#include "../vector/vector.hpp"

#include "../list/list.hpp"

#include "../stack/stack.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"

#include "../queue/queue.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

#include "../binarytree/binarytree.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../bst/bst.hpp"

using namespace std;

std::string characters {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()`~-_=+[{]{|;:'\",<.>/?"};
std::random_device rd;
std::mt19937 generator(rd());
std::string randomString(int length){
  std::string output(characters);
  std::shuffle(output.begin(), output.end(), generator);
  return output.substr(0, length);
}

template <typename Data>
void fill(lasd::Vector<Data> &vec){
  Data dataRandom;
  srand((unsigned int)time(NULL));

  for(ulong i = 0; i < vec.Size(); i++){
    dataRandom = rand() / (100 + 1);
    vec[i] = dataRandom;
  }
}

void fill(lasd::Vector<string> &vec){
  for(ulong i = 0; i < vec.Size(); i++){
    vec[i] = randomString(4);
  }
}

template <typename Data>
void fill(lasd::List<Data> &list, ulong dimension){
  Data dataRandom;
  srand((unsigned int)time(NULL));

  for(ulong i = 0; i < dimension; i++){
    dataRandom = rand() / (100 + 1);
    list.InsertAtBack(dataRandom);
  }
}

void fill(lasd::List<string> &list, ulong dimension){
  for(ulong i = 0; i < dimension; i++){
    list.InsertAtBack(randomString(4));
  }
}

template <typename Data>
void EqualTestBT(const lasd::BinaryTree<Data> &bt1, const lasd::BinaryTree<Data> &bt2) {
  if(bt1 == bt2){
    cout << endl << "The 2 BinaryTree are Equal " << endl;
  } else{
    cout << endl << "The 2 BinaryTree are NOT Equal " << endl;
  }
}

template <typename Data>
void MinMyTest(lasd::BST<Data> &bst) {
  try {
    cout << "Min of the BST:  " << bst.Min() << endl;
  }
  catch (length_error &exc) {
    cout << exc.what() << endl; 
  }
}

template <typename Data>
void MinNRemoveMyTest(lasd::BST<Data> &bst) {
  try {
    cout << "MinNRemove of the BST:  " << bst.Min() << endl;
    bst.MinNRemove();
  }
  catch (length_error &exc) {
    cout << exc.what() << endl; 
  }
}

template <typename Data>
void RemoveMinMyTest(lasd::BST<Data> &bst) {
  try {
    cout << "RemoveMin of the BST ";
    bst.RemoveMin();
  }
  catch (length_error &exc) {
    cout << exc.what() << endl; 
  }
}

template <typename Data>
void MaxMyTest(lasd::BST<Data> &bst) {
  try {
    cout << "Max of the BST:  " << bst.Max() << endl;
  }
  catch (length_error &exc) {
    cout << exc.what() << endl; 
  }
}

template <typename Data>
void MaxNRemoveMyTest(lasd::BST<Data> &bst) {
  try {
    cout << "MaxNRemove of the BST:  " << bst.Max() << endl;
    bst.MaxNRemove();
  }
  catch (length_error &exc) {
    cout << exc.what() << endl; 
  }
}

template <typename Data>
void RemoveMaxMyTest(lasd::BST<Data> &bst) {
  try {
    cout << "Remove Max of the BST ";
    bst.RemoveMax();
  }
  catch (length_error &exc) {
    cout << exc.what() << endl; 
  }
}

template <typename Data>
void PredecessorMyTest(lasd::BST<Data> &bst, const Data &predecessor) {
  try {
    cout << "Predecessor of the BST:  " << bst.Predecessor(predecessor) << endl;
  }
  catch (length_error &exc) {
    cout << exc.what() << endl; 
  }
}

template <typename Data>
void PredecessorNRemoveMyTest(lasd::BST<Data> &bst, const Data &predecessor) {
  try {
    cout << "PredecessorNRemove of the BST:  " << bst.Predecessor(predecessor) << endl;
    bst.PredecessorNRemove(predecessor);
  }
  catch (length_error &exc) {
    cout << exc.what() << endl; 
  }
}

template <typename Data>
void RemovePredecessorMyTest(lasd::BST<Data> &bst, const Data &predecessor) {
  try {
    cout << "Remove Predecessor of the BST ";
    bst.RemovePredecessor(predecessor);
  }
  catch (length_error &exc) {
    cout << exc.what() << endl; 
  }
}

template <typename Data>
void SuccessorMyTest(lasd::BST<Data> &bst, const Data &successor) {
  try {
    cout << "Successor of the BST:  " << bst.Successor(successor) << endl;
  }
  catch (length_error &exc) {
    cout << exc.what() << endl; 
  }
}

template <typename Data>
void SuccessorNRemoveMyTest(lasd::BST<Data> &bst, const Data &successor) {
  try {
    cout << "SuccessorNRemove of the BST:  " << bst.Successor(successor) << endl;
    bst.SuccessorNRemove(successor);
  }
  catch (length_error &exc) {
    cout << exc.what() << endl; 
  }
}

template <typename Data>
void RemoveSuccessorMyTest(lasd::BST<Data> &bst, const Data &successor) {
  try {
    cout << "Remove Successor of the BST ";
    bst.RemoveSuccessor(successor);
  }
  catch (length_error &exc) {
    cout << exc.what() << endl; 
  }
}

template <typename Data>
void ValueIteratorGet(const lasd::Iterator<Data> & itr, const Data &data) {
  try {
    cout << "Value pointed by the Iterator: " << *itr << " ";
    if(*itr == data){
      cout << "Correct Value" << endl;
    } else{
      cout << "Wrong Value" << endl;
    }
  }
  catch (out_of_range &exc) {
    cout << exc.what() << endl;
  }
}

template <typename Data>
void ValueIteratorSet(lasd::MutableIterator<Data> & itr, const Data &data) {
  try {
    cout << "Setting the value pointed by the iterator to " << data << " ";
    *itr = data;
    if(*itr == data){
      cout << "Correct Value" << endl;
    } else{
      cout << "Wrong Value" << endl;
    }
  }
  catch (out_of_range &exc) {
    cout << exc.what() << endl;
  }
}


/* ************************************************************************** */

void mytestBinaryTreeInteger() {
  try{
    cout << endl << "Begin BinaryTree for Integer" << endl;
    cout << endl << "Begin BinaryTreeLnk for Integer" << endl;

    cout << endl << "Creation of a BinaryTreeLnk from Default Constructor" << endl;

    lasd::BinaryTreeLnk<int> btlink;

    if(btlink.Empty()){
      cout << "BinaryTreeLnk is Empty" << endl;
      cout << "BinaryTreeLnk Size is " << btlink.Size() << endl;
    } else{
      cout << "Pre Order Traverse of BinaryTreeLnk" << endl;
      btlink.PreOrderTraverse([](const int &data){cout << data << " - ";});
      cout << endl;
      cout << "Post Order Traverse of BinaryTreeLnk" << endl;
      btlink.PostOrderTraverse([](const int &data){cout << data << " - ";});
      cout << endl;
      cout << "In Order Traverse of BinaryTreeLnk" << endl;
      btlink.InOrderTraverse([](const int &data){cout << data << " - ";});
      cout << endl;
      cout << "Breadth Traverse of BinaryTreeLnk" << endl;
      btlink.BreadthTraverse([](const int &data){cout << data << " - ";});
      cout << endl;

      cout << "Pre Order Map of BinaryTreeLnk" << endl;
      btlink.PreOrderMap([](int &data){cout << data << " - ";});
      cout << endl;
      cout << "Post Order Map of BinaryTreeLnk" << endl;
      btlink.PostOrderMap([](int &data){cout << data << " - ";});
      cout << endl;
      cout << "In Order Map of BinaryTreeLnk" << endl;
      btlink.InOrderMap([](int &data){cout << data << " - ";});
      cout << endl;
      cout << "Breadth Map of BinaryTreeLnk" << endl;
      btlink.BreadthMap([](int &data){cout << data << " - ";});
      cout << endl;
    }

    lasd::Vector<int> vec(6);
    fill(vec);

    lasd::List<int> list;
    fill(list, 6);

    cout << endl << "Creation of a BinaryTreeLnk from a Vector" << endl;

    lasd::BinaryTreeLnk<int> binaryTreeLnk1(vec);
    cout << endl;
    if(binaryTreeLnk1.Empty()){
      cout << "BinaryTreeLnk is Empty" << endl;
    } else{
      cout << "BinaryTreeLnk is NOT Empty" << endl;
    }
    cout << "BinaryTreeLnk Size is "<< binaryTreeLnk1.Size() << endl;
    cout << "Pre Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk1.PreOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk1.PostOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk1.InOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk1.BreadthTraverse([](const int &data){cout << data << " - ";});
    cout << endl;

    cout << "Pre Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk1.PreOrderMap([](int &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk1.PostOrderMap([](int &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk1.InOrderMap([](int &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Map of BinaryTreeLnk" << endl;
    binaryTreeLnk1.BreadthMap([](int &data){cout << data << " - ";});
    cout << endl;

    cout << endl << "Creation of a BinaryTreeLnk from a List" << endl;

    lasd::BinaryTreeLnk<int> binaryTreeLnk2(list);
    cout << endl;
    if(binaryTreeLnk2.Empty()){
      cout << "BinaryTreeLnk is Empty" << endl;
    } else{
      cout << "BinaryTreeLnk is NOT Empty" << endl;
    }
    cout << "BinaryTreeLnk Size is "<< binaryTreeLnk2.Size() << endl;
    cout << "Pre Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk2.PreOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk2.PostOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk2.InOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk2.BreadthTraverse([](const int &data){cout << data << " - ";});
    cout << endl;

    cout << "Pre Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk2.PreOrderMap([](int &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk2.PostOrderMap([](int &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk2.InOrderMap([](int &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Map of BinaryTreeLnk" << endl;
    binaryTreeLnk2.BreadthMap([](int &data){cout << data << " - ";});
    cout << endl;

    lasd::BinaryTreeLnk<int> copBTLnk1(binaryTreeLnk1);
    lasd::BinaryTreeLnk<int> copBTLnk2(binaryTreeLnk2);
    cout << endl;
    cout << "Tests of Copy Constructors (Should be Equals)" << endl;
    cout << endl;
    if(binaryTreeLnk1 == copBTLnk1){
      cout << "The 2 BinaryTreeLnk are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeLnk are NOT Equal" << endl;
    }

    if(binaryTreeLnk2 == copBTLnk2){
      cout << "The 2 BinaryTreeLnk are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeLnk are NOT Equal" << endl;
    }

    cout << "BinaryTreeLnk(from Vector) Size is "<< binaryTreeLnk1.Size() << endl;
    cout << "Copied BinaryTreeLnk(from Vector) Size is "<< copBTLnk1.Size() << endl;
    cout << "BinaryTreeLnk(from List) Size is "<< binaryTreeLnk2.Size() << endl;
    cout << "Copied BinaryTreeLnk(from List) Size is "<< copBTLnk2.Size() << endl;

    lasd::BinaryTreeLnk<int> moveBTLnk1(move(binaryTreeLnk1));
    lasd::BinaryTreeLnk<int> moveBTLnk2(move(binaryTreeLnk2));
    cout << endl;
    cout << "Tests of Move Constructors (Should NOT be Equals)" << endl;
    cout << endl;
    if(binaryTreeLnk1 == moveBTLnk1){
      cout << "The 2 BinaryTreeLnk are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeLnk are NOT Equal" << endl;
    }

    if(binaryTreeLnk2 == moveBTLnk2){
      cout << "The 2 BinaryTreeLnk are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeLnk are NOT Equal" << endl;
    }

    cout << "BinaryTreeLnk(from Vector) Size is "<< binaryTreeLnk1.Size() << endl;
    cout << "Moved BinaryTreeLnk(from Vector) Size is "<< moveBTLnk1.Size() << endl;
    cout << "BinaryTreeLnk(from List) Size is "<< binaryTreeLnk2.Size() << endl;
    cout << "Moved BinaryTreeLnk(from List) Size is "<< moveBTLnk2.Size() << endl;

    cout << endl << "Operator= Tests" << endl << endl;

    binaryTreeLnk1 = copBTLnk1;
    binaryTreeLnk2 = copBTLnk2;
    cout << "BinaryTreeLnk(from Vector) Size is "<< binaryTreeLnk1.Size() << endl;
    cout << "BinaryTreeLnk(from List) Size is "<< binaryTreeLnk2.Size() << endl;

    cout << "BinaryTreeLnk(from Vector) Root is "<< binaryTreeLnk1.Root().Element() << endl;
    cout << "Copied BinaryTreeLnk(from Vector) Root is "<< copBTLnk1.Root().Element() << endl;
    cout << "BinaryTreeLnk(from List) Root is "<< binaryTreeLnk2.Root().Element() << endl;
    cout << "Copied BinaryTreeLnk(from List) Root is "<< copBTLnk2.Root().Element() << endl;

    cout << endl << "Clear Tests" << endl << endl;

    binaryTreeLnk1.Clear();
    copBTLnk1.Clear();
    moveBTLnk1.Clear(); 
    binaryTreeLnk2.Clear();
    copBTLnk2.Clear(); 
    moveBTLnk2.Clear();

    cout << "BinaryTreeLnk(from Vector) Size is "<< binaryTreeLnk1.Size() << endl;
    cout << "Copied BinaryTreeLnk(from Vector) Size is "<< copBTLnk1.Size() << endl;
    cout << "Moved BinaryTreeLnk(from Vector) Size is "<< moveBTLnk1.Size() << endl;
    cout << "BinaryTreeLnk(from List) Size is "<< binaryTreeLnk2.Size() << endl;
    cout << "Copied BinaryTreeLnk(from List) Size is "<< copBTLnk2.Size() << endl;
    cout << "Moved BinaryTreeLnk(from List) Size is "<< moveBTLnk2.Size() << endl;

    cout << endl << "End BinaryTreeLnk for Integer" << endl;

    cout << endl << "Begin BinaryTreeVec for Integer" << endl;

    cout << endl << "Creation of a BinaryTreeVec from Default Constructor" << endl;

    lasd::BinaryTreeVec<int> btvec;

    if(btvec.Empty()){
      cout << "BinaryTreeVec is Empty" << endl;
      cout << "BinaryTreeVec Size is " << btvec.Size() << endl;
    } else{
      cout << "Pre Order Traverse of BinaryTreeVec" << endl;
      btvec.PreOrderTraverse([](const int &data){cout << data << " - ";});
      cout << endl;
      cout << "Post Order Traverse of BinaryTreeVec" << endl;
      btvec.PostOrderTraverse([](const int &data){cout << data << " - ";});
      cout << endl;
      cout << "In Order Traverse of BinaryTreeVec" << endl;
      btvec.InOrderTraverse([](const int &data){cout << data << " - ";});
      cout << endl;
      cout << "Breadth Traverse of BinaryTreeVec" << endl;
      btvec.BreadthTraverse([](const int &data){cout << data << " - ";});
      cout << endl;

      cout << "Pre Order Map of BinaryTreeVec" << endl;
      btvec.PreOrderMap([](int &data){cout << data << " - ";});
      cout << endl;
      cout << "Post Order Map of BinaryTreeVec" << endl;
      btvec.PostOrderMap([](int &data){cout << data << " - ";});
      cout << endl;
      cout << "In Order Map of BinaryTreeVec" << endl;
      btvec.InOrderMap([](int &data){cout << data << " - ";});
      cout << endl;
      cout << "Breadth Map of BinaryTreeVec" << endl;
      btvec.BreadthMap([](int &data){cout << data << " - ";});
      cout << endl;
    }

    lasd::Vector<int> vec2(10);
    fill(vec2);

    lasd::List<int> list2;
    fill(list2, 10);

    cout << endl << "Creation of a BinaryTreeVec from a Vector" << endl;

    lasd::BinaryTreeVec<int> binaryTreeVec1(vec2);
    cout << endl;
    if(binaryTreeVec1.Empty()){
      cout << "BinaryTreeVec is Empty" << endl;
    } else{
      cout << "BinaryTreeVec is NOT Empty" << endl;
    }
    cout << "BinaryTreeVec Size is "<< binaryTreeVec1.Size() << endl;
    cout << "Pre Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec1.PreOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec1.PostOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec1.InOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BinaryTreeVec" << endl;
    binaryTreeVec1.BreadthTraverse([](const int &data){cout << data << " - ";});
    cout << endl;

    cout << "Pre Order Map of BinaryTreeVec" << endl;
    binaryTreeVec1.PreOrderMap([](int &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Map of BinaryTreeVec" << endl;
    binaryTreeVec1.PostOrderMap([](int &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Map of BinaryTreeVec" << endl;
    binaryTreeVec1.InOrderMap([](int &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Map of BinaryTreeVec" << endl;
    binaryTreeVec1.BreadthMap([](int &data){cout << data << " - ";});
    cout << endl;

    cout << endl << "Creation of a BinaryTreeVec from a List" << endl;

    lasd::BinaryTreeVec<int> binaryTreeVec2(list2);
    cout << endl;
    if(binaryTreeVec2.Empty()){
      cout << "BinaryTreeVec is Empty" << endl;
    } else{
      cout << "BinaryTreeVec is NOT Empty" << endl;
    }
    cout << "BinaryTreeVec Size is "<< binaryTreeVec2.Size() << endl;
    cout << "Pre Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec2.PreOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec2.PostOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec2.InOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BinaryTreeVec" << endl;
    binaryTreeVec2.BreadthTraverse([](const int &data){cout << data << " - ";});
    cout << endl;

    cout << "Pre Order Map of BinaryTreeVec" << endl;
    binaryTreeVec2.PreOrderMap([](int &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Map of BinaryTreeVec" << endl;
    binaryTreeVec2.PostOrderMap([](int &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Map of BinaryTreeVec" << endl;
    binaryTreeVec2.InOrderMap([](int &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Map of BinaryTreeVec" << endl;
    binaryTreeVec2.BreadthMap([](int &data){cout << data << " - ";});
    cout << endl;

    lasd::BinaryTreeVec<int> copBTVec1(binaryTreeVec1);
    lasd::BinaryTreeVec<int> copBTVec2(binaryTreeVec2);
    cout << endl;
    cout << "Tests of Copy Constructors (Should be Equals)" << endl;
    cout << endl;
    if(binaryTreeVec1 == copBTVec1){
      cout << "The 2 BinaryTreeVec are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeVec are NOT Equal" << endl;
    }

    if(binaryTreeVec2 == copBTVec2){
      cout << "The 2 BinaryTreeVec are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeVec are NOT Equal" << endl;
    }

    cout << "BinaryTreeVec(from Vector) Size is "<< binaryTreeVec1.Size() << endl;
    cout << "Copied BinaryTreeVec(from Vector) Size is "<< copBTVec1.Size() << endl;
    cout << "BinaryTreeVec(from List) Size is "<< binaryTreeVec2.Size() << endl;
    cout << "Copied BinaryTreeVec(from List) Size is "<< copBTVec2.Size() << endl;

    lasd::BinaryTreeVec<int> moveBTVec1(move(binaryTreeVec1));
    lasd::BinaryTreeVec<int> moveBTVec2(move(binaryTreeVec2));
    cout << endl;
    cout << "Tests of Move Constructors (Should NOT be Equals)" << endl;
    cout << endl;
    if(binaryTreeVec1 == moveBTVec1){
      cout << "The 2 BinaryTreeVec are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeVec are NOT Equal" << endl;
    }

    if(binaryTreeVec2 == moveBTVec2){
      cout << "The 2 BinaryTreeVec are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeVec are NOT Equal" << endl;
    }

    cout << "BinaryTreeVec(from Vector) Size is "<< binaryTreeVec1.Size() << endl;
    cout << "Moved BinaryTreeVec(from Vector) Size is "<< moveBTVec1.Size() << endl;
    cout << "BinaryTreeVec(from List) Size is "<< binaryTreeVec2.Size() << endl;
    cout << "Moved BinaryTreeVec(from List) Size is "<< moveBTVec2.Size() << endl;

    cout << endl << "Operator= Tests" << endl << endl;

    binaryTreeVec1 = copBTVec1;
    binaryTreeVec2 = copBTVec2;
    cout << "BinaryTreeVec(from Vector) Size is "<< binaryTreeVec1.Size() << endl;
    cout << "BinaryTreeVec(from List) Size is "<< binaryTreeVec2.Size() << endl;

    cout << "BinaryTreeVec(from Vector) Root is "<< binaryTreeVec1.Root().Element() << endl;
    cout << "Copied BinaryTreeVec(from Vector) Root is "<< copBTVec1.Root().Element() << endl;
    cout << "BinaryTreeVec(from List) Root is "<< binaryTreeVec2.Root().Element() << endl;
    cout << "Copied BinaryTreeVec(from List) Root is "<< copBTVec2.Root().Element() << endl;

    cout << endl << "Clear Tests" << endl << endl;

    binaryTreeVec1.Clear();
    copBTVec1.Clear();
    moveBTVec1.Clear(); 
    binaryTreeVec2.Clear();
    copBTVec2.Clear(); 
    moveBTVec2.Clear();

    cout << "BinaryTreeVec(from Vector) Size is "<< binaryTreeVec1.Size() << endl;
    cout << "Copied BinaryTreeVec(from Vector) Size is "<< copBTVec1.Size() << endl;
    cout << "Moved BinaryTreeVec(from Vector) Size is "<< moveBTVec1.Size() << endl;
    cout << "BinaryTreeVec(from List) Size is "<< binaryTreeVec2.Size() << endl;
    cout << "Copied BinaryTreeVec(from List) Size is "<< copBTVec2.Size() << endl;
    cout << "Moved BinaryTreeVec(from List) Size is "<< moveBTVec2.Size() << endl;

    cout << endl << "End BinaryTreeVec for Integer" << endl;

    cout << endl << "Begin Tests between BinaryTreeLnk/Vec for Integer" << endl;

    cout << endl << "Creation of BinaryTreeLnk and BinaryTreeVec with Default Constructor " << endl;

    lasd::BinaryTreeLnk<int> btlinkDef;
    lasd::BinaryTreeVec<int> btVecDef;

    EqualTestBT(btlinkDef, btVecDef);

    cout << endl << "Creation of BinaryTreeLnk and BinaryTreeVec from a Vector " << endl;

    lasd::BinaryTreeLnk<int> btlinkVec(vec2);
    lasd::BinaryTreeVec<int> btVecVec(vec2);

    EqualTestBT(btlinkVec, btVecVec);

    cout << "Changing The Root Element to 0 From BinaryTreeLnk";

    btlinkVec.Root().Element() = 0;

    EqualTestBT(btlinkVec, btVecVec);

    cout << "Changing The Root Element to 0 From BinaryTreeVec";

    btVecVec.Root().Element() = 0;

    EqualTestBT(btlinkVec, btVecVec);

    cout << endl << "Tests Method Exists In BinaryTreeLnk" << endl;

    if(btlinkVec.Exists(0)){
      cout << endl <<"Data: '0' Exists" << endl;
      btlinkVec.BreadthTraverse([](const int &data){cout << data << " - ";});
      cout << endl;
    } else{
      cout << "Data: '0' Does NOT Exists" << endl;
      btlinkVec.BreadthTraverse([](const int &data){cout << data << " - ";});
      cout << endl;
    }

    if(btlinkVec.Exists(1)){
      cout << "Data: '1' Exists" << endl;
      btlinkVec.BreadthTraverse([](const int &data){cout << data << " - ";});
      cout << endl;
    } else{
      cout << "Data: '1' Does NOT Exists" << endl;
      btlinkVec.BreadthTraverse([](const int &data){cout << data << " - ";});
      cout << endl;
    }

    cout << endl << "Tests Method Exists In BinaryTreeVec" << endl;

    if(btVecVec.Exists(0)){
      cout << endl <<"Data: '0' Exists" << endl;
      btVecVec.BreadthTraverse([](const int &data){cout << data << " - ";});
      cout << endl;
    } else{
      cout << "Data: '0' Does NOT Exists" << endl;
      btVecVec.BreadthTraverse([](const int &data){cout << data << " - ";});
      cout << endl;
    }

    if(btVecVec.Exists(1)){
      cout << "Data: '1' Exists" << endl;
      btVecVec.BreadthTraverse([](const int &data){cout << data << " - ";});
      cout << endl;
    } else{
      cout << "Data: '1' Does NOT Exists" << endl;
      btVecVec.BreadthTraverse([](const int &data){cout << data << " - ";});
      cout << endl;
    }

    cout << endl << "Clearing The 2 BinaryTree" << endl;

    btlinkVec.Clear();
    btVecVec.Clear();

    if(btlinkVec.Exists(0)){
      cout << endl <<"Data: '0' Exists" << endl;
    } else{
      cout << "Data: '0' Does NOT Exists" << endl;
    }
    if(btVecVec.Exists(0)){
      cout << endl <<"Data: '0' Exists" << endl;
    } else{
      cout << "Data: '0' Does NOT Exists" << endl;
    }

  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << endl << "End of BinaryTree For Integer!" << endl;
}

void mytestBinaryTreeFloat() {
  
  try{
    cout << endl << "Begin BinaryTree for Float" << endl;
    cout << endl << "Begin BinaryTreeLnk for Float" << endl;

    cout << endl << "Creation of a BinaryTreeLnk from Default Constructor" << endl;

    lasd::BinaryTreeLnk<float> btlink;

    if(btlink.Empty()){
      cout << "BinaryTreeLnk is Empty" << endl;
      cout << "BinaryTreeLnk Size is " << btlink.Size() << endl;
    } else{
      cout << "Pre Order Traverse of BinaryTreeLnk" << endl;
      btlink.PreOrderTraverse([](const float &data){cout << data << " - ";});
      cout << endl;
      cout << "Post Order Traverse of BinaryTreeLnk" << endl;
      btlink.PostOrderTraverse([](const float &data){cout << data << " - ";});
      cout << endl;
      cout << "In Order Traverse of BinaryTreeLnk" << endl;
      btlink.InOrderTraverse([](const float &data){cout << data << " - ";});
      cout << endl;
      cout << "Breadth Traverse of BinaryTreeLnk" << endl;
      btlink.BreadthTraverse([](const float &data){cout << data << " - ";});
      cout << endl;

      cout << "Pre Order Map of BinaryTreeLnk" << endl;
      btlink.PreOrderMap([](float &data){cout << data << " - ";});
      cout << endl;
      cout << "Post Order Map of BinaryTreeLnk" << endl;
      btlink.PostOrderMap([](float &data){cout << data << " - ";});
      cout << endl;
      cout << "In Order Map of BinaryTreeLnk" << endl;
      btlink.InOrderMap([](float &data){cout << data << " - ";});
      cout << endl;
      cout << "Breadth Map of BinaryTreeLnk" << endl;
      btlink.BreadthMap([](float &data){cout << data << " - ";});
      cout << endl;
    }

    lasd::Vector<float> vec(6);
    fill(vec);

    lasd::List<float> list;
    fill(list, 6);

    cout << endl << "Creation of a BinaryTreeLnk from a Vector" << endl;

    lasd::BinaryTreeLnk<float> binaryTreeLnk1(vec);
    cout << endl;
    if(binaryTreeLnk1.Empty()){
      cout << "BinaryTreeLnk is Empty" << endl;
    } else{
      cout << "BinaryTreeLnk is NOT Empty" << endl;
    }
    cout << "BinaryTreeLnk Size is "<< binaryTreeLnk1.Size() << endl;
    cout << "Pre Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk1.PreOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk1.PostOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk1.InOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk1.BreadthTraverse([](const float &data){cout << data << " - ";});
    cout << endl;

    cout << "Pre Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk1.PreOrderMap([](float &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk1.PostOrderMap([](float &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk1.InOrderMap([](float &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Map of BinaryTreeLnk" << endl;
    binaryTreeLnk1.BreadthMap([](float &data){cout << data << " - ";});
    cout << endl;

    cout << endl << "Creation of a BinaryTreeLnk from a List" << endl;

    lasd::BinaryTreeLnk<float> binaryTreeLnk2(list);
    cout << endl;
    if(binaryTreeLnk2.Empty()){
      cout << "BinaryTreeLnk is Empty" << endl;
    } else{
      cout << "BinaryTreeLnk is NOT Empty" << endl;
    }
    cout << "BinaryTreeLnk Size is "<< binaryTreeLnk2.Size() << endl;
    cout << "Pre Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk2.PreOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk2.PostOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk2.InOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk2.BreadthTraverse([](const float &data){cout << data << " - ";});
    cout << endl;

    cout << "Pre Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk2.PreOrderMap([](float &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk2.PostOrderMap([](float &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk2.InOrderMap([](float &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Map of BinaryTreeLnk" << endl;
    binaryTreeLnk2.BreadthMap([](float &data){cout << data << " - ";});
    cout << endl;

    lasd::BinaryTreeLnk<float> copBTLnk1(binaryTreeLnk1);
    lasd::BinaryTreeLnk<float> copBTLnk2(binaryTreeLnk2);
    cout << endl;
    cout << "Tests of Copy Constructors (Should be Equals)" << endl;
    cout << endl;
    if(binaryTreeLnk1 == copBTLnk1){
      cout << "The 2 BinaryTreeLnk are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeLnk are NOT Equal" << endl;
    }

    if(binaryTreeLnk2 == copBTLnk2){
      cout << "The 2 BinaryTreeLnk are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeLnk are NOT Equal" << endl;
    }

    cout << "BinaryTreeLnk(from Vector) Size is "<< binaryTreeLnk1.Size() << endl;
    cout << "Copied BinaryTreeLnk(from Vector) Size is "<< copBTLnk1.Size() << endl;
    cout << "BinaryTreeLnk(from List) Size is "<< binaryTreeLnk2.Size() << endl;
    cout << "Copied BinaryTreeLnk(from List) Size is "<< copBTLnk2.Size() << endl;

    lasd::BinaryTreeLnk<float> moveBTLnk1(move(binaryTreeLnk1));
    lasd::BinaryTreeLnk<float> moveBTLnk2(move(binaryTreeLnk2));
    cout << endl;
    cout << "Tests of Move Constructors (Should NOT be Equals)" << endl;
    cout << endl;
    if(binaryTreeLnk1 == moveBTLnk1){
      cout << "The 2 BinaryTreeLnk are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeLnk are NOT Equal" << endl;
    }

    if(binaryTreeLnk2 == moveBTLnk2){
      cout << "The 2 BinaryTreeLnk are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeLnk are NOT Equal" << endl;
    }

    cout << "BinaryTreeLnk(from Vector) Size is "<< binaryTreeLnk1.Size() << endl;
    cout << "Moved BinaryTreeLnk(from Vector) Size is "<< moveBTLnk1.Size() << endl;
    cout << "BinaryTreeLnk(from List) Size is "<< binaryTreeLnk2.Size() << endl;
    cout << "Moved BinaryTreeLnk(from List) Size is "<< moveBTLnk2.Size() << endl;

    cout << endl << "Operator= Tests" << endl << endl;

    binaryTreeLnk1 = copBTLnk1;
    binaryTreeLnk2 = copBTLnk2;
    cout << "BinaryTreeLnk(from Vector) Size is "<< binaryTreeLnk1.Size() << endl;
    cout << "BinaryTreeLnk(from List) Size is "<< binaryTreeLnk2.Size() << endl;

    cout << "BinaryTreeLnk(from Vector) Root is "<< binaryTreeLnk1.Root().Element() << endl;
    cout << "Copied BinaryTreeLnk(from Vector) Root is "<< copBTLnk1.Root().Element() << endl;
    cout << "BinaryTreeLnk(from List) Root is "<< binaryTreeLnk2.Root().Element() << endl;
    cout << "Copied BinaryTreeLnk(from List) Root is "<< copBTLnk2.Root().Element() << endl;

    cout << endl << "Clear Tests" << endl << endl;

    binaryTreeLnk1.Clear();
    copBTLnk1.Clear();
    moveBTLnk1.Clear(); 
    binaryTreeLnk2.Clear();
    copBTLnk2.Clear(); 
    moveBTLnk2.Clear();

    cout << "BinaryTreeLnk(from Vector) Size is "<< binaryTreeLnk1.Size() << endl;
    cout << "Copied BinaryTreeLnk(from Vector) Size is "<< copBTLnk1.Size() << endl;
    cout << "Moved BinaryTreeLnk(from Vector) Size is "<< moveBTLnk1.Size() << endl;
    cout << "BinaryTreeLnk(from List) Size is "<< binaryTreeLnk2.Size() << endl;
    cout << "Copied BinaryTreeLnk(from List) Size is "<< copBTLnk2.Size() << endl;
    cout << "Moved BinaryTreeLnk(from List) Size is "<< moveBTLnk2.Size() << endl;

    cout << endl << "End BinaryTreeLnk for Float" << endl;

    cout << endl << "Begin BinaryTreeVec for Float" << endl;

    cout << endl << "Creation of a BinaryTreeVec from Default Constructor" << endl;

    lasd::BinaryTreeVec<float> btvec;

    if(btvec.Empty()){
      cout << "BinaryTreeVec is Empty" << endl;
      cout << "BinaryTreeVec Size is " << btvec.Size() << endl;
    } else{
      cout << "Pre Order Traverse of BinaryTreeVec" << endl;
      btvec.PreOrderTraverse([](const float &data){cout << data << " - ";});
      cout << endl;
      cout << "Post Order Traverse of BinaryTreeVec" << endl;
      btvec.PostOrderTraverse([](const float &data){cout << data << " - ";});
      cout << endl;
      cout << "In Order Traverse of BinaryTreeVec" << endl;
      btvec.InOrderTraverse([](const float &data){cout << data << " - ";});
      cout << endl;
      cout << "Breadth Traverse of BinaryTreeVec" << endl;
      btvec.BreadthTraverse([](const float &data){cout << data << " - ";});
      cout << endl;

      cout << "Pre Order Map of BinaryTreeVec" << endl;
      btvec.PreOrderMap([](float &data){cout << data << " - ";});
      cout << endl;
      cout << "Post Order Map of BinaryTreeVec" << endl;
      btvec.PostOrderMap([](float &data){cout << data << " - ";});
      cout << endl;
      cout << "In Order Map of BinaryTreeVec" << endl;
      btvec.InOrderMap([](float &data){cout << data << " - ";});
      cout << endl;
      cout << "Breadth Map of BinaryTreeVec" << endl;
      btvec.BreadthMap([](float &data){cout << data << " - ";});
      cout << endl;
    }

    lasd::Vector<float> vec2(10);
    fill(vec2);

    lasd::List<float> list2;
    fill(list2, 10);

    cout << endl << "Creation of a BinaryTreeVec from a Vector" << endl;

    lasd::BinaryTreeVec<float> binaryTreeVec1(vec2);
    cout << endl;
    if(binaryTreeVec1.Empty()){
      cout << "BinaryTreeVec is Empty" << endl;
    } else{
      cout << "BinaryTreeVec is NOT Empty" << endl;
    }
    cout << "BinaryTreeVec Size is "<< binaryTreeVec1.Size() << endl;
    cout << "Pre Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec1.PreOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec1.PostOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec1.InOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BinaryTreeVec" << endl;
    binaryTreeVec1.BreadthTraverse([](const float &data){cout << data << " - ";});
    cout << endl;

    cout << "Pre Order Map of BinaryTreeVec" << endl;
    binaryTreeVec1.PreOrderMap([](float &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Map of BinaryTreeVec" << endl;
    binaryTreeVec1.PostOrderMap([](float &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Map of BinaryTreeVec" << endl;
    binaryTreeVec1.InOrderMap([](float &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Map of BinaryTreeVec" << endl;
    binaryTreeVec1.BreadthMap([](float &data){cout << data << " - ";});
    cout << endl;

    cout << endl << "Creation of a BinaryTreeVec from a List" << endl;

    lasd::BinaryTreeVec<float> binaryTreeVec2(list2);
    cout << endl;
    if(binaryTreeVec2.Empty()){
      cout << "BinaryTreeVec is Empty" << endl;
    } else{
      cout << "BinaryTreeVec is NOT Empty" << endl;
    }
    cout << "BinaryTreeVec Size is "<< binaryTreeVec2.Size() << endl;
    cout << "Pre Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec2.PreOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec2.PostOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec2.InOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BinaryTreeVec" << endl;
    binaryTreeVec2.BreadthTraverse([](const float &data){cout << data << " - ";});
    cout << endl;

    cout << "Pre Order Map of BinaryTreeVec" << endl;
    binaryTreeVec2.PreOrderMap([](float &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Map of BinaryTreeVec" << endl;
    binaryTreeVec2.PostOrderMap([](float &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Map of BinaryTreeVec" << endl;
    binaryTreeVec2.InOrderMap([](float &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Map of BinaryTreeVec" << endl;
    binaryTreeVec2.BreadthMap([](float &data){cout << data << " - ";});
    cout << endl;

    lasd::BinaryTreeVec<float> copBTVec1(binaryTreeVec1);
    lasd::BinaryTreeVec<float> copBTVec2(binaryTreeVec2);
    cout << endl;
    cout << "Tests of Copy Constructors (Should be Equals)" << endl;
    cout << endl;
    if(binaryTreeVec1 == copBTVec1){
      cout << "The 2 BinaryTreeVec are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeVec are NOT Equal" << endl;
    }

    if(binaryTreeVec2 == copBTVec2){
      cout << "The 2 BinaryTreeVec are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeVec are NOT Equal" << endl;
    }

    cout << "BinaryTreeVec(from Vector) Size is "<< binaryTreeVec1.Size() << endl;
    cout << "Copied BinaryTreeVec(from Vector) Size is "<< copBTVec1.Size() << endl;
    cout << "BinaryTreeVec(from List) Size is "<< binaryTreeVec2.Size() << endl;
    cout << "Copied BinaryTreeVec(from List) Size is "<< copBTVec2.Size() << endl;

    lasd::BinaryTreeVec<float> moveBTVec1(move(binaryTreeVec1));
    lasd::BinaryTreeVec<float> moveBTVec2(move(binaryTreeVec2));
    cout << endl;
    cout << "Tests of Move Constructors (Should NOT be Equals)" << endl;
    cout << endl;
    if(binaryTreeVec1 == moveBTVec1){
      cout << "The 2 BinaryTreeVec are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeVec are NOT Equal" << endl;
    }

    if(binaryTreeVec2 == moveBTVec2){
      cout << "The 2 BinaryTreeVec are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeVec are NOT Equal" << endl;
    }

    cout << "BinaryTreeVec(from Vector) Size is "<< binaryTreeVec1.Size() << endl;
    cout << "Moved BinaryTreeVec(from Vector) Size is "<< moveBTVec1.Size() << endl;
    cout << "BinaryTreeVec(from List) Size is "<< binaryTreeVec2.Size() << endl;
    cout << "Moved BinaryTreeVec(from List) Size is "<< moveBTVec2.Size() << endl;

    cout << endl << "Operator= Tests" << endl << endl;

    binaryTreeVec1 = copBTVec1;
    binaryTreeVec2 = copBTVec2;
    cout << "BinaryTreeVec(from Vector) Size is "<< binaryTreeVec1.Size() << endl;
    cout << "BinaryTreeVec(from List) Size is "<< binaryTreeVec2.Size() << endl;

    cout << "BinaryTreeVec(from Vector) Root is "<< binaryTreeVec1.Root().Element() << endl;
    cout << "Copied BinaryTreeVec(from Vector) Root is "<< copBTVec1.Root().Element() << endl;
    cout << "BinaryTreeVec(from List) Root is "<< binaryTreeVec2.Root().Element() << endl;
    cout << "Copied BinaryTreeVec(from List) Root is "<< copBTVec2.Root().Element() << endl;

    cout << endl << "Clear Tests" << endl << endl;

    binaryTreeVec1.Clear();
    copBTVec1.Clear();
    moveBTVec1.Clear(); 
    binaryTreeVec2.Clear();
    copBTVec2.Clear(); 
    moveBTVec2.Clear();

    cout << "BinaryTreeVec(from Vector) Size is "<< binaryTreeVec1.Size() << endl;
    cout << "Copied BinaryTreeVec(from Vector) Size is "<< copBTVec1.Size() << endl;
    cout << "Moved BinaryTreeVec(from Vector) Size is "<< moveBTVec1.Size() << endl;
    cout << "BinaryTreeVec(from List) Size is "<< binaryTreeVec2.Size() << endl;
    cout << "Copied BinaryTreeVec(from List) Size is "<< copBTVec2.Size() << endl;
    cout << "Moved BinaryTreeVec(from List) Size is "<< moveBTVec2.Size() << endl;

    cout << endl << "End BinaryTreeVec for Float" << endl;

    cout << endl << "Begin Tests between BinaryTreeLnk/Vec for Float" << endl;

    cout << endl << "Creation of BinaryTreeLnk and BinaryTreeVec with Default Constructor " << endl;

    lasd::BinaryTreeLnk<float> btlinkDef;
    lasd::BinaryTreeVec<float> btVecDef;

    EqualTestBT(btlinkDef, btVecDef);

    cout << endl << "Creation of BinaryTreeLnk and BinaryTreeVec from a Vector " << endl;

    lasd::BinaryTreeLnk<float> btlinkVec(vec2);
    lasd::BinaryTreeVec<float> btVecVec(vec2);

    EqualTestBT(btlinkVec, btVecVec);

    cout << "Changing The Root Element to 0 From BinaryTreeLnk";

    btlinkVec.Root().Element() = 0;

    EqualTestBT(btlinkVec, btVecVec);

    cout << "Changing The Root Element to 0 From BinaryTreeVec";

    btVecVec.Root().Element() = 0;

    EqualTestBT(btlinkVec, btVecVec);

    cout << endl << "Tests Method Exists In BinaryTreeLnk" << endl;

    if(btlinkVec.Exists(0)){
      cout << endl <<"Data: '0' Exists" << endl;
      btlinkVec.BreadthTraverse([](const float &data){cout << data << " - ";});
      cout << endl;
    } else{
      cout << "Data: '0' Does NOT Exists" << endl;
      btlinkVec.BreadthTraverse([](const float &data){cout << data << " - ";});
      cout << endl;
    }

    if(btlinkVec.Exists(1)){
      cout << "Data: '1' Exists" << endl;
      btlinkVec.BreadthTraverse([](const float &data){cout << data << " - ";});
      cout << endl;
    } else{
      cout << "Data: '1' Does NOT Exists" << endl;
      btlinkVec.BreadthTraverse([](const float &data){cout << data << " - ";});
      cout << endl;
    }

    cout << endl << "Tests Method Exists In BinaryTreeVec" << endl;

    if(btVecVec.Exists(0)){
      cout << endl <<"Data: '0' Exists" << endl;
      btVecVec.BreadthTraverse([](const float &data){cout << data << " - ";});
      cout << endl;
    } else{
      cout << "Data: '0' Does NOT Exists" << endl;
      btVecVec.BreadthTraverse([](const float &data){cout << data << " - ";});
      cout << endl;
    }

    if(btVecVec.Exists(1)){
      cout << "Data: '1' Exists" << endl;
      btVecVec.BreadthTraverse([](const float &data){cout << data << " - ";});
      cout << endl;
    } else{
      cout << "Data: '1' Does NOT Exists" << endl;
      btVecVec.BreadthTraverse([](const float &data){cout << data << " - ";});
      cout << endl;
    }

    cout << "Clearing The 2 BinaryTree" << endl;

    btlinkVec.Clear();
    btVecVec.Clear();

    if(btlinkVec.Exists(0)){
      cout << endl <<"Data: '0' Exists" << endl;
    } else{
      cout << "Data: '0' Does NOT Exists" << endl;
    }
    if(btVecVec.Exists(0)){
      cout << endl <<"Data: '0' Exists" << endl;
    } else{
      cout << "Data: '0' Does NOT Exists" << endl;
    }

  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << endl << "End of BinaryTree For Float!" << endl;
}

void mytestBinaryTreeString() {
  try{
    cout << endl << "Begin BinaryTree for String" << endl;
    cout << endl << "Begin BinaryTreeLnk for String" << endl;

    cout << endl << "Creation of a BinaryTreeLnk from Default Constructor" << endl;

    lasd::BinaryTreeLnk<string> btlink;

    if(btlink.Empty()){
      cout << "BinaryTreeLnk is Empty" << endl;
      cout << "BinaryTreeLnk Size is " << btlink.Size() << endl;
    } else{
      cout << "Pre Order Traverse of BinaryTreeLnk" << endl;
      btlink.PreOrderTraverse([](const string &data){cout << data << " - ";});
      cout << endl;
      cout << "Post Order Traverse of BinaryTreeLnk" << endl;
      btlink.PostOrderTraverse([](const string &data){cout << data << " - ";});
      cout << endl;
      cout << "In Order Traverse of BinaryTreeLnk" << endl;
      btlink.InOrderTraverse([](const string &data){cout << data << " - ";});
      cout << endl;
      cout << "Breadth Traverse of BinaryTreeLnk" << endl;
      btlink.BreadthTraverse([](const string &data){cout << data << " - ";});
      cout << endl;

      cout << "Pre Order Map of BinaryTreeLnk" << endl;
      btlink.PreOrderMap([](string &data){cout << data << " - ";});
      cout << endl;
      cout << "Post Order Map of BinaryTreeLnk" << endl;
      btlink.PostOrderMap([](string &data){cout << data << " - ";});
      cout << endl;
      cout << "In Order Map of BinaryTreeLnk" << endl;
      btlink.InOrderMap([](string &data){cout << data << " - ";});
      cout << endl;
      cout << "Breadth Map of BinaryTreeLnk" << endl;
      btlink.BreadthMap([](string &data){cout << data << " - ";});
      cout << endl;
    }

    lasd::Vector<string> vec(6);
    fill(vec);

    lasd::List<string> list;
    fill(list, 6);

    cout << endl << "Creation of a BinaryTreeLnk from a Vector" << endl;

    lasd::BinaryTreeLnk<string> binaryTreeLnk1(vec);
    cout << endl;
    if(binaryTreeLnk1.Empty()){
      cout << "BinaryTreeLnk is Empty" << endl;
    } else{
      cout << "BinaryTreeLnk is NOT Empty" << endl;
    }
    cout << "BinaryTreeLnk Size is "<< binaryTreeLnk1.Size() << endl;
    cout << "Pre Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk1.PreOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk1.PostOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk1.InOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk1.BreadthTraverse([](const string &data){cout << data << " - ";});
    cout << endl;

    cout << "Pre Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk1.PreOrderMap([](string &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk1.PostOrderMap([](string &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk1.InOrderMap([](string &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Map of BinaryTreeLnk" << endl;
    binaryTreeLnk1.BreadthMap([](string &data){cout << data << " - ";});
    cout << endl;

    cout << endl << "Creation of a BinaryTreeLnk from a List" << endl;

    lasd::BinaryTreeLnk<string> binaryTreeLnk2(list);
    cout << endl;
    if(binaryTreeLnk2.Empty()){
      cout << "BinaryTreeLnk is Empty" << endl;
    } else{
      cout << "BinaryTreeLnk is NOT Empty" << endl;
    }
    cout << "BinaryTreeLnk Size is "<< binaryTreeLnk2.Size() << endl;
    cout << "Pre Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk2.PreOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk2.PostOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk2.InOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk2.BreadthTraverse([](const string &data){cout << data << " - ";});
    cout << endl;

    cout << "Pre Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk2.PreOrderMap([](string &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk2.PostOrderMap([](string &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk2.InOrderMap([](string &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Map of BinaryTreeLnk" << endl;
    binaryTreeLnk2.BreadthMap([](string &data){cout << data << " - ";});
    cout << endl;

    lasd::BinaryTreeLnk<string> copBTLnk1(binaryTreeLnk1);
    lasd::BinaryTreeLnk<string> copBTLnk2(binaryTreeLnk2);
    cout << endl;
    cout << "Tests of Copy Constructors (Should be Equals)" << endl;
    cout << endl;
    if(binaryTreeLnk1 == copBTLnk1){
      cout << "The 2 BinaryTreeLnk are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeLnk are NOT Equal" << endl;
    }

    if(binaryTreeLnk2 == copBTLnk2){
      cout << "The 2 BinaryTreeLnk are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeLnk are NOT Equal" << endl;
    }

    cout << "BinaryTreeLnk(from Vector) Size is "<< binaryTreeLnk1.Size() << endl;
    cout << "Copied BinaryTreeLnk(from Vector) Size is "<< copBTLnk1.Size() << endl;
    cout << "BinaryTreeLnk(from List) Size is "<< binaryTreeLnk2.Size() << endl;
    cout << "Copied BinaryTreeLnk(from List) Size is "<< copBTLnk2.Size() << endl;

    lasd::BinaryTreeLnk<string> moveBTLnk1(move(binaryTreeLnk1));
    lasd::BinaryTreeLnk<string> moveBTLnk2(move(binaryTreeLnk2));
    cout << endl;
    cout << "Tests of Move Constructors (Should NOT be Equals)" << endl;
    cout << endl;
    if(binaryTreeLnk1 == moveBTLnk1){
      cout << "The 2 BinaryTreeLnk are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeLnk are NOT Equal" << endl;
    }

    if(binaryTreeLnk2 == moveBTLnk2){
      cout << "The 2 BinaryTreeLnk are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeLnk are NOT Equal" << endl;
    }

    cout << "BinaryTreeLnk(from Vector) Size is "<< binaryTreeLnk1.Size() << endl;
    cout << "Moved BinaryTreeLnk(from Vector) Size is "<< moveBTLnk1.Size() << endl;
    cout << "BinaryTreeLnk(from List) Size is "<< binaryTreeLnk2.Size() << endl;
    cout << "Moved BinaryTreeLnk(from List) Size is "<< moveBTLnk2.Size() << endl;

    cout << endl << "Operator= Tests" << endl << endl;

    binaryTreeLnk1 = copBTLnk1;
    binaryTreeLnk2 = copBTLnk2;
    cout << "BinaryTreeLnk(from Vector) Size is "<< binaryTreeLnk1.Size() << endl;
    cout << "BinaryTreeLnk(from List) Size is "<< binaryTreeLnk2.Size() << endl;

    cout << "BinaryTreeLnk(from Vector) Root is "<< binaryTreeLnk1.Root().Element() << endl;
    cout << "Copied BinaryTreeLnk(from Vector) Root is "<< copBTLnk1.Root().Element() << endl;
    cout << "BinaryTreeLnk(from List) Root is "<< binaryTreeLnk2.Root().Element() << endl;
    cout << "Copied BinaryTreeLnk(from List) Root is "<< copBTLnk2.Root().Element() << endl;

    cout << endl << "Clear Tests" << endl << endl;

    binaryTreeLnk1.Clear();
    copBTLnk1.Clear();
    moveBTLnk1.Clear(); 
    binaryTreeLnk2.Clear();
    copBTLnk2.Clear(); 
    moveBTLnk2.Clear();

    cout << "BinaryTreeLnk(from Vector) Size is "<< binaryTreeLnk1.Size() << endl;
    cout << "Copied BinaryTreeLnk(from Vector) Size is "<< copBTLnk1.Size() << endl;
    cout << "Moved BinaryTreeLnk(from Vector) Size is "<< moveBTLnk1.Size() << endl;
    cout << "BinaryTreeLnk(from List) Size is "<< binaryTreeLnk2.Size() << endl;
    cout << "Copied BinaryTreeLnk(from List) Size is "<< copBTLnk2.Size() << endl;
    cout << "Moved BinaryTreeLnk(from List) Size is "<< moveBTLnk2.Size() << endl;

    cout << endl << "End BinaryTreeLnk for String" << endl;

    cout << endl << "Begin BinaryTreeVec for String" << endl;

    cout << endl << "Creation of a BinaryTreeVec from Default Constructor" << endl;

    lasd::BinaryTreeVec<string> btvec;

    if(btvec.Empty()){
      cout << "BinaryTreeVec is Empty" << endl;
      cout << "BinaryTreeVec Size is " << btvec.Size() << endl;
    } else{
      cout << "Pre Order Traverse of BinaryTreeVec" << endl;
      btvec.PreOrderTraverse([](const string &data){cout << data << " - ";});
      cout << endl;
      cout << "Post Order Traverse of BinaryTreeVec" << endl;
      btvec.PostOrderTraverse([](const string &data){cout << data << " - ";});
      cout << endl;
      cout << "In Order Traverse of BinaryTreeVec" << endl;
      btvec.InOrderTraverse([](const string &data){cout << data << " - ";});
      cout << endl;
      cout << "Breadth Traverse of BinaryTreeVec" << endl;
      btvec.BreadthTraverse([](const string &data){cout << data << " - ";});
      cout << endl;

      cout << "Pre Order Map of BinaryTreeVec" << endl;
      btvec.PreOrderMap([](string &data){cout << data << " - ";});
      cout << endl;
      cout << "Post Order Map of BinaryTreeVec" << endl;
      btvec.PostOrderMap([](string &data){cout << data << " - ";});
      cout << endl;
      cout << "In Order Map of BinaryTreeVec" << endl;
      btvec.InOrderMap([](string &data){cout << data << " - ";});
      cout << endl;
      cout << "Breadth Map of BinaryTreeVec" << endl;
      btvec.BreadthMap([](string &data){cout << data << " - ";});
      cout << endl;
    }

    lasd::Vector<string> vec2(10);
    fill(vec2);

    lasd::List<string> list2;
    fill(list2, 10);

    cout << endl << "Creation of a BinaryTreeVec from a Vector" << endl;

    lasd::BinaryTreeVec<string> binaryTreeVec1(vec2);
    cout << endl;
    if(binaryTreeVec1.Empty()){
      cout << "BinaryTreeVec is Empty" << endl;
    } else{
      cout << "BinaryTreeVec is NOT Empty" << endl;
    }
    cout << "BinaryTreeVec Size is "<< binaryTreeVec1.Size() << endl;
    cout << "Pre Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec1.PreOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec1.PostOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec1.InOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BinaryTreeVec" << endl;
    binaryTreeVec1.BreadthTraverse([](const string &data){cout << data << " - ";});
    cout << endl;

    cout << "Pre Order Map of BinaryTreeVec" << endl;
    binaryTreeVec1.PreOrderMap([](string &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Map of BinaryTreeVec" << endl;
    binaryTreeVec1.PostOrderMap([](string &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Map of BinaryTreeVec" << endl;
    binaryTreeVec1.InOrderMap([](string &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Map of BinaryTreeVec" << endl;
    binaryTreeVec1.BreadthMap([](string &data){cout << data << " - ";});
    cout << endl;

    cout << endl << "Creation of a BinaryTreeVec from a List" << endl;

    lasd::BinaryTreeVec<string> binaryTreeVec2(list2);
    cout << endl;
    if(binaryTreeVec2.Empty()){
      cout << "BinaryTreeVec is Empty" << endl;
    } else{
      cout << "BinaryTreeVec is NOT Empty" << endl;
    }
    cout << "BinaryTreeVec Size is "<< binaryTreeVec2.Size() << endl;
    cout << "Pre Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec2.PreOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec2.PostOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec2.InOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BinaryTreeVec" << endl;
    binaryTreeVec2.BreadthTraverse([](const string &data){cout << data << " - ";});
    cout << endl;

    cout << "Pre Order Map of BinaryTreeVec" << endl;
    binaryTreeVec2.PreOrderMap([](string &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Map of BinaryTreeVec" << endl;
    binaryTreeVec2.PostOrderMap([](string &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Map of BinaryTreeVec" << endl;
    binaryTreeVec2.InOrderMap([](string &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Map of BinaryTreeVec" << endl;
    binaryTreeVec2.BreadthMap([](string &data){cout << data << " - ";});
    cout << endl;

    lasd::BinaryTreeVec<string> copBTVec1(binaryTreeVec1);
    lasd::BinaryTreeVec<string> copBTVec2(binaryTreeVec2);
    cout << endl;
    cout << "Tests of Copy Constructors (Should be Equals)" << endl;
    cout << endl;
    if(binaryTreeVec1 == copBTVec1){
      cout << "The 2 BinaryTreeVec are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeVec are NOT Equal" << endl;
    }

    if(binaryTreeVec2 == copBTVec2){
      cout << "The 2 BinaryTreeVec are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeVec are NOT Equal" << endl;
    }

    cout << "BinaryTreeVec(from Vector) Size is "<< binaryTreeVec1.Size() << endl;
    cout << "Copied BinaryTreeVec(from Vector) Size is "<< copBTVec1.Size() << endl;
    cout << "BinaryTreeVec(from List) Size is "<< binaryTreeVec2.Size() << endl;
    cout << "Copied BinaryTreeVec(from List) Size is "<< copBTVec2.Size() << endl;

    lasd::BinaryTreeVec<string> moveBTVec1(move(binaryTreeVec1));
    lasd::BinaryTreeVec<string> moveBTVec2(move(binaryTreeVec2));
    cout << endl;
    cout << "Tests of Move Constructors (Should NOT be Equals)" << endl;
    cout << endl;
    if(binaryTreeVec1 == moveBTVec1){
      cout << "The 2 BinaryTreeVec are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeVec are NOT Equal" << endl;
    }

    if(binaryTreeVec2 == moveBTVec2){
      cout << "The 2 BinaryTreeVec are Equal" << endl;
    } else{
      cout << "The 2 BinaryTreeVec are NOT Equal" << endl;
    }

    cout << "BinaryTreeVec(from Vector) Size is "<< binaryTreeVec1.Size() << endl;
    cout << "Moved BinaryTreeVec(from Vector) Size is "<< moveBTVec1.Size() << endl;
    cout << "BinaryTreeVec(from List) Size is "<< binaryTreeVec2.Size() << endl;
    cout << "Moved BinaryTreeVec(from List) Size is "<< moveBTVec2.Size() << endl;

    cout << endl << "Operator= Tests" << endl << endl;

    binaryTreeVec1 = copBTVec1;
    binaryTreeVec2 = copBTVec2;
    cout << "BinaryTreeVec(from Vector) Size is "<< binaryTreeVec1.Size() << endl;
    cout << "BinaryTreeVec(from List) Size is "<< binaryTreeVec2.Size() << endl;

    cout << "BinaryTreeVec(from Vector) Root is "<< binaryTreeVec1.Root().Element() << endl;
    cout << "Copied BinaryTreeVec(from Vector) Root is "<< copBTVec1.Root().Element() << endl;
    cout << "BinaryTreeVec(from List) Root is "<< binaryTreeVec2.Root().Element() << endl;
    cout << "Copied BinaryTreeVec(from List) Root is "<< copBTVec2.Root().Element() << endl;

    cout << endl << "Clear Tests" << endl << endl;

    binaryTreeVec1.Clear();
    copBTVec1.Clear();
    moveBTVec1.Clear(); 
    binaryTreeVec2.Clear();
    copBTVec2.Clear(); 
    moveBTVec2.Clear();

    cout << "BinaryTreeVec(from Vector) Size is "<< binaryTreeVec1.Size() << endl;
    cout << "Copied BinaryTreeVec(from Vector) Size is "<< copBTVec1.Size() << endl;
    cout << "Moved BinaryTreeVec(from Vector) Size is "<< moveBTVec1.Size() << endl;
    cout << "BinaryTreeVec(from List) Size is "<< binaryTreeVec2.Size() << endl;
    cout << "Copied BinaryTreeVec(from List) Size is "<< copBTVec2.Size() << endl;
    cout << "Moved BinaryTreeVec(from List) Size is "<< moveBTVec2.Size() << endl;

    cout << endl << "End BinaryTreeVec for String" << endl;

    cout << endl << "Begin Tests between BinaryTreeLnk/Vec for String" << endl;

    cout << endl << "Creation of BinaryTreeLnk and BinaryTreeVec with Default Constructor " << endl;

    lasd::BinaryTreeLnk<string> btlinkDef;
    lasd::BinaryTreeVec<string> btVecDef;

    EqualTestBT(btlinkDef, btVecDef);

    cout << endl << "Creation of BinaryTreeLnk and BinaryTreeVec from a Vector " << endl;

    lasd::BinaryTreeLnk<string> btlinkVec(vec2);
    lasd::BinaryTreeVec<string> btVecVec(vec2);

    EqualTestBT(btlinkVec, btVecVec);

    cout << "Changing The Root Element to 0 From BinaryTreeLnk";

    btlinkVec.Root().Element() = string("A");

    EqualTestBT(btlinkVec, btVecVec);

    cout << "Changing The Root Element to 0 From BinaryTreeVec";

    btVecVec.Root().Element() = string("A");

    EqualTestBT(btlinkVec, btVecVec);

    cout << endl << "Tests Method Exists In BinaryTreeLnk" << endl;

    if(btlinkVec.Exists("A")){
      cout << endl <<"Data: 'A' Exists" << endl;
      btlinkVec.BreadthTraverse([](const string &data){cout << data << " - ";});
      cout << endl;
    } else{
      cout << "Data: 'A' Does NOT Exists" << endl;
      btlinkVec.BreadthTraverse([](const string &data){cout << data << " - ";});
      cout << endl;
    }

    if(btlinkVec.Exists("B")){
      cout << "Data: 'B' Exists" << endl;
      btlinkVec.BreadthTraverse([](const string &data){cout << data << " - ";});
      cout << endl;
    } else{
      cout << "Data: 'B' Does NOT Exists" << endl;
      btlinkVec.BreadthTraverse([](const string &data){cout << data << " - ";});
      cout << endl;
    }

    cout << endl << "Tests Method Exists In BinaryTreeVec" << endl;

    if(btVecVec.Exists("A")){
      cout << endl <<"Data: 'A' Exists" << endl;
      btVecVec.BreadthTraverse([](const string &data){cout << data << " - ";});
      cout << endl;
    } else{
      cout << "Data: 'A' Does NOT Exists" << endl;
      btVecVec.BreadthTraverse([](const string &data){cout << data << " - ";});
      cout << endl;
    }

    if(btVecVec.Exists("B")){
      cout << "Data: 'B' Exists" << endl;
      btVecVec.BreadthTraverse([](const string &data){cout << data << " - ";});
      cout << endl;
    } else{
      cout << "Data: 'B' Does NOT Exists" << endl;
      btVecVec.BreadthTraverse([](const string &data){cout << data << " - ";});
      cout << endl;
    }

    cout << "Clearing The 2 BinaryTree" << endl;

    btlinkVec.Clear();
    btVecVec.Clear();

    if(btlinkVec.Exists("A")){
      cout << endl <<"Data: 'A' Exists" << endl;
      btVecVec.BreadthTraverse([](const string &data){cout << data << " - ";});
      cout << endl;
    } else{
      cout << "Data: 'A' Does NOT Exists" << endl;
      btVecVec.BreadthTraverse([](const string &data){cout << data << " - ";});
      cout << endl;
    }
    if(btVecVec.Exists("A")){
      cout << endl <<"Data: 'A' Exists" << endl;
      btVecVec.BreadthTraverse([](const string &data){cout << data << " - ";});
      cout << endl;
    } else{
      cout << "Data: 'A' Does NOT Exists" << endl;
      btVecVec.BreadthTraverse([](const string &data){cout << data << " - ";});
      cout << endl;
    }

  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << endl << "End of BinaryTree For String!" << endl;
}

void mytestBSTInteger() {
  try{
    cout<< endl << "Begin BST for Integer " << endl;

    cout << endl << "Creation of BST from Default Constructor " <<  endl << endl;

    lasd::BST<int> bst;

    if(bst.Empty()){
      cout << "BST is Empty " << endl;
    } else{
      cout << "BST is NOT Empty " << endl;
    }
    cout << "BST Size is " << bst.Size() << endl;

    cout << endl << "Tests for Min/Max on a Empty BST" << endl << endl;

    MinMyTest(bst);
    MinNRemoveMyTest(bst);
    RemoveMinMyTest(bst);
    MaxMyTest(bst);
    MaxNRemoveMyTest(bst);
    RemoveMaxMyTest(bst);

    cout << endl << "Inserted 8 Elements" << endl << endl;

    for(int i = 0; i < 8; i++){
      bst.Insert(i);
    }

    if(bst.Empty()){
      cout << "BST is Empty " << endl;
    } else{
      cout << "BST is NOT Empty " << endl;
    }
    cout << "BST Size is " << bst.Size() << endl;

    cout << endl <<"Pre Order Traverse of BST" << endl;
    bst.PreOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BST" << endl;
    bst.PostOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BST" << endl;
    bst.InOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BST" << endl;
    bst.BreadthTraverse([](const int &data){cout << data << " - ";});
    cout << endl << endl;

    MinMyTest(bst);
    MinNRemoveMyTest(bst);
    RemoveMinMyTest(bst);
    MaxMyTest(bst);
    MaxNRemoveMyTest(bst);
    RemoveMaxMyTest(bst);

    cout << endl <<"Pre Order Traverse of BST" << endl;
    bst.PreOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BST" << endl;
    bst.PostOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BST" << endl;
    bst.InOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BST" << endl;
    bst.BreadthTraverse([](const int &data){cout << data << " - ";});
    cout << endl;

    lasd::Vector<int> vec(6);
    fill(vec);

    lasd::List<int> list;
    fill(list, 6);

    lasd::BST<int> bst1(vec);
    lasd::BST<int> bst2(list);

    lasd::BST<int> copBst1(bst1);
    lasd::BST<int> copBst2(bst2);
    cout << endl;
    cout << "Tests of Copy Constructors (Should be Equals)" << endl;
    cout << endl;
    if(bst1 == copBst1){
      cout << "The 2 BST are Equal" << endl;
    } else{
      cout << "The 2 BST are NOT Equal" << endl;
    }

    if(bst2 == copBst2){
      cout << "The 2 BST are Equal" << endl;
    } else{
      cout << "The 2 BST are NOT Equal" << endl;
    }

    cout << "BST(from Vector) Size is "<< bst1.Size() << endl;
    cout << "Copied BST(from Vector) Size is "<< copBst1.Size() << endl;
    cout << "BST(from List) Size is "<< bst2.Size() << endl;
    cout << "Copied BST(from List) Size is "<< copBst2.Size() << endl;

    lasd::BST<int> moveBst1(move(bst1));
    lasd::BST<int> moveBst2(move(bst2));
    cout << endl;
    cout << "Tests of Move Constructors (Should NOT be Equals)" << endl;
    cout << endl;
    if(bst1 == moveBst1){
      cout << "The 2 BST are Equal" << endl;
    } else{
      cout << "The 2 BST are NOT Equal" << endl;
    }

    if(bst2 == moveBst2){
      cout << "The 2 BST are Equal" << endl;
    } else{
      cout << "The 2 BST are NOT Equal" << endl;
    }

    cout << "BST(from Vector) Size is "<< bst1.Size() << endl;
    cout << "Moved BST(from Vector) Size is "<< moveBst1.Size() << endl;
    cout << "BST(from List) Size is "<< bst2.Size() << endl;
    cout << "Moved BST(from List) Size is "<< moveBst2.Size() << endl;

    cout << endl << "Operator= Tests" << endl << endl;

    bst1 = copBst1;
    bst2 = copBst2;
    cout << "BST(from Vector) Size is "<< bst1.Size() << endl;
    cout << "BST(from List) Size is "<< bst2.Size() << endl;

    cout << endl <<"Pre Order Traverse of BST" << endl;
    bst1.PreOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BST" << endl;
    bst1.PostOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BST" << endl;
    bst1.InOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BST" << endl;
    bst1.BreadthTraverse([](const int &data){cout << data << " - ";});
    cout << endl;

    cout << "Test for Method Exists" << endl;

    if(bst1.Exists(0)){
      cout << endl <<"Data: '0' Exists" << endl;
    } else{
      cout << "Data: '0' Does NOT Exists" << endl;
    }

    cout << "Inserting Data: '0' " << endl;
    bst1.Insert(0);

    if(bst1.Exists(0)){
      cout <<"Data: '0' Exists" << endl;
    } else{
      cout << "Data: '0' Does NOT Exists" << endl;
    }

    cout << endl << "Tests for Dictionary InsertAll, ..." << endl << endl;

    lasd::List<int> list2;
    list2.InsertAtBack(1);
    list2.InsertAtBack(2);
    list2.InsertAtBack(3);
    cout << "PreOrder Traverse of List" << endl;
    list2.PreOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;

    cout << "Insert All Element of List" << endl;
    bst1.InsertAll(list2);
    cout << "PreOrder Traverse of BST" << endl;
    bst1.PreOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;

    cout << "Remove All Element of List" << endl;
    bst1.RemoveAll(list2);
    cout << "PreOrder Traverse of BST" << endl;
    bst1.PreOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;

    cout << "Insert Some Element of List" << endl;
    bst1.InsertSome(list2);
    cout << "PreOrder Traverse of BST" << endl;
    bst1.PreOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;

    cout << "Remove Some Element of List" << endl;
    bst1.RemoveSome(list2);
    cout << "PreOrder Traverse of BST" << endl;
    bst1.PreOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;

    cout << endl << "Tests for Successor/Predecessor" << endl << endl;
    PredecessorMyTest(bst1, 0);
    PredecessorNRemoveMyTest(bst1, 0);
    RemovePredecessorMyTest(bst1, 0);
    SuccessorMyTest(bst1, 0);
    SuccessorNRemoveMyTest(bst1, 0);
    RemoveSuccessorMyTest(bst1, 0);

    cout << endl << endl << "Tests for Clear" << endl << endl;
    bst1.Clear();

    if(bst1.Empty()){
      cout << "BST is Empty " << endl;
    } else{
      cout << "BST is NOT Empty " << endl;
    }
    cout << "BST Size is " << bst1.Size() << endl;

  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << endl << "End of BST For Integer!" << endl;
}

void mytestBSTFloat() {

  try{
    cout<< endl << "Begin BST for Float " << endl;

    cout << endl << "Creation of BST from Default Constructor " <<  endl << endl;

    lasd::BST<float> bst;

    if(bst.Empty()){
      cout << "BST is Empty " << endl;
    } else{
      cout << "BST is NOT Empty " << endl;
    }
    cout << "BST Size is " << bst.Size() << endl;

    cout << endl << "Tests for Min/Max on a Empty BST" << endl << endl;

    MinMyTest(bst);
    MinNRemoveMyTest(bst);
    RemoveMinMyTest(bst);
    MaxMyTest(bst);
    MaxNRemoveMyTest(bst);
    RemoveMaxMyTest(bst);

    cout << endl << "Inserted 8 Elements" << endl << endl;

    for(int i = 0; i < 8; i++){
      bst.Insert(i + 0.5);
    }

    if(bst.Empty()){
      cout << "BST is Empty " << endl;
    } else{
      cout << "BST is NOT Empty " << endl;
    }
    cout << "BST Size is " << bst.Size() << endl;

    cout << endl <<"Pre Order Traverse of BST" << endl;
    bst.PreOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BST" << endl;
    bst.PostOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BST" << endl;
    bst.InOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BST" << endl;
    bst.BreadthTraverse([](const float &data){cout << data << " - ";});
    cout << endl << endl;

    MinMyTest(bst);
    MinNRemoveMyTest(bst);
    RemoveMinMyTest(bst);
    MaxMyTest(bst);
    MaxNRemoveMyTest(bst);
    RemoveMaxMyTest(bst);

    cout << endl <<"Pre Order Traverse of BST" << endl;
    bst.PreOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BST" << endl;
    bst.PostOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BST" << endl;
    bst.InOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BST" << endl;
    bst.BreadthTraverse([](const float &data){cout << data << " - ";});
    cout << endl;

    lasd::Vector<float> vec(6);
    fill(vec);

    lasd::List<float> list;
    fill(list, 6);

    lasd::BST<float> bst1(vec);
    lasd::BST<float> bst2(list);

    lasd::BST<float> copBst1(bst1);
    lasd::BST<float> copBst2(bst2);
    cout << endl;
    cout << "Tests of Copy Constructors (Should be Equals)" << endl;
    cout << endl;
    if(bst1 == copBst1){
      cout << "The 2 BST are Equal" << endl;
    } else{
      cout << "The 2 BST are NOT Equal" << endl;
    }

    if(bst2 == copBst2){
      cout << "The 2 BST are Equal" << endl;
    } else{
      cout << "The 2 BST are NOT Equal" << endl;
    }

    cout << "BST(from Vector) Size is "<< bst1.Size() << endl;
    cout << "Copied BST(from Vector) Size is "<< copBst1.Size() << endl;
    cout << "BST(from List) Size is "<< bst2.Size() << endl;
    cout << "Copied BST(from List) Size is "<< copBst2.Size() << endl;

    lasd::BST<float> moveBst1(move(bst1));
    lasd::BST<float> moveBst2(move(bst2));
    cout << endl;
    cout << "Tests of Move Constructors (Should NOT be Equals)" << endl;
    cout << endl;
    if(bst1 == moveBst1){
      cout << "The 2 BST are Equal" << endl;
    } else{
      cout << "The 2 BST are NOT Equal" << endl;
    }

    if(bst2 == moveBst2){
      cout << "The 2 BST are Equal" << endl;
    } else{
      cout << "The 2 BST are NOT Equal" << endl;
    }

    cout << "BST(from Vector) Size is "<< bst1.Size() << endl;
    cout << "Moved BST(from Vector) Size is "<< moveBst1.Size() << endl;
    cout << "BST(from List) Size is "<< bst2.Size() << endl;
    cout << "Moved BST(from List) Size is "<< moveBst2.Size() << endl;

    cout << endl << "Operator= Tests" << endl << endl;

    bst1 = copBst1;
    bst2 = copBst2;
    cout << "BST(from Vector) Size is "<< bst1.Size() << endl;
    cout << "BST(from List) Size is "<< bst2.Size() << endl;

    cout << endl <<"Pre Order Traverse of BST" << endl;
    bst1.PreOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BST" << endl;
    bst1.PostOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BST" << endl;
    bst1.InOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BST" << endl;
    bst1.BreadthTraverse([](const float &data){cout << data << " - ";});
    cout << endl;

    cout << "Test for Method Exists" << endl;

    if(bst1.Exists(0)){
      cout << endl <<"Data: '0' Exists" << endl;
    } else{
      cout << "Data: '0' Does NOT Exists" << endl;
    }

    cout << "Inserting Data: '0' " << endl;
    bst1.Insert(0);

    if(bst1.Exists(0)){
      cout <<"Data: '0' Exists" << endl;
    } else{
      cout << "Data: '0' Does NOT Exists" << endl;
    }

    lasd::List<float> list2;
    list2.InsertAtBack(1.5);
    list2.InsertAtBack(2.5);
    list2.InsertAtBack(3.5);
    cout << "PreOrder Traverse of List" << endl;
    list2.PreOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;

    cout << "Insert All Element of List" << endl;
    bst1.InsertAll(list2);
    cout << "PreOrder Traverse of BST" << endl;
    bst1.PreOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;

    cout << "Remove All Element of List" << endl;
    bst1.RemoveAll(list2);
    cout << "PreOrder Traverse of BST" << endl;
    bst1.PreOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;

    cout << "Insert Some Element of List" << endl;
    bst1.InsertSome(list2);
    cout << "PreOrder Traverse of BST" << endl;
    bst1.PreOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;

    cout << "Remove Some Element of List" << endl;
    bst1.RemoveSome(list2);
    cout << "PreOrder Traverse of BST" << endl;
    bst1.PreOrderTraverse([](const float &data){cout << data << " - ";});
    cout << endl;

    cout << endl << endl << "Tests for Clear" << endl << endl;
    bst1.Clear();

    if(bst1.Empty()){
      cout << "BST is Empty " << endl;
    } else{
      cout << "BST is NOT Empty " << endl;
    }
    cout << "BST Size is " << bst1.Size() << endl;
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << endl << "End of BST For Float!" << endl;
}

void mytestBSTString() {

  try{
    cout<< endl << "Begin BST for String " << endl;

    cout << endl << "Creation of BST from Default Constructor " <<  endl << endl;

    lasd::BST<string> bst;

    if(bst.Empty()){
      cout << "BST is Empty " << endl;
    } else{
      cout << "BST is NOT Empty " << endl;
    }
    cout << "BST Size is " << bst.Size() << endl;

    cout << endl << "Tests for Min/Max on a Empty BST" << endl << endl;

    MinMyTest(bst);
    MinNRemoveMyTest(bst);
    RemoveMinMyTest(bst);
    MaxMyTest(bst);
    MaxNRemoveMyTest(bst);
    RemoveMaxMyTest(bst);

    cout << endl << "Inserted 8 Elements" << endl << endl;

    bst.Insert(string("A"));
    bst.Insert(string("B"));
    bst.Insert(string("C"));
    bst.Insert(string("D"));
    bst.Insert(string("E"));

    if(bst.Empty()){
      cout << "BST is Empty " << endl;
    } else{
      cout << "BST is NOT Empty " << endl;
    }
    cout << "BST Size is " << bst.Size() << endl;

    cout << endl <<"Pre Order Traverse of BST" << endl;
    bst.PreOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BST" << endl;
    bst.PostOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BST" << endl;
    bst.InOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BST" << endl;
    bst.BreadthTraverse([](const string &data){cout << data << " - ";});
    cout << endl << endl;

    MinMyTest(bst);
    MinNRemoveMyTest(bst);
    RemoveMinMyTest(bst);
    MaxMyTest(bst);
    MaxNRemoveMyTest(bst);
    RemoveMaxMyTest(bst);

    cout << endl <<"Pre Order Traverse of BST" << endl;
    bst.PreOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BST" << endl;
    bst.PostOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BST" << endl;
    bst.InOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BST" << endl;
    bst.BreadthTraverse([](const string &data){cout << data << " - ";});
    cout << endl;

    lasd::Vector<string> vec(6);
    fill(vec);

    lasd::List<string> list;
    fill(list, 6);

    lasd::BST<string> bst1(vec);
    lasd::BST<string> bst2(list);

    lasd::BST<string> copBst1(bst1);
    lasd::BST<string> copBst2(bst2);
    cout << endl;
    cout << "Tests of Copy Constructors (Should be Equals)" << endl;
    cout << endl;
    if(bst1 == copBst1){
      cout << "The 2 BST are Equal" << endl;
    } else{
      cout << "The 2 BST are NOT Equal" << endl;
    }

    if(bst2 == copBst2){
      cout << "The 2 BST are Equal" << endl;
    } else{
      cout << "The 2 BST are NOT Equal" << endl;
    }

    cout << "BST(from Vector) Size is "<< bst1.Size() << endl;
    cout << "Copied BST(from Vector) Size is "<< copBst1.Size() << endl;
    cout << "BST(from List) Size is "<< bst2.Size() << endl;
    cout << "Copied BST(from List) Size is "<< copBst2.Size() << endl;

    lasd::BST<string> moveBst1(move(bst1));
    lasd::BST<string> moveBst2(move(bst2));
    cout << endl;
    cout << "Tests of Move Constructors (Should NOT be Equals)" << endl;
    cout << endl;
    if(bst1 == moveBst1){
      cout << "The 2 BST are Equal" << endl;
    } else{
      cout << "The 2 BST are NOT Equal" << endl;
    }

    if(bst2 == moveBst2){
      cout << "The 2 BST are Equal" << endl;
    } else{
      cout << "The 2 BST are NOT Equal" << endl;
    }

    cout << "BST(from Vector) Size is "<< bst1.Size() << endl;
    cout << "Moved BST(from Vector) Size is "<< moveBst1.Size() << endl;
    cout << "BST(from List) Size is "<< bst2.Size() << endl;
    cout << "Moved BST(from List) Size is "<< moveBst2.Size() << endl;

    cout << endl << "Operator= Tests" << endl << endl;

    bst1 = copBst1;
    bst2 = copBst2;
    cout << "BST(from Vector) Size is "<< bst1.Size() << endl;
    cout << "BST(from List) Size is "<< bst2.Size() << endl;

    cout << endl <<"Pre Order Traverse of BST" << endl;
    bst1.PreOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BST" << endl;
    bst1.PostOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BST" << endl;
    bst1.InOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BST" << endl;
    bst1.BreadthTraverse([](const string &data){cout << data << " - ";});
    cout << endl;

    cout << "Test for Method Exists" << endl;

    if(bst1.Exists("Z")){
      cout << endl <<"Data: 'Z' Exists" << endl;
    } else{
      cout << "Data: 'Z' Does NOT Exists" << endl;
    }

    cout << "Inserting Data: 'Z' " << endl;
    bst1.Insert("Z");

    if(bst1.Exists("Z")){
      cout <<"Data: 'Z' Exists" << endl;
    } else{
      cout << "Data: 'Z' Does NOT Exists" << endl;
    }

    lasd::List<string> list2;
    list2.InsertAtBack("A");
    list2.InsertAtBack("B");
    list2.InsertAtBack("C");
    cout << "PreOrder Traverse of List" << endl;
    list2.PreOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;

    cout << "Insert All Element of List" << endl;
    bst1.InsertAll(list2);
    cout << "PreOrder Traverse of BST" << endl;
    bst1.PreOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;

    cout << "Remove All Element of List" << endl;
    bst1.RemoveAll(list2);
    cout << "PreOrder Traverse of BST" << endl;
    bst1.PreOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;

    cout << "Insert Some Element of List" << endl;
    bst1.InsertSome(list2);
    cout << "PreOrder Traverse of BST" << endl;
    bst1.PreOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;

    cout << "Remove Some Element of List" << endl;
    bst1.RemoveSome(list2);
    cout << "PreOrder Traverse of BST" << endl;
    bst1.PreOrderTraverse([](const string &data){cout << data << " - ";});
    cout << endl;

    cout << endl << endl << "Tests for Clear" << endl << endl;
    bst1.Clear();

    if(bst1.Empty()){
      cout << "BST is Empty " << endl;
    } else{
      cout << "BST is NOT Empty " << endl;
    }
    cout << "BST Size is " << bst1.Size() << endl;
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << endl << "End of BST For String!" << endl;
}


void mytestIteratorInteger() {
  try{
    cout<< endl << "Begin Iterator for Integer " << endl;

    cout << endl << "Creation of PreOrderIterator from List" <<  endl;

    lasd::List<int> list;
    list.InsertAtBack(1);
    list.InsertAtBack(2);
    list.InsertAtBack(3);
    list.InsertAtBack(4);
    lasd::BinaryTreeLnk<int> btlink(list);

    lasd::BTPreOrderIterator<int> preItr(btlink);

    cout << "PreOrder Traverse of BinaryTreeLnk" << endl;
    btlink.PreOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    
    ValueIteratorGet(preItr, 1);
    ++preItr;
    ValueIteratorGet(preItr, 2);
    ++preItr;
    ValueIteratorGet(preItr, 4);
    ++preItr;
    ValueIteratorGet(preItr, 3);
    ++preItr;
    cout << "Should Be Terminated" << endl;
    ValueIteratorGet(preItr, 4);

    if(preItr.Terminated()){
      cout << "Iterator is Terminated" << endl;
    } else{
      cout << "Iterator is NOT Terminated" << endl;
    }

    cout << "Reset the Iterator" << endl;
    preItr.Reset();
    if(preItr.Terminated()){
      cout << "Iterator is Terminated" << endl;
    } else{
      cout << "Iterator is NOT Terminated" << endl;
    }

    cout << endl << "Creation of PostOrderIterator from List" <<  endl;

    lasd::BTPostOrderIterator<int> postItr(btlink);

    cout << "PostOrder Traverse of BinaryTreeLnk" << endl;
    btlink.PostOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    
    ValueIteratorGet(postItr, 4);
    ++postItr;
    ValueIteratorGet(postItr, 2);
    ++postItr;
    ValueIteratorGet(postItr, 3);
    ++postItr;
    ValueIteratorGet(postItr, 1);
    ++postItr;
    cout << "Should Be Terminated" << endl;
    ValueIteratorGet(postItr, 4);

    if(postItr.Terminated()){
      cout << "Iterator is Terminated" << endl;
    } else{
      cout << "Iterator is NOT Terminated" << endl;
    }

    cout << "Reset the Iterator" << endl;
    postItr.Reset();
    if(postItr.Terminated()){
      cout << "Iterator is Terminated" << endl;
    } else{
      cout << "Iterator is NOT Terminated" << endl;
    }

    cout << endl << "Creation of InOrderIterator from List" <<  endl;

    lasd::BTInOrderIterator<int> InItr(btlink);

    cout << "InOrder Traverse of BinaryTreeLnk" << endl;
    btlink.InOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    
    ValueIteratorGet(InItr, 4);
    ++InItr;
    ValueIteratorGet(InItr, 2);
    ++InItr;
    ValueIteratorGet(InItr, 1);
    ++InItr;
    ValueIteratorGet(InItr, 3);
    ++InItr;
    cout << "Should Be Terminated" << endl;
    ValueIteratorGet(InItr, 4);

    if(InItr.Terminated()){
      cout << "Iterator is Terminated" << endl;
    } else{
      cout << "Iterator is NOT Terminated" << endl;
    }

    cout << "Reset the Iterator" << endl;
    InItr.Reset();
    if(InItr.Terminated()){
      cout << "Iterator is Terminated" << endl;
    } else{
      cout << "Iterator is NOT Terminated" << endl;
    }

    cout << endl << "Creation of BreadthIterator from List" <<  endl;

    lasd::BTBreadthIterator<int> breItr(btlink);

    cout << "Breadth Traverse of BinaryTreeLnk" << endl;
    btlink.BreadthTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    
    ValueIteratorGet(breItr, 1);
    ++breItr;
    ValueIteratorGet(breItr, 2);
    ++breItr;
    ValueIteratorGet(breItr, 3);
    ++breItr;
    ValueIteratorGet(breItr, 4);
    ++breItr;
    cout << "Should Be Terminated" << endl;
    ValueIteratorGet(breItr, 4);

    if(breItr.Terminated()){
      cout << "Iterator is Terminated" << endl;
    } else{
      cout << "Iterator is NOT Terminated" << endl;
    }

    cout << "Reset the Iterator" << endl;
    breItr.Reset();
    if(breItr.Terminated()){
      cout << "Iterator is Terminated" << endl;
    } else{
      cout << "Iterator is NOT Terminated" << endl;
    }

    lasd::BTPreOrderIterator<int> copPreItr(preItr);
    cout << endl;
    cout << "Tests of Copy Constructors (Should be Equals)" << endl;
    cout << endl;
    if(preItr == copPreItr){
      cout << "The 2 Iterator are Equal" << endl;
    } else{
      cout << "The 2 Iterator are NOT Equal" << endl;
    }

    lasd::BTPreOrderIterator<int> movePreItr(move(preItr));
    cout << endl;
    cout << "Tests of Move Constructors (Should NOT be Equals)" << endl;
    cout << endl;
    if(preItr == movePreItr){
      cout << "The 2 Iterator are Equal" << endl;
    } else{
      cout << "The 2 Iterator are NOT Equal" << endl;
    }

    cout << endl << "Operator= Tests" << endl << endl;

    preItr = copPreItr;

    cout << "Tests of Move Constructors and copied Iterator (Should be Equals)" << endl;
    cout << endl;
    if(preItr == movePreItr){
      cout << "The 2 Iterator are Equal" << endl;
    } else{
      cout << "The 2 Iterator are NOT Equal" << endl;
    }

    lasd::BTPostOrderIterator<int> copPostItr(postItr);
    cout << endl;
    cout << "Tests of Copy Constructors (Should be Equals)" << endl;
    cout << endl;
    if(postItr == copPostItr){
      cout << "The 2 Iterator are Equal" << endl;
    } else{
      cout << "The 2 Iterator are NOT Equal" << endl;
    }

    lasd::BTPostOrderIterator<int> movePostItr(move(postItr));
    cout << endl;
    cout << "Tests of Move Constructors (Should NOT be Equals)" << endl;
    cout << endl;
    if(postItr == movePostItr){
      cout << "The 2 Iterator are Equal" << endl;
    } else{
      cout << "The 2 Iterator are NOT Equal" << endl;
    }

    cout << endl << "Operator= Tests" << endl << endl;

    postItr = copPostItr;

    cout << "Tests of Move Constructors and copied Iterator (Should be Equals)" << endl;
    cout << endl;
    if(postItr == movePostItr){
      cout << "The 2 Iterator are Equal" << endl;
    } else{
      cout << "The 2 Iterator are NOT Equal" << endl;
    }

    lasd::BTInOrderIterator<int> copInItr(InItr);
    cout << endl;
    cout << "Tests of Copy Constructors (Should be Equals)" << endl;
    cout << endl;
    if(InItr == copInItr){
      cout << "The 2 Iterator are Equal" << endl;
    } else{
      cout << "The 2 Iterator are NOT Equal" << endl;
    }

    lasd::BTInOrderIterator<int> moveInItr(move(InItr));
    cout << endl;
    cout << "Tests of Move Constructors (Should NOT be Equals)" << endl;
    cout << endl;
    if(InItr == moveInItr){
      cout << "The 2 Iterator are Equal" << endl;
    } else{
      cout << "The 2 Iterator are NOT Equal" << endl;
    }

    cout << endl << "Operator= Tests" << endl << endl;

    InItr = copInItr;

    cout << "Tests of Move Constructors and copied Iterator (Should be Equals)" << endl;
    cout << endl;
    if(InItr == moveInItr){
      cout << "The 2 Iterator are Equal" << endl;
    } else{
      cout << "The 2 Iterator are NOT Equal" << endl;
    }

    lasd::BTBreadthIterator<int> copBreItr(breItr);
    cout << endl;
    cout << "Tests of Copy Constructors (Should be Equals)" << endl;
    cout << endl;
    if(breItr == copBreItr){
      cout << "The 2 Iterator are Equal" << endl;
    } else{
      cout << "The 2 Iterator are NOT Equal" << endl;
    }

    lasd::BTBreadthIterator<int> moveBreItr(move(breItr));
    cout << endl;
    cout << "Tests of Move Constructors (Should NOT be Equals)" << endl;
    cout << endl;
    if(breItr == moveBreItr){
      cout << "The 2 Iterator are Equal" << endl;
    } else{
      cout << "The 2 Iterator are NOT Equal" << endl;
    }

    cout << endl << "Operator= Tests" << endl << endl;

    breItr = copBreItr;

    cout << "Tests of Move Constructors and copied Iterator (Should be Equals)" << endl;
    cout << endl;
    if(breItr == moveBreItr){
      cout << "The 2 Iterator are Equal" << endl;
    } else{
      cout << "The 2 Iterator are NOT Equal" << endl;
    }

    cout << endl << "Creation of PreOrderMutableIterator from List" <<  endl;

    lasd::BTPreOrderMutableIterator<int> preMutItr(btlink);

    cout << "PreOrder Traverse of BinaryTreeLnk" << endl;
    btlink.PreOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    
    ValueIteratorGet(preMutItr, 1);
    ++preMutItr;
    ValueIteratorGet(preMutItr, 2);
    ++preMutItr;
    ValueIteratorGet(preMutItr, 4);
    ++preMutItr;
    ValueIteratorGet(preMutItr, 3);
    ++preMutItr;
    cout << "Should Be Terminated" << endl;
    ValueIteratorGet(preMutItr, 4);

    if(preMutItr.Terminated()){
      cout << "Iterator is Terminated" << endl;
    } else{
      cout << "Iterator is NOT Terminated" << endl;
    }

    cout << "Reset the Iterator" << endl;
    preMutItr.Reset();
    if(preMutItr.Terminated()){
      cout << "Iterator is Terminated" << endl;
    } else{
      cout << "Iterator is NOT Terminated" << endl;
    }

    cout << "Now Invert the Order setting different value thanks to the MutableIterator" << endl;

    ValueIteratorSet(preMutItr, 3);
    ++preMutItr;
    ValueIteratorSet(preMutItr, 4);
    ++preMutItr;
    ValueIteratorSet(preMutItr, 2);
    ++preMutItr;
    ValueIteratorSet(preMutItr, 1);
    ++preMutItr;

    cout << "PreOrder Traverse of BinaryTreeLnk" << endl;
    btlink.PreOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;

    cout << endl << "Creation of PreOrderMutableIterator from List" <<  endl;

    lasd::BTPostOrderMutableIterator<int> postMutItr(btlink);

    cout << "PostOrder Traverse of BinaryTreeLnk" << endl;
    btlink.PostOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    
    ValueIteratorGet(postMutItr, 2);
    ++postMutItr;
    ValueIteratorGet(postMutItr, 4);
    ++postMutItr;
    ValueIteratorGet(postMutItr, 1);
    ++postMutItr;
    ValueIteratorGet(postMutItr, 3);
    ++postMutItr;
    cout << "Should Be Terminated" << endl;
    ValueIteratorGet(postMutItr, 4);

    if(postMutItr.Terminated()){
      cout << "Iterator is Terminated" << endl;
    } else{
      cout << "Iterator is NOT Terminated" << endl;
    }

    cout << "Reset the Iterator" << endl;
    postMutItr.Reset();
    if(postMutItr.Terminated()){
      cout << "Iterator is Terminated" << endl;
    } else{
      cout << "Iterator is NOT Terminated" << endl;
    }

    cout << "Now Invert the Order setting different value thanks to the MutableIterator" << endl;

    ValueIteratorSet(postMutItr, 3);
    ++postMutItr;
    ValueIteratorSet(postMutItr, 1);
    ++postMutItr;
    ValueIteratorSet(postMutItr, 4);
    ++postMutItr;
    ValueIteratorSet(postMutItr, 2);
    ++postMutItr;

    cout << "PostOrder Traverse of BinaryTreeLnk" << endl;
    btlink.PostOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;

    cout << endl << "Creation of InOrderMutableIterator from List" <<  endl;

    lasd::BTInOrderMutableIterator<int> inMutItr(btlink);

    cout << "InOrder Traverse of BinaryTreeLnk" << endl;
    btlink.InOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    
    ValueIteratorGet(inMutItr, 3);
    ++inMutItr;
    ValueIteratorGet(inMutItr, 1);
    ++inMutItr;
    ValueIteratorGet(inMutItr, 2);
    ++inMutItr;
    ValueIteratorGet(inMutItr, 4);
    ++inMutItr;
    cout << "Should Be Terminated" << endl;
    ValueIteratorGet(inMutItr, 4);

    if(inMutItr.Terminated()){
      cout << "Iterator is Terminated" << endl;
    } else{
      cout << "Iterator is NOT Terminated" << endl;
    }

    cout << "Reset the Iterator" << endl;
    inMutItr.Reset();
    if(inMutItr.Terminated()){
      cout << "Iterator is Terminated" << endl;
    } else{
      cout << "Iterator is NOT Terminated" << endl;
    }

    cout << "Now Invert the Order setting different value thanks to the MutableIterator" << endl;

    ValueIteratorSet(inMutItr, 4);
    ++inMutItr;
    ValueIteratorSet(inMutItr, 2);
    ++inMutItr;
    ValueIteratorSet(inMutItr, 1);
    ++inMutItr;
    ValueIteratorSet(inMutItr, 3);
    ++inMutItr;

    cout << "InOrder Traverse of BinaryTreeLnk" << endl;
    btlink.InOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;

    cout << endl << "Creation of BreadthMutableIterator from List" <<  endl;

    lasd::BTBreadthMutableIterator<int> breMutItr(btlink);

    cout << "Breadth Traverse of BinaryTreeLnk" << endl;
    btlink.BreadthTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    
    ValueIteratorGet(breMutItr, 1);
    ++breMutItr;
    ValueIteratorGet(breMutItr, 2);
    ++breMutItr;
    ValueIteratorGet(breMutItr, 3);
    ++breMutItr;
    ValueIteratorGet(breMutItr, 4);
    ++breMutItr;
    cout << "Should Be Terminated" << endl;
    ValueIteratorGet(breMutItr, 4);

    if(breMutItr.Terminated()){
      cout << "Iterator is Terminated" << endl;
    } else{
      cout << "Iterator is NOT Terminated" << endl;
    }

    cout << "Reset the Iterator" << endl;
    breMutItr.Reset();
    if(breMutItr.Terminated()){
      cout << "Iterator is Terminated" << endl;
    } else{
      cout << "Iterator is NOT Terminated" << endl;
    }

    cout << "Now Invert the Order setting different value thanks to the MutableIterator" << endl;

    ValueIteratorSet(breMutItr, 4);
    ++breMutItr;
    ValueIteratorSet(breMutItr, 3);
    ++breMutItr;
    ValueIteratorSet(breMutItr, 2);
    ++breMutItr;
    ValueIteratorSet(breMutItr, 1);
    ++breMutItr;

    cout << "Breadth Traverse of BinaryTreeLnk" << endl;
    btlink.BreadthTraverse([](const int &data){cout << data << " - ";});
    cout << endl;

  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << endl << "End Iterator for Integer" << endl;
}


void mytest() {
  cout << "Begin of MyTests!" << endl;
  int choice = 0;
  do{
    cout << endl << "1: To Run BinaryTree Tests" << endl;
    cout << "2: To Run BST Tests" << endl;
    cout << "3: To Run Iterator Tests" << endl;
    cout << "Any Other Key: To Close" << endl;
    cin >> choice;
    if(choice == 1){
      mytestBinaryTreeInteger();
      mytestBinaryTreeFloat();
      mytestBinaryTreeString();
      cout << endl << "End of BinaryTree Test" << endl;
    }
    else if(choice == 2){
      mytestBSTInteger();
      mytestBSTFloat();
      mytestBSTString();
      cout << endl << "End of BST Test" << endl;
    } 
    else if(choice == 3){
      mytestIteratorInteger();
      cout << endl << "End of Iterator Test" << endl;
    }
  } while (choice == 1 || choice == 2 || choice == 3);
  cout<< "End of MyTest!" << endl;
  cout << endl;
}
