//
//  Test.hpp
//  data-structure
//
//  Created by POTADOS on 2018. 5. 22..
//  Copyright © 2018 POTADOS. All rights reserved.
//

#ifndef Test_h
#define Test_h

// **
// You can uncomment at least one line below:
 #define LINKED_LIST
// #define LINKED_STACK
// #define LINKED_QUEUE
// #define LINKED_TREE
// **

#if !(defined LINKED_LIST || defined LINKED_STACK || defined LINKED_QUEUE || defined LINKED_TREE)
#error Please uncomment at least one line in Test.hpp
#endif

#include <iostream>

class Test {
private:
    static void ListTest();
    static void StackTest();
    static void QueueTest();
    static void TreeTest();
public:
    static void DoTest();
};

#endif /* Test_h */
