#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <unistd.h>
# include <stdlib.h>

//utils1
int	ft_isdigit(int c);
int	ft_isspace(int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);

//utils2
void	*ft_memset(void *ptr, int value, size_t num);
#endif