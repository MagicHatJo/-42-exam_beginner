#include <unistd.h>

#define DISPLAY_OPT write(1, "options: abcdefghijklmnopqrstuvwxyz", 35)
#define DISPLAY_INV write(1, "Invalid Option", 14)
#define IS_LOWER(x) (x >= 'a' && x <= 'z' ? 1 : 0)
#define SHIFTED(x) (1 << (x))

int	options(int ac, char **av)
{
	int	opt = 0;

	for (int i = 0; i < ac; i++)
		if (av[i][0] == '-')
			for (int k = 1; av[i][k]; k++)
			{
				if (!IS_LOWER(av[i][k]))
					return (-1);
				opt |= SHIFTED(av[i][k] - 'a');
			}
	return (opt);
}

void	print_int(int opt)
{
	if ((opt >> ('h' - 'a')) & 1)
		DISPLAY_OPT;
	else
		for (int i = 31; i >= 0; i--)
		{
			write(1, (((opt >> i) & 1) ? "1" : "0"), 1);
			if (i && !(i % 8))
				write(1, " ", 1);
		}
}

int	main(int ac, char **av)
{
	int	opt;
	if (ac > 1)
	{
		if ((opt = options(ac - 1, &av[1])) == -1)
			DISPLAY_INV;
		else
			print_int(opt);
	}
	else
		DISPLAY_OPT;
	write(1, "\n", 1);
	return (0);
}
