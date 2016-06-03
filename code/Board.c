
/*
    Alejandro Salas
    2-13-15
    CS 49C Section 2
    Homework 2
    hexBoard: This function prints out a hexboard with m rows and n columns and return the hexboard that is drawn.
*/
#include <stdio.h>
char buf[2048];

char * hexBoard(int m, int n)
{
    char *bufp = buf;
    int i;  //keeps track of current column
    int x;  //keeps track of current row
    int z;  //keeps track of the spaces before each row
    
    bufp += sprintf(bufp, "\n");
    
    for(i=0; i<n; i++)  {                   // prints the first row of / \
        
        bufp += sprintf(bufp, " / \\");
    }

    for(x=0; x<m; x++)  {
        bufp += sprintf(bufp, "\n");
     
        for(z = x; z>0; z--)  {             //prints the spaces before the row of |
            
            bufp += sprintf(bufp, "  ");
        }
        
        for(i=0; i<=n-1; i++) {             //prints the | in each row
            
            bufp += sprintf(bufp, "|   ");
        }
        
        if(x != (m)) {                      // prints the last | in each row
            
            bufp += sprintf(bufp, "|");
        }
    
        bufp += sprintf(bufp, "\n");
        
        for(z = x; z>0; z--)  {             //prints the spaces before each row or \ /
            
            bufp += sprintf(bufp, "  ");
        }
        
        for(i=0; i<n; i++)  {               //prints the \ / in each row
            
            bufp += sprintf(bufp, " \\ /");
        }
        
        if(x != (m-1)) {                    //prints the final \ in each row
            
            bufp += sprintf(bufp, " \\");
        }
    }
    
   bufp += sprintf(bufp, "\n");
    
   return buf;
}