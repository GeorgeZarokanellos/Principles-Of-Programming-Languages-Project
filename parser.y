%{
#include <stdio.h>
#include <string.h>
#define EXIT_FAILURE    -1   
void yyerror(const char *s);
void gameCatLimit(int counter);
void checkGameId(int val);
void listIntegerCountLimit(int counter);
void listIntegerInterval(int val);
void lastElements();
void activeElements();
void winningNElements();
void bonusElements();
void counterChecker();
extern FILE *yyin;
extern FILE *yyout;
extern int yylex();
extern int lineno;
extern int value;
extern int listflag;
extern int bonusflag;
extern int prizeCatflag;
extern int contentflag;
extern int token_numbers[2][10];
int mD_Flg = 0;
int prCatCntr=0;
int listCntr = 0;
int arrCntr = 0;
int errorflg = 0;
int genericCounter = 0;

%}

%token T_U_INT                      "Unsigned Integer"      
%token T_U_FLOAT                    "Unsigned Float"                              
%token T_GAMEID                     "GameID"      
%token T_FLOAT                      "Float"    
%token T_JSON_STRING                "JSON String"
%token T_BOOLEAN                    "Boolean"      
%token T_JSON_ARRAY                 "JSON Array"      
%token T_L_BRACE                    "Left Brace ({)"  
%token T_R_BRACE                    "Right Brace (})"
%token T_L_BRACKET                  "Left Bracket ([)"
%token T_R_BRACKET                  "Right Bracket (])"
%token T_DOT                        "Dot (.)"
%token T_QUOTATIONS                 "Quotations"     
%token T_ASSIGNMENT                 "Assignment (:)"      
%token T_COMMA                      "Comma (,)"     
%token T_U_INT_ARRAY                "Unsigned Integer Array"      
%token T_LAST                       "Last"     
%token T_ACTIVE                     "Active"      
%token T_DRAWID                     "DrawID"      
%token T_DRAWTIME                   "Draw Time"     
%token T_VISUALDRAW                 "Visual Draw"     
%token T_PRICEPOINTS                "Price Points"      
%token T_AMOUNT                     "Amount"      
%token T_WINNINGNUMBERS             "Winning Numbers"
%token T_LIST                       "List"     
%token T_BONUS                      "Bonus"      
%token T_PRIZECATEGORIES            "Prize Categories"
%token T_ID                         "ID"
%token T_DIVIDENT                   "Divident"
%token T_WINNERS                    "Winners"
%token T_DISTRIBUTED                "Distributed"
%token T_JACKPOT                    "Jackpot"
%token T_FIXED                      "Fixed"
%token T_CATEGORYTYPE               "Category Type"
%token T_GAMETYPE                   "Game Type"
%token T_MINIMUMDISTRIBUTED         "Minimum Distributed"
%token T_WAGERSTATISTICS            "Wager Statistics"
%token T_COLUMNS                    "Columns"
%token T_WAGERS                     "Wagers"
%token T_SORT                       "Sort"
%token T_DIRECTION                  "Direction"
%token T_NUMBEROFELEMEMENTS         "Number of Elements"
%token T_TOTALELEMENTS              "Total Elements"
%token T_TOTALPAGES                 "Total Pages"
%token T_DRAWBREAK                  "Draw Break"
%token T_STATUS                     "Status"
%token T_CONTENT                    "Content"
%token T_ADDON                      "Addon"
%token T_PROPERTY                   "Property"
%token T_IGNORE_CASE                "Ignore Case"
%token T_NULL_HANDLING              "Null Handling"
%token T_DESCENDING                 "Descending"
%token T_ASCENDING                  "Ascending"
%token T_FIRST                      "First"
%token T_SIZE                       "Size"
%token T_NUMBER                     "Number"
%token T_SIGN                       "sign"
%token T_EOF                        0     

%define parse.error verbose

%start program

%%


program:                T_L_BRACE last T_COMMA active T_R_BRACE         //included
                  |     T_L_BRACE order T_R_BRACE
                  |     error                
                  ;                                                                                               

last_scope:             expr T_COMMA last_scope       //included
                  |     expr    
                  |     expr error last_scope
                  ;


