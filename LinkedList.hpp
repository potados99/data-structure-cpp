//
//  LinkedList.hpp
//  cpp-test
//
//  Created by POTADOS on 2018. 5. 19..
//  Copyright © 2018 POTADOS. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>
#include <functional>
#include <string>

namespace LinkedList {
    
    template <typename Element>
    class ListNode {
        
    private:
        Element                 _data;
        ListNode *              _prev;
        ListNode *              _next;
        
    public:
        
        Element                 _Data(void);
        ListNode *              _Prev(void);
        ListNode *              _Next(void);
        void                    _SetData(Element data);
        void                    _SetPrev(ListNode * prev);
        void                    _SetNext(ListNode * next);
        
        ListNode();
        ListNode(Element data);
        ListNode(Element data, ListNode * next);
        ListNode(Element data, ListNode * prev, ListNode * next);
        ~ListNode();
        
    };
    
    template <typename Element>
    class List {
        
    private:
        ListNode<Element> *     _head;
        ListNode<Element> *     _currentNode;
        ListNode<Element> *     _lastNode;
        unsigned int            _length;
        
        ListNode<Element> *     _GetNodeAtIndex(int index);
        Element                 _GetItemAtIndex(int index);
        unsigned int            _GetSafeIndex(int unsafeIndex);
        void                    _ForEachNode(std::function<void(ListNode<Element> *)> action);
        
    public:
        List();
        List(ListNode<Element> * head);
        ~List();
        
        bool                    IsEmpty();
        void                    Append(Element data);
        void                    Insert(int index, Element data);
        Element                 Pop(int index);
        void                    Delete(int index);
        void                    ForEach(std::function<void(Element)> action);
        void                    Print();
        int                     Length();
        Element                 operator[](int index);
    };
    
}

#include "LinkedListTP.hpp"

#endif /* LinkedList_hpp */
