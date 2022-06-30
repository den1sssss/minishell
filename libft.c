#include "minishell.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!*s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s1);
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (NULL);
	dst[len] = 0;
	if (len)
	{
		while (len--)
			dst[len] = s1[len];
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	i = 0;
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

int	ft_atoi(const char *str)
{
	unsigned long	s;
	int				zn;

	s = 0;
	zn = 1;
	while (*str == '\f' || *str == '\t' || *str == '\r' \
	|| *str == '\v' || *str == '\n' || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		zn = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		s = s * 10 + *str - '0';
		str++;
		if (s > 2147483647 && zn + 1)
			return (-1);
		if (s > 2147483648)
			return (0);
	}
	return ((int) s * zn);
}

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c && *s != 0)
		s++;
	if (c != 0 && *s == 0)
		return (NULL);
	return ((char *)s);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sum;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	sum = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!sum)
		return (NULL);
	while (*s1)
		sum[i++] = *s1++;
	while (*s2)
		sum[i++] = *s2++;
	sum[i] = 0;
	return (sum);
}
