
#include "../fdf.h"

int	key_hook(int keycode, t_param *grid)
{
	(void)grid;
	if (keycode == KEY_ESCAPE)
		exit(0);
	return (0);
}
