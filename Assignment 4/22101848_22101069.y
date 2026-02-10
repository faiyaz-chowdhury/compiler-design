%{

#include "symbol_table.h"
#include "ast.h"
#include "three_addr_code.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

/* Type definition for all grammar symbols */
#define YYSTYPE symbol_info*

extern FILE *yyin;
int yyparse(void);
int yylex(void);
extern YYSTYPE yylval;

symbol_table *sym_tbl = new symbol_table();
ProgramNode* program_root = new ProgramNode();

int line_count = 1;
int error_count = 0;
ofstream log_file, error_file, code_file;

string variable_list=""; //for variable declaration tracking
vector<string>parameter_types; //for parameter types in func dec and def
vector<string>parameter_names; //for func def parameter names	
vector<string>argument_types; //to store types of function arguments

int inside_function = 0; //is compound statement inside function definition

string return_data_type, function_name, function_return_type;

void yyerror(char *s)
{
	log_file<<"At line "<<line_count<<" "<<s<<endl<<endl;
	error_file<<"At line "<<line_count<<" "<<s<<endl<<endl;
	error_count++;
	
	variable_list = "";
	parameter_types.clear();
	parameter_names.clear();
	argument_types.clear();
	inside_function = 0;
	return_data_type = "";
	function_name = "";
	function_return_type = "";
}

%}

/* Token declarations */
%token IF ELSE FOR WHILE DO BREAK INT CHAR FLOAT DOUBLE VOID RETURN SWITCH CASE DEFAULT CONTINUE PRINTLN ADDOP MULOP INCOP DECOP RELOP ASSIGNOP LOGICOP NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON CONST_INT CONST_FLOAT ID

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

start : program
	{
		log_file<<"At line no: "<<line_count<<" start : program "<<endl<<endl;
		log_file<<"Symbol Table"<<endl<<endl;
		
		sym_tbl->Print_all_scope(log_file);
		
		$$ = $1;
		// Set root of AST to the program node
		program_root = (ProgramNode*)$1->get_ast_node();
	}
	;

program : program unit
	{
		log_file<<"At line no: "<<line_count<<" program : program unit "<<endl<<endl;
		log_file<<$1->getname()+"\n"+$2->getname()<<endl<<endl;
		
		$$ = new symbol_info($1->getname()+"\n"+$2->getname(),"program");
		
		// Build/update AST node for program
		ProgramNode* prog_node;
		if($1->get_ast_node()) {
			prog_node = (ProgramNode*)$1->get_ast_node();
		} else {
			prog_node = new ProgramNode();
		}
		
		// Append the unit to the program
		if($2->get_ast_node()) {
			prog_node->add_unit($2->get_ast_node());
		}
		
		$$->set_ast_node(prog_node);
	}
	| unit
	{
		log_file<<"At line no: "<<line_count<<" program : unit "<<endl<<endl;
		log_file<<$1->getname()<<endl<<endl;
		
		$$ = new symbol_info($1->getname(),"program");
		
		// Build AST node for program with a single unit
		ProgramNode* prog_node = new ProgramNode();
		if($1->get_ast_node()) {
			prog_node->add_unit($1->get_ast_node());
		}
		$$->set_ast_node(prog_node);
	}
	;

unit : var_declaration
	 {
		log_file<<"At line no: "<<line_count<<" unit : var_declaration "<<endl<<endl;
		log_file<<$1->getname()<<endl<<endl;
		
		$$ = new symbol_info($1->getname(),"unit");
		$$->set_ast_node($1->get_ast_node());
	 }
     | func_definition
     {
		log_file<<"At line no: "<<line_count<<" unit : func_definition "<<endl<<endl;
		log_file<<$1->getname()<<endl<<endl;
		
		$$ = new symbol_info($1->getname(),"unit");
		$$->set_ast_node($1->get_ast_node());
	 }
	 | error
	 {
	 	$$ = new symbol_info("","unit");
	 }
     ;

func_definition : type_specifier id_name LPAREN parameter_list RPAREN enter_func compound_statement
		{	
			log_file<<"At line no: "<<line_count<<" func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement "<<endl<<endl;
			log_file<<$1->getname()<<" "<<$2->getname()<<"("+$4->getname()+")\n"<<$7->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname()+" "+$2->getname()+"("+$4->getname()+")\n"+$7->getname(),"func_def");	
			
			// Build AST node for function definition
			FuncDeclNode* func_node = new FuncDeclNode($1->getname(), $2->getname());
			
			// Add function parameters
			for(int i = 0; i < parameter_types.size(); i++) {
				if(parameter_names[i] != "_null_") {
					func_node->add_param(parameter_types[i], parameter_names[i]);
				}
			}
			
			// Set function body
			if($7->get_ast_node()) {
				func_node->set_body((BlockNode*)$7->get_ast_node());
			}
			
			$$->set_ast_node(func_node);
			
			if(sym_tbl->getID()!=1)
			{
				sym_tbl->Remove_from_table($2->getname());
			}
			
			parameter_types.clear();
			parameter_names.clear();	
		}
		| type_specifier id_name LPAREN RPAREN enter_func compound_statement
		{
			
			log_file<<"At line no: "<<line_count<<" func_definition : type_specifier ID LPAREN RPAREN compound_statement "<<endl<<endl;
			log_file<<$1->getname()<<" "<<$2->getname()<<"()\n"<<$6->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname()+" "+$2->getname()+"()\n"+$6->getname(),"func_def");	
			
			// Build AST node for function definition
			FuncDeclNode* func_node = new FuncDeclNode($1->getname(), $2->getname());
			
			// Set function body
			if($6->get_ast_node()) {
				func_node->set_body((BlockNode*)$6->get_ast_node());
			}
			
			$$->set_ast_node(func_node);
			
			if(sym_tbl->getID()!=1)
			{
				sym_tbl->Remove_from_table($2->getname());
			}
			
			parameter_types.clear();
			parameter_names.clear();	
		}
 		;

