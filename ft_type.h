/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:28 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/07/05 14:42:28 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPE_H
# define FT_TYPE_H
# include <stdlib.h>

typedef long long	t_ll;

typedef	struct	s_pivot
{
	int	big;
	int	sml;
}				t_pivot;


typedef struct	s_list
{
	int	data;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

typedef struct	s_deque
{
	int		size;
	t_list	*top;
	t_list	*bot;
}				t_deque;

typedef struct	s_cd_lst
{
	char	*cmd;
	struct s_cd_lst	*next;
}				t_cd_lst;

typedef struct	s_cd_deq
{
	int		size;
	t_cd_lst	*head;
	t_cd_lst	*last;
}				t_cd_deq;

typedef struct	s_qu_lst
{
	t_ll	data;
	struct s_qu_lst	*next;
}				t_qu_lst;

typedef struct	s_queue
{
	int	size;
	t_qu_lst	*fst;
	t_qu_lst	*last;
}				t_queue;

typedef struct	s_sort
{
	int	size;
	t_ll	*arr;
}				t_sort;	

#endif
