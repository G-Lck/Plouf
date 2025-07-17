/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:22:02 by glucken           #+#    #+#             */
/*   Updated: 2025/07/07 16:36:13 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_byte_hex1(unsigned char Byte);
void	print_content_dot(void *str, unsigned int size);
void	print_content_hex(void *str, unsigned int size);
void	print_address_hex(void *str);

char	*ft_print_memory(void *addr, unsigned int size)
{
	if (size == 1)
		return (addr);
	print_address_hex(addr);
	print_content_hex(addr, size);
	print_content_dot(addr, size);
	return (addr);
}

void	print_address_hex(void *str)
{
	unsigned char	*ptr_byte;
	int				i;

	ptr_byte = (unsigned char *)&str;
	i = 7;
	while (i >= 0)
	{
		print_byte_hex1(*(ptr_byte + i));
		i--;
	}
	write(1, ":", 1);
}

void	print_byte_hex1(unsigned char Byte)
{
	char	c;

	if ((Byte / 16) < 10)
	{
		c = '\0' + 48 + (Byte / 16);
		write(1, &c, 1);
	}
	else
	{
		c = '\0' + 97 -10 + (Byte / 16);
		write(1, &c, 1);
	}
	if ((Byte % 16) < 10)
	{
		c = '\0' + 48 + (Byte % 16);
		write(1, &c, 1);
	}
	else
	{
		c = '\0' + 97 -10 + (Byte % 16);
		write(1, &c, 1);
	}
}

void	print_content_hex(void *str, unsigned int size)
{
	int		i;
	int		limit;

	limit = 16;
	i = 0;
	while (--size && limit--)
	{
		if (!(i % 2))
			write(1, " ", 1);
		print_byte_hex1(*((unsigned char *)str));
		++str;
		++i;
	}	
	if (i % 2)
		write(1, "  ", 2);
	else
		write(1, " ", 1);
}

void	print_content_dot(void *str, unsigned int size)
{
	short	limit;

	limit = 16;
	while (--size && limit--)
	{	
		if (*(char *)str >= 32 && *(char *)str < 127)
			write(1, str, 1);
		else
			write(1, ".", 1);
		++str;
	}	
	write(1, "\n", 1);
}

/*
 #include <stdio.h>
int	main()
{
	char	str[] = "Bonjour\nles amis\t\a\b\v\n, comment ca va aujourdui?";
	short	size = sizeof(str);

	ft_print_memory(str, size);
	return(0);

}

	void	print_byte_hex1(unsigned char Byte)
{
	if ((Byte / 16) < 10)
		ft_putcharfromascii(48 + (Byte / 16));
	else
		ft_putcharfromascii(97 - 10 + (Byte / 16));
	if ((Byte % 16) < 10)
		ft_putcharfromascii(48 + (Byte % 16));
	else
		ft_putcharfromascii(97 - 10 + (Byte % 16));
}

 void printByteHex2(unsigned char Byte)
{
	int	_4_Upper_bits;
	int	_4_Lower_bits;

	_4_Upper_bits = (Byte & 0b1111000) >> 4;
	if (_4_Upper_bits < 10)
		ft_putcharfromascii(48 + _4_Upper_bits);
	else
		ft_putcharfromascii(97 - 10 + _4_Upper_bits);

	_4_Lower_bits = (Byte & 0b00001111);
	if (_4_Upper_bits < 10)
		ft_putcharfromascii(48 + _4_Lower_bits);
	else
		ft_putcharfromascii(97 - 10 + _4_Lower_bits);
} 
void ft_putcharfromascii(int n)
{
	char	a;
	a = '\0' + n;
	write (1, &a, 1);
}*/