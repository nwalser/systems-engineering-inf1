/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: NathanielWalser
 *
 * Created on September 22, 2022, 3:24 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int value = 0;
    
    printf("Enter Value: ");
    scanf("%d", &value);
    
    printf("Value is: ");
    printf("%d", value);

    return 0;
}