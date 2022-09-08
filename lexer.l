%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
extern int token_numbers[2][10];            // counts tokens in last_scope and active_scope
extern void listIntegerInterval(int val);   //defined in parser.y 
int lineno = 1;                             //line counter for error recovery
int value;                                  //value of last integer read
int listflag = 0;                           // is 1 when reading list 
int prizeCatflag = 0;                       // is 1 when reading prizeCategory
int contentflag = 0;                        // is 1 when reading content

%}

%option case-insensitive
%option noyywrap

digit                       [0-9]
letter                      [a-zA-Z]
sign                        [-,+]
u_int                       {digit}+
float                       ({sign}{u_int}+\.{u_int}+)+
u_float                     ({u_int}+\.{u_int}+)+
JSON_string                 ({u_int}|{letter}|\_?|\.?)+
newline                     [\n]


%%




"{"                         {return T_L_BRACE;}
"}"                         {return T_R_BRACE;}
"["                         {return T_L_BRACKET;}
"]"                         {return T_R_BRACKET;}
"."                         {return T_DOT;}
\"                          {return T_QUOTATIONS;}
":"                         {return T_ASSIGNMENT;}
","                         {return T_COMMA;}

"last"                      {return T_LAST;}
"gameId"                    {token_numbers[1][0]++;return T_GAMEID;}
"drawId"                    {token_numbers[1][1]++;return T_DRAWID;}
"drawTime"                  {token_numbers[1][2]++;return T_DRAWTIME;}
"status"                    {token_numbers[1][3]++;return T_STATUS;}
"drawBreak"                 {token_numbers[1][4]++;return T_DRAWBREAK;}
"visualDraw"                {token_numbers[1][5]++;return T_VISUALDRAW;}
"pricePoints"               {token_numbers[1][6]++;return T_PRICEPOINTS;}
"amount"                    {return T_AMOUNT;}
"bonus"                     {return T_BONUS;}
"prizeCategories"           {token_numbers[1][7]++;prizeCatflag=1;return T_PRIZECATEGORIES;}
"id"                        {return T_ID;}
"divident"                  {return T_DIVIDENT;}
"winners"                   {return T_WINNERS;}
"distributed"               {return T_DISTRIBUTED;}
"jackpot"                   {return T_JACKPOT;}
"fixed"                     {return T_FIXED;}
"categoryType"              {return T_CATEGORYTYPE;}
"gameType"                  {return T_GAMETYPE;}
"minimumDIstributed"        {return T_MINIMUMDISTRIBUTED;}
"wagerstatistics"           {token_numbers[1][8]++; return T_WAGERSTATISTICS;}
"columns"                   {return T_COLUMNS;}
"wagers"                    {return T_WAGERS;}
"addOn"                     {return T_ADDON;}
"active"                    {return T_ACTIVE;}
"content"                   {contentflag=1;return T_CONTENT;}
"winningNumbers"            {token_numbers[1][9]++;return T_WINNINGNUMBERS;}
"list"                      {listflag=1;return T_LIST;}
"totalPages"                {return T_TOTALPAGES;}
"totalELements"             {return T_TOTALELEMENTS;}
"numberOfElements"          {return T_NUMBEROFELEMEMENTS;}
"sort"                      {return T_SORT;}
"direction"                 {return T_DIRECTION;}
"true"                      {return T_BOOLEAN;}
"false"                     {return T_BOOLEAN;}
"property"                  {return T_PROPERTY;}
"ignoreCase"                {return T_IGNORE_CASE;}
"nullHandling"              {return T_NULL_HANDLING;}
"descending"                {return T_DESCENDING;}
"ascending"                 {return T_ASCENDING;}
"first"                     {return T_FIRST;}
"size"                      {return T_SIZE;}
"number"                    {return T_NUMBER;}

{u_int}                     {value = atoi(yytext);if(listflag==1)listIntegerInterval(value);return T_U_INT;} /* set value equal to integer parsed and if reading "list" make sure it is in [1,45] */
{u_float}                   {return T_U_FLOAT;}
{float}                     {return T_FLOAT;}
{JSON_string}               {return T_JSON_STRING;}
{sign}                      {return T_SIGN;}
{newline}                   {lineno++;}



%%

