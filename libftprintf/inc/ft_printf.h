/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:59:20 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/05/27 16:00:38 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FT_PRINTF_H
# define PRINTF_FT_PRINTF_H
# define TRUE 1
# define FALSE 0
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <wchar.h>
# include "libft.h"
# define FLAGS "#-+0 hljz"
# define DIGITS "0123456789."
# define CONV "idDoOuUxXsScCp%"

typedef struct		s_flags
{
	int				hash;
	int				zeros;
	int				minus;
	int				plus;
	int				blank;

}					t_flags;

typedef struct		s_len
{
	int				len_h;
	int				len_l;
	int				len_j;
	int				len_z;

}					t_len;

typedef struct		s_conv
{
	t_len			lenght;
	t_flags			flags;
	int				width;
	int				precision;
	char			conv;
	int				dot;
	int				temp;
	intmax_t		arg;
}					t_conv;

char				*ft_itoa_base(uintmax_t nb, int base, int capitilise);
int					ft_len_u(uintmax_t nb, int base);
int					ft_ustrlen(wchar_t *value);
int					ft_ucharlen(wchar_t value);
int					ft_putwchar(wchar_t nmb);

int					ft_printf(char *format, ...);
void				pf_checkplus(t_conv *fl, int *ret);
void				check(t_conv *fl, int *ret, int widhlen);
void				parsestr1(char *str, int len, t_conv *fl, int *ret);
void				parsestr2(t_conv *fl, int len, int *ret);
void				utf_parselenstr(t_conv *fl, int len, wchar_t *wstr);
int					ulen(wchar_t *str, t_conv *fl);
void				ft_findlp(char *str, t_conv *fl, size_t *pos);
void				ft_findlp1(char *str, t_conv *fl, size_t *pos, int len);
t_conv				ft_checkfalgs(char str, t_conv *fl);
void				another_symb(char str, t_conv *fl, int *ret);
intmax_t			ft_parse_sign(t_conv *fl, va_list *arg_ptr);
int					ft_numbers(t_conv *fl, va_list *arg_ptr);
int					ft_conv(char str, t_conv *new, va_list *arg_ptr);
size_t				ft_reading(char **str, va_list *arg_ptr, int *step);
int					ft_str(t_conv *fl, va_list *arg_ptr);
int					ft_chars(t_conv *fl, va_list *arg_ptr);
int					fl_unsconv(t_conv *fl, va_list *arg_ptr, int base);
void				write_precision(t_conv *fl, int widthlen, int *ret);
char				*cast_unsigned(va_list *arg_ptr, int base, t_conv *fl, \
int cap);
int					ft_point(t_conv *fl, va_list *arg_ptr, int base);
void				print_unsigned_hash(t_conv *fl, int len, int *ret,\
char *value);
void				write_zero_blank(t_conv *fl, int *ret, intmax_t arg, \
int widhlen);
void				utf_str(wchar_t *wstr, int len, t_conv *fl, int *ret);

#endif
