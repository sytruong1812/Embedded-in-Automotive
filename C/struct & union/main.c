#include "stdio.h"

union Roadway
{
    int car;
    int motorcycle;
    int bicycle;
};
union Waterway
{
    int boat;
    int ferries;
};
union Airway
{
    int airliner;
    int airship;
};

union Option
{
    union Roadway duongbo;
    union Waterway duongbien;
    union Airway hangkhong;
};

union Option vehical;

int main(int argc, char const *argv[])
{
    vehical.duongbo.car = 1;
    vehical.duongbien.boat = 1;
    vehical.hangkhong.airliner = 1;

    printf("Roadway: %d\n", vehical.duongbo.car);
    printf("Waterway: %d\n", vehical.duongbien.boat);
    printf("Airway: %d\n", vehical.hangkhong.airliner);
    
    return 0;
}