enter_func : {
				//not in global scope check
				
				inside_function=1;//compound statement is coming in function definition. enter parameter variables.
				
				if(parameter_types.size()!=0) //validate parameters
				{
					for(int i = 0; i < parameter_types.size();i++)
					{
						if(parameter_names[i]=="_null_")
						{
							error_file<<"At line no: "<<line_count<<" Parameter "<<i+1<<"'s name not given in function definition of "<<function_name<<endl<<endl;
							log_file<<"At line no: "<<line_count<<" Parameter "<<i+1<<"'s name not given in function definition of "<<function_name<<endl<<endl;
							error_count++;
						}
					}
				}
				
				//check if function already exists and perform error checking
				if(sym_tbl->Insert_in_table(function_name,"ID"))
				{
					(sym_tbl->Lookup_in_table(function_name))->setvartype(function_return_type);
					(sym_tbl->Lookup_in_table(function_name))->setidtype("func_def");
					(sym_tbl->Lookup_in_table(function_name))->setparamlist(parameter_types);//set parameters
					(sym_tbl->Lookup_in_table(function_name))->setparamname(parameter_names);
				}
				else
				{
					error_file<<"At line no: "<<line_count<<" Multiple declaration of function "<<function_name<<endl<<endl;
					log_file<<"At line no: "<<line_count<<" Multiple declaration of function "<<function_name<<endl<<endl;
					error_count++;
				}
					
				if((sym_tbl->Lookup_in_table(function_name))->getvartype() != function_return_type)
				{
					error_file<<"At line no: "<<line_count<<" Return type mismatch of function "<<function_name<<endl<<endl;
					log_file<<"At line no: "<<line_count<<" Return type mismatch of function "<<function_name<<endl<<endl;
					error_count++;
				}
            }
            ;

parameter_list : parameter_list COMMA type_specifier ID
		{
			log_file<<"At line no: "<<line_count<<" parameter_list : parameter_list COMMA type_specifier ID "<<endl<<endl;
			log_file<<$1->getname()+","+$3->getname()+" "+$4->getname()<<endl<<endl;
					
			$$ = new symbol_info($1->getname()+","+$3->getname()+" "+$4->getname(),"param_list");
			
			if(count(parameter_names.begin(),parameter_names.end(),$4->getname()))
			{
				error_file<<"At line no: "<<line_count<<" Multiple declaration of variable "<<$4->getname()<<" in parameter of "<<function_name<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" Multiple declaration of variable "<<$4->getname()<<" in parameter of "<<function_name<<endl<<endl;
				error_count++;
			}
			
			parameter_types.push_back($3->getname());
			parameter_names.push_back($4->getname());
		}
		| parameter_list COMMA type_specifier
		{
			log_file<<"At line no: "<<line_count<<" parameter_list : parameter_list COMMA type_specifier "<<endl<<endl;
			log_file<<$1->getname()+","+$3->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname()+","+$3->getname(),"param_list");
			
			parameter_types.push_back($3->getname());
			parameter_names.push_back("_null_");
		}
 		| type_specifier ID
 		{
			log_file<<"At line no: "<<line_count<<" parameter_list : type_specifier ID "<<endl<<endl;
			log_file<<$1->getname()<<" "<<$2->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname()+" "+$2->getname(),"param_list");
			
			parameter_types.push_back($1->getname());
			parameter_names.push_back($2->getname());
		}
		| type_specifier
		{
			log_file<<"At line no: "<<line_count<<" parameter_list : type_specifier "<<endl<<endl;
			log_file<<$1->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname(),"param_list");
			
			parameter_types.push_back($1->getname());
			parameter_names.push_back("_null_");
		}
 		;

compound_statement : LCURL enter_scope_variables statements RCURL
			{ 
 		    	log_file<<"At line no: "<<line_count<<" compound_statement : LCURL statements RCURL "<<endl<<endl;
				log_file<<"{\n"+$3->getname()+"\n}"<<endl<<endl;
				
				$$ = new symbol_info("{\n"+$3->getname()+"\n}","comp_stmnt");
				
				// Set AST node for compound statement
				$$->set_ast_node($3->get_ast_node());
				
				sym_tbl->Print_all_scope(log_file);
			    sym_tbl->exit_scope(log_file);
 		    }
 		    | LCURL enter_scope_variables RCURL
 		    { 
 		    	log_file<<"At line no: "<<line_count<<" compound_statement : LCURL RCURL "<<endl<<endl;
				log_file<<"{\n}"<<endl<<endl;
				
				$$ = new symbol_info("{\n}","comp_stmnt");
				
				// Build empty block node
				BlockNode* empty_block = new BlockNode();
				$$->set_ast_node(empty_block);
				
				sym_tbl->Print_all_scope(log_file);
			    sym_tbl->exit_scope(log_file);
 		    }
 		    ;
enter_scope_variables :
			{
				sym_tbl->enter_scope(log_file);
				
				if(inside_function == 1)
				{
					if(parameter_names.size()!=0)
					{
						for(int i = 0; i < parameter_names.size(); i++)
						{
							if(parameter_names[i]!="_null_")
							{
								sym_tbl->Insert_in_table(parameter_names[i],"ID");
								(sym_tbl->Lookup_in_table(parameter_names[i]))->setidtype("var");
								(sym_tbl->Lookup_in_table(parameter_names[i]))->setvartype(parameter_types[i]);
							}
							
						}
					}
					inside_function=0; //variables entered. if more compound statements come in func definitions, don't re-enter.
				}
				
			}
 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON
		 {
			log_file<<"At line no: "<<line_count<<" var_declaration : type_specifier declaration_list SEMICOLON "<<endl<<endl;
			log_file<<$1->getname()<<" "<<variable_list<<";"<<endl<<endl;
			
			$$ = new symbol_info($1->getname()+" "+variable_list+";","var_dec");
			
			if($1->getname()=="void")
			{
				error_file<<"At line no: "<<line_count<<" variable type can not be void "<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" variable type can not be void "<<endl<<endl;
				error_count++;
				$1 = new symbol_info("error","type"); //variable declared void so pass error instead
			}
			
			// Build AST node for variable declaration
			DeclNode* declaration_node = new DeclNode($1->getname());
			
			// Parse variable_list to add variables to the declaration node
			stringstream var_stream(variable_list);
			string var_identifier;
			
			while(getline(var_stream,var_identifier,','))
			{
				if(var_identifier.find("[") == string::npos) // regular variable
				{
					declaration_node->add_var(var_identifier, 0);
					
					if(sym_tbl->Insert_in_table(var_identifier,"ID"))
					{
						(sym_tbl->Lookup_in_table(var_identifier))->setvartype($1->getname());
						(sym_tbl->Lookup_in_table(var_identifier))->setidtype("var");
					}
					else
					{
						error_file<<"At line no: "<<line_count<<" Multiple declaration of variable "<<var_identifier<<endl<<endl;
						log_file<<"At line no: "<<line_count<<" Multiple declaration of variable "<<var_identifier<<endl<<endl;
						error_count++;
					}
				}
				else // array variable
				{
					stringstream array_stream(var_identifier);
					string array_name, array_dimension;
					
					getline(array_stream,array_name,'['); // extract array name
					getline(array_stream,array_dimension,']'); // extract array size
					
					declaration_node->add_var(array_name, stoi(array_dimension));
					
					if(sym_tbl->Insert_in_table(array_name,"ID"))
					{
						(sym_tbl->Lookup_in_table(array_name))->setvartype($1->getname());
						(sym_tbl->Lookup_in_table(array_name))->setidtype("array");
						(sym_tbl->Lookup_in_table(array_name))->setarraysize(stoi(array_dimension));
					}
					else
					{
						error_file<<"At line no: "<<line_count<<" Multiple declaration of variable "<<array_name<<endl<<endl;
						log_file<<"At line no: "<<line_count<<" Multiple declaration of variable "<<array_name<<endl<<endl;
						error_count++;
					}
				}
			}
			
			$$->set_ast_node(declaration_node);
			variable_list = "";
		 }
 		 ;

