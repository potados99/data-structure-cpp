//
//  Test.cpp
//  cpp-test
//
//  Created by POTADOS on 2018. 5. 17..
//  Copyright © 2018 POTADOS. All rights reserved.
//
//  Please comment out at least one below.
//

#include "Test.hpp"

#ifdef LINKED_LIST
#include "LinkedList.hpp"
#endif

#ifdef ARRAY_STACK
#include "ArrayStack.hpp"
#endif

#ifdef LINKED_STACK
#include "LinkedStack.hpp"
#endif

#ifdef LINKED_QUEUE
#include "LinkedQueue.hpp"
#endif

#ifdef LINKED_TREE
#include "LinkedTree.hpp"
#endif


#if defined LINKED_LIST
void Test::ListTest() {

    LinkedList::List<int> intList;
    int count = 0;
    
    intList.Append(256);
    intList.Insert(0, 32);
    intList.Insert(0, 8);
    intList.Insert(1, 16);
    intList.Insert(-1, 128);
    intList.Insert(-2, 64);
    intList.Insert(-1, 9999);
    
    intList.Print();

    std::cout << "Poped " << intList.Pop(-2) << std::endl;

    intList.ForEach([&count](int data) {
        count += data;
    });
    
    intList.Print();
    
    std::cout << "Total of them is " << count << std::endl;
    
}
#endif

#if defined ARRAY_STACK || defined LINKED_STACK
void Test::StackTest() {
    
    std::cout << "\nTest for stack" << std::endl;
    ArrayStack::Stack<int> intStack(0);
    
    for (int i = 0; i < 20; ++ i) {
        intStack.Push(i);
    }

    for (int i = 0; i < 20; ++ i) {
        std::cout << intStack.Pop() << std::endl;
    }

}
#endif

#if defined LINKED_QUEUE
void Test::QueueTest() {
    
}
#endif

#if defined LINKED_TREE
void Test::TreeTest() {
    
}
#endif

void Test::DoTest() {
#if defined LINKED_LIST
    ListTest();
#endif

#if defined ARRAY_STACK || defined LINKED_STACK
    StackTest();
#endif

#if defined LINKED_QUEUE
    QueueTest();
#endif

#if defined LINKED_TREE
    TreeTest();
#endif

    
#ifdef __APPLE__
    std::cout << std::endl << ":)" << std::endl;
    
#elif defined __unix__
	std::cout << std::endl << ":D" << std::endl;

#elif defined _MSC_VER
	std::cout << std::endl << ":(" << std::endl;
	getchar();
    
#endif
}
