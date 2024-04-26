/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:39:59 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 20:09:15 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
[Norm]

Hi hitchhikers,
I have a question about norm, specifically static variables.
I am currently attempting to make a struct work like a C++ class.
What I am trying to do is create a function that contains a static struct variable, instantiate it only for the first time when the function is called, and return the instantiated struct.
Shortly, I'm implementing Singleton with my struct. I will attach the code that I tested down here.

The wonder that I have is, 'Is it  allowed by norms?' because I never used static variables before except for gnl project.
So I checked Norm V4 and there was a single line showing, 'Using global variables that are not marked const and static is forbidden and is
considered a norm error, unless the project explicitly allows them.'.

If I didn't misunderstand, norm says that static variables are forbidden unless the project explicitly allows it, but I focused on the word 'unless'.
I checked the get_next_line subject (English version) to check if this project is explicitly allowing the static variable, but I couldn't find any phrase that mentions 'you are allowed to use static variables'.

Now, I want to ask a peer's opinion on whether static variables are allowed or not.

PS: I am actually doing minishell project.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct s_test
{
	int	nb;
}	t_test;

t_test	*get_test(void)
{
	static t_test	*test;

	if (test == NULL)
		test = (t_test *)calloc(1, sizeof(t_test));
	return (test);
}

int	main(void)
{
	printf("%p %d\n", get_test(), get_test()->nb);
	printf("%p %d\n", get_test(), get_test()->nb);
	get_test()->nb = 1;
	printf("%p %d\n", get_test(), get_test()->nb);
	return (0);
}

/*	=====OUTPUT=====
	0x7fa423c05840 0
	0x7fa423c05840 0
	0x7fa423c05840 1
*/
