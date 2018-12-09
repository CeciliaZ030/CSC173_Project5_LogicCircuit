//
//  main.c
//  Logic_Parser
//
//  Created by Cecilia Zhang on 12/7/18.
//  Copyright © 2018 Cecilia Zhang. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "Parser.h"
#include "Node.h"

void removeNewLine(char* i);
void removeNewLine(char* i){
    long length=strlen(i);
    if(i[length-1]=='\n'){
        i[length-1]='\0';
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char str [256];
    printf("----------Enter an input (\"quit\" to quit): ");
    fgets(str,255,stdin);
    removeNewLine(str);
    if(strcmp(str,"quit")==0){
        return 0;
    }
    //input:str
    printf("\n-----Recursive-descent parser...\n");
    Parser RDP1 = new_Parser(str);
    if(RDP1->root==NULL){
        printf("Not a well-formed input\n");
    }
    else{
        
        print_Tree(RDP1->root);
    }
    
    return 0;
}
