#include "libft.h"

static int	typecheck(char format, va_list *args, char *error_flag)
{
	int	print;

	if (*error_flag)
		return (-1);
	print = 0;
	if (format == 'c')
		print += print_char(va_arg(*args, int), error_flag);
	else if (format == 's')
		print += print_str(va_arg(*args, char *), error_flag);
	else if (format == 'p')
		print += print_ptr((unsigned long)va_arg(*args, void *), error_flag);
	else if (format == 'd' || format == 'i')
		print += print_int(va_arg(*args, int), error_flag);
	else if (format == 'u')
		print += print_uint(va_arg(*args, unsigned int), error_flag);
	else if (format == 'x' || format == 'X')
		print += print_hex(va_arg(*args, unsigned int), &format, error_flag);
	else
		return (-1);
	return (print);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print;
	char	error_flag;

	print = 0;
	error_flag = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				print += print_char('%', &error_flag);
			else
				print += typecheck(*str, &args, &error_flag);
		}
		else
			print += print_char(*str, &error_flag);
		str++;
		if (error_flag)
			break;
	}
	va_end(args);
	if (error_flag)
		return (-1);
	return (print);
}