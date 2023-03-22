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
            switch(i)                                  
            {
                case 0:
                    printf("Shirt already exists in cart!\n");
                    break;
                case 1:                                            
                    printf("Pant already exists in cart!\n");
                    break;
                case 2:
                    printf("Skirt already exists in cart!\n");
                    break;
                case 3:
                    printf("Dress already exists in cart!\n");
                    break;
                case 4:
                    printf("Ring already exists in cart!\n");
                    break;
                case 5:
                    printf("Bracelet already exists in cart!\n");
                    break;
                case 6:
                    printf("Shoes already exists in cart!\n");
                    break;
                case 7:
                    printf("Bag already exists in cart!\n");
                    break;
                default:
                    break;
            }
        }                                       
        if(~(cart | ~(1 << i)) == (item_name & (1 << i)))
        {
            switch(i)
            {
                case 0:
                    printf("Shirt do not exist in the cart!\n");
                    break;
                case 1:
                    printf("Pant do not exist in the cart!\n");
                    break;
                case 2:
                    printf("Skirt do not exist in the cart!\n");
                    break;
                case 3:
                    printf("Dress do not exist in the cart!\n");
                    break;
                case 4:
                    printf("Ring do not exist in the cart!\n");
                    break;
                case 5:
                    printf("Bracelet do not exist in the cart!\n");
                    break;
                case 6:
                    printf("Shoes do not exist in the cart!\n");
                    break;
                case 7:
                    printf("Bag do not exist in the cart!\n");
                    break;
                default:
                    break;
            }
        }
    }   
}

void Show_Cart(uint8_t cart){
    printf("Item in the cart:\n");
    printf("STT\t NAME\n");
    for(int i=0; i<8; i++){
        if((cart & (1 << i)) != 0){
            switch(i){
                case 0:
                    printf(" 1\t Shirt\n");
                    break;
                case 1:
                    printf(" 2\t Pant\n");
                    break;
                case 2:
                    printf(" 3\t Skirt\n");
                    break;
                case 3:
                    printf(" 4\t Dress\n");
                    break;
                case 4:
                    printf(" 5\t Ring\n");
                    break;
                case 5:
                    printf(" 6\t Bracelet\n");
                    break;
                case 6:
                    printf(" 7\t Shoes\n");
                    break;
                case 7:
                    printf(" 8\t Bag");
                    break;
                default:
                    break;
            }
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
