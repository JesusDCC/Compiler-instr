typedef enum {I_LABEL, I_GOTO, I_ATRIB, I_PLUS, I_MINUS, I_MULT, I_DIV, I_IFG, I_IFL, I_IFGE, I_IFLE, I_IFEQ, I_IFNEQ, I_PRINT, I_PRINTT} I_Kind;

typedef struct{
	enum{
		A_STRING,
		A_INT
	}kind;
	union{
		int value;
		char *name;
	}                                                    
}Atom;


typedef struct{
  I_Kind ikind;
  union{ 
    struct{
      int operator;   
      Atom* a1;
      Atom* a2;
      char* label1;
      char* label2;
    } i_if;
    struct{
      char* label1;
    } label;
    struct{
      Atom* a1; // variavel
      Atom* a2; // valor
    } atrib;
    struct{
      char* label1;
    } i_goto;
    struct{
      int operator;
      Atom* a1;
      Atom* a2;
      Atom* a3;
    } op;
    struct{
      Atom* a1;   
    } print;
    struct {
      Atom* a1;
      Atom* a2;
    }printt;   
  } attr;
} Instr;

