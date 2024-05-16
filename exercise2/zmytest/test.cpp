
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

/* ************************************************************************** */

//StackTests
template <typename BT, typename Data>
void mytestBinaryTree(BT &bt) {
  try {

  }
  catch (...) {
    cout << "Error!" << endl;
  }
}

void mytestBinaryTreeInteger() {
  try{
    lasd::Vector<int> vec(6);
    for(int i = 0; i < 6; i++){
      vec[i] = i;
    }
    lasd::BinaryTreeLnk<int> binaryTreeLnk(vec);
    cout << endl << "Begin BinaryTreeLnk for Integer" << endl;

    cout << "Pre Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk.PreOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk.PostOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk.InOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BinaryTreeLnk" << endl;
    binaryTreeLnk.BreadthTraverse([](const int &data){cout << data << " - ";});
    cout << endl;

    cout << "Pre Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk.PreOrderMap([](int &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk.PostOrderMap([](int &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Map of BinaryTreeLnk" << endl;
    binaryTreeLnk.InOrderMap([](int &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Map of BinaryTreeLnk" << endl;
    binaryTreeLnk.BreadthMap([](int &data){cout << data << " - ";});
    cout << endl;

    lasd::BinaryTreeVec<int> binaryTreeVec(vec);
    cout << endl << "Begin BinaryTreeVec for Integer" << endl;

    cout << "Pre Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec.PreOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec.PostOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BinaryTreeVec" << endl;
    binaryTreeVec.InOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BinaryTreeVec" << endl;
    binaryTreeVec.BreadthTraverse([](const int &data){cout << data << " - ";});
    cout << endl;

    cout << "Pre Order Map of BinaryTreeVec" << endl;
    binaryTreeVec.PreOrderMap([](int &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Map of BinaryTreeVec" << endl;
    binaryTreeVec.PostOrderMap([](int &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Map of BinaryTreeVec" << endl;
    binaryTreeVec.InOrderMap([](int &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Map of BinaryTreeVec" << endl;
    binaryTreeVec.BreadthMap([](int &data){cout << data << " - ";});
    cout << endl;

  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << "End of BinaryTreeLnk For Integer!" << endl;
}

void mytestBinaryTreeFloat() {
  
  try{
    
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << "End of StackTest For Float!" << endl;
}

void mytestBinaryTreeString() {

  try{
    
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << "End of StackTest For String!" << endl;
}

void mytestBST() {
  try {
    
  }
  catch (...) {
    cout << "Error!" << endl;
  }

  cout << "End of QueueTest(Vector)!" << endl;
}

void mytestBSTInteger() {
  try{
    cout<< endl << "Begin BST for Integer " << endl;
    lasd::List<int> lst;

    lst.InsertAtBack(0);
    lst.InsertAtBack(1);
    lst.InsertAtBack(2);
    lst.InsertAtBack(3);
    lst.InsertAtBack(4);
    lst.InsertAtBack(5);

    lasd::BST<int> bst1(lst);

    cout << endl;
    cout << "Pre Order Traverse of BST" << endl;
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

    lasd::BST<int> bst2;

    bst2.Insert(0);
    bst2.Insert(1);
    bst2.Insert(2);
    bst2.Insert(3);
    bst2.Insert(4);
    bst2.Insert(5);

    cout << endl;
    cout << "Pre Order Traverse of BST" << endl;
    bst2.PreOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Post Order Traverse of BST" << endl;
    bst2.PostOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "In Order Traverse of BST" << endl;
    bst2.InOrderTraverse([](const int &data){cout << data << " - ";});
    cout << endl;
    cout << "Breadth Traverse of BST" << endl;
    bst2.BreadthTraverse([](const int &data){cout << data << " - ";});
    cout << endl;

  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << "End of QueueTest For Integer!" << endl;
}

void mytestBSTFloat() {

  try{
    
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << "End of QueueTest For Float!" << endl;
}

void mytestBSTString() {

  try{
    
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << "End of QueueTest For String!" << endl;
}

template <typename Data>
void mytestIterator(lasd::SortableVector<Data> &vec) {
  try {
    
  }
  catch (...) {
    cout << "Error!" << endl;
  }

}

void mytestIteratorInteger() {

  try{
    
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << endl << "End Vector for Integer" << endl;
}

void mytestIteratorFloat() {

  try{
   
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << endl << "End Vector for Float" << endl;
}

void mytestIteratorString() {
  
  try{
    
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << endl << "End Vector for String" << endl;
}



void mytest() {
  cout << "Begin of MyTests!" << endl;
  mytestBinaryTreeInteger();
  mytestBinaryTreeFloat();
  mytestBinaryTreeString();
  mytestBSTInteger();
  mytestBSTFloat();
  mytestBSTString();
  mytestIteratorInteger();
  mytestIteratorFloat();
  mytestIteratorString();
  cout<< "End of MyTest!" << endl;
  cout << endl;
}
