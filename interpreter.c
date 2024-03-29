#include <stdio.h>
#include "parser.h"
#include "printAbsTree.h"
#include "code.h"

/*
extern FILE *yyin;
extern FILE *yyout;
extern int yyparse(void);
 
/*int eval(Expr* expr) {
  int result = 0;
  if (expr == 0) {
    yyerror("Null expression!!");
  }
  else if (expr->kind == E_INTEGER) {
    result = expr->attr.value; 
  } 
  else if (expr->kind == E_OPERATION) {
    int vLeft = eval(expr->attr.op.left);
    int vRight = eval(expr->attr.op.right);
    switch (expr->attr.op.operator) {
      case PLUS: 
        result = vLeft + vRight; 
        break;
      // TODO Other cases here ...
      default: yyerror("Unknown operator!");
    }
  }
  return result;
}*/ 

int main(int argc, char** argv) {
  --argc; ++argv;
  if (argc != 0) {
    yyin = fopen(*argv, "r");
    if (!yyin) {
      printf("'%s': could not open file\n", *argv);
      return 1;
    }
  } //yyin = stdin

  if (yyparse() == 0) {
    //printf("Result = %d\n", evalExpr(root,0));
    //evalCmdList(root,0);
    //printListIntrs(compileCmdList(root));
    
    printListIntrs(compileCmdList(root));

    /*LIST* l1 = compileCmd(root->cmd);
    LIST* l2 = compileCmd(root->next->cmd);
    LIST* l3 = append(l1,l2);
    printListIntrs(l3);*/

    /*while(root->cmd!=NULL){
      printInstr(compileCmd(root->cmd)->instr);
      if(root->next==NULL) break;
      root = root->next;
    }*/
      
  }
  return 0;
}


/*int main(int argc, char** argv) {
  --argc; ++argv;
  if (argc != 0) {
    yyin = fopen(*argv, "r");
    /*if (!yyin) {
      printf("'%s': could not open file\n", *argv);
      return 1;
    }
  } //  yyin = stdin
  printf("fn main(){\n");

      if(yyparse() == 0) {
        while(root->cmd!=NULL){    
          print(root->cmd,4);
          if(root-> next ==NULL) break;
            root = root->next;
        }
    printf("}\n");
  }
    
  return 0;


} */
