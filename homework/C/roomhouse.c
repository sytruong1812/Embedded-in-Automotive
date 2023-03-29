#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "stddef.h"

/*
1. Kiểm tra chuỗi có bao nhiêu Object
2. 
3. 
4. 
5.
*/

typedef enum{
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;

char *nameJsonType[] = {
    "JSON_NULL",
    "JSON_BOOLEAN",
    "JSON_NUMBER",
    "JSON_STRING",
    "JSON_ARRAY",
    "JSOM_OBJECT"
};

typedef struct 
{
  JsonType type;
  union
  {
    int boolean;
    double number;
    char *string;
    struct
    {
        JsonValue *values;
        size_t count;
    } array;
    struct
    {
        char **keys;
        JsonValue *values;
        size_t count;
    } object;
  } value;
} JsonValue;

void skip_whitespace(const char **json){

}

JsonValue *parse_null(const char **json){

}

JsonValue *parse_boolean(const char **json){

}

JsonValue *parse_number(const char **json){

}

JsonValue *parse_string(const char **json){

}

JsonValue *parse_array(const char **json){

}

JsonValue *parse_object(const char **json){

}

int main(int argc, char const *argv[])
{    
    return 0;
}


