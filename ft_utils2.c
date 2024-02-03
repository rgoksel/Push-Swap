/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:57:06 by rdemiray          #+#    #+#             */
/*   Updated: 2023/08/28 21:48:27 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_word_count(const char *s, char c)
{
	size_t	num;

	num = 0;
	while (*s)
	{
		if (*s != c)
		{
			++num;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (num);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	ret = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!ret)
		return (0);
	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue ;
		}
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		ret[i++] = ft_substr(s, 0, len);
		s += len;
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;
	size_t	i;

	s_len = ft_strlen((char *)s);
	i = 0;
	if (!s)
		return (NULL);
	if (len > s_len)
		len = s_len;
	if (start >= s_len)
	{
		substr = (char *)malloc(1);
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	substr = (char *)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	while (i++ < start)
		s++;
	ft_strlcpy(substr, s, len + 1);
	return (substr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen((char *)src);
	i = 0;
	if (dstsize <= 0)
		return (len);
	while (i < (dstsize -1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		start;

	i = 0;
	start = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	str = (char *)malloc((ft_strlen((char *) s1) + ft_strlen((char *) s2)) \
	* sizeof(char) + 1);
	if (!(str))
		return (0);
	while (s1[i])
		str[start++] = s1[i++];
	i = 0;
	while (s2[i])
		str[start++] = s2[i++];
	free(s1);
	str[start] = '\0';
	return (str);
}
