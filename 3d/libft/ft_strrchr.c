/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:36:03 by sbecker           #+#    #+#             */
/*   Updated: 2018/11/30 17:33:55 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*a;

	a = 0;
	while (*s)
	{
		if (*s == c)
			a = (char*)s;
		s++;
	}
	if (*s == c)
		return ((char*)s);
	if (a != 0)
		return (a);
	return (0);
}
