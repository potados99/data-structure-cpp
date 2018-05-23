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

#define ERROR(message) \
    _DEBUG_PIN \
    std::cout << message << std::endl; \
    exit(1);

#endif /* debug_h */

/* common */
#if defined _DEBUG_MSG_FOR_LIST
#define _LIST_EMPTY "List is empty."
#define _NODE_NULL "Node is null."
#define _INDEX_OUT "Index is out of range."
#endif

#if defined _DEBUG_MSG_FOR_STACK
#define _INIT_SIZE_INVALID "Initial size cannot have negative value."
#define _ALLOC_FAILED "Allocation failed."
#define _STACK_EMPTY "Stack is empty"
#endif

#ifdef _DEBUG_MSG_FOR_QUEUE
#endif

#ifdef _DEBUG_MSG_FOR_TREE
#endif