type_specifier : INT
		{
			log_file<<"At line no: "<<line_count<<" type_specifier : INT "<<endl<<endl;
			log_file<<"int"<<endl<<endl;
			
			$$ = new symbol_info("int","type");
			return_data_type = "int";
	    }
 		| FLOAT
 		{
			log_file<<"At line no: "<<line_count<<" type_specifier : FLOAT "<<endl<<endl;
			log_file<<"float"<<endl<<endl;
			
			$$ = new symbol_info("float","type");
			return_data_type = "float";
	    }
 		| VOID
 		{
			log_file<<"At line no: "<<line_count<<" type_specifier : VOID "<<endl<<endl;
			log_file<<"void"<<endl<<endl;
			
			$$ = new symbol_info("void","type");
			return_data_type = "void";
	    }
 		;

declaration_list : declaration_list COMMA id_name
		  {
 		  	string var_name = $3->getname();
 		  	log_file<<"At line no: "<<line_count<<" declaration_list : declaration_list COMMA ID "<<endl<<endl;
 		  	
 		  	variable_list=variable_list+","+var_name;
 		  	
			log_file<<variable_list<<endl<<endl;
			
 		  }
 		  | declaration_list COMMA id_name LTHIRD CONST_INT RTHIRD //array after declarations
 		  {
 		  	string var_name = $3->getname();
 		  	string array_size = $5->getname();
 		  	log_file<<"At line no: "<<line_count<<" declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD "<<endl<<endl;
 		  	
 		  	variable_list=variable_list+","+var_name+"["+array_size+"]";
 		  	
			log_file<<variable_list<<endl<<endl;
			
 		  }
 		  |id_name
 		  {
 		  	string var_name = $1->getname();
 		  	log_file<<"At line no: "<<line_count<<" declaration_list : ID "<<endl<<endl;
			log_file<<var_name<<endl<<endl;
			
			variable_list+=var_name;
 		  }
 		  | id_name LTHIRD CONST_INT RTHIRD //array
 		  {
 		  	string var_name = $1->getname();
 		  	string array_size = $3->getname();
 		  	log_file<<"At line no: "<<line_count<<" declaration_list : ID LTHIRD CONST_INT RTHIRD "<<endl<<endl;
			log_file<<var_name+"["+array_size+"]"<<endl<<endl;
			
			variable_list=variable_list+var_name+"["+array_size+"]";
 		  }
 		  ;
id_name : ID
		  {
		   	$$ = new symbol_info($1->getname(),"ID");
		   	function_name = $1->getname();
		   	function_return_type = return_data_type;
		  }
 		  ;

statements : statement
	   {
	    	log_file<<"At line no: "<<line_count<<" statements : statement "<<endl<<endl;
			log_file<<$1->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname(),"stmnts");
			
			// Build block for statements
			BlockNode* statement_block = new BlockNode();
			if($1->get_ast_node()) {
				statement_block->add_statement((StmtNode*)$1->get_ast_node());
			}
			$$->set_ast_node(statement_block);
	   }
	   | statements statement
	   {
	    	log_file<<"At line no: "<<line_count<<" statements : statements statement "<<endl<<endl;
			log_file<<$1->getname()<<"\n"<<$2->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname()+"\n"+$2->getname(),"stmnts");
			
			// Append statement to block
			BlockNode* statement_block = (BlockNode*)$1->get_ast_node();
			if($2->get_ast_node()) {
				statement_block->add_statement((StmtNode*)$2->get_ast_node());
			}
			$$->set_ast_node(statement_block);
	   }
	   | error
	   {
	  		$$ = new symbol_info("","stmnts");
			BlockNode* error_block = new BlockNode();
			$$->set_ast_node(error_block);
	   }  
	   | statements error
	   {
	   		$$ = new symbol_info($1->getname(),"stmnts");
			$$->set_ast_node($1->get_ast_node());
	   }
	   ;
	   
