//
//  LinkedList.cpp
//  cpp-test
//
//  Created by POTADOS on 2018. 5. 19..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef SingleLinkedListTP_hpp
#define SingleLinkedListTP_hpp

#include "SingleLinkedList.hpp"

#ifndef DEBUG_PIN
#include "debug.hpp"
#endif

namespace SingleLinkedList {
    
#pragma mark ListNode - public
    template <typename Element>
    ListNode<Element>::ListNode() {
        this->next = nullptr;
    }
    
    template <typename Element>
    ListNode<Element>::ListNode(Element data) {
        this->data = data;
        this->next = nullptr;
    }
    
    template <typename Element>
    ListNode<Element>::ListNode(Element data, ListNode * next) {
        this->data = data;
        this->next = next;
    }
    
    template <typename Element>
    ListNode<Element>::~ListNode() {
    }
    
    
#pragma mark List - public
    template <typename Element>
    List<Element>::List() {
        this->head = nullptr;
    }
    
    template <typename Element>
    List<Element>::List(ListNode<Element> * head) {
        this->head = head;
    }
    
    template <typename Element>
    List<Element>::~List() {
        ListNode<Element> * nextNode;
        for (ListNode<Element> * currentNode = this->head;
             currentNode != nullptr;
             currentNode = nextNode) {
            nextNode = currentNode->next;
            delete currentNode;
        }
    }
    
    template <typename Element>
    bool List<Element>::IsEmpty() {
        return (head == nullptr);
    }
    
    template <typename Element>
    void List<Element>::Append(Element data) {
        if (IsEmpty()) {
            this->head = new ListNode<Element>(data);
            return;
        }
        
        ListNode<Element> * lastNode = GetLastNode();
        ListNode<Element> * newNode = new ListNode<Element>(data);
        
        lastNode->next = newNode;
    }
    
    template <typename Element>
    void List<Element>::Insert(Element data, int index) {
        
    }
    
    template <typename Element>
    void List<Element>::ForEach(std::function<void(Element)> action) {
        if (IsEmpty()) {
            Error(LIST_EMPTY);
        }
        for (ListNode<Element> * currentNode = head;
             currentNode != nullptr;
             currentNode = currentNode->next) {
            action(currentNode->data);
        }
    }
    
    template <typename Element>
    void List<Element>::Print() {
        if (IsEmpty()){
            Error(LIST_EMPTY);
        }
        for (ListNode<Element> * currentNode = head;
             currentNode != nullptr;
             currentNode = currentNode->next) {
            std::cout << currentNode->data << std::endl;
        }
    }
    
    template <typename Element>
    Element List<Element>::Pop(int targetIndex) {
        
    }
    
    template <typename Element>
    Element List<Element>::operator[](int targetIndex) {
        if (IsEmpty()) {
            Error(LIST_EMPTY);
        }
        if (targetIndex > Length) {
            Error(INDEX_OUT);
        }
        
        return GetItemAtIndex(targetIndex);
    }
    
#pragma mark List - private
    template <typename Element>
    ListNode<Element> * List<Element>::GetLastNode() {
        if (IsEmpty()) {
            Error(LIST_EMPTY);
        }
        ListNode<Element> * currentNode = this->head;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
        return currentNode;
    }
    
    template <typename Element>
    Element List<Element>::GetItemAtIndex(int targetIndex) {
        int currentIndex = 0;
        ListNode<Element> * currentNode = head;
        while (currentIndex < targetIndex) {
            if (currentNode == nullptr) {
                Error(NODE_NULL);
            }
            
            currentIndex += 1;
            currentNode = currentNode->next;
        }
        return currentNode->data;
    }
}

#endif /* SingleLinkedListTP_hpp */
