#include <stdio.h>

int	main(void)
{
	float	rx;
	float	rx2;
	float	mx;
	float	px;

	px = 7.3;
	rx = (((int)px >> 6) << 6) + 64;
	printf("%f\n", rx);
	mx = (float)(64 / px);
	printf("%d\n", mx);
	rx2 = (((int)px >> 6) << 6) - 0.0001;
	printf("%f\n", rx2);
	mx = (int)rx2 / 64;
	printf("%d\n", mx);
}

// void Buttons(unsigned char key,int x,int y)
// {
// 	if(key=='a')
// 	{
// 		mlx->player->pa = ft_adjust_angle(mlx->player->pa + 5);
// 		printf("pa is %f\n", mlx->player->pa);
// 		mlx->player->pdx = cos(ft_deg_to_rad(mlx->player->pa));
// 		printf("pdx is %f\n", mlx->player->pdx);
// 		printf("px is %f\n", mlx->player->px);
// 		mlx->player->pdy = -sin(ft_deg_to_rad(mlx->player->pa));
// 		printf("pdy is %f\n", mlx->player->pdy);
// 		printf("py is %f\n", mlx->player->py);
// 		printf("==============\n");
// 	}
// 	if(key=='d')
// 	{
// 		mlx->player->pa = ft_adjust_angle(mlx->player->pa - 5);
// 		printf("pa is %f\n", mlx->player->pa);
// 		mlx->player->pdx = cos(ft_deg_to_rad(mlx->player->pa));
// 		printf("pdx is %f\n", mlx->player->pdx);
// 		printf("px is %f\n", mlx->player->px);
// 		mlx->player->pdy = -sin(ft_deg_to_rad(mlx->player->pa));
// 		printf("pdy is %f\n", mlx->player->pdy);
// 		printf("py is %f\n", mlx->player->py);
// 		printf("==============\n");
// 	}
// 	if(key=='w')
// 	{
// 		printf("pdx is %f\n", mlx->player->pdx);
// 		mlx->player->px = mlx->player->px + (mlx->player->pdx * 5);
// 		printf("px is %f\n", mlx->player->px);
// 		printf("pdy is %f\n", mlx->player->pdy);
// 		mlx->player->py = mlx->player->py + (mlx->player->pdy * 5);
// 		printf("py is %f\n", mlx->player->py);
// 		printf("==============\n");
// 	}
// 	if(key=='s')
// 	{
// 		printf("pdx is %f\n", mlx->player->pdx);
// 		mlx->player->px = mlx->player->px - (mlx->player->pdx * 5);
// 		printf("px is %f\n", mlx->player->px);
// 		printf("pdy is %f\n", mlx->player->pdy);
// 		mlx->player->py = mlx->player->py - (mlx->player->pdy * 5);
// 		printf("py is %f\n", mlx->player->py);
// 		printf("==============\n");
// 	}
// }