statement : var_declaration
	  {
	    	log_file<<"At line no: "<<line_count<<" statement : var_declaration "<<endl<<endl;
			log_file<<$1->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname(),"stmnt");
			$$->set_ast_node($1->get_ast_node());
	  }
	  | func_definition
	  {
	  		log_file<<"At line no: "<<line_count<<" Function definition must be in the global scope "<<endl<<endl;
	  		error_file<<"At line no: "<<line_count<<" Function definition must be in the global scope "<<endl<<endl;
	  		error_count++;
	  		$$ = new symbol_info("","stmnt");
	  		
	  }
	  | expression_statement
	  {
	    	log_file<<"At line no: "<<line_count<<" statement : expression_statement "<<endl<<endl;
			log_file<<$1->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname(),"stmnt");
			$$->set_ast_node($1->get_ast_node());
	  }
	  | compound_statement
	  {
	    	log_file<<"At line no: "<<line_count<<" statement : compound_statement "<<endl<<endl;
			log_file<<$1->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname(),"stmnt");
			$$->set_ast_node($1->get_ast_node());
	  }
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement
	  {
	    	log_file<<"At line no: "<<line_count<<" statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement "<<endl<<endl;
			log_file<<"for("<<$3->getname()<<$4->getname()<<$5->getname()<<")\n"<<$7->getname()<<endl<<endl;
			
			$$ = new symbol_info("for("+$3->getname()+$4->getname()+$5->getname()+")\n"+$7->getname(),"stmnt");
			
			// Build AST node for for loop
			ForNode* for_loop_node = new ForNode(
				(ExprNode*)$3->get_ast_node(),
				(ExprNode*)$4->get_ast_node(),
				(ExprNode*)$5->get_ast_node(),
				(StmtNode*)$7->get_ast_node()
			);
			$$->set_ast_node(for_loop_node);
	  }
	  | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE
	  {
	    	log_file<<"At line no: "<<line_count<<" statement : IF LPAREN expression RPAREN statement "<<endl<<endl;
			log_file<<"if("<<$3->getname()<<")\n"<<$5->getname()<<endl<<endl;
			
			$$ = new symbol_info("if("+$3->getname()+")\n"+$5->getname(),"stmnt");
			
			// Build AST node for if statement (no else)
			IfNode* if_stmt_node = new IfNode(
				(ExprNode*)$3->get_ast_node(),
				(StmtNode*)$5->get_ast_node()
			);
			$$->set_ast_node(if_stmt_node);
	  }
	  | IF LPAREN expression RPAREN statement ELSE statement
	  {
	    	log_file<<"At line no: "<<line_count<<" statement : IF LPAREN expression RPAREN statement ELSE statement "<<endl<<endl;
			log_file<<"if("<<$3->getname()<<")\n"<<$5->getname()<<"\nelse\n"<<$7->getname()<<endl<<endl;
			
			$$ = new symbol_info("if("+$3->getname()+")\n"+$5->getname()+"\nelse\n"+$7->getname(),"stmnt");
			
			// Build AST node for if-else statement
			IfNode* if_else_node = new IfNode(
				(ExprNode*)$3->get_ast_node(),
				(StmtNode*)$5->get_ast_node(),
				(StmtNode*)$7->get_ast_node()
			);
			$$->set_ast_node(if_else_node);
	  }
	  | WHILE LPAREN expression RPAREN statement
	  {
	    	log_file<<"At line no: "<<line_count<<" statement : WHILE LPAREN expression RPAREN statement "<<endl<<endl;
			log_file<<"while("<<$3->getname()<<")\n"<<$5->getname()<<endl<<endl;
			
			$$ = new symbol_info("while("+$3->getname()+")\n"+$5->getname(),"stmnt");
			
			// Build AST node for while loop
			WhileNode* while_loop_node = new WhileNode(
				(ExprNode*)$3->get_ast_node(),
				(StmtNode*)$5->get_ast_node()
			);
			$$->set_ast_node(while_loop_node);
	  }
	  | PRINTLN LPAREN id_name RPAREN SEMICOLON
	  {
	    	log_file<<"At line no: "<<line_count<<" statement : PRINTLN LPAREN ID RPAREN SEMICOLON "<<endl<<endl;
			log_file<<"printf("<<$3->getname()<<");"<<endl<<endl; 
			
			if(sym_tbl->Lookup_in_table($3->getname()) == NULL)
			{
				error_file<<"At line no: "<<line_count<<" Undeclared variable "<<$3->getname()<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" Undeclared variable "<<$3->getname()<<endl<<endl;
				error_count++;
			}
			
			$$ = new symbol_info("printf("+$3->getname()+");","stmnt");
			
			// Build a basic expression statement for printf
			VarNode* print_var = new VarNode($3->getname(), 
			                         sym_tbl->Lookup_in_table($3->getname()) ? 
			                         sym_tbl->Lookup_in_table($3->getname())->getvartype() : "error");
			ExprStmtNode* printf_node = new ExprStmtNode(print_var);
			$$->set_ast_node(printf_node);
	  }
	  | RETURN expression SEMICOLON
	  {
	    	log_file<<"At line no: "<<line_count<<" statement : RETURN expression SEMICOLON "<<endl<<endl;
			log_file<<"return "<<$2->getname()<<";"<<endl<<endl;
			
			$$ = new symbol_info("return "+$2->getname()+";","stmnt");
			
			// Build AST node for return statement
			ReturnNode* return_stmt_node = new ReturnNode((ExprNode*)$2->get_ast_node());
			$$->set_ast_node(return_stmt_node);
	  }
	  ;
	  
expression_statement : SEMICOLON
			{
				log_file<<"At line no: "<<line_count<<" expression_statement : SEMICOLON "<<endl<<endl;
				log_file<<";"<<endl<<endl;
				
				$$ = new symbol_info(";","expr_stmt");
				
				// Build empty expression statement
				ExprStmtNode* empty_expr_stmt = new ExprStmtNode(nullptr);
				$$->set_ast_node(empty_expr_stmt);
	        }			
			| expression SEMICOLON 
			{
				log_file<<"At line no: "<<line_count<<" expression_statement : expression SEMICOLON "<<endl<<endl;
				log_file<<$1->getname()<<";"<<endl<<endl;
				
				$$ = new symbol_info($1->getname()+";","expr_stmt");
				
				// Build expression statement from expression
				ExprStmtNode* expr_stmt_node = new ExprStmtNode((ExprNode*)$1->get_ast_node());
				$$->set_ast_node(expr_stmt_node);
	        }
			;
	  
