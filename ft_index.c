/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:39:23 by rdemiray          #+#    #+#             */
/*   Updated: 2023/08/28 20:23:01 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_next_min(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp_min;
	int		flag;

	temp_min = 0;
	flag = 1;
	temp = *stack;
	if (temp)
	{
		while (temp)
		{
			if ((temp->index == -1) && \
				(flag || temp->content < temp_min->content))
			{
				temp_min = temp;
				flag = 0;
			}
			temp = temp->next;
		}
	}
	return (temp_min);
}

void	ft_index(t_stack **stack)
{
	t_stack	*temp;
	int		index;

	index = 0;
	temp = get_next_min(stack);
	while (temp)
	{
		temp->index = index++;
		temp = get_next_min(stack);
	}
}
