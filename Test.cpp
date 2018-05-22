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
using namespace LinkedList;

#elif defined STACK

#endif

#if defined LINKED_LIST
void Test::ListTest() {
    
    List<std::string> strList;
    
    strList.Append("Hello");
    strList.Append("World");
    strList.Append("!");
    
    strList.Print();
    
    List<int> intList;
    int count = 0;
    
    // Inserting to int list
    intList.Append(36);             // [36]
    intList.Insert(0, 77);          // [77, 36]
    intList.Insert(0, 88);          // [88, 77, 36]
    intList.Insert(1, 96);          // [88, 96, 77, 36]
    intList.Insert(-1, 100);        // [88, 96, 77, 100, 36]
    intList.Insert(-2, 1101);       // [88, 96, 77, 1101, 100, 36]
    
}
#elif defined STACK
void Test::StackTest() {
    
}
#endif

void Test::DoTest() {
#if defined LINKED_LIST
    ListTest();
#elif defined STACK
    StackTest();
#endif
}
