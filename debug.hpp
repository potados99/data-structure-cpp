//
//  debug.hpp
//  data-structure
//
//  Created by POTADOS on 2018. 5. 20..
//  Copyright © 2018 POTADOS. All rights reserved.
//

#ifndef debug_h
#define debug_h

#ifdef DEBUG

#define _ERROR_FORMAT "In file %s, line %d\n", __FILE__, __LINE__
#define _DEBUG_PIN fprintf(stderr, _ERROR_FORMAT);

#else

#define _DEBUG_PIN

#endif


#ifdef _DEBUG_MSG_FOR_LIST
#define LIST_EMPTY "List is empty."
#define NODE_NULL "Node is null."
#define INDEX_OUT "Index is out of range."

#elif defined _DEBUG_MSG_FOR_STACK

#elif defined _DEBUG_MSG_FOR_QUEUE

#elif defined _DEBUG_MSG_FOR_TREE

#endif


#define Error(message) \
    _DEBUG_PIN \
    std::cout << message << std::endl; \
    exit(1)

#endif /* debug_h */
