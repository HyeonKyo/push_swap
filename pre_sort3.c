#include "ft_type.h"
#include "ft_utils.h"
#include "list.h"
#include "push_swap.h"

void	before_bios(t_sort *repo, t_ll bios)
{
	int	i;

	i = 0;
	while (i < repo->size)
		repo->arr[i++] -= bios;
}

void	radix_sort(t_deque *deq, t_sort *repo, t_ll bios, int max)
{
	int	i;
	int	digit;

	digit = find_digit(bios + max);
	putin_data(deq, repo, bios);
	i = 1;
	while (i <= digit)
		sorting(repo, bios, i++);
	before_bios(repo, bios);
}

void	pre_sort(t_deque *deq, int base, t_pivot *piv)
{
	int	max;
	int	min;
	int	len;
	t_ll	bios;
	t_sort	*repo;

	len = check_stack(deq, base, &max, &min);
	repo = make_repo(len);
	bios = 0;
	if (min < 0)
		bios = -1 * min;
	radix_sort(deq, repo, bios, max);
	//choose_pivot(piv, repo);
	//clear_repo();
}