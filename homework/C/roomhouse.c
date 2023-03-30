#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "stddef.h"
#include "string.h"
#include "ctype.h"

/*
1. Kiểm tra khoảng trắng và dịch con trỏ
2. Kiểm tra chuỗi có bao nhiêu Object
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

typedef struct JsonValue   
{
  JsonType type;        //Phân biêt Value là kiểu dữ liệu gì
  union                 //Chọn kiểu dữ liệu của value
  {
    int boolean;
    double number;
    char *string;
    struct              //Trong 1 mảng, mình cần biết 2 thông số
    {
        struct JsonValue *values;       //Địa chỉ đầu tiên
        size_t count;                   //Kích thước của mảng
    } array;            
    struct              //Đối với object mình cần biết 3 thông số
    {
        char **keys;                    //Key
        struct JsonValue *values;       //Value
        size_t count;                   //Số lượng object
    } object;
  } value;              
} JsonValue;

static void skip_whitespace(const char **json){
    while (isspace(**json))
    {
        (*json)++;
    }
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
    skip_whitespace(json);
    if(**json == '{'){
        (*json)++;              //pointer address shift
        skip_whitespace(json);
    }
    
    JsonValue *object_value = (JsonValue *)malloc(sizeof(JsonValue));
    object_value->type = JSON_OBJECT;
    object_value->value.object.keys = NULL;
    object_value->value.object.values = NULL;
    object_value->value.object.count = 0;

}


JsonValue *parse_json(const char **json){
    skip_whitespace(json);

    switch (**json)         
    {
    case 'n':
        return parse_null(json);
    case 'f':
    case 't':
        return parse_boolean(json);
    case '\"':
        return parse_string(json);
    case '[':
        return parse_array(json);
    case '{':
        return parse_object(json);
    default:
        return parse_number(json);
    } 
}

void check_object(const char *json){
    int object = 0;
    int count = 0;
    int i = 0;
    while (json[i] != 0)
    {
        if(json[i] == '{') count++;
        if(json[i] == '}') count--;
        if(count == 0) object++;
        i++;
    }
    printf("Count: %d, object: %d", count, object);
}

int main(int argc, char const *argv[])
{    
    const char* json_str = "{\"Nguoi1\":{\"Ten\":\"Nguyen Van A\",\"Tuoi\":\"20\",\"Gioitinh\":\"Nam\",\"Diachi\":{\"Phuong\":\"Phuong 3\",\"Quan\":\"Go Vap\",\"Thanhpho\":\"Ho Chi Minh\"},\"SDT\":[{\"Loai\":\"So di thoai ca nhan\",\"SDT\":\"0938348442\"},{\"Loai\":\"So dien thoai co quan\",\"SDT\":\"0799124108\"}],\"TrangThaiHonNhan\":False}}";
    check_object(json_str);
    return 0;
}


