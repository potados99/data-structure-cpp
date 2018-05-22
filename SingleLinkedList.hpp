//
//  LinkedList.hpp
//  cpp-test
//
//  Created by POTADOS on 2018. 5. 19..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef SingleLinkedList_hpp
#define SingleLinkedList_hpp

#include <iostream>

namespace SingleLinkedList {
    
#pragma mark Template class declarations
    template <typename Element>
    class ListNode {
    public:
        Element data;
        ListNode<Element> * next;
        
        ListNode();
        ListNode(Element data);
        ListNode(Element data, ListNode * next);
        ~ListNode();
    };
    
    template <typename Element>
    class List {
    private:
        ListNode<Element> * head;
        ListNode<Element> * GetLastNode();
        Element GetItemAtIndex(int targetIndex);
    public:
        int Length;
        
        List();
        List(ListNode<Element> * head);
        ~List();
        
        bool IsEmpty();
        void Append(Element data);
        void Insert(Element data, int targetIndex);
        void ForEach(std::function<void(Element)> action);
        void Print();
        
        Element Pop(int targetIndex);
        
        Element operator[](int targetIndex);
    };
    
}

#include "SingleLinkedListTP.hpp"

#endif /* SingleLinkedList_hpp */
