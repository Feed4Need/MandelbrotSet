#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int counter;
    float Zn, C, Xz, Yz, Zn1, Xc, Yc, RandMax, negX, negY, Xn, Yn; //Setting variables

    srand(getpid()); //Making a random string for rand() function

    Xz = 0; //Setting inital values
    Yz = 0;
    Zn = Xz + Yz;
    RandMax = 32767;
    counter=0;

    Xc = ((float)rand()/RandMax); //Random Xc value bounded [0, 1] inlcusive
    Yc = ((float)rand()/RandMax); //Random Yc value bounded [0, 1] inclusive     //printf("X is %f and Y is %f", Xc, Yc)

    negX = rand() % 2 + 1; //Testing to define Xc as postitive or nengative
    srand(getpid()); //Resetting string again
    negY = rand() % 2 + 1; //Testing to define Yc as postitive or nengative
        if (negX==1)
        {
            Xc = (-1)*Xc;
        }
        if (negY==1)
        {
            Yc = (-1)*Yc;
        }
    printf("X is %f and Y is %f\n", Xc, Yc);

    C = Xc + Yc;

    //C = Xc + Yc; //Defining C as a complex number bounded [-2, 2] inclusive
    printf("C is %f\n", C);

    while (counter<1000)
    {
        Zn1 = (Zn*Zn) + C;

        Xn = Xz; //Defining current Xn for formula use
        Yn = Yz; //Defining current Yn for formula use

        Xz = (Xn*Xn) - (Yn*Yn) + Xc; //Defining new Xz (Real part of Zn)
        Yz = (2*Yn*Xn) + Yc; //Defining new Yz (Imaginary part of Zn)

        Zn = Xz + Yz; //Defining new Zn

        printf("Zn1 is %f\n", Zn1);

        counter++;
    }





    return 0;
}