last:                   T_QUOTATIONS T_LAST T_QUOTATIONS T_ASSIGNMENT T_L_BRACE last_scope T_R_BRACE        {lastElements();}                                          
                  |     T_QUOTATIONS T_LAST T_QUOTATIONS T_ASSIGNMENT T_BOOLEAN 
                  |     error    //included
                  ;

order:                  content T_COMMA total_pages T_COMMA total_elements T_COMMA last T_COMMA number_of_elements T_COMMA sort T_COMMA first T_COMMA size T_COMMA number
                  |     error                         
                  ;


active:                 T_QUOTATIONS T_ACTIVE T_QUOTATIONS T_ASSIGNMENT T_L_BRACE active_scope T_R_BRACE    {activeElements();}
                  |     error    //included     
                  ;

active_scope:     |     expr T_COMMA active_scope                 //included
                  |     expr
                  |     expr error active_scope
                  ;     

wager_objects:          columns T_COMMA wagers T_COMMA add_on     
                  |     error      //included  
                  ;

columns:                T_QUOTATIONS T_COLUMNS T_QUOTATIONS T_ASSIGNMENT T_U_INT     
                  |     error       //check
                  ;

wagers:                 T_QUOTATIONS T_WAGERS T_QUOTATIONS T_ASSIGNMENT T_U_INT
                  |     error
                  ;           //to be continued

add_on:           |     T_QUOTATIONS T_ADDON T_QUOTATIONS T_ASSIGNMENT T_L_BRACKET T_R_BRACKET 
                  |     error       //to becontinued
                  ;


price_points:           T_L_BRACE T_QUOTATIONS T_AMOUNT T_QUOTATIONS T_ASSIGNMENT T_U_FLOAT T_R_BRACE     
                  |     error
                  ;                 //done

list:                   T_QUOTATIONS T_LIST T_QUOTATIONS T_ASSIGNMENT u_int_array   {counterChecker(genericCounter, 5);genericCounter=0;listflag=0;}    
                  |     error   //done     
                  ;

bonus:                  T_QUOTATIONS T_BONUS T_QUOTATIONS T_ASSIGNMENT u_int_array   {counterChecker(genericCounter, 1);genericCounter=0;}     
                  |     error       //done
                  ;

winning_numbers:        T_L_BRACE list T_COMMA bonus  T_R_BRACE     
                  |     error       //done
                  ;

u_int_array:            T_L_BRACKET u_int_scope T_R_BRACKET    //included  
                  |     error
                  ;

u_int_scope:            T_U_INT T_COMMA u_int_scope                     {genericCounter++;}
                  |     T_U_INT                                         {genericCounter++;}
                  |     T_U_INT error u_int_scope                       //Included
                  ;     

json_string:            T_QUOTATIONS T_JSON_STRING T_QUOTATIONS
                  |     T_QUOTATIONS T_ACTIVE T_QUOTATIONS     
                  |     error             //included
                  ;

json_array:             T_L_BRACKET json_arr_scope T_R_BRACKET 
                  |     error   //included                 
                  ;  

json_arr_scope:         json_object T_COMMA json_arr_scope
                  |     json_object  //included
                  |     json_object error json_arr_scope
                  ;

json_object:            T_L_BRACE json_obj_scope T_R_BRACE                    {if(prizeCatflag==0 && contentflag==1)lastElements();if(prizeCatflag==1)prCatCntr++;}     
                  |     error       //included              
                  ;          

json_obj_scope:         expr T_COMMA json_obj_scope         //included
                  |     expr
                  |     expr error json_obj_scope
                  ;

content_scope:          json_object T_COMMA content_scope                    
                  |     json_object      //included              
                  |     json_object error content_scope     
                  ;

content:                T_QUOTATIONS T_CONTENT T_QUOTATIONS T_ASSIGNMENT T_L_BRACKET content_scope T_R_BRACKET {contentflag=0;} 
                  ;           //included
 
total_pages:            T_QUOTATIONS T_TOTALPAGES T_QUOTATIONS T_ASSIGNMENT T_U_INT     
                  |     error       //done
                  ;

total_elements:         T_QUOTATIONS T_TOTALELEMENTS T_QUOTATIONS T_ASSIGNMENT T_U_INT     
                  |     error       //done
                  ;
    

