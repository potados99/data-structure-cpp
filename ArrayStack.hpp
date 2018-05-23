//
//  ArrayStack.hpp
//  data-structure-cpp
//
//  Created by POTADOS on 2018. 5. 23..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef ArrayStack_hpp
#define ArrayStack_hpp

#include <iostream>
#include <cstdlib>

namespace ArrayStack {
    
    template <typename Element>
    class Stack {
        
    private:
        Element *   _array;
        int         _top;
        int         _arraySize;
        
    public:
        Stack();
        Stack(const int initialSize);
        ~Stack();
        
        bool        IsEmpty();
        void        Push(Element data);
        Element     Pop();
        int         Size();
    };
    
}

#include "ArrayStackTP.hpp"

#endif /* ArrayStack_hpp */
