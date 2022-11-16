/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:55:47 by znichola          #+#    #+#             */
/*   Updated: 2022/11/17 00:07:49 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	message_ret(int sig, int fd, char *msg)
{
	while (*msg)
		write(fd, msg++, 1);
	write(fd, &"\n", 1);
	return (sig);
}

int	ft_freeret_1(int ret, void *x)
{
	free(x);
	return (ret);
}

int	ft_freeret_2(int ret, void *x, void *y)
{
	free(x);
	free(y);
	return (ret);
}

int	ft_freeret_3(int ret, void *x, void *y, void *z)
{
	free(x);
	free(y);
	free(z);
	return (ret);
}
