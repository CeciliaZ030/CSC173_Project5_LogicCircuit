//
//  Node.c
//  Project2
//
//  Created by Junkang Gu on 10/10/18.
//  Copyright © 2018 Junkang Gu. All rights reserved.
//

#include "Node.h"
#include <stdlib.h>

Node new_Node(char c){
    Node this=(Node) malloc(sizeof(struct Node));
    this->element=c;
    this -> childNum = 0;
    for(int i=0; i<5;i++){
        this->children[i]=NULL;
    }
    this->depth=0;
    this->parent=NULL;
    this->nthChild=0;
    return this;
}

void Node_add_Children(Node this, Node* children, int numOfChildren){
    int start=this->childNum;
    for(int i=start;i<start+numOfChildren;i++){
        this->children[i]=children[i-start];
        this->children[i]->parent=this;
        this->children[i]->nthChild=i;
        this -> childNum ++;
    }
}

void Node_add_Children_By_String(Node this, char* children){
    char *i;
    for (i=children; *i; i++) {
        Node child=new_Node(*i);
        Node array[]={child};
        Node_add_Children(this, array, 1);
    }
}
void print_Tree(Node node){
    int name=(int)node->element;
    if(name>=0||name<=256){
        
        for(int i=0; i<node->depth;i++){
            printf("  ");
        }
        printf("%c\n", node -> element);
        
        if ( node -> childNum == 0){
            //
        }else {
            for (int i = 0; i < node -> childNum; i++){
                node->children[i]->depth=node->depth+1;
                print_Tree(node -> children[i]);
            }
        }
        
    }
}

Node find_Next_Sibling(Node node){
    
    int nthChild=node->nthChild;
    if(nthChild>=node->parent->childNum-1){//no more siblings
        return NULL;
    }else{
        return node->parent->children[nthChild+1];
    }
}

char begin_With(Node node){
    if(node->childNum==0)return 'X';
    else
        return node->children[0]->element;
}

double evaluate(Node node){
    
    switch(node->element){
            
        case 'E':{// T TT
            Node T=node->children[0];
            Node TT=node->children[1];
            char c=begin_With(TT);
            switch(c){
                case '+':
                    return evaluate(T)+evaluate(TT);
                    
                    break;
                case '-':
                    return evaluate(T)-evaluate(TT);
                    
                    break;
                default: return evaluate(T);break;
            }
        }
            break;
        case 't':{//+-T TT
            Node T=node->children[1];
            Node TT=node->children[2];
            char c=begin_With(TT);
            switch(c){
                case '+':
                    
                    return evaluate(T)+evaluate(TT);break;
                case '-':
                    
                    return evaluate(T)-evaluate(TT);break;
                default: return evaluate(T);break;
            }
        }
            break;
        case 'T':{//F FT
            Node F=node->children[0];
            Node FT=node->children[1];
            char c=begin_With(FT);
            switch(c){
                case '*':
                    
                    return evaluate(F)*evaluate(FT);break;
                case '/':
                    
                    return evaluate(F)/evaluate(FT);break;
                default: return evaluate(F);break;
            }
        }
            break;
        case 'f':{//*/F FT
            Node F=node->children[1];
            Node FT=node->children[2];
            char c=begin_With(FT);
            switch(c){
                case '*':
                    
                    return evaluate(F)*evaluate(FT);break;
                case '/':
                    
                    return evaluate(F)/evaluate(FT);break;
                default: return evaluate(F);break;
            }
        }
            break;
        case 'F':{// N | (E)
            char c=begin_With(node);
            if(c=='('){
                return evaluate(node->children[1]);
            }else{
                return evaluate(node->children[0]);
            }
        }
            break;
        case 'N':{// D NT
            Node D=node->children[0];
            Node NT=node->children[1];
            
            
            
            if(begin_With(NT)=='e'){
                return evaluate(D);
            }else{
                int compare=1;
                double nt=evaluate(NT);
                // printf("%s%c", "nt:", nt);
                while(compare<=nt){
                    
                    compare*=10;
                    
                    
                }
                return compare*evaluate(D)+evaluate(NT);
            }
        }
            break;
        case 'n':{// N|e
            return evaluate(node->children[0]);
        }
            break;
        case 'D':{
            char x=node->children[0]->element;
            switch (x) {
                case '0':
                    
                    return 0;break;
                case '1':
                    
                    return 1;break;
                case '2':
                    
                    return 2;break;
                case '3':
                    
                    return 3;break;
                case '4':
                    
                    return 4;break;
                case '5':
                    
                    return 5;break;
                case '6':
                    
                    return 6;break;
                case '7':
                    
                    return 7;break;
                case '8':
                    
                    return 8;break;
                case '9':
                    
                    return 9;break;
                    
                default:
                    break;
            }
        }
        default:
            break;
    }
    
    return 0;
}

void free_Node(Node this){
    this -> childNum = 0;
    for(int i=0; i<5;i++){
        free(this->children[i]);
    }
    free(this->children);
    free(this);
}

