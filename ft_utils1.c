#include "ft_utils.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_isspace(int c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*str;

	if (s1 == 0 || s2 == 0)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = ' ';
	j = 0;
	while (i < len)
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}

char	*ft_strdup(const char *src)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (src[i])
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (temp == 0)
		return (0);
	while (++j <= i)
		temp[j] = src[j];
	return (temp);
}