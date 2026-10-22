/* CS100 Fall 2026 - HW2 Problem 5: CPU emulator
 *
 * Emulate a toy CPU with registers x0..x5 (16-bit signed, x0 always 0)
 * executing add/sub/mul/div/let/print instructions read as hex words.
 * Do not use <math.h>. Do not rename this file.
 */
#include <stdio.h>

int main(void)
{
    short a[6] = {0};
    int n, i;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        unsigned int p;
        scanf("%x", &p);

        int op = (p >> 13) & 7;
        int b1     = (p >> 10) & 7;
        int b2     = (p  >> 7)  & 7;
        int imm    = p & 127;

        if (op == 0) 
        {
            if (b1 != 0) a[b1] = (short)(a[b1] + a[b2]);
        }
        else if (op == 1)   
        {
            if (b1 != 0) a[b1] = (short)(a[b1] - a[b2]);
        }
        else if (op == 2) 
        {
            if (b1 != 0) a[b1] = (short)(a[b1] * a[b2]);
        }
        else if (op == 3)  
        {
            if (b1 != 0) a[b1] = (short)(a[b1] / a[b2]);
        }
        else if (op == 4)  
        {
            if (b1 != 0) a[b1] = (short)imm;
        }
        else if (op == 5)  
        {
            printf("x%d = %d\n", b1, a[b1]);
        }
    }
    return 0;
}
