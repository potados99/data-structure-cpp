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

#elif defined LINKED_STACK
#include "LinkedStack.hpp"

#elif defined LINKED_QUEUE
#include "LinkedQueue.hpp"

#elif defined LINKED_TREE
#include "LinkedTree.hpp"

#endif

#if defined LINKED_LIST
void Test::ListTest() {
    
    LinkedList::List<std::string> strList;
    
    strList.Append("Hello");
    strList.Append("World");
    strList.Append("!");
    strList.Insert(0, "I say: ");
    
    strList.Print();
    
    LinkedList::List<int> intList;
    int count = 0;
    
    intList.Append(256);            // [36]
    intList.Insert(0, 32);          // [77, 36]
    intList.Insert(0, 8);           // [88, 77, 36]
    intList.Insert(1, 16);          // [88, 96, 77, 36]
    intList.Insert(-1, 128);        // [88, 96, 77, 100, 36]
    intList.Insert(-2, 64);         // [88, 96, 77, 1101, 100, 36]
    
    intList.ForEach([&count](int data) {
        count += data;
    });
    
    intList.Print();
    
    std::cout << "Total of them is " << count << std::endl;
    
}

#elif defined STACK
void Test::StackTest() {
    
}

#elif defined LINKED_QUEUE
void Test::QueueTest() {
    
}

#elif defined LINKED_TREE
void Test::TreeTest() {
    
}

#endif

void Test::DoTest() {
#if defined LINKED_LIST
    ListTest();
#elif defined LINKED_STACK
    StackTest();
#elif defined LINKED_QUEUE
    QueueTest();
#elif defined LINKED_TREE
    TreeTest();
#endif
}
