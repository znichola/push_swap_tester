/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:05:30 by znichola          #+#    #+#             */
/*   Updated: 2022/11/17 00:43:46 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0' && len > 0)
	{
		b = (char *)big;
		l = (char *)little;
		i = len;
		while (*b++ == *l++ && i-- > 0)
			if (*l == '\0')
				return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}

static int find_opp(char *str, size_t len)
{
	if (!ft_strnstr(str, "SA", len))
		return (SA);
	if (!ft_strnstr(str, "SB", len))
		return (SB);
	if (!ft_strnstr(str, "SS", len))
		return (SS);
	if (!ft_strnstr(str, "PA", len))
		return (PA);
	if (!ft_strnstr(str, "PB", len))
		return (PB);
	if (!ft_strnstr(str, "RA", len))
		return (RA);
	if (!ft_strnstr(str, "RB", len))
		return (RB);
	if (!ft_strnstr(str, "RR", len))
		return (RR);
	if (!ft_strnstr(str, "RRA", len))
		return (RRA);
	if (!ft_strnstr(str, "RRB", len))
		return (RRB);
	if (!ft_strnstr(str, "RRR", len))
		return (RRR);
	return (FAILURE);
}

static int addopp(t_stack *s, char **str)
{
	char	*end;
	size_t	len;
	int		opp;

	while (ft_isspace(**str) && **str != '\0')
		(*str)++;
	end = (char *)*str;
	while (!ft_isspace(*end) && *end != '\0')
		end++;
	len = end - *str + 1;
	printf("here len:%ld\n", len);
	if (len > 1)
	{
		opp = find_opp(*str, len);
		if (opp == FAILURE)
			return (message_ret(FAILURE, 2, "find op error"));
		*s->ops = opp;
		s->ops++;
	}
	*str = end + 1;
	return (SUCCESS);
}

int	process_input_ops(t_stack *s, char *str)
{
	int	len;
	int	i;
	
	len = ft_count_args(str);
	s->ops_root = (int *)malloc(sizeof(int) * len);
	if (!s->ops_root)
		return (message_ret(ERROR, 2, "ops malloc error"));
	s->ops = s->ops_root;
	*s->ops = EMPTY;
	i = -1;
	while(i++ < len)
		if (addopp(s, &str) == FAILURE)
			return (message_ret(0, 2, "add ops error")
				+ ft_freeret_1(FAILURE, s->ops_root));
	printf("process ops len:%d\n", len);
	for (int i = 0; i < len; i++)
		printf("%d\n", s->ops_root[i]);
	return (SUCCESS);
}