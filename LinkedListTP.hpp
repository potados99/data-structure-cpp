//
//  SingleLinkedList.cpp
//  cpp-test
//
//  Created by POTADOS on 2018. 5. 19..
//  Copyright © 2018 POTADOS. All rights reserved.
//

#ifndef LinkedListTP_hpp
#define LinkedListTP_hpp

#include "LinkedList.hpp"

#ifndef _DEBUG_PIN
#define _DEBUG_MSG_FOR_LIST
#include "debug.hpp"
#endif

namespace LinkedList {
    
#pragma mark ListNode
    // Public
    //
    //
    template <typename Element>
    Element ListNode<Element>::_Data() {
        return _data;
    }

    template <typename Element>
    ListNode<Element> * ListNode<Element>::_Prev() {
        return _prev;
    }
    
    template <typename Element>
    ListNode<Element> * ListNode<Element>::_Next() {
        return _next;
    }

    template <typename Element>
    void ListNode<Element>::_SetData(Element data) {
        _data = data;
    }
    
    template <typename Element>
    void ListNode<Element>::_SetPrev(ListNode * prev) {
        _prev = prev;
    }
    
    template <typename Element>
    void ListNode<Element>::_SetNext(ListNode * next) {
        _next = next;
    }
    
    template <typename Element>
    ListNode<Element>::ListNode() {
        this->_prev = nullptr;
        this->_next = nullptr;
    }
    
    template <typename Element>
    ListNode<Element>::ListNode(Element data) {
        this->_data = data;
        this->_prev = nullptr;
        this->_next = nullptr;
    }
    
    template <typename Element>
    ListNode<Element>::ListNode(Element data, ListNode * next) {
        this->_data = data;
        this->_prev = nullptr;
        this->_next = next;
    }
    
    template <typename Element>
    ListNode<Element>::ListNode(Element data, ListNode * prev, ListNode * next) {
        this->_data = data;
        this->_prev = prev;
        this->_next = next;
    }

    template <typename Element>
    ListNode<Element>::~ListNode() {
    }

    
#pragma mark List
    // Public
    //
    //
    template <typename Element>
    List<Element>::List() {
        this->_head = nullptr;
        this->_lastNode = nullptr;
        this->_length = 0;
    }
    
    template <typename Element>
    List<Element>::List(ListNode<Element> * head) {
        this->_head = head;
        this->_lastNode = head;
        this->_length = 1;
    }

    template <typename Element>
    List<Element>::~List() {
        ListNode<Element> * nextNode;
        for (_currentNode = this->_head;
             _currentNode != nullptr;
             _currentNode = nextNode) {
            nextNode = _currentNode->_Next();
            delete _currentNode;
        }
    }

    
    template <typename Element>
    bool List<Element>::IsEmpty() {
        return (this->_head == nullptr);
    }
    
    template <typename Element>
    void List<Element>::Append(Element data) {
        if (IsEmpty()) {
            this->_head = new ListNode<Element>(data);
            this->_lastNode = this->_head;
            ++ _length;
            return;
        }
        
        ListNode<Element> * newNode = new ListNode<Element>(data, _lastNode, nullptr);
        
        _lastNode->_SetNext(newNode);
        _lastNode = newNode;
        
        ++ _length;
    }
    
    template <typename Element>
    void List<Element>::Insert(int index, Element data) {
        if (IsEmpty()) {
            Error(LIST_EMPTY);
        }
        
        unsigned int targetIndex = _GetSafeIndex(index);
        
        if (targetIndex == 0) {
            _head->_SetPrev(new ListNode<Element>(data, nullptr, _head)) ;
            _head = _head->_Prev();
            ++ _length;
            return;
        }

        ListNode<Element> * beforeNode = _GetNodeAtIndex(targetIndex)->_Prev();
        ListNode<Element> * nextNode = beforeNode->_Next();
        ListNode<Element> * newNode = new ListNode<Element>(data, beforeNode, nextNode);
        
        beforeNode->_SetNext(newNode);
        nextNode->_SetPrev(newNode);
        ++ _length;
    }
    
    template <typename Element>
    Element List<Element>::Pop(int targetIndex) {
        
    }
    
    template <typename Element>
    void List<Element>::Delete(int targetIndex) {
        
    }
    
    template <typename Element>
    void List<Element>::ForEach(std::function<void(Element)> action) {
        if (IsEmpty()) {
            Error(LIST_EMPTY);
        }
        
        for (_currentNode = _head;
             _currentNode != nullptr;
             _currentNode = _currentNode->_Next()) {
            action(_currentNode->_Data());
        } _currentNode = _head;
        
    }

    template <typename Element>
    void List<Element>::Print() {
        if (IsEmpty()){
            Error(LIST_EMPTY);
        }
        
        std::cout << "[";
        _ForEachNode([this](ListNode<Element> * node) {
            std::cout << node->_Data();
            
            if (node != this->_lastNode)
                std::cout << ", ";
        });
        std::cout << "]" << std::endl;

    }
    
    template <typename Element>
    int List<Element>::Length() {
        return _length;
    }
    
    template <typename Element>
    Element List<Element>::operator[](int targetIndex) {
        return _GetItemAtIndex(targetIndex);
    }
    

    // Private
    //
    //
    template <typename Element>
    ListNode<Element> * List<Element>::_GetNodeAtIndex(int index) {
        if (IsEmpty()) {
            Error(LIST_EMPTY);
        }
        
        unsigned int targetIndex = _GetSafeIndex(index);
        
        if (targetIndex > _length) {
            Error(INDEX_OUT);
        }
        
        int currentIndex = 0;
        _currentNode = _head;
        
        while (currentIndex < targetIndex) {
            if (_currentNode == nullptr) {
                Error(NODE_NULL);
            }
            
            currentIndex += 1;
            _currentNode = _currentNode->_Next();
        }
        
        return _currentNode;
    }
    
    template <typename Element>
    Element List<Element>::_GetItemAtIndex(int index) {
        return _GetNodeAtIndex(_GetSafeIndex(index))->_Data();
    }
    
    template <typename Element>
    unsigned int List<Element>::_GetSafeIndex(int unsafeIndex) {
        unsigned int safeIndex = 0;
        
        if (unsafeIndex < 0) {
            if ((unsafeIndex * -1) > _length) {
                Error(INDEX_OUT);
            }
            safeIndex = _length + unsafeIndex;
        } else {
            if (unsafeIndex > _length - 1) {
                Error(INDEX_OUT);
            }
            safeIndex = unsafeIndex;
        }
        
        return safeIndex;
    }
    
    template <typename Element>
    void List<Element>::_ForEachNode(std::function<void(ListNode<Element> *)> action) {
        if (IsEmpty()) {
            Error(LIST_EMPTY);
        }
        
        for (_currentNode = _head;
             _currentNode != nullptr;
             _currentNode = _currentNode->_Next()) {
            action(_currentNode);
        } _currentNode = _head;
    }

}

#endif /* LinkedListTP_hpp */
