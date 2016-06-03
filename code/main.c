//
//  main.c
//  hw8
//
//  Created by Alex Salas on 4/18/15.
//  Copyright (c) 2015 Alex. All rights reserved.
//

#include <stdio.h>
#include "hw8.h"
int main() {
    char smallGame [ ][maxH] = {
    {'b', 'b',' ','b', ' '},
    {' ', 'b' ','g','g'},
    {'g',' ', 'b', 'g','b'},
    {'b','b',' ','g','g'},
    {'b','b','b', ' ', 'b'}
    };
    printf("%c", eval(smallGame, 5,5));
    
    //printf("%c", smallGame[0][0]);
    return 0;
}
