//
//  main.cpp
//  cpp-test
//
//  Created by POTADOS on 2018. 5. 17..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#define SINGLE_LINKED_LIST
// #define STACK
// #define QUEUE
// #define TREE



#include "Test.hpp"

int main(int argc, const char * argv[]) {
    Test tester;

    tester.SetTest();
    tester.DoTest();
    return 0;
}




#if defined SINGLE_LINKED_LIST || DUAL_LINKED_LIST
void Test::ListTest() {
    List<std::string> strList;
    List<ListNode<int>> objectList;
    
    // Appending to string list
    std::string str = "Test String";
    for (int i = 0; i < 10; ++ i ) {
        strList.Append(str);
        str.append("!");
    }
    
    // Appending to object list
    for (int i = 0; i < 10; ++ i )
        objectList.Append(ListNode<int>(i, nullptr));
    
    // Testing ForEach method
    strList.ForEach([](std::string data) {
        std::cout << data << std::endl;
    });
    
    objectList.ForEach([](ListNode<int> node) {
        std::cout << node.data << std::endl;
    });
}
#elif defined STACK
void Test::StackTest() {
    
}
#endif



void Test::SetTest() {
#if defined SINGLE_LINKED_LIST || defined DUAL_LINKED_LIST
    this->TestFunction = this->ListTest;
#elif defined STACK
    //~~
#endif
}

void Test::DoTest() {
    this->TestFunction();
}