variable : id_name 	
      {
	    log_file<<"At line no: "<<line_count<<" variable : ID "<<endl<<endl;
		log_file<<$1->getname()<<endl<<endl;
			
		$$ = new symbol_info($1->getname(),"varbl");
		
		if(sym_tbl->Lookup_in_table($1->getname()) == NULL)
		{
			error_file<<"At line no: "<<line_count<<" Undeclared variable "<<$1->getname()<<endl<<endl;
			log_file<<"At line no: "<<line_count<<" Undeclared variable "<<$1->getname()<<endl<<endl;
			error_count++;
			
			$$->setvartype("error");; //not found set error type
		}
		else if((sym_tbl->Lookup_in_table($1->getname()))->getidtype() != "var") //variable is not a normal variable
		{
			if((sym_tbl->Lookup_in_table($1->getname()))->getidtype() == "array")
			{
				error_file<<"At line no: "<<line_count<<" variable is of array type : "<<$1->getname()<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" variable is of array type : "<<$1->getname()<<endl<<endl;
				error_count++;
			}
			else if((sym_tbl->Lookup_in_table($1->getname()))->getidtype() == "func_def") 
			{
				error_file<<"At line no: "<<line_count<<" variable is of function type : "<<$1->getname()<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" variable is of function type : "<<$1->getname()<<endl<<endl;
				error_count++;
			}
			else if((sym_tbl->Lookup_in_table($1->getname()))->getidtype() == "func_dec") 
			{
				error_file<<"At line no: "<<line_count<<" variable is of function type : "<<$1->getname()<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" variable is of function type : "<<$1->getname()<<endl<<endl;
				error_count++;
			}
			
			
			$$->setvartype("error");; //doesn't match set error type
		}
		else $$->setvartype((sym_tbl->Lookup_in_table($1->getname()))->getvartype());  //set variable type as id type
		
		// Build AST node for variable
		VarNode* variable_node = new VarNode($1->getname(), $$->getvartype());
		$$->set_ast_node(variable_node);
	 }	
	 | id_name LTHIRD expression RTHIRD 
	 {
	 	log_file<<"At line no: "<<line_count<<" variable : ID LTHIRD expression RTHIRD "<<endl<<endl;
		log_file<<$1->getname()<<"["<<$3->getname()<<"]"<<endl<<endl;
		
		$$ = new symbol_info($1->getname()+"["+$3->getname()+"]","varbl");
		
		if(sym_tbl->Lookup_in_table($1->getname()) == NULL)
		{
			error_file<<"At line no: "<<line_count<<" Undeclared variable "<<$1->getname()<<endl<<endl;
			log_file<<"At line no: "<<line_count<<" Undeclared variable "<<$1->getname()<<endl<<endl;
			error_count++;
			
			$$->setvartype("error");; //not found set error type
		}
		else if((sym_tbl->Lookup_in_table($1->getname()))->getidtype() != "array") //variable is not an array
		{
			error_file<<"At line no: "<<line_count<<" variable is not of array type : "<<$1->getname()<<endl<<endl;
			log_file<<"At line no: "<<line_count<<" variable is not of array type : "<<$1->getname()<<endl<<endl;
			error_count++;
			
			$$->setvartype("error");; //doesn't match set error type
		}
		else if($3->getvartype()!="int") // get type of expression for array index
		{
			error_file<<"At line no: "<<line_count<<" array index is not of integer type : "<<$1->getname()<<endl<<endl;
			log_file<<"At line no: "<<line_count<<" array index is not of integer type : "<<$1->getname()<<endl<<endl;
			error_count++;
			
			$$->setvartype("error");
		}
		else
		{
			$$->setvartype((sym_tbl->Lookup_in_table($1->getname()))->getvartype());
		}
		
		// Build AST node for array access
		VarNode* array_access_node = new VarNode($1->getname(), $$->getvartype(), (ExprNode*)$3->get_ast_node());
		$$->set_ast_node(array_access_node);
	 }
	 ;
	 
expression : logic_expression //expression can be void
	   {
	    	log_file<<"At line no: "<<line_count<<" expression : logic_expression "<<endl<<endl;
			log_file<<$1->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname(),"expr");
			$$->setvartype($1->getvartype());
			$$->set_ast_node($1->get_ast_node());
	   }
	   | variable ASSIGNOP logic_expression 	
	   {
	    	log_file<<"At line no: "<<line_count<<" expression : variable ASSIGNOP logic_expression "<<endl<<endl;
			log_file<<$1->getname()<<"="<<$3->getname()<<endl<<endl;

			$$ = new symbol_info($1->getname()+"="+$3->getname(),"expr");
			$$->setvartype($1->getvartype());
			
			if($1->getvartype() == "void" || $3->getvartype() == "void") //if any operand is void
			{
				error_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				error_count++;
				
				$$->setvartype("error");
			}
			else if($1->getvartype() == "int" && $3->getvartype() == "float") // assigning float into int
			{
				error_file<<"At line no: "<<line_count<<" Warning: Assignment of float value into variable of integer type "<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" Warning: Assignment of float value into variable of integer type "<<endl<<endl;
				error_count++;
				
				$$->setvartype("int");
			}
			
			if($1->getvartype() == "error" || $3->getvartype() == "error") //if any operand is error
			{
				$$->setvartype("error");
			}
			
			// Build AST node for assignment
			AssignNode* assignment_node = new AssignNode(
				(VarNode*)$1->get_ast_node(),
				(ExprNode*)$3->get_ast_node(),
				$$->getvartype()
			);
			$$->set_ast_node(assignment_node);
	   }
	   ;
			
logic_expression : rel_expression //logic expression can be void
	     {
	    	log_file<<"At line no: "<<line_count<<" logic_expression : rel_expression "<<endl<<endl;
			log_file<<$1->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname(),"lgc_expr");
			$$->setvartype($1->getvartype());
			$$->set_ast_node($1->get_ast_node());
	     }	
		 | rel_expression LOGICOP rel_expression 
		 {
	    	log_file<<"At line no: "<<line_count<<" logic_expression : rel_expression LOGICOP rel_expression "<<endl<<endl;
			log_file<<$1->getname()<<$2->getname()<<$3->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname()+$2->getname()+$3->getname(),"lgc_expr");
			$$->setvartype("int");
			
			//perform type checking on both sides of logicop
			
			if($1->getvartype() == "void" || $3->getvartype() == "void") //if any operand is void
			{
				error_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				error_count++;
				
				$$->setvartype("error");
			}
			
			if($1->getvartype() == "error" || $3->getvartype() == "error") //if any operand is error
			{
				$$->setvartype("error");
			}
			
			// Build AST node for logical operation
			BinaryOpNode* logic_operation_node = new BinaryOpNode(
				$2->getname(),
				(ExprNode*)$1->get_ast_node(),
				(ExprNode*)$3->get_ast_node(),
				$$->getvartype()
			);
			$$->set_ast_node(logic_operation_node);
	     }	
		 ;
			
