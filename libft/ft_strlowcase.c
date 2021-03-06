/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 22:03:10 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/07 22:04:58 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char *a;

	a = str;
	if (str)
		while (*str)
		{
			if (*str >= 'A' && *str <= 'Z')
				*str += 32;
			str++;
		}
	return (a);
}
