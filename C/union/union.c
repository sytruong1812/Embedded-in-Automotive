#include <stdio.h>
#include <stdint.h>

// union Data_union
// {
//     uint8_t u8bit;      //1byte
//     uint16_t u16bit;    //2byte
//     uint32_t u32bit;    //4byte  => size lớn nhất
// };

typedef union 
{          
    uint8_t u8bit;      //1byte
    uint16_t u16bit;    //2byte
    uint32_t u32bit;    //4byte     => size lớn nhất
}Data_union;

typedef union 
{
    uint8_t name[8];
    uint8_t class[4];
}sinhvien;


int main(int argc, char const *argv[])
{

//Kích thước (size) của union = size lớn nhất của kiểu dữ liệu trong đó
    // union Data_union data;
    // printf("Size of Union: %d\n", sizeof(data));

    // Data_union data;
    // printf("Size of Union: %d\n", sizeof(data));


//Các member dùng chung vùng nhớ (địa chỉ)
    // Data_union data;
    // Data_union *ptr = &data;

    // printf("Address union: %p\n", &data);
    // printf("Address u8bit: %p\n", &(data.u8bit));
    // printf("Address u16bit: %p\n", &(data.u16bit));
    // printf("Address u32bit: %p\n", &(data.u16bit));

//Việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác.
//Nói cách khác, việc gán giá trị cho các member của union trước thì chỉ thành phần cuối cùng được 
//gián giá trị được sử dụng. Các thành phần trước đó sẽ bị ghi đè.

    sinhvien data_sv;

    for (int i = 0; i < 8; i++)
    {
        data_sv.name[i] = 3*i;
        printf("Name %d: %d\n",i, data_sv.name[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        printf("Class %d: %d\n",i, data_sv.class[i]);   //Bị ghi đè giá trị khi chưa gán "data_sv.class[i] = 2*i;"
    }
    printf("............\n");
    for (int i = 0; i < 4; i++)
    {
        data_sv.class[i] = 2*i;                         //Gán giá trị "data_sv.class[i] = 2*i;"
        printf("Class %d: %d\n",i, data_sv.class[i]);   //Giá trị cuối cùng được sử dụng
    }
    for (int i = 0; i < 8; i++)
    {
        printf("Name %d: %d\n",i, data_sv.name[i]);     //Bị ghi đè giá trị khi chưa gán "data_sv.name[i] = 3*i;"
    }

    return 0;
}
