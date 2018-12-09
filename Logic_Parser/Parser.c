//
//  Parser.c
//  Logic_Parser
//
//  Created by Cecilia Zhang on 12/7/18.
//  Copyright © 2018 Cecilia Zhang. All rights reserved.
//

#include "Parser.h"


Parser new_Parser(char * input){
    Parser this=(Parser)malloc(sizeof(struct Parser));
    this->input=input;
    this->root= E (this);
    return this;
}

Node E(Parser this){
    Node yy = T(this);
    if(yy == NULL) return NULL;
    Node yyy = TT(this);
    if(yyy == NULL)return NULL;
    Node x = new_Node('E');
    
    Node y[]={yy,yyy};
    Node_add_Children(x, y,2);
    return x;
}

Node T(Parser this){
    
    Node yy = F(this);
    if(yy==NULL)return NULL;
    Node yyy = FT(this);
    if(yyy==NULL)return NULL;
    Node x=new_Node('T');
    Node y[]={yy,yyy};
    Node_add_Children(x, y,2);
    return x;
    
}

Node FT(Parser this){
    
    if (rdp_matchTerminal(this, '*')){
        Node yy = F(this);
        if(yy==NULL)return NULL;
        Node yyy=FT(this);
        if(yyy==NULL)return NULL;
        Node x=new_Node('f');
        Node sign=new_Node('*');
        Node y[]={sign,yy,yyy};
        Node_add_Children(x, y, 3);
        return x;
        
    }else {
        Node x=new_Node('f');
        Node y[]={new_Node('e')};
        Node_add_Children(x, y,1);
        return x;
    }
}

Node F (Parser this){
    if(rdp_matchTerminal(this, '(')){
        Node yy =E(this);
        if(yy==NULL)return NULL;
        if(!rdp_matchTerminal(this, ')'))return NULL;
        Node x=new_Node('F');
        Node xx=new_Node('(');
        Node xxx=new_Node(')');
        Node y[]={xx,yy,xxx};
        Node_add_Children(x, y,3);
        return x;
        
    } else if(rdp_matchTerminal(this, '!')){
        Node yy =E(this);
        if(yy==NULL)return NULL;
        Node x=new_Node('F');
        Node sign=new_Node('!');
        Node y[]={sign,yy};
        Node_add_Children(x, y, 2);
        return x;
    }else{
        Node yy= N (this);
        if(yy==NULL)return NULL;
        Node x=new_Node('F');
        Node y[]={yy};
        Node_add_Children(x, y,1);
        return x;
    }
}

Node N (Parser this){
    switch (rdp_lookahead2(this)) {
        case 'T':
            rdp_matchTerminal(this, 'T');
            Node x=new_Node('N');
            Node y[]={new_Node('T')};
            Node_add_Children(x, y, 1);
            return x;
            
        case 'F':
            rdp_matchTerminal(this, 'F');
            Node x1=new_Node('N');
            Node y1[]={new_Node('F')};
            Node_add_Children(x1, y1, 1);
            return x1;
        default:
            return NULL;
    }
}

Node TT(Parser this){
    
    if (rdp_matchTerminal(this, '+')){
        Node yy = T(this);
        if(yy==NULL)return NULL;
        Node yyy=TT(this);
        if(yyy==NULL)return NULL;
        Node x= new_Node('t');
        Node sign= new_Node('+');
        Node y[]={sign,yy,yyy};
        Node_add_Children(x, y,3);
        return x;
        
    } else {
        Node x=new_Node('t');
        Node y[]={new_Node( 'e')};
        Node_add_Children(x, y, 1);
        return x;
    }
}

int rdp_matchTerminal(Parser this, char c){
    if( *this->input==c){
        this->input++;
        return 1;
    }else{
        return 0;
    }
}

char rdp_lookahead2(Parser this){
    return *this -> input;
}

void RDP_free(Parser this){
    free(this);
}

