/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiestas <cfiestas@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:00:04 by cfiestas          #+#    #+#             */
/*   Updated: 2022/11/17 01:55:33 by cfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_invalid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (1);
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_length;
	int	pos;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (ft_invalid_base(base))
		return ;
	base_length = 0;
	while (base[base_length])
		base_length++;
	if (base_length < 2)
		return ;
	if (nbr > 1)
		ft_putnbr_base(nbr / base_length, base);
	if (nbr != 0)
	{
		pos = nbr % base_length;
		write(1, &base[pos], 1);
	}
}
/*
int	main()
{
	ft_putnbr_base(-42, "01");
	return (0);
}*/
