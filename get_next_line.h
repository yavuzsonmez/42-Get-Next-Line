/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:24:00 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/29 12:06:38 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

/*
*	LIBRARIES
*/
# include <stdlib.h>
# include <unistd.h>

/*
*	PROTOTYPES
*/

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strchr_pos(const char *s, int c);

char	*get_next_line(int fd);

/*
*	DATA STRUCT
*/

typedef struct s_data
{
	char	*buff;
	char	*newline;
	int		r;
	int		i;
}	t_data;

#endif
