/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:43:03 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/09 15:26:19 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putnbr_ret(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr_ret(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n *= -1;
		}
		ft_putnbr_ret(n);
	}
}
