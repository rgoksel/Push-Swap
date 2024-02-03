/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:58:38 by rdemiray          #+#    #+#             */
/*   Updated: 2023/08/28 21:10:29 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bit(t_stack **stack)
{
	t_stack	*temp;
	int		max_num;
	int		max_bit;

	temp = *stack;
	max_num = temp->index;
	max_bit = 0;
	while (temp)
	{
		if (temp->index > max_num)
			max_num = temp->index;
		temp = temp->next; 
	}
	while ((max_num >> max_bit))
		max_bit++;
	return (max_bit);
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	size = ft_lstsize(*stack_a);
	max_bits = max_bit(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b))
			ft_pa(stack_a, stack_b);
		i++;
	}
}
