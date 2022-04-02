/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:09:23 by mait-aad          #+#    #+#             */
/*   Updated: 2022/04/02 19:54:56 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mov_f(int	*list, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		list[i] = list[i + 1];
}

void	sent_stack2(int *list1, int	*list2, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = list2[i + 1];
		list2[len] = list2[len - 1];
		len--;
	}
	list2[0] = list1[0];
	mov_f(list1, len);
	write(1, "pa\n", 3);
	if (list2[0] < list2[1])
	{
		j = list2[0];
		list2[0] = list2[1];
		list2[1] = j;
		write (1, "m\n", 3);
	}
}

void	chan_f_s(int	*list)
{
	int	i;

	i = list[1];
	list[1] = list[0];
	list[0] = i;
}

void	return_to_stack1(int	*list1, int	*list2, int len)
{
	
}

void	ft_moves(int *list1, int	*list2, int deg, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		while (deg < 1)
		{
			if (list1[i] / deg < list1[i + 1] / deg)
				sent_stack2(list1, list2, len--);
			else if (list1[i] / deg > list1[i + 1] / deg)
			{
				chan_f_s(list1);
				sent_stack2(list1, list2, len--);
			}
			else
				deg = deg / 10;
		}
		i++;
	}
	return_to_stack1(list1, list2, i);
}

int	finde_degree(int *list)
{
	int	i;
	int	max;
	int	degree;

	i = 0;
	max = 0;
	while (list[i])
	{
		if (list[i] > max)
			max = list[i];
		i++;
	}
	i = 0;
	while (max > 9)
	{
		max / 10;
		i++;
	}
	max = 0;
	degree = 1;
	while (max++ < i)
		degree = degree * 10;
	return (degree);
}

void	ft_sort(char **c_n, int	*stack1, int len)
{
	int	j;
	int	*stack2;
	int	degree;

	j = 0;
	while (j < len)
	{
		stack1[j] = ft_atoi(c_n[j]);
		j++;
	}
	stack2 = (int *)malloc(sizeof(int) * len);
	degree = finde_degree(stack1);
	ft_moves(stack1, stack2, degree, len);
}

int	main(int ac, char	**av)
{
	char	**chr_nums;
	int		*nums;
	int		i;

	nums = (int *)malloc(sizeof(int) * (ac - 1));
	ft_sort(av + 1, nums, ac - 1);
}