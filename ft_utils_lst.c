/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:31:45 by rdemiray          #+#    #+#             */
/*   Updated: 2023/08/28 20:22:51 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	size_t	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = malloc (sizeof(t_stack));
	if (!new)
		return (((t_stack *)0));
	new->content = content;
	new->index = -1;
	new->next = 0;
	return (new);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*last;

	last = lst;
	if (last)
	{
		while (last -> next)
			last = last->next;
	}
	return (last);
}