number_of_elements:     T_QUOTATIONS T_NUMBEROFELEMEMENTS T_QUOTATIONS T_ASSIGNMENT T_U_INT     
                  |     error       //done
                  ;

sort:                   T_QUOTATIONS T_SORT T_QUOTATIONS T_ASSIGNMENT json_array
                  |     error       //done
                  ;          

expr:                   T_QUOTATIONS T_GAMEID T_QUOTATIONS T_ASSIGNMENT T_U_INT                 {checkGameId(value);}  //included
                  |     T_QUOTATIONS T_DRAWID T_QUOTATIONS T_ASSIGNMENT T_U_INT
                  |     T_QUOTATIONS T_DRAWTIME T_QUOTATIONS T_ASSIGNMENT T_U_INT
                  |     T_QUOTATIONS T_STATUS T_QUOTATIONS T_ASSIGNMENT json_string
                  |     T_QUOTATIONS T_DRAWBREAK T_QUOTATIONS T_ASSIGNMENT T_U_INT
                  |     T_QUOTATIONS T_VISUALDRAW T_QUOTATIONS T_ASSIGNMENT T_U_INT
                  |     T_QUOTATIONS T_PRICEPOINTS T_QUOTATIONS T_ASSIGNMENT price_points 
                  |     T_QUOTATIONS T_WINNINGNUMBERS T_QUOTATIONS T_ASSIGNMENT winning_numbers
                  |     T_QUOTATIONS T_PRIZECATEGORIES T_QUOTATIONS T_ASSIGNMENT json_array           {gameCatLimit(prCatCntr);prCatCntr=0;prizeCatflag=0;if(mD_Flg!=0){ printf("Expected %d minimumDistributed found %d near line: %d",mD_Flg+1, mD_Flg, lineno);errorflg=1;}}            
                  |     T_QUOTATIONS T_WAGERSTATISTICS T_QUOTATIONS T_ASSIGNMENT T_L_BRACE wager_objects T_R_BRACE
                  |     T_QUOTATIONS T_ID T_QUOTATIONS T_ASSIGNMENT T_U_INT                           {if(value < 1 || value > 9){errorflg = 1; printf("Expected a value from 1-8 got %d near line %d", value, lineno);} else if(value == 1) mD_Flg++;}
                  |     T_QUOTATIONS T_DIVIDENT T_QUOTATIONS T_ASSIGNMENT T_U_FLOAT
                  |     T_QUOTATIONS T_WINNERS T_QUOTATIONS T_ASSIGNMENT T_U_INT
                  |     T_QUOTATIONS T_DISTRIBUTED T_QUOTATIONS T_ASSIGNMENT T_U_FLOAT
                  |     T_QUOTATIONS T_JACKPOT T_QUOTATIONS T_ASSIGNMENT T_U_FLOAT
                  |     T_QUOTATIONS T_FIXED T_QUOTATIONS T_ASSIGNMENT T_U_FLOAT
                  |     T_QUOTATIONS T_CATEGORYTYPE T_QUOTATIONS T_ASSIGNMENT T_U_INT                 {if(value != 0 && value != 1){errorflg = 1; printf("Expected 0 or 1 got %d near line %d", value, lineno);}}
                  |     T_QUOTATIONS T_GAMETYPE T_QUOTATIONS T_ASSIGNMENT json_string 
                  |     T_QUOTATIONS T_MINIMUMDISTRIBUTED T_QUOTATIONS T_ASSIGNMENT T_U_FLOAT         {mD_Flg--;}
                  |     T_QUOTATIONS T_DIRECTION T_QUOTATIONS T_ASSIGNMENT json_string
                  |     T_QUOTATIONS T_PROPERTY T_QUOTATIONS T_ASSIGNMENT  json_string
                  |     T_QUOTATIONS T_IGNORE_CASE T_QUOTATIONS T_ASSIGNMENT T_BOOLEAN
                  |     T_QUOTATIONS T_NULL_HANDLING T_QUOTATIONS T_ASSIGNMENT json_string
                  |     T_QUOTATIONS T_DESCENDING T_QUOTATIONS T_ASSIGNMENT T_BOOLEAN
                  |     T_QUOTATIONS T_ASCENDING T_QUOTATIONS T_ASSIGNMENT T_BOOLEAN 
                  |     error
                  ;