rel_expression	: simple_expression //relational expression can be void
		{
	    	log_file<<"At line no: "<<line_count<<" rel_expression : simple_expression "<<endl<<endl;
			log_file<<$1->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname(),"rel_expr");
			$$->setvartype($1->getvartype());
			$$->set_ast_node($1->get_ast_node());
	    }
		| simple_expression RELOP simple_expression
		{
	    	log_file<<"At line no: "<<line_count<<" rel_expression : simple_expression RELOP simple_expression "<<endl<<endl;
			log_file<<$1->getname()<<$2->getname()<<$3->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname()+$2->getname()+$3->getname(),"rel_expr");
			$$->setvartype("int");
			
			//perform type checking on both sides of relop
			
			if($1->getvartype() == "void" || $3->getvartype() == "void") //if any operand is void
			{
				error_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				error_count++;
				
				$$->setvartype("error");
			}
			
			if($1->getvartype() == "error" || $3->getvartype() == "error") //if any operand is error
			{
				$$->setvartype("error");
			}
			
			// Build AST node for relational operation
			BinaryOpNode* relational_operation_node = new BinaryOpNode(
				$2->getname(),
				(ExprNode*)$1->get_ast_node(),
				(ExprNode*)$3->get_ast_node(),
				$$->getvartype()
			);
			$$->set_ast_node(relational_operation_node);
	    }
		;
				
simple_expression : term //simple expression can be void
          {
	    	log_file<<"At line no: "<<line_count<<" simple_expression : term "<<endl<<endl;
			log_file<<$1->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname(),"simp_expr");
			$$->setvartype($1->getvartype());
			$$->set_ast_node($1->get_ast_node());
			
	      }
		  | simple_expression ADDOP term 
		  {
	    	log_file<<"At line no: "<<line_count<<" simple_expression : simple_expression ADDOP term "<<endl<<endl;
			log_file<<$1->getname()<<$2->getname()<<$3->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname()+$2->getname()+$3->getname(),"simp_expr");
			$$->setvartype($1->getvartype());
			
			//perform type checking on both sides of addop
			
			if($1->getvartype() == "void" || $3->getvartype() == "void") //if any operand is void
			{
				error_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				error_count++;
				
				$$->setvartype("error");
			}
			else if($1->getvartype() == "float" || $3->getvartype() == "float") //if any operand is float
			{
				$$->setvartype("float");
			}
			else $$->setvartype("int");
			
			if($1->getvartype() == "error" || $3->getvartype() == "error") //if any operand is error
			{
				$$->setvartype("error");
			}
			
			// Build AST node for addition/subtraction
			BinaryOpNode* addop_node = new BinaryOpNode(
				$2->getname(),
				(ExprNode*)$1->get_ast_node(),
				(ExprNode*)$3->get_ast_node(),
				$$->getvartype()
			);
			$$->set_ast_node(addop_node);
	      }
		  ;
					
term :	unary_expression //term can be void due to unary_expr->factor
     {
	    	log_file<<"At line no: "<<line_count<<" term : unary_expression "<<endl<<endl;
			log_file<<$1->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname(),"term");
			$$->setvartype($1->getvartype());
			$$->set_ast_node($1->get_ast_node());
			
	 }
     |  term MULOP unary_expression
     {
	    	log_file<<"At line no: "<<line_count<<" term : term MULOP unary_expression "<<endl<<endl;
			log_file<<$1->getname()<<$2->getname()<<$3->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname()+$2->getname()+$3->getname(),"term");
			$$->setvartype($1->getvartype());
			
			//perform type checking on both sides of mulop
			if($1->getvartype() == "void" || $3->getvartype() == "void") //if any operand is void
			{
				error_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				error_count++;
				
				$$->setvartype("error");
			}
			else if($1->getvartype() == "float" || $3->getvartype() == "float") //if any operand is float
			{
				$$->setvartype("float");
			}
			else $$->setvartype("int");
			
			//check if both operands are int for modulus
			if($2->getname() == "%")
			{
				if($1->getvartype() == "int" && $3->getvartype() == "int")
				{
					if($3->getname()=="0")
					{
						error_file<<"At line no: "<<line_count<<" Modulus by 0 "<<endl<<endl;
						log_file<<"At line no: "<<line_count<<" Modulus by 0 "<<endl<<endl;
						error_count++;
						
						$$->setvartype("error");
					}
					else $$->setvartype("int");
				}
				else if($1->getvartype() == "float" || $3->getvartype() == "float")
				{
					error_file<<"At line no: "<<line_count<<" Modulus operator on non integer type "<<endl<<endl;
					log_file<<"At line no: "<<line_count<<" Modulus operator on non integer type "<<endl<<endl;
					error_count++;
					
					$$->setvartype("error");
				}
			}
			
			if($2->getname() == "/") //division by zero
			{
				if($3->getname()=="0")
				{
					error_file<<"At line no: "<<line_count<<" Divide by 0 "<<endl<<endl;
					log_file<<"At line no: "<<line_count<<" Divide by 0 "<<endl<<endl;
					error_count++;
					
					$$->setvartype("error");
				}
			}
			if($1->getvartype() == "error" || $3->getvartype() == "error") //if any operand is error
			{
				$$->setvartype("error");
			}
			
			// Build AST node for multiplication/division/modulus
			BinaryOpNode* mulop_node = new BinaryOpNode(
				$2->getname(),
				(ExprNode*)$1->get_ast_node(),
				(ExprNode*)$3->get_ast_node(),
				$$->getvartype()
			);
			$$->set_ast_node(mulop_node);
	 }
     ;

