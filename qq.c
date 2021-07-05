/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qq.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:43:01 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/07/05 14:43:02 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>

// size_t	ft_strlen(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }


// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	len;
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (s1 == 0 || s2 == 0)
// 		return (0);
// 	len = ft_strlen(s1) + ft_strlen(s2) + 1;
// 	str = (char *)malloc((len + 1) * sizeof(char));
// 	if (str == 0)
// 		return (0);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	str[i++] = ' ';
// 	j = 0;
// 	while (i < len)
// 		str[i++] = s2[j++];
// 	str[i] = 0;
// 	return (str);
// }

// int main(int ac, char **av)
// {
// 	char *str = ft_strjoin(av[1], av[2]);

// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }
