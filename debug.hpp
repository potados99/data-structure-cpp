//
//  demo.hpp
//  data-structure
//
//  Created by POTADOS on 2018. 5. 20..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef debug_h
#define debug_h

#ifdef DEBUG

#define ERROR_FORMAT "In file %s, line %d\n", __FILE__, __LINE__
#define DEBUG_PIN fprintf(stderr, ERROR_FORMAT);

#else

#define DEBUG_PIN

#endif

#define LIST_EMPTY "List is empty."
#define NODE_NULL "Node is null."
#define INDEX_OUT "Index is out of range."

#define Error(message) \
    DEBUG_PIN \
    std::cout << message << std::endl; \
    exit(1)

#endif /* debug_h */
