#include "stdio.h"
#include "stdint.h"

typedef enum{
    SHIRT          = 1 << 0,   //0b00000001
    PANT           = 1 << 1,   //0b00000010
    SKIRT          = 1 << 2,   //0b00000100
    DRESS          = 1 << 3,   //0b00001000
    RING           = 1 << 4,   //0b00010000
    BRACELET       = 1 << 5,   //0b00100000
    SHOES          = 1 << 6,   //0b01000000
    BAG            = 1 << 7    //0b10000000
}PersonalBelongings;

char *item[] = {"SHIRT", "PANT", "SKIRT", "DRESS", "RING", "BRACELET", "SHOES", "BAG"}; 

void Add_Cart(uint8_t *cart, PersonalBelongings item_name ){
    *cart |= item_name; 
}

void Remove_From_Cart(uint8_t *cart, PersonalBelongings item_name){
    *cart &= ~item_name;          
}

void Check_Item(uint8_t cart, PersonalBelongings item_name)
{                   
    cart &= item_name;           //0b00000101 & 0b00000111  = 0b00000101

    for (int i = 0; i < 8; i++)
    {
        if((cart & (1 << i)) != 0)             //0b00000101 & 0b00000010 = 0b00000010  
        {
            printf("%s already exists in cart!\n", item[i]);
        }                                       
        if(~(cart | ~(1 << i)) == (item_name & (1 << i)))           //0b00000010 == 0b00000010
        {
            printf("%s do not exists in cart!\n", item[i]);
        }
    }   
}

void Show_Cart(uint8_t cart){
    printf("Item in the cart:\n");
    printf("STT\t NAME\n");
    for(int i=0; i<8; i++){
        if((cart & (1 << i)) != 0){
            printf(" 1\t %s\n", item[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    uint8_t CART;                                       //1byte: 0b00000000
    Add_Cart(&CART, SHIRT|PANT|SKIRT|DRESS);            //CART = 0b00000111 (Sử dụng toán tử OR)
    Remove_From_Cart(&CART, PANT|SHIRT);                //CART = 0b00000101
    Check_Item(CART, SHIRT|PANT|SKIRT|RING);
    Show_Cart(CART);
    return 0;
}
