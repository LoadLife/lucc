#include "token.h"
namespace jcc {

  std::unordered_map<std::string, TokenKind> Str_Keyword_Map = {
    {"const", CONST},
    {"restrict", RESTRICT},
    {"volatile", VOLATILE},
    {"atomic", ATOMIC},

    {"void", VOID},
    {"char", CHAR},
    {"short", SHORT},
    {"int", INT},
    {"long", LONG},
    {"float", FLOAT},
    {"double", DOUBLE},
    {"signed", SIGNED},
    {"unsigned", UNSIGNED},
    {"bool", BOOL},
    {"complex", COMPLEX},
    {"struct", STRUCT},
    {"union", UNION},
    {"enum", ENUM},

    {"+", ADD},
    {"++", INC},
    {"-", SUB},
    {"--", DEC},
    {"*", MUL},
    {"/", DIV},
    {"%", MOD},
    {"+=", ADD_ASSIGN},
    {"-=", SUB_ASSIGN},
    {"*=", MUL_ASSIGN},
    {"/=", DIV_ASSIGN},
    {"%=", MOD_ASSIGN},
    {"<<=", LEFT_ASSIGN},
    {">>=", RIGHT_ASSIGN},
    {"&=", AND_ASSIGN},
    {"^=", XOR_ASSIGN},
    {"|=", OR_ASSIGN},

    {"(", LPAR},
    {")", RPAR},
    {"{", LBRACE},
    {"}", RBRACE},
    {";", SEMI}   

    //{"",},
  };

}