%{
#include <stdio.h>
#include <string.h>
#define EXIT_FAILURE    -1   
void yyerror(const char *s);
void prizeCatLimit(int counter);
void validateGameId(int val);
void listIntegerCountLimit(int counter);
void listIntegerInterval(int val);
void countAllElements();
void countActiveElements();
void winningNElements();
void bonusElements();
void counterChecker();
void prizeCatElements();
extern FILE *yyin;
extern FILE *yyout;
extern int yylex();
extern int lineno;                        //line counter
extern int value;                         //stores the value of last read integer
extern int listflag;                      //1 when reading a "list" 
extern int prizeCatflag;                  //1 when reading a "prizeCategories"
extern int contentflag;                   //1 when reading a "content"
int token_numbers[2][10];                 //an array of tokens we expect to read in no particular order in last, active and content
int prizeCatElem[2][8];                   //an array of tokens we expect to read in no particular order in prizeCategories
int minDistFlg = 0;                       //1 when reading "minimumDistributed"
int prCatCntr=0;                          //counts json objects in "prizeCategories"
int errors = 0;                           //counts errors encountered
int intArrCounter = 0;                    //counts integers in an array

%}

%token T_U_INT                      "Unsigned Integer"      //whatever
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


program:                T_L_BRACE last T_COMMA active T_R_BRACE        
                  |     T_L_BRACE order T_R_BRACE
                  |     error                
                  ;                                                                                               

last_scope:             expr T_COMMA last_scope       
                  |     expr    
                  |     expr error last_scope
                  ;


last:                   T_QUOTATIONS T_LAST T_QUOTATIONS T_ASSIGNMENT T_L_BRACE last_scope T_R_BRACE        {countAllElements();}                                          
                  |     T_QUOTATIONS T_LAST T_QUOTATIONS T_ASSIGNMENT T_BOOLEAN 
                  |     error    
                  ;

order:                  content T_COMMA total_pages T_COMMA total_elements T_COMMA last T_COMMA number_of_elements T_COMMA sort T_COMMA first T_COMMA size T_COMMA number
                  |     error                          
                  ;


active:                 T_QUOTATIONS T_ACTIVE T_QUOTATIONS T_ASSIGNMENT T_L_BRACE active_scope T_R_BRACE    {countActiveElements();}
                  |     error         
                  ;

active_scope:     |     expr T_COMMA active_scope                 
                  |     expr
                  |     expr error active_scope
                  ;     

wager_objects:          columns T_COMMA wagers T_COMMA add_on  
                  |     error
                  ;

columns:                T_QUOTATIONS T_COLUMNS T_QUOTATIONS T_ASSIGNMENT T_U_INT     
                  |     error       
                  ;

wagers:                 T_QUOTATIONS T_WAGERS T_QUOTATIONS T_ASSIGNMENT T_U_INT
                  |     error
                  ;           

add_on:           |     T_QUOTATIONS T_ADDON T_QUOTATIONS T_ASSIGNMENT T_L_BRACKET T_R_BRACKET 
                  |     error       
                  ;


price_points:           T_L_BRACE T_QUOTATIONS T_AMOUNT T_QUOTATIONS T_ASSIGNMENT T_U_FLOAT T_R_BRACE     
                  |     error
                  ;                 

list:                   T_QUOTATIONS T_LIST T_QUOTATIONS T_ASSIGNMENT u_int_array   {counterChecker(intArrCounter, 5);intArrCounter=0;listflag=0;}    
                  |     error        
                  ;

bonus:                  T_QUOTATIONS T_BONUS T_QUOTATIONS T_ASSIGNMENT u_int_array   {counterChecker(intArrCounter, 1);intArrCounter=0;}     
                  |     error       
                  ;

winning_numbers:        T_L_BRACE list T_COMMA bonus  T_R_BRACE     
                  |     error       
                  ;

u_int_array:            T_L_BRACKET u_int_scope T_R_BRACKET      
                  |     error
                  ;

u_int_scope:            T_U_INT T_COMMA u_int_scope                     {intArrCounter++;}
                  |     T_U_INT                                         {intArrCounter++;}
                  |     T_U_INT error u_int_scope                       
                  ;     

json_string:            T_QUOTATIONS T_JSON_STRING T_QUOTATIONS
                  |     T_QUOTATIONS T_ACTIVE T_QUOTATIONS     
                  |     error             
                  ;

json_array:             T_L_BRACKET json_arr_scope T_R_BRACKET 
                  |     error                   
                  ;  

json_arr_scope:         json_object T_COMMA json_arr_scope
                  |     json_object  
                  |     json_object error json_arr_scope
                  ;

