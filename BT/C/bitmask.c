#include "stdio.h"
#include "stdint.h"

typedef enum{
    AO          = 1 << 0,   //0b00000001
    QUAN        = 1 << 1,   //0b00000010
    VAY         = 1 << 2,   //0b00000100
    DAM         = 1 << 3,   //0b00001000
    NHAN        = 1 << 4,   //0b00010000
    VONG_TAY    = 1 << 5,   //0b00100000
    GIAY        = 1 << 6,   //0b01000000
    TUI         = 1 << 7    //0b10000000
}DoDungCaNhan;

void Them_Vao_Gio_Hang(uint8_t *gio_hang, DoDungCaNhan ten_do_dung ){
    *gio_hang |= ten_do_dung; 
}


void Xoa_Khoi_Gio_Hang(uint8_t *gio_hang, DoDungCaNhan ten_do_dung){
    *gio_hang &= ~ten_do_dung;
}

void Kiem_Tra_San_Pham(uint8_t gio_hang, DoDungCaNhan ten_do_dung){

}
void Hien_Thi_Gio_Hang(uint8_t gio_hang){
    
}

int main(int argc, char const *argv[])
{
    uint8_t GIO_HANG;           //1byte: 0b00000000

    return 0;
}