first:                  T_QUOTATIONS T_FIRST T_QUOTATIONS T_ASSIGNMENT T_BOOLEAN               
                  |     error    //done                                                        
                  ;

size:                   T_QUOTATIONS T_SIZE T_QUOTATIONS T_ASSIGNMENT T_U_INT             
                  |     error    //done                                                         
                  ;

number:                 T_QUOTATIONS T_NUMBER T_QUOTATIONS T_ASSIGNMENT T_U_INT           
                  |     error    //done                                                  
                  ;
  
%%
int token_numbers[2][10]={T_GAMEID, T_DRAWID, T_DRAWTIME, T_STATUS, T_DRAWBREAK, T_VISUALDRAW, T_PRICEPOINTS, T_PRIZECATEGORIES, T_WAGERSTATISTICS, T_WINNINGNUMBERS};

void yyerror(const char *s) {
      errorflg = 1;
      printf("%s line: %d\n", s, lineno);
}									

void checkGameId(int val){
      //if value of gameId is invalid
      if(val!=1100 && val!=1110 && val!=2100 && val!=2101 && val!=5103 && val!=5104 && val!=5106)
            {
                  printf("Invalid gameId: %d near line: %d\n\n", val, lineno);
                  errorflg = 1;
            }
}

void gameCatLimit(int counter){
      if(counter != 8 ){
            errorflg = 1;
            printf("\n\nExpected 8 JSON objects in prizeCategories found: %d, near line: %d\n",prCatCntr,lineno);  
      }

      //else printf("gameCategory is OK\n");
}

void listIntegerCountLimit(int counter){
            if(counter != 5 ){
            errorflg = 1;
            printf("\n\nExpected 5 integers in list found: %d, near line: %d\n",    listCntr,lineno);  
      }

      //else printf("List is OK\n");
}

void listIntegerInterval(int val){
      if(!(val >= 1 && val <= 45) ){
            errorflg = 1;
            printf("\n\nExpected wait what an integer in [1, 45] found: %d, near line: %d\n", val, lineno);  
      }
      //else printf("\nval: %d is ok.\n", val);
}

//checks last in last_result
void lastElements(){
      for(int i=0; i<10; i++){
            if(token_numbers[1][i] != 1){
                  errorflg = 1;
                  printf("Found %d %s expected 1 in \"last\" before line: %d\n", token_numbers[1][i], yytname[YYTRANSLATE(token_numbers[0][i])], lineno);
            }
            //reset array
            token_numbers[1][i]=0;
      }
}

//checks active in last_result
void activeElements(){
      for(int i=0; i<9; i++){
            if(token_numbers[1][i] != 1){
                  errorflg = 1;
                  printf("Found %d %s expected 1 in \"active\" before line: %d\n", token_numbers[1][i], yytname[YYTRANSLATE(token_numbers[0][i])], lineno);
            }
            if(token_numbers[1][10] != 0){
                  errorflg = 1;
                  printf("Found %d %s expected 0 in \"active\" before line: %d\n", token_numbers[1][10], yytname[YYTRANSLATE(token_numbers[0][10])], lineno);
                  token_numbers[1][10] = 0;
            }
            //reset array
            token_numbers[1][i] = 0;
            token_numbers[1][10] = 0;
      }
}

void bonusElements(int counter){
      if(counter != 2) {
            errorflg = 1;
            printf("Found %d integers expected 1 in \"Bonus\" before line: %d\n", counter-1, lineno);
      }
}

void counterChecker(int counter, int limit)
{
      if(counter != limit)
            printf("Found %d integers expected %d before line: %d\n", counter, limit, lineno);
}

int main ( int argc, char **argv  ) 
{
      ++argv; --argc;
      if ( argc > 0 )
            yyin = fopen( argv[0], "r" );
      else
            yyin = stdin;
      yyout = fopen ( "output", "w" );	
      yyparse (); 
      fclose(yyout);
      fclose(yyin);   
      if(errorflg == 0)
            printf("\n\nParsing successful \n\n");
      else
            printf("\n\nParsing failed due to errors \n\n");

      /* for(int i=0;i<10;i++){
            printf("%d\t", token_numbers[1][i]);
      } */

      return 0;
}   