json_object:            T_L_BRACE json_obj_scope T_R_BRACE                    {if(prizeCatflag==0 && contentflag==1)countAllElements();if(prizeCatflag==1){prCatCntr++;prizeCatElements();}if(minDistFlg!=0){printf("Unexpected amount of \"minimumDistributed\" before line: %d\n", lineno);errors++;}minDistFlg=0;}     
                  |     error                     
                  ;          

json_obj_scope:         expr T_COMMA json_obj_scope         
                  |     expr
                  |     expr error json_obj_scope
                  ;

content_scope:          json_object T_COMMA content_scope
                  |     json_object        
                  |     json_object error content_scope     
                  ;

content:                T_QUOTATIONS T_CONTENT T_QUOTATIONS T_ASSIGNMENT T_L_BRACKET content_scope T_R_BRACKET {contentflag=0;} 
                  ;           
 
total_pages:            T_QUOTATIONS T_TOTALPAGES T_QUOTATIONS T_ASSIGNMENT T_U_INT     
                  |     error       
                  ;

total_elements:         T_QUOTATIONS T_TOTALELEMENTS T_QUOTATIONS T_ASSIGNMENT T_U_INT     
                  |     error       
                  ;
    

number_of_elements:     T_QUOTATIONS T_NUMBEROFELEMEMENTS T_QUOTATIONS T_ASSIGNMENT T_U_INT     
                  |     error       
                  ;

sort:                   T_QUOTATIONS T_SORT T_QUOTATIONS T_ASSIGNMENT json_array
                  |     error       
                  ;          

expr:                   T_QUOTATIONS T_GAMEID T_QUOTATIONS T_ASSIGNMENT T_U_INT                 {validateGameId(value);}  
                  |     T_QUOTATIONS T_DRAWID T_QUOTATIONS T_ASSIGNMENT T_U_INT
                  |     T_QUOTATIONS T_DRAWTIME T_QUOTATIONS T_ASSIGNMENT T_U_INT
                  |     T_QUOTATIONS T_STATUS T_QUOTATIONS T_ASSIGNMENT json_string
                  |     T_QUOTATIONS T_DRAWBREAK T_QUOTATIONS T_ASSIGNMENT T_U_INT
                  |     T_QUOTATIONS T_VISUALDRAW T_QUOTATIONS T_ASSIGNMENT T_U_INT
                  |     T_QUOTATIONS T_PRICEPOINTS T_QUOTATIONS T_ASSIGNMENT price_points 
                  |     T_QUOTATIONS T_WINNINGNUMBERS T_QUOTATIONS T_ASSIGNMENT winning_numbers
                  |     T_QUOTATIONS T_PRIZECATEGORIES T_QUOTATIONS T_ASSIGNMENT json_array           {prizeCatLimit(prCatCntr);prCatCntr=0;prizeCatflag=0;}            
                  |     T_QUOTATIONS T_WAGERSTATISTICS T_QUOTATIONS T_ASSIGNMENT T_L_BRACE wager_objects T_R_BRACE
                  |     T_QUOTATIONS T_ID T_QUOTATIONS T_ASSIGNMENT T_U_INT                           {if(value < 1 || value > 8){errors++; printf("Expected a value from 1-8 got %d near line %d\n", value, lineno);} else if(value == 1) minDistFlg++;}
                  |     T_QUOTATIONS T_DIVIDENT T_QUOTATIONS T_ASSIGNMENT T_U_FLOAT
                  |     T_QUOTATIONS T_WINNERS T_QUOTATIONS T_ASSIGNMENT T_U_INT
                  |     T_QUOTATIONS T_DISTRIBUTED T_QUOTATIONS T_ASSIGNMENT T_U_FLOAT
                  |     T_QUOTATIONS T_JACKPOT T_QUOTATIONS T_ASSIGNMENT T_U_FLOAT
                  |     T_QUOTATIONS T_FIXED T_QUOTATIONS T_ASSIGNMENT T_U_FLOAT
                  |     T_QUOTATIONS T_CATEGORYTYPE T_QUOTATIONS T_ASSIGNMENT T_U_INT                 {if(value != 0 && value != 1){errors++; printf("Expected 0 or 1 got %d near line %d\n", value, lineno);}}
                  |     T_QUOTATIONS T_GAMETYPE T_QUOTATIONS T_ASSIGNMENT json_string 
                  |     T_QUOTATIONS T_MINIMUMDISTRIBUTED T_QUOTATIONS T_ASSIGNMENT T_U_FLOAT         {minDistFlg--;}
                  |     T_QUOTATIONS T_DIRECTION T_QUOTATIONS T_ASSIGNMENT json_string
                  |     T_QUOTATIONS T_PROPERTY T_QUOTATIONS T_ASSIGNMENT  json_string
                  |     T_QUOTATIONS T_IGNORE_CASE T_QUOTATIONS T_ASSIGNMENT T_BOOLEAN
                  |     T_QUOTATIONS T_NULL_HANDLING T_QUOTATIONS T_ASSIGNMENT json_string
                  |     T_QUOTATIONS T_DESCENDING T_QUOTATIONS T_ASSIGNMENT T_BOOLEAN
                  |     T_QUOTATIONS T_ASCENDING T_QUOTATIONS T_ASSIGNMENT T_BOOLEAN 
                  |     error
                  ;

