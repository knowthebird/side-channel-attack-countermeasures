// Basic example code to prevent power analysis or timing attacks for pin/key comparison
// Does not protect memory, in this case device would still need to by physically protected
// See YouTube video for more details... https://youtu.be/ajEC53uBUrs?si=BXtbqp-nsRZmuaOq

#include <stdio.h>

// Macros from https://stackoverflow.com/questions/2525310
#define SetBit(A,k)     ( A[(k)/32] |= (1 << ((k)%32)) )
#define TestBit(A,k)    ( A[(k)/32] & (1 << ((k)%32)) )

int main() {
    // when int is 4 bytes or 32 bits, we can have 32 possible passwords per byte
    // for 10000 possible passwords, 10000/32 = 312.5
    int UniqueData[313] = {0};
    
    // set the bit for the pin/key
    SetBit(UniqueData,7);
    
    int UserProvideValue;
    printf("Enter Your Pin / Key: \n");
    scanf("%d", &UserProvideValue);
    
    if TestBit(UniqueData,UserProvideValue) {
        printf("Open Lock \n");
    } else {
        printf("Do Not Open Lock \n");
    }
    
    return 0;
}
