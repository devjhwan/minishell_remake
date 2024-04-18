/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:36:57 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/18 21:40:18 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_dec3(char *buff, t_flag *flag, int d, t_pack p)
{
	if (!(flag->f & ZERO) && p.sign != 0)
		buff[p.i++] = p.sign;
	if (flag->f & PRECITION && flag->precition > 0)
	{
		ft_memset(&buff[p.i], '0', p.slen - p.nlen);
		p.i += p.slen - p.nlen;
	}
	if (flag->precition != 0 || d != 0)
	{
		ft_setnbr_base(&buff[p.i], (unsigned int)ft_abs(d), "0123456789");
		p.i += p.nlen;
	}
	if (flag->f & MINUS)
		ft_memset(&buff[p.i], ' ', p.width - p.slen - p.count);
	return (ft_flush_buffer(buff, p.width));
}

static int	ft_print_dec2(t_flag *flag, int d, t_pack p)
{
	char	*buff;

	buff = (char *)malloc(sizeof(char) * p.width);
	if (buff == NULL)
		return (-1);
	if (flag->f & _SPACE && p.sign == 0)
		buff[p.i++] = ' ';
	if (flag->f & ZERO)
	{
		if (p.sign != 0)
			buff[p.i++] = p.sign;
		ft_memset(&buff[p.i], '0', p.width - p.slen - p.count);
		p.i += p.width - p.slen - p.count;
	}
	else if (!(flag->f & MINUS))
	{
		ft_memset(&buff[p.i], ' ', p.width - p.slen - p.count);
		p.i += p.width - p.slen - p.count;
	}
	return (ft_print_dec3(buff, flag, d, p));
}

int	ft_print_dec(t_flag *flag, int d)
{
	t_pack	p;

	p.i = 0;
	p.sign = 0;
	p.count = 0;
	p.nlen = ft_nblen_base((unsigned int)ft_abs(d), 10);
	p.slen = p.nlen;
	if (flag->precition == 0 && d == 0)
		p.slen = 0;
	else if (flag->f & PRECITION)
		p.slen = ft_max(flag->precition, p.slen);
	if (flag->f & _SPACE)
		p.count++;
	if (d < 0)
		p.sign = '-';
	else if (flag->f & PLUS)
		p.sign = '+';
	if (p.sign != 0 && !(flag->f & _SPACE))
		p.count++;
	p.width = ft_max(flag->width, p.slen + p.count);
	return (ft_print_dec2(flag, d, p));
}