first:                  T_QUOTATIONS T_FIRST T_QUOTATIONS T_ASSIGNMENT T_BOOLEAN               
                  |     error                                                            
                  ;

size:                   T_QUOTATIONS T_SIZE T_QUOTATIONS T_ASSIGNMENT T_U_INT             
                  |     error                                                          
                  ;

number:                 T_QUOTATIONS T_NUMBER T_QUOTATIONS T_ASSIGNMENT T_U_INT           
                  |     error                                                   
                  ;
  
%%
// count # of tokens in last, active and content 
int token_numbers[2][10]={T_GAMEID, T_DRAWID, T_DRAWTIME, T_STATUS, T_DRAWBREAK, T_VISUALDRAW, T_PRICEPOINTS, T_PRIZECATEGORIES, T_WAGERSTATISTICS, T_WINNINGNUMBERS};
//count of elements in prizeCategories in range_result
int prizeCatElem[2][8] = {T_ID, T_DIVIDENT, T_WINNERS, T_DISTRIBUTED, T_JACKPOT, T_FIXED, T_CATEGORYTYPE, T_GAMETYPE};



void yyerror(const char *s) {
      errors++;
      printf("%s line: %d\n", s, lineno);
}									

void validateGameId(int val){
      //if value of gameId is not invalid
      if(val!=1100 && val!=1110 && val!=2100 && val!=2101 && val!=5103 && val!=5104 && val!=5106)
            {
                  printf("Invalid gameId: %d near line: %d\n", val, lineno);
                  errors++;
            }
}

//validates that "prizeCategory" contains 8 json objects
void prizeCatLimit(int counter){
      if(counter != 8 ){
            errors++;
            printf("Expected 8 JSON objects in prizeCategories found: %d, near line: %d\n",counter,lineno);  
      }

}

//counts elements in "prizeCategory"
void prizeCatElements()
{
      for(int i = 0; i < 8; i++){
            //each element must appear only once
            if(prizeCatElem[1][i] != 1){
                  errors++;
                  printf("Found %d %s expected 1 before line: %d\n",prizeCatElem[1][i], yytname[YYTRANSLATE(prizeCatElem[0][i])], lineno);
            }
            //reset array
            prizeCatElem[1][i]=0;
      }
}

//integers in "list" must be in [1,45]
void listIntegerInterval(int val){
      if(!(val >= 1 && val <= 45) ){
            errors++;
            printf("Expected integer in [1, 45] found: %d, near line: %d\n", val, lineno);  
      }
}

//counts elements in "last" for last_result and in "content" for range_result
void countAllElements(){
      for(int i=0; i<10; i++){
            //contains each token specified in token_numbers[0][0:9] once
            if(token_numbers[1][i] != 1){
                  errors++;
                  printf("Found %d %s expected 1 before line: %d\n", token_numbers[1][i], yytname[YYTRANSLATE(token_numbers[0][i])], lineno);
            }
            //reset array
            token_numbers[1][i]=0;
      }
}

//counts elements in "active" for file last_result
void countActiveElements(){
      for(int i=0; i<9; i++){
            //contains each token specified in token_numbers[0][0:8] once 
            if(token_numbers[1][i] != 1){
                  errors++;
                  printf("Found %d %s expected 1 in \"active\" before line: %d\n", token_numbers[1][i], yytname[YYTRANSLATE(token_numbers[0][i])], lineno);
            }
            //reset array
            token_numbers[1][i] = 0;
      }
      //does not contain "winningNumbers"
      if(token_numbers[1][9] != 0){
            errors++;
            printf("Found %d %s expected 0 in \"active\" before line: %d\n", token_numbers[1][9], yytname[YYTRANSLATE(token_numbers[0][9])], lineno);
            //reset array
            token_numbers[1][9] = 0;
      }
}

//validates # of entries in an array
void counterChecker(int counter, int limit)
{
      //counter: # integers read
      //limit: # expected integers in an array
      if(counter != limit){
            printf("Found %d integers expected %d before line: %d\n", counter, limit, lineno);
            errors++;
      }
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
      if(errors == 0)
            printf("\n\nParsing successful \n\n");
      else
            printf("\nParsing failed due to %d errors \n\n", errors);

      return 0;
}   