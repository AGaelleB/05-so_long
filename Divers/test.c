// #include <stdio.h>
// #include <conio.h>

// int main(void) {
//     int key;
//     printf("Presser une touche de clavier: ");
//     key = getch();
//     printf("Le numero de la touche pressée est : %d\n", key);
//     return 0;
// }

// #include<stdio.h>
// int main (void)
// { char c;

// do{
// printf("presser une touche de clavier");
// scanf("%c",&c);
// printf("Le code ascci de %c est %d",c,c);
// }while(c!=0); // le programme se termine en tapant 0

// getch();
// return 0;
// }

// #include <stdio.h>
// #include <conio.h>

// int main() {
// 	int c;
	
// 	c = getch();
// 	printf("%d\n", c);

// 	c = getch();
// 	printf("%d\n", c);

// 	return 0;
// }

#include "../includes/so_long.h"


int		main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "mlx_hook key press example");
	mlx_hook(win, 2, 1L<<0, key_press, 0);
	mlx_loop(mlx);
	return (0);
}
