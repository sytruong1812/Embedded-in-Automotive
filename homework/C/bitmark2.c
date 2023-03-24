#include<stdio.h>
#include<stdint.h>

typedef enum{
    SHIRT         = 1 << 0,  //0b00000001
    PANTS         = 1 << 1,  //0b00000010
    DRESS         = 1 << 2,  //0b00000100
    SHORT         = 1 << 3,  //0b00001000
    RING          = 1 << 4,  //0b00010000
    BRACELET      = 1 << 5,  //0b00100000
    SHOE          = 1 << 6,  //0b01000000
    BAG           = 1 << 7,  //0b10000000
}PersonalBelongings;

char *utensil[] = {"SHIRT", "PANTS", "DRESS", "SHORT", "RING", "BRACELET", "SHOE", "BAG"};

void Add_To_Cart(uint8_t *cart, PersonalBelongings utensilName) {
    *cart |= utensilName;
}

void Remove_From_Cart(uint8_t *cart, PersonalBelongings utensilName) {
    *cart &=  ~utensilName;
}

void Check_Product(uint8_t *cart, PersonalBelongings utensilName) {
    for (int i=0; i<8; i++) {
        if (utensilName & (1 << i)) {
            if (*cart & (1 << i)) {
                printf("\nAVAILABLE: %s ",utensil[i]);
            } else {
                printf("\nUNAVAILABLE: %s ",utensil[i]);
            }
        }
    }
}

void Display_Product(uint8_t *cart) {
    printf("\nSHOW CART AVAILABLE:");
    for (int i=0; i<8; i++) {
        if (*cart & (1 << i)) {
            printf("%s ",utensil[i]);
        }
    }
}

int main()
{
    uint8_t cart; 
    Add_To_Cart(&cart, SHOE|SHORT|SHIRT|PANTS|BAG);
    Remove_From_Cart(&cart, SHOE);
    Check_Product (&cart, BAG|BRACELET|SHORT);
    Display_Product(&cart);
}