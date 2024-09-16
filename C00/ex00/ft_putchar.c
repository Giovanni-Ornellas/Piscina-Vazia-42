/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_putchar.c                                                             */
/*                                                                            */
/*   By: Giovanni Ornellas                                                    */
/*                                                                            */
/*   Created: 2024/09/16 by Giovanni Ornellas                                 */                                   
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void ft_putchar(char letra);

int main(){
    char letra;
    printf("Digite uma letra:");
    scanf("%c",&letra);
    ft_putchar(letra);
    return 0;
}

void ft_putchar(char letra){
    write(1,&letra,1);
    printf("\n");
}
