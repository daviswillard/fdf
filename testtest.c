#include "fdf.h"

int main()
{
	void	*mlx;
	int		matrix[601][601];
	int		metrix[1001][1001];
	int		mutrix[601][601];
	void	*mlx_win;
	int		k;
	int		l;
	int		m;
	int		n;
	int		i;
	int		j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 1000, "Hello world!");
	m = 0;
	while (m < 1001)
	{
		n = 0;
		while (n < 1001)
			metrix[m][n++] = 0;
		m++;
	}
	k = 0;
	while (k < 1001)
	{
		l = 0;
		while (l < 1001)
			metrix[k][l++] = 0;
		k++;
	}
	i = 0;
	while (i < 301)
	{
		j = 0;
		while (j < 301)
		{
			if (i == 0 || i == 300 || j == 0 || j == 300)
				matrix[i][j] = 1;
			else if (i % 30 == 0 && j % 30 == 0)
				matrix[i][j] = 1;
			else
				matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 301)
	{
		j = 0;
		while (j < 301)
		{
			if (matrix[i][j] == 1)
			{
				n = j * cos(PI / 4) + i * sin(PI / 4);
				m = (-j * sin(PI / 4)) + i * cos(PI / 4);
				m += 250;
				metrix[m][n] = 1;
			}
			j++;
		}
		i++;
	}
	m = 0;
	while (m < 1001)
	{
		n = 0;
		while (n < 1001)
		{
			if (metrix[m][n] == 1)
			{
				k = m;
				l = n / 3;
				mutrix[k][l] = 1;
			}
			n++;
		}
		m++;
	}
	i = 0;
	while (i < 301)
	{
		j = 0;
		while (j < 301)
		{
			if (matrix[i][j] == 1)
				mlx_pixel_put(mlx, mlx_win, j, i + 100, 0x0000FF00);
			j++;
		}
		i++;
	}
	n = 0;
	while (n < 601)
	{
		m = 0;
		while (m < 601)
		{
			if (metrix[n][m] == 1)
				mlx_pixel_put(mlx, mlx_win, m + 300, n + 3, 0x00FF0000);
			m++;
		}
		n++;
	}
	k = 0;
	while (k < 601)
	{
		l = 0;
		while (l < 601)
		{
			if (mutrix[k][l] == 1)
				mlx_pixel_put(mlx, mlx_win, k + 265, l + 465, 0x000000FF);
			l++;
		}
		k++;
	}
	mlx_loop(mlx);
	return (0);
}
