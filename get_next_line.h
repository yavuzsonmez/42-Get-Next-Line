/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:24:00 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/20 10:37:16 by ysonmez          ###   ########.fr       */
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
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*
*	STATIC STRUCTURE
*/
typedef static struct s_struct
{
	char	*str;
}	t_struct;

#endif
