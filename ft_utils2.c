/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:39 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/07/05 14:42:40 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	char	*str;
	size_t	i;

	i = 0;
	str = ptr;
	while (i < num)
		str[i++] = value;
	return (ptr);
}
