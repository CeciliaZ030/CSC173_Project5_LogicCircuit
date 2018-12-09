//
//  Node.h
//  Project2
//
//  Created by Junkang Gu on 10/10/18.
//  Copyright © 2018 Junkang Gu. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>



typedef struct Node *Node;
struct Node{
    char element;
    struct Node* children[5];
    int childNum;
    Node parent;
    int depth;
    int nthChild;
};

void Node_add_Children_By_String(Node this, char* children);

extern Node new_Node(char c);

extern void Node_add_Children(Node node, Node* children, int numOfChildren);

extern void print_Tree(Node node);

extern Node find_Left_Most_Nonterminal_Leaf(Node node);

extern Node find_Next_Sibling(Node node);

extern char begin_With(Node node);

extern double evaluate(Node node);

extern void free_Node(Node this);
#endif /* Node_h */
