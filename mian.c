/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mian.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:54:15 by znichola          #+#    #+#             */
/*   Updated: 2022/11/17 16:50:22 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char ** argv)
{
	t_stack	stack;
	
	ft_strlen("sdfds");
	ft_printf("my printf test\n");

	if (argc != 3)
		return (message_ret(1, 1, "ags error"));
	if (process_input_nums(&stack, argv[2]))
		return (message_ret(1, 1, "num error"));
	if (process_input_ops(&stack, argv[1]))
		return(ft_freeret_3(0, stack.root_a, stack.root_b, stack.solution) + 
			message_ret(1, 1, "ops error"));
	print_stack(&stack);
	if (execute_ops(&stack) == SUCCESS)
		return (message_ret(SUCCESS, 1, "OK"));
	// print_stack(&stack);
}