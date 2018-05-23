//
//  ArrayStack.cpp
//  data-structure-cpp
//
//  Created by POTADOS on 2018. 5. 23..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef ArrayStackTP_hpp
#define ArrayStackTP_hpp

#define _DEBUG_MSG_FOR_STACK
#include "debug.hpp"

#define _DEFAULT_STACK_SIZE 5

namespace ArrayStack {
    
    template <typename Element>
    Stack<Element>::Stack() {
        _array = (Element *)malloc(sizeof(Element) * _DEFAULT_STACK_SIZE);
        _top = _DEFAULT_STACK_SIZE - 1;
        _arraySize = _DEFAULT_STACK_SIZE;
    }
    
    template <typename Element>
    Stack<Element>::Stack(const int initialSize) {
        if (initialSize < 0) {
            ERROR(_INIT_SIZE_INVALID)
        }
        _array = (Element *)malloc(sizeof(Element) * initialSize);
        _top = initialSize - 1;
        _arraySize = initialSize;
    }
    
    template <typename Element>
    Stack<Element>::~Stack() {
        free(_array);
        _array = nullptr;
    }
    
    template <typename Element>
    bool Stack<Element>::IsEmpty() {
        return (_top == -1);
    }
    
    template <typename Element>
    void Stack<Element>::Push(Element data) {
        if (_top + 1 == _arraySize) {
            _array = (Element *)realloc(_array, sizeof(Element) * ++ _arraySize);
        }
        if (! _array) {
            ERROR(_ALLOC_FAILED)
        }
        
        *(_array + (++ _top)) = data;
    }
    
    template <typename Element>
    Element Stack<Element>::Pop() {
        if (IsEmpty()) {
            ERROR(_STACK_EMPTY)
        }
        Element data = *(_array + _top);
        *(_array + (_top --)) = '\0';
        return data;
    }
    
    template <typename Element>
    int Stack<Element>::Size() {
        return _top + 1;
    }
}


#endif /* ArrayStackTP_hpp */
