#include <stdio.h>
#include <stdint.h>

typedef enum{
    SHIRT          = 1 << 0,   //0b00000001
    SHORT          = 1 << 1,   //0b00000010
    SKIRT          = 1 << 2,   //0b00000100
    DRESS          = 1 << 3,   //0b00001000
    RING           = 1 << 4,   //0b00010000
    BRACELET       = 1 << 5,   //0b00100000
    SHOES          = 1 << 6,   //0b01000000
    BAG            = 1 << 7,   //0b10000000
} PersonalBelongings;

char *individual_items[] = {"SHIRT","SHORT","SKIRT","DRESS","RING","BRACELET","SHOES","BAG"};

void addCart (uint8_t *cart, PersonalBelongings items){

    *cart |= items;
}

void removeItemsFromCart (uint8_t *cart, PersonalBelongings items){

    *cart &= ~items;
}

void checkItems (uint8_t cart, PersonalBelongings items){

/*Ý tưởng: Kiểm tra lần lượt từng sản phẩm trong giỏ hàng. Nếu kiểm tra sản phẩm A, đồng thời giỏ hàng đang 
chứa sản phẩm A thì in ra sản phẩm A có trong giỏ hàng. Ngược lại thì sản phẩm A không có trong giỏ hàng*/

    for(int i = 0; i < 8; i++)
    {
        if(items & (1 << i) && cart & (1 << i)){                 //Kiểm tra sản phẩm và giỏ hàng cũng có sản phẩm đó
            printf("THE CART HAS : %s\n", individual_items[i]);
        }
        else if (items & (1 << i) || cart & (1 << i)){           //Kiểm tra sản phẩm hoặc giỏ hàng
            printf("THE CART HASN'T : %s\n", individual_items[i]); 
        }            
    }
}

void showCart (uint8_t cart){

    printf( "THE CART INCLUDES : ");
    
    for(int i = 0; i < 8; i++)
    {
        if(cart & (1 << i))
        {
            printf("%s ", individual_items[i]);
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    uint8_t cart;
    
    addCart(&cart, SHIRT|SHORT|RING);
     
    removeItemsFromCart(&cart, SHIRT);

    checkItems(cart, SHIRT|RING|SHORT|BAG);
 
    showCart(cart);

    return 0;
}