unary_expression : ADDOP unary_expression  // unary expression can be void due to factor
		 {
	    	log_file<<"At line no: "<<line_count<<" unary_expression : ADDOP unary_expression "<<endl<<endl;
			log_file<<$1->getname()<<$2->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname()+$2->getname(),"un_expr");
			$$->setvartype($2->getvartype());
			
			if($2->getvartype()=="void")
			{
				error_file<<"At line no: "<<line_count<<" operation on void type : "<<$2->getname()<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" operation on void type : "<<$2->getname()<<endl<<endl;
				error_count++;
				
				$$->setvartype("error");
			}
			
			// Build AST node for unary plus/minus
			UnaryOpNode* unary_addop_node = new UnaryOpNode(
				$1->getname(),
				(ExprNode*)$2->get_ast_node(),
				$$->getvartype()
			);
			$$->set_ast_node(unary_addop_node);
	     }
		 | NOT unary_expression 
		 {
	    	log_file<<"At line no: "<<line_count<<" unary_expression : NOT unary_expression "<<endl<<endl;
			log_file<<"!"<<$2->getname()<<endl<<endl;
			
			$$ = new symbol_info("!"+$2->getname(),"un_expr");
			$$->setvartype("int");
			
			if($2->getvartype()=="void")
			{
				error_file<<"At line no: "<<line_count<<" operation on void type : "<<$2->getname()<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" operation on void type : "<<$2->getname()<<endl<<endl;
				error_count++;
				
				$$->setvartype("error");
			}
			
			// Build AST node for logical NOT
			UnaryOpNode* not_operation_node = new UnaryOpNode(
				"!",
				(ExprNode*)$2->get_ast_node(),
				$$->getvartype()
			);
			$$->set_ast_node(not_operation_node);
	     }
		 | factor 
		 {
	    	log_file<<"At line no: "<<line_count<<" unary_expression : factor "<<endl<<endl;
			log_file<<$1->getname()<<endl<<endl;
			
			$$ = new symbol_info($1->getname(),"un_expr");
			$$->setvartype($1->getvartype());
			$$->set_ast_node($1->get_ast_node());
	     }
		 ;
	
factor	: variable  // factor can be void
    {
	    log_file<<"At line no: "<<line_count<<" factor : variable "<<endl<<endl;
		log_file<<$1->getname()<<endl<<endl;
			
		$$ = new symbol_info($1->getname(),"fctr");
		$$->setvartype($1->getvartype());
		$$->set_ast_node($1->get_ast_node());
	}
	| id_name LPAREN argument_list RPAREN
	{
	    log_file<<"At line no: "<<line_count<<" factor : ID LPAREN argument_list RPAREN "<<endl<<endl;
	    log_file<<$1->getname()<<"("<<$3->getname()<<")"<<endl<<endl;
	
	    $$ = new symbol_info($1->getname()+"("+$3->getname()+")","fctr");
	    $$->setvartype("error");
	
	    int type_match_flag = 0;
	
	    // Perform type checking (existing code)
	    if(sym_tbl->Lookup_in_table($1->getname())==NULL) //undeclared function
	    {
	        error_file<<"At line no: "<<line_count<<" Undeclared function: "<<$1->getname()<<endl<<endl;
	        log_file<<"At line no: "<<line_count<<" Undeclared function: "<<$1->getname()<<endl<<endl;
	        error_count++;
	    }
	    else
	    {
	        if((sym_tbl->Lookup_in_table($1->getname()))->getidtype()=="func_dec") //declared but not defined
	        {
	            error_file<<"At line no: "<<line_count<<" Undefined function: "<<$1->getname()<<endl<<endl;
	            log_file<<"At line no: "<<line_count<<" Undefined function: "<<$1->getname()<<endl<<endl;
	            error_count++;
	        }
	        else if((sym_tbl->Lookup_in_table($1->getname()))->getidtype()=="func_def")
	        {
	            vector<string> param_type_list = (sym_tbl->Lookup_in_table($1->getname()))->getparamlist();
	
	            if(argument_types.size()!=param_type_list.size()) //number of parameters don't match
	            {
	                error_file<<"At line no: "<<line_count<<" Inconsistencies in number of arguments in function call: "<<$1->getname()<<endl<<endl;
	                log_file<<"At line no: "<<line_count<<" Inconsistencies in number of arguments in function call: "<<$1->getname()<<endl<<endl;
	                error_count++;
	            }
	            else if(param_type_list.size()!=0)
	            {
	                for(int i = 0; i < param_type_list.size(); i++)
	                {
	                    if(argument_types[i]!=param_type_list[i])
	                    {
	                        if(argument_types[i] == "int" && param_type_list[i] == "float") {}
	                        else if(argument_types[i]!="error")
	                        {
	                            type_match_flag = 1;
	                            error_file<<"At line no: "<<line_count<<" "<<"argument "<<i+1<<" type mismatch in function call: "<<$1->getname()<<endl<<endl;
	                            log_file<<"At line no: "<<line_count<<" "<<"argument "<<i+1<<" type mismatch in function call: "<<$1->getname()<<endl<<endl;
	                            error_count++;
	                        }
	                    }
	                }                   
	            }
	            if(!type_match_flag) $$->setvartype((sym_tbl->Lookup_in_table($1->getname()))->getvartype());
	        }
	    }
	
	    // Build function call node
	    FuncCallNode* func_call_node = new FuncCallNode($1->getname(), $$->getvartype());
	
	    // Get arguments from the ArgumentsNode if exists
	    if ($3->get_ast_node()) {
	        ArgumentsNode* args_node = dynamic_cast<ArgumentsNode*>($3->get_ast_node());
	        if (args_node) {
	            // Add each argument to function call
	            for (auto arg : args_node->get_arguments()) {
	                func_call_node->add_argument(arg);
	            }
	        }
	    }
	
	    $$->set_ast_node(func_call_node);
	
	    argument_types.clear();
	}
	| LPAREN expression RPAREN
	{
	   	log_file<<"At line no: "<<line_count<<" factor : LPAREN expression RPAREN "<<endl<<endl;
		log_file<<"("<<$2->getname()<<")"<<endl<<endl;
		
		$$ = new symbol_info("("+$2->getname()+")","fctr");
		$$->setvartype($2->getvartype());
		$$->set_ast_node($2->get_ast_node()); // Pass through expression AST
	}
	| CONST_INT 
	{
	    log_file<<"At line no: "<<line_count<<" factor : CONST_INT "<<endl<<endl;
		log_file<<$1->getname()<<endl<<endl;
			
		$$ = new symbol_info($1->getname(),"fctr");
		$$->setvartype("int");
		
		// Build AST node for integer constant
		ConstNode* int_const_node = new ConstNode($1->getname(), "int");
		$$->set_ast_node(int_const_node);
	}
	| CONST_FLOAT
	{
	    log_file<<"At line no: "<<line_count<<" factor : CONST_FLOAT "<<endl<<endl;
		log_file<<$1->getname()<<endl<<endl;
			
		$$ = new symbol_info($1->getname(),"fctr");
		$$->setvartype("float");
		
		// Build AST node for float constant
		ConstNode* float_const_node = new ConstNode($1->getname(), "float");
		$$->set_ast_node(float_const_node);
	}
	| variable INCOP 
	{
	    log_file<<"At line no: "<<line_count<<" factor : variable INCOP "<<endl<<endl;
		log_file<<$1->getname()<<"++"<<endl<<endl;
			
		$$ = new symbol_info($1->getname()+"++","fctr");
		$$->setvartype($1->getvartype());
		
		// Build AST nodes for increment
		// For x++, represented as (x = x + 1)
		VarNode* inc_var_node = (VarNode*)$1->get_ast_node();
		ConstNode* one_const_node = new ConstNode("1", "int");
		BinaryOpNode* add_one_node = new BinaryOpNode("+", inc_var_node, one_const_node, $1->getvartype());
		AssignNode* inc_assign_node = new AssignNode(inc_var_node, add_one_node, $1->getvartype());
		$$->set_ast_node(inc_assign_node);
	}
	| variable DECOP
	{
	    log_file<<"At line no: "<<line_count<<" factor : variable DECOP "<<endl<<endl;
		log_file<<$1->getname()<<"--"<<endl<<endl;
			
		$$ = new symbol_info($1->getname()+"--","fctr");
		$$->setvartype($1->getvartype());
		
		// Build AST nodes for decrement
		// For x--, represented as (x = x - 1)
		VarNode* dec_var_node = (VarNode*)$1->get_ast_node();
		ConstNode* one_const_node = new ConstNode("1", "int");
		BinaryOpNode* sub_one_node = new BinaryOpNode("-", dec_var_node, one_const_node, $1->getvartype());
		AssignNode* dec_assign_node = new AssignNode(dec_var_node, sub_one_node, $1->getvartype());
		$$->set_ast_node(dec_assign_node);
	}
	;
	
