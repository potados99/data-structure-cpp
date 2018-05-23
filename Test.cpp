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

#elif defined ARRAY_STACK
#include "ArrayStack.hpp"

#elif defined LINKED_STACK
#include "LinkedStack.hpp"

#elif defined LINKED_QUEUE
#include "LinkedQueue.hpp"

#elif defined LINKED_TREE
#include "LinkedTree.hpp"

#endif

#if defined LINKED_LIST
void Test::ListTest() {
//
//    LinkedList::List<std::string> strList;
//
//    strList.Append("Hello");
//    strList.Append("World");
//    strList.Append("!");
//    strList.Insert(0, "I say: ");
//
//    strList.Print();
//
    
    LinkedList::List<int> intList;
    int count = 0;
    
    intList.Append(256);
    intList.Insert(0, 32);
    intList.Insert(0, 8);
    intList.Insert(1, 16);
    intList.Insert(-1, 128);
    intList.Insert(-2, 64);
    
    intList.ForEach([&count](int data) {
        count += data;
    });
    
    intList.Print();
    
    std::cout << "Total of them is " << count << std::endl;
    
}

#elif defined ARRAY_STACK || defined LINKED_STACK
void Test::StackTest() {
    ArrayStack::Stack<int> intStack(0);
    
    for (int i = 0; i < 20; ++ i) {
        intStack.Push(i);
    }

    for (int i = 0; i < 20; ++ i) {
        std::cout << intStack.Pop() << std::endl;
    }

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
    
#elif defined ARRAY_STACK || defined LINKED_STACK
    StackTest();
    
#elif defined LINKED_QUEUE
    QueueTest();
    
#elif defined LINKED_TREE
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
