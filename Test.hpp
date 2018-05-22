//
//  demo.h
//  data-structure
//
//  Created by POTADOS on 2018. 5. 22..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef Test_h
#define Test_h


#ifdef SINGLE_LINKED_LIST
#include "SingleLinkedList.hpp"
using namespace SingleLinkedList;

#elif defined DUAL_LINKED_LIST
#include "DualLinkedList.hpp"
using namespace DualLinkedList;

#endif

#include <iostream>

class Test {
private:
    void (*TestFunction)(void);
    static void ListTest();
    static void StackTest();
    static void QueueTest();
    static void TreeTest();
public:
    void SetTest();
    void DoTest();
};

#endif /* Test_h */