argument_list : arguments
              {
                    log_file<<"At line no: "<<line_count<<" argument_list : arguments "<<endl<<endl;
                    log_file<<$1->getname()<<endl<<endl;
                        
                    $$ = $1; // Pass through arguments node
              }
              |
              {
                    log_file<<"At line no: "<<line_count<<" argument_list :  "<<endl<<endl;
                    log_file<<""<<endl<<endl;
                        
                    $$ = new symbol_info("","arg_list");
                    // Build empty arguments node
                    ArgumentsNode* empty_args = new ArgumentsNode();
                    $$->set_ast_node(empty_args);
              }
              ;
    
arguments : arguments COMMA logic_expression
          {
                log_file<<"At line no: "<<line_count<<" arguments : arguments COMMA logic_expression "<<endl<<endl;
                log_file<<$1->getname()<<","<<$3->getname()<<endl<<endl;
                        
                $$ = new symbol_info($1->getname()+","+$3->getname(),"arg");
                
                // Get existing arguments node or create new
                ArgumentsNode* args_list;
                if ($1->get_ast_node()) {
                    args_list = dynamic_cast<ArgumentsNode*>($1->get_ast_node());
                } else {
                    args_list = new ArgumentsNode();
                }
                
                // Add new argument
                if ($3->get_ast_node()) {
                    args_list->add_argument(dynamic_cast<ExprNode*>($3->get_ast_node()));
                }
                
                $$->set_ast_node(args_list);
                argument_types.push_back($3->getvartype());
          }
          | logic_expression
          {
                log_file<<"At line no: "<<line_count<<" arguments : logic_expression "<<endl<<endl;
                log_file<<$1->getname()<<endl<<endl;
                        
                $$ = new symbol_info($1->getname(),"arg");
                
                // Build new arguments node with single argument
                ArgumentsNode* args_list = new ArgumentsNode();
                if ($1->get_ast_node()) {
                    args_list->add_argument(dynamic_cast<ExprNode*>($1->get_ast_node()));
                }
                
                $$->set_ast_node(args_list);
                argument_types.push_back($1->getvartype());
          }
          ;
 

%%

int main(int argc, char *argv[])
{
	if(argc != 2) 
	{
		cout<<"Please input file name"<<endl;
		return 0;
	}
	yyin = fopen(argv[1], "r");
	log_file.open("log.txt", ios::trunc);
	error_file.open("error.txt", ios::trunc);
	code_file.open("code.txt", ios::trunc);

	if(yyin == NULL)
	{
		cout<<"Couldn't open file"<<endl;
		return 0;
	}
	
	// First pass: Parse input and build AST
	cout << "==== Pass 1: Parsing and constructing AST ====" << endl;
	log_file << "==== Pass 1: Parsing and constructing AST ====" << endl;
	
	sym_tbl->enter_scope(log_file);
	yyparse();
	
	log_file << endl << "Symbol Table after first pass:" << endl;
	sym_tbl->Print_all_scope(log_file);
	
	// Only proceed to second pass if no errors occurred
	if (error_count == 0 && program_root) {
		cout << "==== Pass 2: Generating Three-Address Code ====" << endl;
		log_file << endl << "==== Pass 2: Generating Three-Address Code ====" << endl;
		
		// Generate three-address code (second pass)
		log_file << "Initiating Three-Address Code generation..." << endl;
		ThreeAddrCodeGenerator tac_generator(program_root, code_file);
		tac_generator.generate();
		
		log_file << "Three-Address Code generation completed successfully" << endl;
		cout << "Three-Address Code generated successfully. Output in code.txt" << endl;
	} else {
		cout << "Three-Address Code generation skipped due to compilation errors" << endl;
		log_file << endl << "Three-Address Code generation skipped due to errors" << endl;
		code_file << "// Three-Address Code generation aborted due to compilation errors" << endl;
	}
	
	log_file<<endl<<"Total lines: "<<line_count<<endl;
	log_file<<"Total errors: "<<error_count<<endl;
	error_file<<"Total errors: "<<error_count<<endl;
	
	log_file.close();
	error_file.close();
	code_file.close();

	
	fclose(yyin);
	
	return 0;
}
