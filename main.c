/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:54:15 by znichola          #+#    #+#             */
/*   Updated: 2022/12/02 14:04:02 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// TODO: for today
/**
 * [ ] fix process input ops
 * [ ] validate execute ops
 * [ ] good stack displayer fuction
 * [ ] have a checker that i can test and works
 * [ ] write todo for the pushswap 
 */

int	main(int argc, char ** argv)
{
	t_stack	stack;
	
	if (argc != 3)
		return (message_ret(1, 1, "ags error"));
	if (process_input_nums(&stack, argv[2]))
		return (message_ret(1, 1, "num error"));
	if (process_input_ops(&stack, argv[1]))
		return(ft_freeret_3(0, stack.root_a, stack.root_b, stack.solution) + 
			message_ret(1, 1, "ops error"));
	ft_printf("here\n");
	print_stack(&stack);
	if (execute_ops(&stack) == SUCCESS)
		return (message_ret(SUCCESS, 1, "OK"));

// print_stack(&stack);
// 	free(stack.root_a);
// 	free(stack.root_b);
// 	free(stack.ops_root);

}
