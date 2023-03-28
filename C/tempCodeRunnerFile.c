unsigned short swap_bytes(unsigned short x) 
// {
//     unsigned short bitmask = 0x00FF;
//     unsigned short temp = x & bitmask;
//     x = x >> 8;
//     temp = temp << 8;
//     x = x | temp;
//     return x;
// }