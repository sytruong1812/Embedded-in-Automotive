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

void Kiem_Tra_San_Pham(uint8_t gio_hang, DoDungCaNhan ten_do_dung)
{
                                                        // gio_hang  & ten_do_dung = kiem_tra
                                                        //  AO|VAY   & AO|QUAN|VAY =  AO|VAY
    uint8_t kiem_tra = gio_hang & ten_do_dung;          //0b00000101 & 0b00000111  = 0b00000101
    
    for (int i = 0; i < 8; i++)
    {
        if((kiem_tra & (1 << i)) != 0)                  //0b00000101 & 0b00000010 = 0b00000010  
        {
            switch(i)                                  
            {
                case 0:
                    printf("Ao da ton tai trong gio hang!\n");
                    break;
                case 1:                                            
                    printf("Quan da ton tai trong gio hang!\n");
                    break;
                case 2:
                    printf("Vay da ton tai trong gio hang!\n");
                    break;
                case 3:
                    printf("Dam da ton tai trong gio hang!\n");
                    break;
                case 4:
                    printf("Nhan da ton tai trong gio hang!\n");
                    break;
                case 5:
                    printf("Vong Tay da ton tai trong gio hang!\n");
                    break;
                case 6:
                    printf("Giay da ton tai trong gio hang!\n");
                    break;
                case 7:
                    printf("Tui da ton tai trong gio hang!\n");
                    break;
                default:
                    break;
            }
        }                                       
        if(~(kiem_tra | ~(1 << i)) == (ten_do_dung & (1 << i)))
        {
            switch(i)
            {
                case 0:
                    printf("Ao khong ton tai trong gio hang!\n");
                    break;
                case 1:
                    printf("Quan khong ton tai trong gio hang!\n");
                    break;
                case 2:
                    printf("Vay khong ton tai trong gio hang!\n");
                    break;
                case 3:
                    printf("Dam khong ton tai trong gio hang!\n");
                    break;
                case 4:
                    printf("Nhan khong ton tai trong gio hang!\n");
                    break;
                case 5:
                    printf("Vong tay khong ton tai trong gio hang!\n");
                    break;
                case 6:
                    printf("Giay khong ton tai trong gio hang!\n");
                    break;
                case 7:
                    printf("Tui khong ton tai trong gio hang\n");
                    break;
                default:
                    break;
            }
        }
    }   
}

void Hien_Thi_Gio_Hang(uint8_t gio_hang){
    printf("Cac san pham trong gio hang:\n");
    printf("STT\t NAME\n");
    for(int i=0; i<8; i++){
        if((gio_hang & (1 << i)) != 0){
            switch(i){
                case 0:
                    printf(" 1\t Ao\n");
                    break;
                case 1:
                    printf(" 2\t Quan\n");
                    break;
                case 2:
                    printf(" 3\t Vay\n");
                    break;
                case 3:
                    printf(" 4\t Dam\n");
                    break;
                case 4:
                    printf(" 5\t Nhan\n");
                    break;
                case 5:
                    printf(" 6\t Vong Tay\n");
                    break;
                case 6:
                    printf(" 7\t Giay\n");
                    break;
                case 7:
                    printf(" 8\t Tui");
                    break;
                default:
                    break;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    uint8_t GIO_HANG;                                    //1byte: 0b00000000
    Them_Vao_Gio_Hang(&GIO_HANG, AO|QUAN|VAY|DAM);       //GIO_HANG = 0b00000111 (Sử dụng toán tử OR)
    Xoa_Khoi_Gio_Hang(&GIO_HANG, QUAN|AO);               //GIO_HANG = 0b00000101
    Kiem_Tra_San_Pham(GIO_HANG, AO|QUAN|VAY|DAM);
    Hien_Thi_Gio_Hang(GIO_HANG);
    return 0;
}
