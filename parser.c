#include "minishell.h"

int	ft_in(char c, char *str)

{
	while(str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}


	