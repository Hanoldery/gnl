/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_in_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:18:33 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/12/19 14:18:54 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	lst_del_if(t_list **a, char *s, int i)
{
	t_list	*last;
	t_list	*current;
	t_list	*nxt;

	if (!*a || !(*a)->next)
		return ; // Gerer ca en up
	current = *a;
	nxt = (*a)->next;
	while (!ft_strncmp((char*)(*a)->content, s, i) && nxt->next)
	{
		last = current;
		current = nxt;
		current = nxt->next;
	}
	if (current->content)
		free(current->content);
	free(current);
	last->next = nxt;
}

void	ft_lstchangeif(t_list **alst, void* cnt, void* ncnt)
{
	if (!*alst)
		return ;
	while (*alst)
	{
		if (ft_strncmp((*alst)->content, cnt, 1))
			(*alst)->content = ft_strcpy((*alst)->content, ncnt);
		*alst = (*alst)->next;
	}
}

t_list	*lst_exist(t_list *lst, char *str)
{
	while (lst)
	{
		if (((char *)lst->content)[0] == str[0])
			return lst;
		lst = lst->next;
	}
	return NULL;
}
