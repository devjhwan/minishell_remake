/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:14:57 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 00:02:24 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nb)
{
	int	len;

	len = 1;
	if (nb < 0)
		len++;
	while (nb > 9 || nb < -9)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static void	ft_itoa_rec(char *ret, int nb, int *i)
{
	if (nb > 9 || nb < -9)
		ft_itoa_rec(ret, nb / 10, i);
	ret[(*i)++] = ft_abs(nb % 10) + '0';
}

char	*ft_itoa(int nb)
{
	int		len;
	char	*ret;
	int		i;

	len = ft_len(nb);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret != NULL)
	{
		i = 0;
		if (nb < 0)
			ret[i++] = '-';
		ft_itoa_rec(ret, nb, &i);
		ret[i] = '\0';
	}
	return (ret);
}
