/*
 Alejandro Salas
 4-20-15
 CS 49C Section 2
 Homework 8
 eval: checks to see what player wins a game of hexboard. Either b, g, 0
 search: checks the 6 diffrerent positions on the hexboard to find a winner
 */
#include <stdio.h>
#include "hw8.h"
char search(char game[][maxH], int SizeV, int SizeH, int i, int j, player p, dir d, int searched[][SizeH]);

char eval(char game[][maxH], int SizeV, int SizeH) {
    int vl, hz, i, j;
    int searched[SizeV][SizeH];
    
    for(vl = 0; vl<SizeV; vl++) {
        if(game[vl][0] == BC) {
            for(i = 0; i < SizeV; i++) {
                for(j=0;j<SizeH; j++) {
                    searched[i][j] = FALSE;
                }
            }
            searched[vl][0] = TRUE;
            if(search(game, SizeV, SizeH, vl, 0, blue, h, searched) == BC) return BC;
        }
    }
    
    for(hz = 0; hz<SizeH; hz++) {
        if(game[0][hz]==GC) {
            for(i = 0; i< SizeV; i++) {
                for(j=0;j<SizeH; j++) {
                    searched[i][j] = FALSE;
                }
            }
            searched[0][hz] = TRUE;
            if (search(game, SizeV, SizeH, 0, hz, gold, v, searched) == GC) return GC;
        }
    }
    return 0;

}


char search(char game[][maxH], int SizeV, int SizeH, int i, int j, player p, dir d, int searched[SizeV][SizeH])
{
    if(p == blue)
    {
        if(j == (SizeH-1)) return BC;
        else
        {
            if(((i)>=0 && (i)<SizeV && (j-1)>=0 && (j-1)<SizeH) && (game[i][j-1] == BC) && (searched[i][j-1] == FALSE)) {
                searched[i][j-1] = TRUE;
                if(search(game, SizeV, SizeH, i, j-1, blue, v, searched) == BC) return BC;
            }
            if(((i-1)>=0 && (i-1)<SizeV && (j)>=0 && (j)<SizeH) && (game[i-1][j] == BC) && (searched[i-1][j]==FALSE)) {
                searched[i-1][j]= TRUE;
                if(search(game, SizeV, SizeH, i-1, j, blue, v, searched) == BC) return BC;
            }
            if(((i-1)>=0 && (i-1)<SizeV && (j+1)>=0 && (j+1)<SizeH) && (game[i-1][j+1] == BC) && (searched[i-1][j+1]== FALSE)) {
                searched[i-1][j+1] = TRUE;
                if (search(game, SizeV, SizeH, i-1, j+1, blue, v, searched) == BC) return BC;
            }
            if(((i)>=0 && (i)<SizeV && (j+1)>=0 && (j+1)<SizeH) && (game[i][j+1] == BC) && (searched[i][j+1]== FALSE)) {
                searched[i][j+1] = TRUE;
                if (search(game, SizeV, SizeH, i, j+1, blue, v, searched) == BC) return BC;
            }
            if(((i+1)>=0 && (i+1)<SizeV && (j)>=0 && (j)<SizeH) && (game[i+1][j] == BC) && (searched[i+1][j]== FALSE)) {
                searched[i+1][j] = TRUE;
                if (search(game, SizeV, SizeH, i+1, j, blue, v, searched) == BC ) return BC;
            }
            if(((i+1)>=0 && (i+1)<SizeV && (j-1)>=0 && (j-1)<SizeH) && (game[i+1][j-1] == BC) && (searched[i+1][j-1]== FALSE)) {
                searched[i+1][j-1] = TRUE;
                if (search(game, SizeV, SizeH, i+1, j-1, blue, v, searched) == BC) return BC;
            }
        }
    }
    
    
    if(p == gold) {
       if (i == (SizeV-1)) return GC;
       else {
           if(((i)>=0 && (i)<SizeV && (j-1)>=0 && (j-1)<SizeH) && (game[i][j-1] == GC) && (searched[i][j-1] == FALSE)) {
               searched[i][j-1] = TRUE;
               if (search(game, SizeV, SizeH, i, j-1, gold, h, searched) == GC) return GC;
           }
           if(((i-1)>=0 && (i-1)<SizeV && (j)>=0 && (j)<SizeH) && (game[i-1][j] == GC) && (searched[i-1][j]==FALSE)) {
               searched[i-1][j]= TRUE;
               if (search(game, SizeV, SizeH, i-1, j, gold, h, searched) == GC) return GC;
           }
           if(((i-1)>=0 && (i-1)<SizeV && (j+1)>=0 && (j+1)<SizeH) && (game[i-1][j+1] == GC) && (searched[i-1][j+1]== FALSE)) {
               searched[i-1][j+1] = TRUE;
               if (search(game, SizeV, SizeH, i-1, j+1, gold, h, searched) == GC) return GC;
           }
           if(((i)>=0 && (i)<SizeV && (j+1)>=0 && (j+1)<SizeH) && (game[i][j+1] == GC) && (searched[i][j+1]== FALSE)) {
               searched[i][j+1] = TRUE;
               if (search(game, SizeV, SizeH, i, j+1, gold, h, searched) == GC) return GC;
           }
           if(((i+1)>=0 && (i+1)<SizeV && (j)>=0 && (j)<SizeH) && (game[i+1][j] == GC) && (searched[i+1][j]== FALSE)) {
               searched[i+1][j] = TRUE;
               if (search(game, SizeV, SizeH, i+1, j, gold, h, searched) == GC) return GC;
           }
           if(((i+1)>=0 && (i+1)<SizeV && (j-1)>=0 && (j-1)<SizeH) && (game[i+1][j-1] == GC) && (searched[i+1][j-1]== FALSE)) {
               searched[i+1][j-1] = TRUE;
              if (search(game, SizeV, SizeH, i+1, j-1, gold, h, searched) == GC) return GC;
           }
       }
    }
    return 0;
}




