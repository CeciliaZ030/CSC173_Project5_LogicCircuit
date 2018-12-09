//
//  Parser.h
//  Logic_Parser
//
//  Created by Cecilia Zhang on 12/7/18.
//  Copyright © 2018 Cecilia Zhang. All rights reserved.
//

#ifndef Parser_h
#define Parser_h

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

typedef struct Parser *Parser;
struct Parser{
    char * input;
    Node root;
};

extern Parser new_Parser(char * input);

extern Node E(Parser this);

extern Node F (Parser this);

extern Node FT(Parser this);

extern Node T(Parser this);

extern Node TT(Parser this);

extern Node N (Parser this);

extern char rdp_lookahead2(Parser this);

extern int rdp_matchTerminal(Parser this, char c);

extern void RDP_free(Parser this);

#endif /* Parser_h */
