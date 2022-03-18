#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define max 100

int fraction[max], integer[max], loop;

void border1();
void decimalintobinary();
void binaryintodecimal();
void menuUtama();

int main()
{
    menuUtama();
    return 0;
}

void border1()
{
    printf("\n===============================\n");
}

void menuUtama()
{
    int menu;
    loop = 1;
    while (1)
    {
        border1();
        printf("\n===Binary Decimal Calculator===");
        border1();
        printf("         *** MENU ***\n\n");
        printf("\n<1> Turn Binary into Decimal");
        printf("\n<2> Turn Decimal into Binary");
        printf("\n<0> Exit\n\n");

        printf("---------------------------------------------\n");
    inputs:
        printf("Pilih Menu : ");
        scanf("%d", &menu);
        printf("\n");
        switch (menu)
        {
        case 0:
            exit(0); // keluar dari program
        case 1:
            binaryintodecimal(); // memanggil fungsi binary into decimal
            break;
        case 2:
            decimalintobinary(); // memanggil fungsi decimal into binary
            break;
        default: // case untuk input selain yang disediakan
            printf("\n  !! Wrong Choice !! \n");
            printf("----------------------------------------------\n");
            goto inputs; // kembali ke baris untuk memasukkan input menu yang diinginkan
        }
    }
}


void decimalintobinary()
{
    float des, f;
    int i, bef_point, com;
    printf("Decimal : ");
    scanf("%f", &des);
    printf("\n");

    f = des - (int)des;
    for (i = 0; i < max; i++)
    {
        f = f - (int)f;
        fraction[i] = (int)(f * 2);
        f *= 2;
    }

    bef_point = (int)des;

    for (i = max - 1; i >= 0; i--)
    {
        if (bef_point % 2 == 0)
        {
            integer[i] = 0;
        }
        else
            integer[i] = 1;
        bef_point /= 2;
    }

    printf("Binary : ");
    com = 0;

    for (i = 0; i < max; i++)
    {
        if (integer[i] || com)
        {
            com = 1;
            printf("%d", integer[i]);
        }
    }
    printf(".");

    for (i = 0; i < 10; i++)
        printf("%d", fraction[i]);

    printf("\n");
}

void binaryintodecimal()
{
    double bin, point, des=0;
    long bef_point, i=0, j=0;
    printf("Binary : ");
    scanf("%lf", &bin);
    printf("\n");

    bef_point = bin;

    point = bin - (long)bin;

    while (bef_point)
    {
        des += (bef_point % 10) * pow(2, i++);
        bef_point /= 10;
    }

    for (i = 0; i < max; i++)
    {
        j--;
        point *= 10;
        if (point >= 1)
        {
            point -= 1;
            des += pow(2, j);
        }
    }
    printf("Decimal :  %lf\n", des);
}