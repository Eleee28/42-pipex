/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:47:09 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:15:10 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/** 
 *  @struct s_flags
 * 
 * 	@brief Structure to hold formatting flags
 * 
 * 	@param justified Indicates whether the output is left-padded with 
 * 	zeroes ('0') or right-padded with spaces ('-'). 
 *  @details '-' has priority over '0'. 
 * 	'0' works only with numbers and '-' works with all.
 *  
 *  @param sign Indicates whether to print the sign, '+' or 1 space (' ').
 * 	@details '+' has priority over ' '. 
 *  It works only with positive numbers, with negative '-' will be printed.
 *
 * 	@param hex Indicates whether to print the hexadecimal notation ('#') or 
 *  not.
 *  @details Only for hexadecimal numbers, it prints '0x'.
 * 
 *  @param width Indicates the number of characters to be printed.
 *  @details It takes into account the effect of other flags.
 * 
 *  @param precision Indicates the maximum length (strings) or precision 
 *  (numbers).
 *  @details For strings: maximum length to be printed.
 * 	For numbers: width, filling with zeroes, only taking into account the 
 *  digits of the number.
 * 
 *  @param args Argument type
 * 	@details
 *  - c: character
 *  - s: string
 *  - p: pointer
 *  - d, i: decimal number
 *  - u: unsigned number
 *  - x, X: hexadecimal character (lower/upper case)
 *  - %: '%'
 * 
*/
typedef struct s_flags
{
	char	justified;
	char	sign;
	char	hex;
	int		width;
	int		precision;
	char	arg;
}			t_flags;

int		ft_printf(char const *str, ...);
int		ft_flags(t_flags *flags, char const *str);
void	ft_printchar(int *len, char c);
void	ft_putargs(int *len, t_flags *flags, va_list args);
void	ft_putchar(t_flags *flags, int *len, char c);
char	*ft_putnbr(t_flags *flags, int n);
char	*ft_puthex_up(t_flags *flags, unsigned int n);
char	*ft_puthex_low(t_flags *flags, unsigned int n);
char	*ft_putptr(t_flags *flags, unsigned long int n);
char	*ft_putstr(int precision, char *s);
char	*ft_putunsig(t_flags *flags, unsigned int n);
int		ft_strlen2(char *str);
int		ft_numlen(long int n);
int		ft_unsiglen(unsigned long int n, int base);
int		ft_toupper(int c);

#endif