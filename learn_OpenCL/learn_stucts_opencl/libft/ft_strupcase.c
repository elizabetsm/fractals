/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 21:25:13 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/07 22:05:11 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char *a;

	a = str;
	if (str)
		while (*str)
		{
			if (*str >= 'a' && *str <= 'z')
				*str -= 32;
			str++;
		}
	return (a);
}