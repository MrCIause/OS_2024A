#include "myShell.h"
#include "myFunction.h"

int main()
{
    welcome();
    getLocation();
    while(1)
    {
        getLocation();
        char *input = getInputFromUser();
        if(strcmp(input,"exit")==0 || strncmp(input, "exit ", 5)==0)
            logout(input);
        char **arg = splitArgument(input);
        // cp\0<file>\0<file>\0  - we put a \0 to create an ending index.
        // [cp, <file>, <file>] - we place the strings into an array.
        // [input, input+3, input+10] - input will read cp untill \0, input+3 will read <file> till \0.

            free(arg);
            free(input);
    }
    
    return 0;
}
// example

//                      aSPY//YASa
//              apyyyyCY//////////YCa       |
//             sY//////YSpcs  scpCY//Pp     | Welcome to myShell
//  ayp ayyyyyyySCP//Pp           syY//C    | Version 2.4.3
//  AYAsAYYYYYYYY///Ps              cY//S   |
//          pCCCCY//p          cSSps y//Y   | https://github.com/<user>
//          SPPPP///a          pP///AC//Y   |
//               A//A            cyP////C   | Have fun!
//               p///Ac            sC///a   |
//               P////YCpc           A//A   | Wanna support scapy? Rate it on
//        scccccp///pSP///p          p//Y   | sectools!
//       sY/////////y  caa           S//P   | http://sectools.org/tool/scapy/
//        cayCyayP//Ya              pY/Ya   |             -- Satoshi Nakamoto
//         sY/PsY////YCc          aC//Yp    |
//          sc  sccaCY//PCypaapyCP//YSs
//                   spCPY//////YPSps
//                        ccaacs
//                                        using c
void welcome()
{
    puts("Welcome to my Shell");
}