%{
%}

%pure-parser
%define parse.error verbose
%lex-param {void* scanner}
%parse-param {PSLCompilerContext* pContext}

%union {
	int symIndex;
    ASTNode* pNode;
}

%locations

%token SEMICOLON
%token LEFT_PAREN
%token RIGHT_PAREN
%token LT
%token GT
%token WORD_TOKEN
%token <symIndex> IDENTIFIER
%type <pNode> expression

%%

translation_unit:
      expression LT expression
    ;

expression:
      IDENTIFIER                                                    { $$ = new IdentifierNode(); }
    | IDENTIFIER LT WORD_TOKEN GT LEFT_PAREN RIGHT_PAREN            { $$ = new FunctionCallNode(); }
    ;

%%
