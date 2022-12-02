/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:54:02 by znichola          #+#    #+#             */
/*   Updated: 2022/12/02 15:02:15 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	display_ops(t_stack *s)
{
	int	i;

	i = -1;
	while(++i < s->ops - s->ops_root)
	{
		if (write_ops(i))
			ft_printf("overflow ops");
	}
	return (0);
}
