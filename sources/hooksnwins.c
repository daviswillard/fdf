
#include "../fdf.h"

int	key_hook(int keycode, t_param *grid)
{
	if (keycode == 53)
		exit(0);
	return (0);
}
