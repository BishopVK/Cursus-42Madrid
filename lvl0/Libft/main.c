/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:19:26 by danjimen          #+#    #+#             */
/*   Updated: 2024/02/05 14:19:26 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>

#define ANSI_COLOR_RED	 "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE	"\x1b[34m"
#define ANSI_COLOR_CYAN	"\x1b[36m"
#define ANSI_COLOR_BOLD	"\x1b[1m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define OK ANSI_COLOR_GREEN " OK" ANSI_COLOR_RESET
#define KO ANSI_COLOR_RED " KO" ANSI_COLOR_RESET
#define TIMEOUT ANSI_COLOR_YELLOW "TIMEOUT" ANSI_COLOR_RESET

//#define TEST_TITLE(color, number, description) printf("  %sTest %d: %s" ANSI_COLOR_RESET description ":", color ANSI_COLOR_BOLD, (int)(number), ANSI_COLOR_RESET)

void print_test_title(const char *color, int number, const char *description, ...) {
	printf("  %sTest %d: ", color, number);
	
	va_list args;
	va_start(args, description);

	// Print the description in white
	printf(ANSI_COLOR_RESET);
	vprintf(description, args);

	// Reset color and print a colon
	printf("%s:", ANSI_COLOR_RESET);

	va_end(args);
}

// Función para imprimir el nombre de la función en las pruebas
void print_test_header(const char* function_name) {
	printf(ANSI_COLOR_BLUE ANSI_COLOR_BOLD "\nTesting %s\n" ANSI_COLOR_RESET, function_name);
}

//Funciones adicionales//
static char	ft_strmapi_toggle_case(unsigned int n, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	else if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}

//Funciones adicionales//
static void	ft_striteri_toggle_case(unsigned int n, char *c)
{
	(void)n;
	if (*c >= 'a' && *c <= 'z')
		*c = (char)(*c - 'a' + 'A');
	else if (*c >= 'A' && *c <= 'Z')
		*c = (char)(*c - 'A' + 'a');
}

///////////////////////////////////
//		PARTE OBLIGATORIA		//
/////////////////////////////////
/* int main()
{
	// Test ft_isalpha
	print_test_header("ft_isalpha");

	// Test 1: Check if 'A' is an alphabet character
	print_test_title(ANSI_COLOR_CYAN, 1, "Check if 'A' is an alphabet character");
	char ft_isalpha_result1 = ft_isalpha('A') ? '1' : '0';
	char isalpha_result1 = isalpha('A') ? '1' : '0';
	printf("%s\n", (ft_isalpha_result1 == isalpha_result1) ? OK : KO);

	// Test 2: Check if 'a' is an alphabet character
	print_test_title(ANSI_COLOR_CYAN, 2, "Check if 'a' is an alphabet character");
	char ft_isalpha_result2 = ft_isalpha('a') ? '1' : '0';
	char isalpha_result2 = isalpha('a') ? '1' : '0';
	printf("%s\n", (ft_isalpha_result2 == isalpha_result2) ? OK : KO);

	// Test 3: Check if '1' is not an alphabet character
	print_test_title(ANSI_COLOR_CYAN, 3, "Check if '1' is not an alphabet character");
	char ft_isalpha_result3 = ft_isalpha('1') ? '1' : '0';
	char isalpha_result3 = isalpha('1') ? '1' : '0';
	printf("%s\n", (ft_isalpha_result3 == isalpha_result3) ? OK : KO);

	// Test 4: Check if '@' is not an alphabet character
	print_test_title(ANSI_COLOR_CYAN, 4, "Check if '@' is not an alphabet character");
	char ft_isalpha_result4 = ft_isalpha('@') ? '1' : '0';
	char isalpha_result4 = isalpha('@') ? '1' : '0';
	printf("%s\n", (ft_isalpha_result4 == isalpha_result4) ? OK : KO);

	/////////////////////////////////////

	// Test ft_isdigit
	print_test_header("ft_isdigit");

	// Test 1: Check if '5' is a digit
	print_test_title(ANSI_COLOR_CYAN, 1, "Check if '5' is a digit");
	char ft_isdigit_result1 = ft_isdigit('5') ? '1' : '0';
	char isdigit_result1 = isdigit('5') ? '1' : '0';
	printf("%s\n", (ft_isdigit_result1 == isdigit_result1) ? OK : KO);

	// Test 2: Check if 'A' is not a digit
	print_test_title(ANSI_COLOR_CYAN, 2, "Check if 'A' is not a digit");
	char ft_isdigit_result2 = ft_isdigit('A') ? '1' : '0';
	char isdigit_result2 = isdigit('A') ? '1' : '0';
	printf("%s\n", (ft_isdigit_result2 == isdigit_result2) ? OK : KO);

	// Test 3: Check if '@' is not a digit
	print_test_title(ANSI_COLOR_CYAN, 3, "Check if '@' is not a digit");
	char ft_isdigit_result3 = ft_isdigit('@') ? '1' : '0';
	char isdigit_result3 = isdigit('@') ? '1' : '0';
	printf("%s\n", (ft_isdigit_result3 == isdigit_result3) ? OK : KO);

	// Test 4: Check if ' ' is not a digit
	print_test_title(ANSI_COLOR_CYAN, 4, "Check if ' ' is not a digit");
	char ft_isdigit_result4 = ft_isdigit(' ') ? '1' : '0';
	char isdigit_result4 = isdigit(' ') ? '1' : '0';
	printf("%s\n", (ft_isdigit_result4 == isdigit_result4) ? OK : KO);

	// Test 5: Check if '0' is a digit
	print_test_title(ANSI_COLOR_CYAN, 5, "Check if '-5' is a digit");
	char ft_isdigit_result5 = ft_isdigit(-5) ? '1' : '0';
	char isdigit_result5 = isdigit(-5) ? '1' : '0';
	printf("%s\n", (ft_isdigit_result5 == isdigit_result5) ? OK : KO);

	/////////////////////////////////////

	// Test ft_isalnum
	print_test_header("ft_isalnum");

	// Test 1: Check if 'A' is alphanumeric
	print_test_title(ANSI_COLOR_CYAN, 1, "Check if 'A' is alphanumeric");
	char ft_isalnum_result1 = ft_isalnum('A') ? '1' : '0';
	char isalnum_result1 = isalnum('A') ? '1' : '0';
	printf("%s\n", (ft_isalnum_result1 == isalnum_result1) ? OK : KO);

	// Test 2: Check if '5' is alphanumeric
	print_test_title(ANSI_COLOR_CYAN, 2, "Check if '5' is alphanumeric");
	char ft_isalnum_result2 = ft_isalnum('5') ? '1' : '0';
	char isalnum_result2 = isalnum('5') ? '1' : '0';
	printf("%s\n", (ft_isalnum_result2 == isalnum_result2) ? OK : KO);

	// Test 3: Check if '@' is not alphanumeric
	print_test_title(ANSI_COLOR_CYAN, 3, "Check if '@' is not alphanumeric");
	char ft_isalnum_result3 = ft_isalnum('@') ? '1' : '0';
	char isalnum_result3 = isalnum('@') ? '1' : '0';
	printf("%s\n", (ft_isalnum_result3 == isalnum_result3) ? OK : KO);

	// Test 4: Check if ' ' is not alphanumeric
	print_test_title(ANSI_COLOR_CYAN, 4, "Check if ' ' is not alphanumeric");
	char ft_isalnum_result4 = ft_isalnum(' ') ? '1' : '0';
	char isalnum_result4 = isalnum(' ') ? '1' : '0';
	printf("%s\n", (ft_isalnum_result4 == isalnum_result4) ? OK : KO);

	// Test 5: Check if '&' is alphanumeric
	print_test_title(ANSI_COLOR_CYAN, 5, "Check if '&' is alphanumeric");
	char ft_isalnum_result5 = ft_isalnum('&') ? '1' : '0';
	char isalnum_result5 = isalnum('&') ? '1' : '0';
	printf("%s\n", (ft_isalnum_result5 == isalnum_result5) ? OK : KO);

	/////////////////////////////////////

	// Test ft_isascii
	print_test_header("ft_isascii");

	// Test 1: Check if 'A' is an ASCII character
	print_test_title(ANSI_COLOR_CYAN, 1, "Check if 'A' is an ASCII character");
	char ft_isascii_result1 = ft_isascii('A') ? '1' : '0';
	char isascii_result1 = isascii('A') ? '1' : '0';
	printf("%s\n", (ft_isascii_result1 == isascii_result1) ? OK : KO);

	// Test 2: Check if 150 is not an ASCII character
	print_test_title(ANSI_COLOR_CYAN, 2, "Check if 150 is not an ASCII character");
	char ft_isascii_result2 = ft_isascii(150) ? '1' : '0';
	char isascii_result2 = isascii(150) ? '1' : '0';
	printf("%s\n", (ft_isascii_result2 == isascii_result2) ? OK : KO);

	// Test 3: Check if '@' is an ASCII character
	print_test_title(ANSI_COLOR_CYAN, 3, "Check if '@' is an ASCII character");
	char ft_isascii_result3 = ft_isascii('@') ? '1' : '0';
	char isascii_result3 = isascii('@') ? '1' : '0';
	printf("%s\n", (ft_isascii_result3 == isascii_result3) ? OK : KO);

	// Test 4: Check if -5 is not an ASCII character
	print_test_title(ANSI_COLOR_CYAN, 4, "Check if -5 is not an ASCII character");
	char ft_isascii_result4 = ft_isascii(-5) ? '1' : '0';
	char isascii_result4 = isascii(-5) ? '1' : '0';
	printf("%s\n", (ft_isascii_result4 == isascii_result4) ? OK : KO);

	// Test 5: Check if 127 is an ASCII character
	print_test_title(ANSI_COLOR_CYAN, 5, "Check if 127 is an ASCII character");
	char ft_isascii_result5 = ft_isascii(127) ? '1' : '0';
	char isascii_result5 = isascii(127) ? '1' : '0';
	printf("%s\n", (ft_isascii_result5 == isascii_result5) ? OK : KO);

	/////////////////////////////////////

	// Test ft_isprint
	print_test_header("ft_isprint");

	// Test 1: Check if 'A' is a printable character
	print_test_title(ANSI_COLOR_CYAN, 1, "Check if 'A' is a printable character");
	char ft_isprint_result1 = ft_isprint('A') ? '1' : '0';
	char isprint_result1 = isprint('A') ? '1' : '0';
	printf("%s\n", (ft_isprint_result1 == isprint_result1) ? OK : KO);

	// Test 2: Check if 10 is not a printable character
	print_test_title(ANSI_COLOR_CYAN, 2, "Check if 10 is not a printable character");
	char ft_isprint_result2 = ft_isprint(10) ? '1' : '0';
	char isprint_result2 = isprint(10) ? '1' : '0';
	printf("%s\n", (ft_isprint_result2 == isprint_result2) ? OK : KO);

	// Test 3: Check if '@' is a printable character
	print_test_title(ANSI_COLOR_CYAN, 3, "Check if '@' is a printable character");
	char ft_isprint_result3 = ft_isprint('@') ? '1' : '0';
	char isprint_result3 = isprint('@') ? '1' : '0';
	printf("%s\n", (ft_isprint_result3 == isprint_result3) ? OK : KO);

	// Test 4: Check if -5 is not a printable character
	print_test_title(ANSI_COLOR_CYAN, 4, "Check if -5 is not a printable character");
	char ft_isprint_result4 = ft_isprint(-5) ? '1' : '0';
	char isprint_result4 = isprint(-5) ? '1' : '0';
	printf("%s\n", (ft_isprint_result4 == isprint_result4) ? OK : KO);

	// Test 5: Check if 126 is a printable character
	print_test_title(ANSI_COLOR_CYAN, 5, "Check if 126 is a printable character");
	char ft_isprint_result5 = ft_isprint(126) ? '1' : '0';
	char isprint_result5 = isprint(126) ? '1' : '0';
	printf("%s\n", (ft_isprint_result5 == isprint_result5) ? OK : KO);


	/////////////////////////////////////

	// Test ft_strlen
	print_test_header("ft_strlen");

	// Test 1: Check length of "Hello"
	print_test_title(ANSI_COLOR_CYAN, 1, "Check length of 'Hello'");
	printf("%s\n", (ft_strlen("Hello") == strlen("Hello")) ? OK : KO);

	// Test 2: Check length of empty string
	print_test_title(ANSI_COLOR_CYAN, 2, "Check length of empty string");
	printf("%s\n", (ft_strlen("") == strlen("")) ? OK : KO);

	// Test 3: Check length of string with spaces
	print_test_title(ANSI_COLOR_CYAN, 3, "Check length of 'Hello World'");
	printf("%s\n", (ft_strlen("Hello World") == strlen("Hello World")) ? OK : KO);

	// Test 4: Check length of string with special characters
	print_test_title(ANSI_COLOR_CYAN, 4, "Check length of 'C programming!'");
	printf("%s\n", (ft_strlen("C programming!") == strlen("C programming!")) ? OK : KO);

	// Test 5: Check length of string with numbers
	print_test_title(ANSI_COLOR_CYAN, 5, "Check length of '12345'");
	printf("%s\n", (ft_strlen("12345") == strlen("12345")) ? OK : KO);

	// Test 6: (En cyan) Realizar prueba con NULL (Ejecutar manualmente después de las pruebas)
	print_test_title(ANSI_COLOR_CYAN, 6, ANSI_COLOR_YELLOW"Realizar prueba con NULL (Ejecutar manualmente después de las pruebas)\n");

	/////////////////////////////////////

	// Test ft_memset
	print_test_header("ft_memset");

	// Test 1: Set first 5 characters of string to 'A'
	print_test_title(ANSI_COLOR_CYAN, 1, "Set first 5 characters of string to 'A'");
	char str_ft_memset1[] = "Hello World!";
	ft_memset(str_ft_memset1, 'A', 5);
	char str_memset1[] = "Hello World!";
	memset(str_memset1, 'A', 5);
	printf("%s\n", (memcmp(str_ft_memset1, str_memset1, 12) == 0) ? OK : KO);

	// Test 2: Set entire string to 'X'
	print_test_title(ANSI_COLOR_CYAN, 2, "Set entire string to 'X'");
	char str_ft_memset2[] = "Hello";
	ft_memset(str_ft_memset2, 'X', 5);
	char str_memset2[] = "Hello";
	memset(str_memset2, 'X', 5);
	printf("%s\n", (memcmp(str_ft_memset2, str_memset2, 5) == 0) ? OK : KO);

	// Test 3: Set first 3 characters of empty string to 'Y'
	print_test_title(ANSI_COLOR_CYAN, 3, "Set first 3 characters of empty string to 'Y'");
	char str_ft_memset3[10] = "";
	ft_memset(str_ft_memset3, 'Y', 3);
	char str_memset3[10] = "";
	memset(str_memset3, 'Y', 3);	
	printf("%s\n", (memcmp(str_ft_memset3, str_memset3, 3) == 0) ? OK : KO);

	// Test 4: Set first 10 characters of numbers array to 9
	print_test_title(ANSI_COLOR_CYAN, 4, "Set first 10 characters of numbers array to 9");
	int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	ft_memset(numbers, 9, 10 * sizeof(int));

	// Verificar cada elemento del array
	int is_ok = 1;
	int expected_numbers[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
	for (size_t i = 0; i < 10; i++)
	{
		if (numbers[i] != (int)0x09090909)
		{
			is_ok = 0;
			break;
		}
	}
	printf("%s\n", (is_ok) ? OK : KO);

	/////////////////////////////////////

	// Test ft_bzero
	print_test_header("ft_bzero");

	// Test 1: Set first 5 characters of string to 'A'
	print_test_title(ANSI_COLOR_CYAN, 1, "Set first 5 characters of string to '0'");
	char str_ft_bzero1[] = "Hello World!";
	ft_bzero(str_ft_bzero1, 5);
	char str_bzero1[] = "Hello World!";
	bzero(str_bzero1, 5);
	printf("%s\n", (memcmp(str_ft_bzero1, str_bzero1, 12) == 0) ? OK : KO);

	// Test 2: Set entire string to 'X'
	print_test_title(ANSI_COLOR_CYAN, 2, "Set entire string to '0'");
	char str_ft_bzero2[] = "Hello";
	ft_bzero(str_ft_bzero2, 5);
	char str_bzero2[] = "Hello";
	bzero(str_bzero2, 5);
	printf("%s\n", (memcmp(str_ft_bzero2, str_bzero2, 5) == 0) ? OK : KO);

	// Test 3: Set first 3 characters of empty string to '0'
	print_test_title(ANSI_COLOR_CYAN, 3, "Set first 3 characters of empty string to \0");
	char str_ft_bzero3[10];
	ft_bzero(str_ft_bzero3, 3);
	char str_bzero3[10];
	bzero(str_bzero3, 3);
	printf("%s\n", (memcmp(str_ft_bzero3, str_bzero3, 3) == 0) ? OK : KO);

	// Test 4: Set first 10 characters of numbers array to 9
	print_test_title(ANSI_COLOR_CYAN, 4, "Set first 10 characters of numbers array to 9");
	int numbers_ft_bzero[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	ft_bzero(numbers_ft_bzero, 10 * sizeof(int));
	int numbers_bzero[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	ft_bzero(numbers_bzero, 10 * sizeof(int));
	printf("%s\n", (memcmp(numbers_ft_bzero, numbers_bzero, 10 * sizeof(int)) == 0) ? OK : KO);

	/////////////////////////////////////

	// Test ft_memcpy
	print_test_header("ft_memcpy");

	// Test 1: Copy 5 characters from source to destination
	print_test_title(ANSI_COLOR_CYAN, 1, "Copy 5 characters from source to destination");
	char src_ft_memcpy1[] = "Hello World!";
	char dst_ft_memcpy1[5];
	ft_memcpy(dst_ft_memcpy1, src_ft_memcpy1, 5);
	char src_memcpy1[] = "Hello World!";
	char dst_memcpy1[5];
	memcpy(dst_memcpy1, src_memcpy1, 5);
	printf("%s\n", (memcmp(dst_ft_memcpy1, dst_memcpy1, 5) == 0) ? OK : KO);

	// Test 2: Copy entire string from source to destination
	print_test_title(ANSI_COLOR_CYAN, 2, "Copy entire string from source to destination");
	char src_ft_memcpy2[] = "Hello";
	char dst_ft_memcpy2[6];
	ft_memcpy(dst_ft_memcpy2, src_ft_memcpy2, 6);
	char src_memcpy2[] = "Hello";
	char dst_memcpy2[6];
	memcpy(dst_memcpy2, src_memcpy2, 6);
	printf("%s\n", (memcmp(dst_ft_memcpy2, dst_memcpy2, 6) == 0) ? OK : KO);

	// Test 3: Copy 3 characters from empty source to destination
	print_test_title(ANSI_COLOR_CYAN, 3, "Copy 3 characters from empty source to destination");
	char src_ft_memcpy3[] = "";
	char dst_ft_memcpy3[3];
	ft_memcpy(dst_ft_memcpy3, src_ft_memcpy3, 3);
	char src_memcpy3[] = "";
	char dst_memcpy3[3];
	memcpy(dst_memcpy3, src_memcpy3, 3);
	printf("%s\n", (memcmp(dst_ft_memcpy3, dst_memcpy3, 1) == 0) ? OK : KO);

	// Test 4: Copy 10 characters from numbers array to destination
	print_test_title(ANSI_COLOR_CYAN, 4, "Copy 10 characters from numbers array to destination");
	int src_ft_memcpy4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int dst_ft_memcpy4[10];
	ft_memcpy(dst_ft_memcpy4, src_ft_memcpy4, 10 * sizeof(int));
	int src_memcpy4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int dst_memcpy4[10];
	memcpy(dst_memcpy4, src_memcpy4, 10 * sizeof(int));
	printf("%s\n", (memcmp(dst_ft_memcpy4, dst_memcpy4, 10 * sizeof(int)) == 0) ? OK : KO);

	// Test 5: Copy 0 characters from source to destination
	print_test_title(ANSI_COLOR_CYAN, 5, "Copy 0 characters from source to destination");
	char dst_ft_memcpy5[5] = "ABCDE";
	const char *src_ft_memcpy5 = "12345";
	ft_memcpy(dst_ft_memcpy5, src_ft_memcpy5, 0);
	char dst_memcpy5[5] = "ABCDE";
	const char *src_memcpy5 = "12345";
	memcpy(dst_memcpy5, src_memcpy5, 0);
	printf("%s\n", (memcmp(dst_ft_memcpy5, dst_memcpy5, 5) == 0) ? OK : KO);

	/////////////////////////////////////

	// Test ft_memmove
	print_test_header("ft_memmove");

	// Test 1: Move 5 characters from source to destination (no overlap)
	print_test_title(ANSI_COLOR_CYAN, 1, "Move 5 characters from source to destination (no overlap)");
	char dest_ft_memmove1[] = "ABCDE";
	const char *src_ft_memmove1 = "12345";
	ft_memmove(dest_ft_memmove1, src_ft_memmove1, 5);
	char dest_memmove1[] = "ABCDE";
	const char *src_memmove1 = "12345";
	memmove(dest_memmove1, src_memmove1, 5);
	printf("%s\n", (memcmp(dest_ft_memmove1, dest_memmove1, 5) == 0) ? OK : KO);

	// Test 2: Move 7 characters from source to destination (overlap, src before dest)
	print_test_title(ANSI_COLOR_CYAN, 2, "Move 7 characters from source to destination (overlap, src before dest)");
	char dest_ft_memmove2[10] = "abcdefghi";
	const char *src_ft_memmove2 = "1234567";
	ft_memmove(dest_ft_memmove2 + 3, src_ft_memmove2, 7);
	char dest_memmove2[10] = "abcdefghi";
	const char *src_memmove2 = "1234567";
	memmove(dest_memmove2 + 3, src_memmove2, 7);
	printf("%s\n", (memcmp(dest_ft_memmove2, dest_memmove2, 10) == 0) ? OK : KO);

	// Test 3: Move 6 characters from source to destination (overlap, dest before src)
	print_test_title(ANSI_COLOR_CYAN, 3, "Move 6 characters from source to destination (overlap, dest before src)");
	char dest_ft_memmove3[10] = "abcdefghi";
	const char *src_ft_memmove3 = "123456";
	ft_memmove(dest_ft_memmove3 + 4, src_ft_memmove3, 6);
	char dest_memmove3[10] = "abcdefghi";
	const char *src_memmove3 = "123456";
	memmove(dest_memmove3 + 4, src_memmove3, 6);
	printf("%s\n", (memcmp(dest_ft_memmove3, dest_memmove3, 10) == 0) ? OK : KO);

	// Test 4: Move 0 characters from source to destination
	print_test_title(ANSI_COLOR_CYAN, 4, "Move 0 characters from source to destination");
	char dest_ft_memmove4[10] = "abcdefghi";
	const char *src_ft_memmove4 = "12345";
	ft_memmove(dest_ft_memmove4 + 2, src_ft_memmove4, 0);
	char dest_memmove4[10] = "abcdefghi";
	const char *src_memmove4 = "12345";
	memmove(dest_memmove4 + 2, src_memmove4, 0);
	printf("%s\n", (memcmp(dest_ft_memmove4, dest_memmove4, 10) == 0) ? OK : KO);

	// Test 5: Move 5 characters from source to destination (src and dest are the same)
	print_test_title(ANSI_COLOR_CYAN, 5, "Move 5 characters from source to destination (src and dest are the same)");
	char dest_ft_memmove5[] = "12345";
	const char *src_ft_memmove5 = dest_ft_memmove5;
	ft_memmove(dest_ft_memmove5, src_ft_memmove5, 5);
	char dest_memmove5[] = "12345";
	const char *src_memmove5 = dest_memmove5;
	memmove(dest_memmove5, src_memmove5, 5);
	printf("%s\n", (memcmp(dest_ft_memmove5, dest_memmove5, 5) == 0) ? OK : KO);

	/////////////////////////////////////

	// Test ft_strlcpy
	print_test_header("ft_strlcpy");

	// Test 1: Copy 'Hello' to destination with size 5
	print_test_title(ANSI_COLOR_CYAN, 1, "Copy 'Hello' to destination with size 5");
	char dest_strlcpy1[5];
	printf("%s\n", (ft_strlcpy(dest_strlcpy1, "Hello", 5) == strlen("Hello")) ? OK : KO);

	// Test 2: Copy 'Hello' to destination with size 3
	print_test_title(ANSI_COLOR_CYAN, 2, "Copy 'Hello' to destination with size 3");
	char dest_strlcpy2[3];
	printf("%s\n", (ft_strlcpy(dest_strlcpy2, "Hello", 3) == strlen("Hello")) ? OK : KO);

	// Test 3: Copy 'Hello' to destination with size 0
	print_test_title(ANSI_COLOR_CYAN, 3, "Copy 'Hello' to destination with size 0");
	char dest_strlcpy3[10];
	printf("%s\n", (ft_strlcpy(dest_strlcpy3, "Hello", 0) == strlen("Hello")) ? OK : KO);

	// Test 4: Copy empty string to destination with size 5
	print_test_title(ANSI_COLOR_CYAN, 4, "Copy empty string to destination with size 5");
	char dest_strlcpy4[5];
	printf("%s\n", (ft_strlcpy(dest_strlcpy4, "", 5) == strlen("")) ? OK : KO);

	// Test 5: Copy 'Hello' to destination with size 10
	print_test_title(ANSI_COLOR_CYAN, 5, "Copy 'Hello' to destination with size 10");
	char dest_strlcpy5[10];
	printf("%s\n", (ft_strlcpy(dest_strlcpy5, "Hello", 10) == strlen("Hello")) ? OK : KO);

	/////////////////////////////////////

	// Test ft_strlcat
	print_test_header("ft_strlcat");

	// Test 1: Concatenate 'World' to 'Hello'
	print_test_title(ANSI_COLOR_CYAN, 1, "Concatenate 'World' to 'Hello'");
	char dest_strlcat1[12] = "Hello";
	const char *src_strlcat1 = "World";
	size_t result_strlcat1 = ft_strlcat(dest_strlcat1, src_strlcat1, sizeof(dest_strlcat1));
	printf("%s\n", (result_strlcat1 == 10 && strcmp(dest_strlcat1, "HelloWorld") == 0) ? OK : KO);

	// Test 2: Concatenate '!' to 'C programming'
	print_test_title(ANSI_COLOR_CYAN, 2, "Concatenate '!' to 'C programming'");
	char dest_strlcat2[15] = "C programming";
	const char *src_strlcat2 = "!";
	size_t result_strlcat2 = ft_strlcat(dest_strlcat2, src_strlcat2, sizeof(dest_strlcat2));
	printf("%s\n", (result_strlcat2 == 14 && strcmp(dest_strlcat2, "C programming!") == 0) ? OK : KO);

	// Test 3: Concatenate '123' to empty string
	print_test_title(ANSI_COLOR_CYAN, 3, "Concatenate '123' to empty string");
	char dest_strlcat3[4] = "";
	const char *src_strlcat3 = "123";
	size_t result_strlcat3 = ft_strlcat(dest_strlcat3, src_strlcat3, sizeof(dest_strlcat3));
	printf("%s\n", (result_strlcat3 == 3 && strcmp(dest_strlcat3, "123") == 0) ? OK : KO);

	// Test 4: Concatenate 'Programming!' to 'C '
	print_test_title(ANSI_COLOR_CYAN, 4, "Concatenate 'Programming!' to 'C '");
	char dest_strlcat4[15] = "C ";
	const char *src_strlcat4 = "Programming!";
	size_t result_strlcat4 = ft_strlcat(dest_strlcat4, src_strlcat4, sizeof(dest_strlcat4));
	printf("%s\n", (result_strlcat4 == 14 && strcmp(dest_strlcat4, "C Programming!") == 0) ? OK : KO);

	// Test 5: Concatenate '12345' to 'ABCDE' with limited buffer
	print_test_title(ANSI_COLOR_CYAN, 5, "Concatenate '12345' to 'ABCDE' with limited buffer");
	char dest_strlcat5[10] = "ABCDE";
	const char *src_strlcat5 = "12345";
	size_t original_length_strlcat5 = strlen(dest_strlcat5);
	size_t result_strlcat5 = ft_strlcat(dest_strlcat5, src_strlcat5, sizeof(dest_strlcat5));
	printf("%s\n", (result_strlcat5 == original_length_strlcat5 + 5 && strcmp(dest_strlcat5, "ABCDE1234") == 0) ? OK : KO);

	/////////////////////////////////////

	// Test ft_toupper
	print_test_header("ft_toupper");

	// Test 1: Convert lowercase 'a' to uppercase: OK
	print_test_title(ANSI_COLOR_CYAN, 1, "Convert lowercase 'a' to uppercase");
	printf("%s\n", (ft_toupper('a') == toupper('a')) ? OK : KO);

	// Test 2: Convert uppercase 'Z' to uppercase (already uppercase): OK
	print_test_title(ANSI_COLOR_CYAN, 2, "Convert uppercase 'Z' to uppercase (already uppercase)");
	printf("%s\n", (ft_toupper('Z') == toupper('Z')) ? OK : KO);

	// Test 3: Convert digit '7' to uppercase (not applicable): OK
	print_test_title(ANSI_COLOR_CYAN, 3, "Convert digit '7' to uppercase (not applicable)");
	printf("%s\n", (ft_toupper('7') == toupper('7')) ? OK : KO);

	// Test 4: Convert special character '$' to uppercase (not applicable): OK
	print_test_title(ANSI_COLOR_CYAN, 4, "Convert special character '$' to uppercase (not applicable)");
	printf("%s\n", (ft_toupper('$') == toupper('$')) ? OK : KO);

	// Test 5: Convert newline character '\n' to uppercase (not applicable): OK
	print_test_title(ANSI_COLOR_CYAN, 5, "Convert newline character '\\n' to uppercase (not applicable)");
	printf("%s\n", (ft_toupper('\n') == toupper('\n')) ? OK : KO);

	/////////////////////////////////////

	// Test ft_tolower
	print_test_header("ft_tolower");

	// Test 1: Convert uppercase 'A' to lowercase
	print_test_title(ANSI_COLOR_CYAN, 1, "Convert uppercase 'A' to lowercase");
	printf("%s\n", (ft_tolower('A') == tolower('A')) ? OK : KO);

	// Test 2: Convert lowercase 'z' to lowercase (already lowercase)
	print_test_title(ANSI_COLOR_CYAN, 2, "Convert lowercase 'z' to lowercase (already lowercase)");
	printf("%s\n", (ft_tolower('z') == tolower('z')) ? OK : KO);

	// Test 3: Convert digit '5' to lowercase (not applicable)
	print_test_title(ANSI_COLOR_CYAN, 3, "Convert digit '5' to lowercase (not applicable)");
	printf("%s\n", (ft_tolower('5') == tolower('5')) ? OK : KO);

	// Test 4: Convert special character '%' to lowercase (not applicable)
	print_test_title(ANSI_COLOR_CYAN, 4, "Convert special character '%' to lowercase (not applicable)");
	printf("%s\n", (ft_tolower('%') == tolower('%')) ? OK : KO);

	// Test 5: Convert newline character '\n' to lowercase (not applicable)
	print_test_title(ANSI_COLOR_CYAN, 5, "Convert newline character '\\n' to lowercase (not applicable)");
	printf("%s\n", (ft_tolower('\n') == tolower('\n')) ? OK : KO);

	/////////////////////////////////////

	// Test ft_strchr
	print_test_header("ft_strchr");

	// Test 1: Find 'l' in "Hello"
	print_test_title(ANSI_COLOR_CYAN, 1, "Find 'l' in \"Hello\"");
	char str_strchr1[] = "Hello";
	printf("%s\n", (ft_strchr(str_strchr1, 'l') == strchr(str_strchr1, 'l')) ? OK : KO);

	// Test 2: Find 'o' in "Hello"
	print_test_title(ANSI_COLOR_CYAN, 2, "Find 'o' in \"Hello\"");
	char str_strchr2[] = "Hello";
	printf("%s\n", (ft_strchr(str_strchr2, 'o') == strchr(str_strchr2, 'o')) ? OK : KO);

	// Test 3: Find 'H' in "Hello"
	print_test_title(ANSI_COLOR_CYAN, 3, "Find 'H' in \"Hello\"");
	char str_strchr3[] = "Hello";
	printf("%s\n", (ft_strchr(str_strchr3, 'H') == strchr(str_strchr3, 'H')) ? OK : KO);

	// Test 4: Find 'x' in "Hello"
	print_test_title(ANSI_COLOR_CYAN, 4, "Find 'x' in \"Hello\"");
	char str_strchr4[] = "Hello";
	printf("%s\n", (ft_strchr(str_strchr4, 'x') == strchr(str_strchr4, 'x')) ? OK : KO);

	// Test 5: Find '\0' in "Hello"
	print_test_title(ANSI_COLOR_CYAN, 5, "Find '\\0' in \"Hello\"");
	char str_strchr5[] = "Hello";
	printf("%s\n", (ft_strchr(str_strchr5, '\0') == strchr(str_strchr5, '\0')) ? OK : KO);

	// Test 6: Find 'H' in empty string
	print_test_title(ANSI_COLOR_CYAN, 6, "Find 'H' in empty string");
	char str_strchr6[] = "";
	printf("%s\n", (ft_strchr(str_strchr6, 'H') == strchr(str_strchr6, 'H')) ? OK : KO);

	// Test 7: Find '\0' in empty string
	print_test_title(ANSI_COLOR_CYAN, 7, "Find '\\0' in empty string");
	char str_strchr7[] = "";
	printf("%s\n", (ft_strchr(str_strchr7, '\0') == strchr(str_strchr7, '\0')) ? OK : KO);

	/////////////////////////////////////

	// Test ft_strrchr
	print_test_header("ft_strrchr");

	// Test 1: Find 'l' in "Hello"
	print_test_title(ANSI_COLOR_CYAN, 1, "Find 'l' in \"Hello\"");
	char str_strrchr1[] = "Hello";
	printf("%s\n", (ft_strrchr(str_strrchr1, 'l') == strrchr(str_strrchr1, 'l')) ? OK : KO);

	// Test 2: Find 'o' in "Hello"
	print_test_title(ANSI_COLOR_CYAN, 2, "Find 'o' in \"Hello\"");
	char str_strrchr2[] = "Hello";
	printf("%s\n", (ft_strrchr(str_strrchr2, 'o') == strrchr(str_strrchr2, 'o')) ? OK : KO);

	// Test 3: Find 'H' in "Hello"
	print_test_title(ANSI_COLOR_CYAN, 3, "Find 'H' in \"Hello\"");
	char str_strrchr3[] = "Hello";
	printf("%s\n", (ft_strrchr(str_strrchr3, 'H') == strrchr(str_strrchr3, 'H')) ? OK : KO);

	// Test 4: Find 'x' in "Hello"
	print_test_title(ANSI_COLOR_CYAN, 4, "Find 'x' in \"Hello\"");
	char str_strrchr4[] = "Hello";
	printf("%s\n", (ft_strrchr(str_strrchr4, 'x') == strrchr(str_strrchr4, 'x')) ? OK : KO);

	// Test 5: Find '\0' in "Hello"
	print_test_title(ANSI_COLOR_CYAN, 5, "Find '\\0' in \"Hello\"");
	char str_strrchr5[] = "Hello";
	printf("%s\n", (ft_strrchr(str_strrchr5, '\0') == strrchr(str_strrchr5, '\0')) ? OK : KO);

	// Test 6: Find 'H' in empty string
	print_test_title(ANSI_COLOR_CYAN, 6, "Find 'H' in empty string");
	char str_strrchr6[] = "";
	printf("%s\n", (ft_strrchr(str_strrchr6, 'H') == strrchr(str_strrchr6, 'H')) ? OK : KO);

	// Test 7: Find '\0' in empty string
	print_test_title(ANSI_COLOR_CYAN, 7, "Find '\\0' in empty string");
	char str_strrchr7[] = "";
	printf("%s\n", (ft_strrchr(str_strrchr7, '\0') == strrchr(str_strrchr7, '\0')) ? OK : KO);

	/////////////////////////////////////

	// Test ft_strncmp
	print_test_header("ft_strncmp");

	// Test 1: Compare first 3 characters of "Hello" and "Hell"
	print_test_title(ANSI_COLOR_CYAN, 1, "Compare first 3 characters of \"Hello\" and \"Hell\"");
	char str_strncmp1[] = "Hello";
	char str_strncmp1_2[] = "Hell";
	printf("%s\n", (ft_strncmp(str_strncmp1, str_strncmp1_2, 3) == strncmp(str_strncmp1, str_strncmp1_2, 3)) ? OK : KO);

	// Test 2: Compare first 5 characters of "Hello" and "Hello"
	print_test_title(ANSI_COLOR_CYAN, 2, "Compare first 5 characters of \"Hello\" and \"Hello\"");
	char str_strncmp2[] = "Hello";
	char str_strncmp2_2[] = "Hello";
	printf("%s\n", (ft_strncmp(str_strncmp2, str_strncmp2_2, 5) == strncmp(str_strncmp2, str_strncmp2_2, 5)) ? OK : KO);

	// Test 3: Compare first 3 characters of "Hello" and "Hellx"
	print_test_title(ANSI_COLOR_CYAN, 3, "Compare first 3 characters of \"Hello\" and \"Hellx\"");
	char str_strncmp3[] = "Hello";
	char str_strncmp3_2[] = "Hellx";
	printf("%s\n", (ft_strncmp(str_strncmp3, str_strncmp3_2, 3) == strncmp(str_strncmp3, str_strncmp3_2, 3)) ? OK : KO);

	// Test 4: Compare first 5 characters of "Hello" and "Helloo"
	print_test_title(ANSI_COLOR_CYAN, 4, "Compare first 5 characters of \"Hello\" and \"Helloo\"");
	char str_strncmp4[] = "Hello";
	char str_strncmp4_2[] = "Helloo";
	printf("%s\n", (ft_strncmp(str_strncmp4, str_strncmp4_2, 5) == strncmp(str_strncmp4, str_strncmp4_2, 5)) ? OK : KO);

	// Test 5: Compare first 3 characters of "Hello" and "Hell"
	print_test_title(ANSI_COLOR_CYAN, 5, "Compare first 3 characters of \"Hello\" and \"Hell\"");
	char str_strncmp5[] = "Hello";
	char str_strncmp5_2[] = "Hell";
	printf("%s\n", (ft_strncmp(str_strncmp5, str_strncmp5_2, 3) == strncmp(str_strncmp5, str_strncmp5_2, 3)) ? OK : KO);

	// Test 6: Compare first 2 characters of "Hi" and "Hello"
	print_test_title(ANSI_COLOR_CYAN, 6, "Compare first 2 characters of \"Hi\" and \"Hello\"");
	char str_strncmp6[] = "Hi";
	char str_strncmp6_2[] = "Hello";
	printf("%s\n", (ft_strncmp(str_strncmp6, str_strncmp6_2, 2) == strncmp(str_strncmp6, str_strncmp6_2, 2)) ? OK : KO);

	// Test 7: Compare first 0 characters of "Hello" and "Hello"
	print_test_title(ANSI_COLOR_CYAN, 7, "Compare first 0 characters of \"Hello\" and \"Hello\"");
	char str_strncmp7[] = "Hello";
	char str_strncmp7_2[] = "Hello";
	printf("%s\n", (ft_strncmp(str_strncmp7, str_strncmp7_2, 0) == strncmp(str_strncmp7, str_strncmp7_2, 0)) ? OK : KO);

	/////////////////////////////////////

	// Test ft_memchr
	print_test_header("ft_memchr");

	// Test 1: Find 'e' in "Hello" (searching within the first 5 characters)
	print_test_title(ANSI_COLOR_CYAN, 1, "Find 'e' in \"Hello\" (searching within the first 5 characters)");
	char str_memchr1[] = "Hello";
	printf("%s\n", (ft_memchr(str_memchr1, 'e', 5) == memchr(str_memchr1, 'e', 5)) ? OK : KO);

	// Test 2: Find 'o' in "Hello" (searching within the first 5 characters)
	print_test_title(ANSI_COLOR_CYAN, 2, "Find 'o' in \"Hello\" (searching within the first 5 characters)");
	char str_memchr2[] = "Hello";
	printf("%s\n", (ft_memchr(str_memchr2, 'o', 5) == memchr(str_memchr2, 'o', 5)) ? OK : KO);

	// Test 3: Find 'z' in "Hello" (searching within the first 5 characters)
	print_test_title(ANSI_COLOR_CYAN, 3, "Find 'z' in \"Hello\" (searching within the first 5 characters)");
	char str_memchr3[] = "Hello";
	printf("%s\n", (ft_memchr(str_memchr3, 'z', 5) == memchr(str_memchr3, 'z', 5)) ? OK : KO);

	// Test 4: Find 'H' in "Hello" (searching within the first 5 characters)
	print_test_title(ANSI_COLOR_CYAN, 4, "Find 'H' in \"Hello\" (searching within the first 5 characters)");
	char str_memchr4[] = "Hello";
	printf("%s\n", (ft_memchr(str_memchr4, 'H', 5) == memchr(str_memchr4, 'H', 5)) ? OK : KO);

	// Test 5: Find 'x' in "Hello" (searching within the first 5 characters)
	print_test_title(ANSI_COLOR_CYAN, 5, "Find 'x' in \"Hello\" (searching within the first 5 characters)");
	char str_memchr5[] = "Hello";
	printf("%s\n", (ft_memchr(str_memchr5, 'x', 5) == memchr(str_memchr5, 'x', 5)) ? OK : KO);

	// Test 6: Find 'l' in "Hello" (searching within the first 5 characters)
	print_test_title(ANSI_COLOR_CYAN, 6, "Find 'l' in \"Hello\" (searching within the first 5 characters)");
	char str_memchr6[] = "Hello";
	printf("%s\n", (ft_memchr(str_memchr6, 'l', 5) == memchr(str_memchr6, 'l', 5)) ? OK : KO);

	/////////////////////////////////////

	// Test ft_memcmp
	print_test_header("ft_memcmp");

	// Test 1: Compare first 5 characters of "Hello" and "Hello" - should be equal
	print_test_title(ANSI_COLOR_CYAN, 1, "Compare first 5 characters of \"Hello\" and \"Hello\"");
	char str_memcmp1[] = "Hello";
	char str_memcmp1_2[] = "Hello";
	printf("%s\n", (ft_memcmp(str_memcmp1, str_memcmp1_2, 5) == memcmp(str_memcmp1, str_memcmp1_2, 5)) ? OK : KO);

	// Test2: Compare first 3 characters of "Hello" and "Hell" - should be positive
	print_test_title(ANSI_COLOR_CYAN, 2, "Compare first 3 characters of \"Hello\" and \"Hell\"");
	char str_memcmp2[] = "Hello";
	char str_memcmp2_2[] = "Hell";
	printf("%s\n", (ft_memcmp(str_memcmp2, str_memcmp2_2, 3) == memcmp(str_memcmp2, str_memcmp2_2, 3)) ? OK : KO);

	// Test 3: Compare first 4 characters of "Hello" and "Hell" - should be positive
	print_test_title(ANSI_COLOR_CYAN, 3, "Compare first 4 characters of \"Hello\" and \"Hell\"");
	char str_memcmp3[] = "Hello";
	char str_memcmp3_2[] = "Hell";
	printf("%s\n", (ft_memcmp(str_memcmp3, str_memcmp3_2, 4) == memcmp(str_memcmp3, str_memcmp3_2, 4)) ? OK : KO);

	// Test 4: Compare first 3 characters of "Hell" and "Hello" - should be negative
	print_test_title(ANSI_COLOR_CYAN, 4, "Compare first 3 characters of \"Hell\" and \"Hello\"");
	char str_memcmp4[] = "Hell";
	char str_memcmp4_2[] = "Hello";
	printf("%s\n", (ft_memcmp(str_memcmp4, str_memcmp4_2, 3) == memcmp(str_memcmp4, str_memcmp4_2, 3)) ? OK : KO);

	// Test 5: Compare first 5 characters of "Goodbye" and "Hello" - should be negative
	print_test_title(ANSI_COLOR_CYAN, 5, "Compare first 5 characters of \"Goodbye\" and \"Hello\"");
	char str_memcmp5[] = "Goodbye";
	char str_memcmp5_2[] = "Hello";
	printf("%s\n", (ft_memcmp(str_memcmp5, str_memcmp5_2, 5) == memcmp(str_memcmp5, str_memcmp5_2, 5)) ? OK : KO);

	// Test 6: Compare first 0 characters of "Hello" and "Hello" - should be equal
	print_test_title(ANSI_COLOR_CYAN, 6, "Compare first 0 characters of \"Hello\" and \"Hello\"");
	char str_memcmp6[] = "Hello";
	char str_memcmp6_2[] = "Hello";
	printf("%s\n", (ft_memcmp(str_memcmp6, str_memcmp6_2, 0) == memcmp(str_memcmp6, str_memcmp6_2, 0)) ? OK : KO);

	/////////////////////////////////////

	// Test ft_strnstr
	print_test_header("ft_strnstr");

	// Test 1: Search for "llo" in "Hello" with a limit of 5 characters
	print_test_title(ANSI_COLOR_CYAN, 1, "Search for \"llo\" in \"Hello\" with a limit of 5 characters");
	char str_strnstr1[] = "Hello";
	char str_strnstr1_2[] = "llo";
	printf("%s\n", (ft_strnstr(str_strnstr1, str_strnstr1_2, 5) == str_strnstr1 + 2) ? OK : KO);

	// Test 2: Search for "llo" in "Hello" with a limit of 3 characters
	print_test_title(ANSI_COLOR_CYAN, 2, "Search for \"llo\" in \"Hello\" with a limit of 3 characters");
	char str_strnstr2[] = "Hello";
	char str_strnstr2_2[] = "llo";
	printf("%s\n", (ft_strnstr(str_strnstr2, str_strnstr2_2, 3) == NULL) ? OK : KO);

	// Test 3: Search for "ello" in "Hello" with a limit of 5 characters
	print_test_title(ANSI_COLOR_CYAN, 3, "Search for \"ello\" in \"Hello\" with a limit of 5 characters");
	char str_strnstr3[] = "Hello";
	char str_strnstr3_2[] = "ello";
	printf("%s\n", (ft_strnstr(str_strnstr3, str_strnstr3_2, 5) == str_strnstr3 + 1) ? OK : KO);

	// Test 4: Search for "Hello" in "Hello" with a limit of 10 characters
	print_test_title(ANSI_COLOR_CYAN, 4, "Search for \"Hello\" in \"Hello\" with a limit of 10 characters");
	char str_strnstr4[] = "Hello";
	char str_strnstr4_2[] = "Hello";
	printf("%s\n", (ft_strnstr(str_strnstr4, str_strnstr4_2, 10) == str_strnstr4) ? OK : KO);

	// Test 5: Search for "Good" in "Hello" with a limit of 5 characters
	print_test_title(ANSI_COLOR_CYAN, 5, "Search for \"Good\" in \"Hello\" with a limit of 5 characters");
	char str_strnstr5[] = "Hello";
	char str_strnstr5_2[] = "Good";
	printf("%s\n", (ft_strnstr(str_strnstr5, str_strnstr5_2, 5) == NULL) ? OK : KO);

	// Test 6: Search for "Good" in "Hello" with a limit of 0 characters (empty needle)
	print_test_title(ANSI_COLOR_CYAN, 6, "Search for \"Good\" in \"Hello\" with a limit of 0 characters");
	char str_strnstr6[] = "Hello";
	char str_strnstr6_2[] = "Good";
	printf("%s\n", (ft_strnstr(str_strnstr6, str_strnstr6_2, 0) != str_strnstr6) ? OK : KO);


	/////////////////////////////////////

	// Test ft_atoi
	print_test_header("ft_atoi");

	// Test 1: Convert "123" to integer
	print_test_title(ANSI_COLOR_CYAN, 1, "Convert \"123\" to integer");
	printf("%s\n", (ft_atoi("123") == atoi("123")) ? OK : KO);

	// Test 2: Convert "-123" to integer
	print_test_title(ANSI_COLOR_CYAN, 2, "Convert \"-123\" to integer");
	printf("%s\n", (ft_atoi("-123") == atoi("-123")) ? OK : KO);

	// Test 3: Convert "0" to integer
	print_test_title(ANSI_COLOR_CYAN, 3, "Convert \"0\" to integer");
	printf("%s\n", (ft_atoi("0") == atoi("0")) ? OK : KO);

	// Test 4: Convert "2147483647" to integer
	print_test_title(ANSI_COLOR_CYAN, 4, "Convert \"2147483647\" to integer");
	printf("%s\n", (ft_atoi("2147483647") == atoi("2147483647")) ? OK : KO);

	// Test 5: Convert "-2147483648" to integer
	print_test_title(ANSI_COLOR_CYAN, 5, "Convert \"-2147483648\" to integer");
	printf("%s\n", (ft_atoi("-2147483648") == atoi("-2147483648")) ? OK : KO);

	// Test 6: Convert "2147483648" to integer (overflow)
	print_test_title(ANSI_COLOR_CYAN, 6, "Convert \"2147483648\" to integer (overflow)");
	printf("%s\n", (ft_atoi("2147483648") == atoi("2147483648")) ? OK : KO);

	// Test 7: Convert "-2147483649" to integer (overflow)
	print_test_title(ANSI_COLOR_CYAN, 7, "Convert \"-2147483649\" to integer (overflow)");
	printf("%s\n", (ft_atoi("-2147483649") == atoi("-2147483649")) ? OK : KO);

	// Test 8: Convert "123abc" to integer
	print_test_title(ANSI_COLOR_CYAN, 8, "Convert \"123abc\" to integer");
	printf("%s\n", (ft_atoi("123abc") == atoi("123abc")) ? OK : KO);

	// Test 9: Convert "abc123" to integer
	print_test_title(ANSI_COLOR_CYAN, 9, "Convert \"abc123\" to integer");
	printf("%s\n", (ft_atoi("abc123") == atoi("abc123")) ? OK : KO);

	// Test 10: Convert "abc" to integer
	print_test_title(ANSI_COLOR_CYAN, 10, "Convert \"abc\" to integer");
	printf("%s\n", (ft_atoi("abc") == atoi("abc")) ? OK : KO);

	// Test 11: Convert "123" to integer with leading spaces
	print_test_title(ANSI_COLOR_CYAN, 11, "Convert \"123\" to integer with leading spaces");
	printf("%s\n", (ft_atoi("   123") == atoi("   123")) ? OK : KO);

	// Test 12: Convert "123" to integer with leading spaces and '+' sign
	print_test_title(ANSI_COLOR_CYAN, 12, "Convert \"123\" to integer with leading spaces and '+' sign");
	printf("%s\n", (ft_atoi("   +123") == atoi("   +123")) ? OK : KO);

	// Test 13: Convert "123" to integer with leading spaces and '-' sign
	print_test_title(ANSI_COLOR_CYAN, 13, "Convert \"123\" to integer with leading spaces and '-' sign");
	printf("%s\n", (ft_atoi("   -123") == atoi("   -123")) ? OK : KO);

	/////////////////////////////////////

	// Test ft_calloc
	print_test_header("ft_calloc");

	// Test 1: Allocate memory for 5 integers and initialize to zero
	print_test_title(ANSI_COLOR_CYAN, 1, "Allocate memory for 5 integers and initialize to zero");
	int *ft_calloc_result1 = ft_calloc(5, sizeof(int));
	int *calloc_result1 = calloc(5, sizeof(int));
	printf("%s\n", (memcmp(ft_calloc_result1, calloc_result1, 5 * sizeof(int)) == 0) ? OK : KO);
	free(ft_calloc_result1);
	free(calloc_result1);

	// Test 2: Allocate memory for 3 characters and initialize to zero
	print_test_title(ANSI_COLOR_CYAN, 2, "Allocate memory for 3 characters and initialize to zero");
	char *ft_calloc_result2 = ft_calloc(3, sizeof(char));
	char *calloc_result2 = calloc(3, sizeof(char));
	printf("%s\n", (memcmp(ft_calloc_result2, calloc_result2, 3 * sizeof(char)) == 0) ? OK : KO);
	free(ft_calloc_result2);
	free(calloc_result2);

	// Test 3: Allocate memory for 0 elements (edge case)
	print_test_title(ANSI_COLOR_CYAN, 3, "Allocate memory for 0 elements (edge case)");
	int *ft_calloc_result3 = ft_calloc(0, sizeof(int));
	int *calloc_result3 = calloc(0, sizeof(int));
	printf("%s\n", (memcmp(ft_calloc_result3, calloc_result3, 0) == 0) ? OK : KO);
	free(ft_calloc_result3); // Liberar la memoria asignada por ft_calloc
	free(calloc_result3); // Liberar la memoria asignada por calloc

	// Test 4: Allocate memory with potential overflow
	print_test_title(ANSI_COLOR_CYAN, 4, "Allocate memory with potential overflow (SIZE_MAX)");
	int *ft_calloc_result4 = ft_calloc(SIZE_MAX, sizeof(int));
	printf("%s\n", (ft_calloc_result4 == NULL) ? OK : KO);
	free(ft_calloc_result4);

	/////////////////////////////////////

	// Test ft_strdup
	print_test_header("ft_strdup");

	// Test 1: Duplicate a simple string
	print_test_title(ANSI_COLOR_CYAN, 1, "Duplicate a simple string");
	const char *str1 = "Hello, world!";
	char *ft_strdup_result1 = ft_strdup(str1);
	char *strdup_result1 = strdup(str1);
	printf("%s\n", (strcmp(ft_strdup_result1, strdup_result1) == 0) ? OK : KO);
	free(ft_strdup_result1);
	free(strdup_result1);

	// Test 2: Duplicate an empty string
	print_test_title(ANSI_COLOR_CYAN, 2, "Duplicate an empty string");
	const char *str2 = "";
	char *ft_strdup_result2 = ft_strdup(str2);
	char *strdup_result2 = strdup(str2);
	printf("%s\n", (strcmp(ft_strdup_result2, strdup_result2) == 0) ? OK : KO);
	free(ft_strdup_result2);
	free(strdup_result2);

	// Test 3: Duplicate a string with special characters
	print_test_title(ANSI_COLOR_CYAN, 3, "Duplicate a string with special characters");
	const char *str3 = "!@#$%^&*()";
	char *ft_strdup_result3 = ft_strdup(str3);
	char *strdup_result3 = strdup(str3);
	printf("%s\n", (strcmp(ft_strdup_result3, strdup_result3) == 0) ? OK : KO);
	free(ft_strdup_result3);
	free(strdup_result3);

	/////////////////////////////////////

	// Test ft_substr
	print_test_header("ft_substr");

	// Test 1: Get substring from the beginning
	print_test_title(ANSI_COLOR_CYAN, 1, "Get substring from the beginning");
	const char *ft_substr_str1 = "Hello, world!";
	printf("%s\n", (strcmp(ft_substr(ft_substr_str1, 0, 5), "Hello") == 0) ? OK : KO);

	// Test 2: Get substring from the middle
	print_test_title(ANSI_COLOR_CYAN, 2, "Get substring from the middle");
	const char *ft_substr_str2 = "Hello, world!";
	printf("%s\n", (strcmp(ft_substr(ft_substr_str2, 7, 5), "world") == 0) ? OK : KO);

	// Test 3: Get substring from the end
	print_test_title(ANSI_COLOR_CYAN, 3, "Get substring from the end");
	const char *ft_substr_str3 = "This is a longer string with more words!";
	printf("%s\n", (strcmp(ft_substr(ft_substr_str3, 10, 100), "longer string with more words!") == 0) ? OK : KO);

	// Test 4: Get substring with length 0
	print_test_title(ANSI_COLOR_CYAN, 4, "Get substring with length 0");
	const char *ft_substr_str4 = "Hello, world!";
	printf("%s\n", (strcmp(ft_substr(ft_substr_str4, 7, 0), "") == 0) ? OK : KO);

	// Test 5: Get substring with start index out of bounds
	print_test_title(ANSI_COLOR_CYAN, 5, "Get substring with start index out of bounds");
	const char *ft_substr_str5 = "Hello, world!";
	char *result_substr5 = ft_substr(ft_substr_str5, 100, 5);
	printf("%s\n", (*result_substr5 == '\0') ? OK : KO);
	free(result_substr5);  // Liberar la memoria asignada por ft_substr

	// Test 6: Get substring with negative start index
	print_test_title(ANSI_COLOR_CYAN, 6, "Get substring with negative start index");
	const char *ft_substr_str6 = "Hello, world!";
	char *result_substr6 = ft_substr(ft_substr_str6, -5, 5);
	printf("%s\n", (*result_substr6 == '\0') ? OK : KO);
	free(result_substr6);  // Liberar la memoria asignada por ft_substr

	/////////////////////////////////////

	// Test ft_strjoin
	print_test_header("ft_strjoin");

	// Test 1: Join two strings "Hello" and " World!"
	print_test_title(ANSI_COLOR_CYAN, 1, "Join two strings \"Hello\" and \" World!\"");
	const char *str1_strjoin1 = "Hello";
	const char *str2_strjoin1 = " World!";
	char *ft_strjoin_result1 = ft_strjoin(str1_strjoin1, str2_strjoin1);
	printf("%s\n", (strcmp(ft_strjoin_result1, "Hello World!") == 0) ? OK : KO);
	free(ft_strjoin_result1);

	// Test 2: Join an empty string and "World!"
	print_test_title(ANSI_COLOR_CYAN, 2, "Join an empty string and \"World!\"");
	const char *str1_strjoin2 = "";
	const char *str2_strjoin2 = "World!";
	char *ft_strjoin_result2 = ft_strjoin(str1_strjoin2, str2_strjoin2);
	printf("%s\n", (strcmp(ft_strjoin_result2, "World!") == 0) ? OK : KO);
	free(ft_strjoin_result2);

	// Test 3: Join "Hello" and an empty string
	print_test_title(ANSI_COLOR_CYAN, 3, "Join \"Hello\" and an empty string");
	const char *str1_strjoin3 = "Hello";
	const char *str2_strjoin3 = "";
	char *ft_strjoin_result3 = ft_strjoin(str1_strjoin3, str2_strjoin3);
	printf("%s\n", (strcmp(ft_strjoin_result3, "Hello") == 0) ? OK : KO);
	free(ft_strjoin_result3);

	// Test 4: Join two empty strings
	print_test_title(ANSI_COLOR_CYAN, 4, "Join two empty strings");
	const char *str1_strjoin4 = "";
	const char *str2_strjoin4 = "";
	char *ft_strjoin_result4 = ft_strjoin(str1_strjoin4, str2_strjoin4);
	printf("%s\n", (strcmp(ft_strjoin_result4, "") == 0) ? OK : KO);
	free(ft_strjoin_result4);

	/////////////////////////////////////

	// Test ft_strtrim
	print_test_header("ft_strtrim");

	// Test 1: Trim leading and trailing whitespaces
	print_test_title(ANSI_COLOR_CYAN, 1, "Trim leading and trailing whitespaces");
	const char *strtrim_str1 = "   Hello, world!   ";
	const char *set1 = " ";
	char *ft_strtrim_result1 = ft_strtrim(strtrim_str1, set1);
	printf("%s\n", (strcmp(ft_strtrim_result1, "Hello, world!") == 0) ? OK : KO);
	free(ft_strtrim_result1);

	// Test 2: Trim leading and trailing characters from the set
	print_test_title(ANSI_COLOR_CYAN, 2, "Trim leading and trailing characters from the set");
	const char *strtrim_str2 = "xxxyyHello, world!zzz";
	const char *set2 = "xyz";
	char *ft_strtrim_result2 = ft_strtrim(strtrim_str2, set2);
	printf("%s\n", (strcmp(ft_strtrim_result2, "Hello, world!") == 0) ? OK : KO);
	free(ft_strtrim_result2);

	// Test 3: Empty string
	print_test_title(ANSI_COLOR_CYAN, 3, "Empty string");
	const char *strtrim_str3 = "";
	const char *set3 = "xyz";
	char *ft_strtrim_result3 = ft_strtrim(strtrim_str3, set3);
	printf("%s\n", (strcmp(ft_strtrim_result3, "") == 0) ? OK : KO);
	free(ft_strtrim_result3);

	// Test 4: String with characters only from the set
	print_test_title(ANSI_COLOR_CYAN, 4, "String with characters only from the set");
	const char *strtrim_str4 = "xyzxyzxyz";
	const char *set4 = "xyz";
	char *ft_strtrim_result4 = ft_strtrim(strtrim_str4, set4);
	printf("%s\n", (strcmp(ft_strtrim_result4, "") == 0) ? OK : KO);
	free(ft_strtrim_result4);

	// Test 5: String with no characters from the set
	print_test_title(ANSI_COLOR_CYAN, 5, "String with no characters from the set");
	const char *strtrim_str5 = "Hello, world!";
	const char *set5 = "xyz";
	char *ft_strtrim_result5 = ft_strtrim(strtrim_str5, set5);
	printf("%s\n", (strcmp(ft_strtrim_result5, "Hello, world!") == 0) ? OK : KO);
	free(ft_strtrim_result5);

	/////////////////////////////////////

	// Test ft_split
	print_test_header("ft_split");

	// Test 1: Split a simple string
	print_test_title(ANSI_COLOR_CYAN, 1, "Split a simple string");
	const char *strsplit_str1 = "Hello, world!";
	char **ft_split_result1 = ft_split(strsplit_str1, ' ');
	printf("%s\n", (strcmp(ft_split_result1[0], "Hello,") == 0 && strcmp(ft_split_result1[1], "world!") == 0 && ft_split_result1[2] == NULL) ? OK : KO);
	free(ft_split_result1[0]);
	free(ft_split_result1[1]);
	free(ft_split_result1);

	// Test 2: Split a string with leading and trailing delimiters
	print_test_title(ANSI_COLOR_CYAN, 2, "Split a string with leading and trailing delimiters");
	const char *strsplit_str2 = "   Hello, world!   ";
	char **ft_split_result2 = ft_split(strsplit_str2, ' ');
	printf("%s\n", (strcmp(ft_split_result2[0], "Hello,") == 0 && strcmp(ft_split_result2[1], "world!") == 0 && ft_split_result2[2] == NULL) ? OK : KO);
	free(ft_split_result2[0]);
	free(ft_split_result2[1]);
	free(ft_split_result2);

	// Test 3: Split a string with no delimiters
	print_test_title(ANSI_COLOR_CYAN, 3, "Split a string with no delimiters");
	const char *strsplit_str3 = "Hello, world!";
	char **ft_split_result3 = ft_split(strsplit_str3, 'X');
	printf("%s\n", (strcmp(ft_split_result3[0], "Hello, world!") == 0 && ft_split_result3[1] == NULL) ? OK : KO);
	free(ft_split_result3[0]);
	free(ft_split_result3);
	
	// Test 4: Split an empty string
	print_test_title(ANSI_COLOR_CYAN, 4, "Split an empty string");
	const char *strsplit_str4 = "";
	char **ft_split_result4 = ft_split(strsplit_str4, ' ');
	printf("%s\n", (ft_split_result4[0] == NULL) ? OK : KO);
	free(ft_split_result4);

	// Test 5: Split a string with multiple delimiter
	print_test_title(ANSI_COLOR_CYAN, 5, "Split a string with multiple delimiters");
	const char *strsplit_str5 = "xxxxxHello,xxxxxxxxworld!xxxxxx";
	char **ft_split_result5 = ft_split(strsplit_str5, 'x');
	printf("%s\n", (strcmp(ft_split_result5[0], "Hello,") == 0 && strcmp(ft_split_result5[1], "world!") == 0 && ft_split_result5[2] == NULL) ? OK : KO);
	free(ft_split_result5[0]);
	free(ft_split_result5[1]);
	free(ft_split_result5);

	// Test 6: Split a string with a lot of words delimeted by a comma
	print_test_title(ANSI_COLOR_CYAN, 5, "Split a string with a lot of words delimeted by a comma");
	const char *strsplit_str6 = "Apple,Orange,Banana,Mango";
	char **ft_split_result6 = ft_split(strsplit_str6, ',');
	printf("%s\n", (strcmp(ft_split_result6[0], "Apple") == 0 && strcmp(ft_split_result6[1], "Orange") == 0
		&& strcmp(ft_split_result6[2], "Banana") == 0 && strcmp(ft_split_result6[3], "Mango") == 0 && ft_split_result6[4] == NULL) ? OK : KO);
	free(ft_split_result6[0]);
	free(ft_split_result6[1]);
	free(ft_split_result6[2]);
	free(ft_split_result6[3]);
	free(ft_split_result6);

	/////////////////////////////////////

	// Test ft_itoa
	print_test_header("ft_itoa");

	// Test 1: Convert 123 to string
	print_test_title(ANSI_COLOR_CYAN, 1, "Convert 123 to string");
	printf("%s\n", (strcmp(ft_itoa(123), "123") == 0) ? OK : KO);

	// Test 2: Convert -123 to string
	print_test_title(ANSI_COLOR_CYAN, 2, "Convert -123 to string");
	printf("%s\n", (strcmp(ft_itoa(-123), "-123") == 0) ? OK : KO);

	// Test 3: Convert 0 to string
	print_test_title(ANSI_COLOR_CYAN, 3, "Convert 0 to string");
	printf("%s\n", (strcmp(ft_itoa(0), "0") == 0) ? OK : KO);

	// Test 4: Convert 2147483647 to string
	print_test_title(ANSI_COLOR_CYAN, 4, "Convert 2147483647 to string");
	printf("%s\n", (strcmp(ft_itoa(2147483647), "2147483647") == 0) ? OK : KO);

	// Test 5: Convert -2147483648 to string
	print_test_title(ANSI_COLOR_CYAN, 5, "Convert -2147483648 to string");
	printf("%s\n", (strcmp(ft_itoa(-2147483648), "-2147483648") == 0) ? OK : KO);

	/////////////////////////////////////

	// Test ft_strmapi
	print_test_header("ft_strmapi");

	// Test 1: Apply a simple function to a string
	print_test_title(ANSI_COLOR_CYAN, 1, "Apply a simple function to a string");
	const char *strmapi_str1 = "Hello, world!";
	char *ft_strmapi_result1 = ft_strmapi(strmapi_str1, &ft_strmapi_toggle_case);
	printf("%s\n", (strcmp(ft_strmapi_result1, "hELLO, WORLD!") == 0) ? OK : KO);
	free(ft_strmapi_result1);

	// Test 2: Apply a function to an empty string
	print_test_title(ANSI_COLOR_CYAN, 2, "Apply a function to an empty string");
	const char *strmapi_str2 = "";
	char *ft_strmapi_result2 = ft_strmapi(strmapi_str2, &ft_strmapi_toggle_case);
	printf("%s\n", (strcmp(ft_strmapi_result2, "") == 0) ? OK : KO);
	free(ft_strmapi_result2);

	// Test 3: Apply a function to a string with special characters
	print_test_title(ANSI_COLOR_CYAN, 3, "Apply a function to a string with special characters");
	const char *strmapi_str3 = "x@xx1xx$xxx3xx";
	char *ft_strmapi_result3 = ft_strmapi(strmapi_str3, &ft_strmapi_toggle_case);
	printf("%s\n", (strcmp(ft_strmapi_result3, "X@XX1XX$XXX3XX") == 0) ? OK : KO);
	free(ft_strmapi_result3);

	/////////////////////////////////////

	// Test ft_striteri
	print_test_header("ft_striteri");

	// Test 1: Apply a simple function to a string
	print_test_title(ANSI_COLOR_CYAN, 1, "Apply a simple function to a string");
	char striteri_str1[] = "Hello, world!";
	ft_striteri(striteri_str1, ft_striteri_toggle_case);
	printf("%s\n", (strcmp(striteri_str1, "hELLO, WORLD!") == 0) ? OK : KO);

	// Test 2: Apply a function to an empty string
	print_test_title(ANSI_COLOR_CYAN, 2, "Apply a function to an empty string");
	char striteri_str2[] = "";
	ft_striteri(striteri_str2, ft_striteri_toggle_case);
	printf("%s\n", (strcmp(striteri_str2, "") == 0) ? OK : KO);

	// Test 3: Apply a function to a string with special characters
	print_test_title(ANSI_COLOR_CYAN, 3, "Apply a function to a string with special characters");
	char striteri_str3[] = "x@xx1xx$xxx3xx";
	ft_striteri(striteri_str3, ft_striteri_toggle_case);
	printf("%s\n", (strcmp(striteri_str3, "X@XX1XX$XXX3XX") == 0) ? OK : KO);

	/////////////////////////////////////

	// Test ft_putchar_fd
	print_test_header("ft_putchar_fd");

	int		fd_ft_putchar_fd;
	char	char_ft_putchar_fd;
	char	buffer[2]; // Buffer para leer el contenido del archivo

	// Abre o crea un archivo llamado "ft_putchar_fd.txt"
	// en modo de escritura (O_WRONLY)
	// y con la bandera O_CREAT que crea el archivo si no existe.
	fd_ft_putchar_fd = open("ft_putchar_fd.txt", O_WRONLY | O_CREAT, 0644);
	if (fd_ft_putchar_fd == -1)
	{
		perror("Error al abrir el archivo");
		return (EXIT_FAILURE);
	}

	// Carácter que queremos escribir en el archivo
	char_ft_putchar_fd = 'c';

	// Llama a la función para escribir el carácter en el archivo
	ft_putchar_fd(char_ft_putchar_fd, fd_ft_putchar_fd);

	// Cierra el archivo
	if (close(fd_ft_putchar_fd) == -1)
	{
		perror("Error al cerrar el archivo");
		return (EXIT_FAILURE);
	}

	// Vuelve a abrir el archivo en modo de lectura (O_RDONLY)
	fd_ft_putchar_fd = open("ft_putchar_fd.txt", O_RDONLY);
	if (fd_ft_putchar_fd == -1)
	{
		perror("Error al abrir el archivo para lectura");
		return (EXIT_FAILURE);
	}

	// Lee un carácter del archivo y colócalo en el buffer
	ssize_t bytes_read = read(fd_ft_putchar_fd, buffer, 1);
	if (bytes_read == -1)
	{
		perror("Error al leer el archivo");
		return (EXIT_FAILURE);
	}

	// Null-termina el buffer
	buffer[1] = '\0';

	// Compara el contenido del archivo con el resultado esperado
	if (strcmp(buffer, "c") == 0)
	{
		print_test_title(ANSI_COLOR_CYAN, 1, "Correct character writing in the fd");
		printf(OK "\n");
	}
	else
	{
		print_test_title(ANSI_COLOR_CYAN, 1, "Correct character writing in the fd");
		printf(KO "\n");
	}

	// Cierra el archivo
	if (close(fd_ft_putchar_fd) == -1)
	{
		perror("Error al cerrar el archivo");
		return (EXIT_FAILURE);
	}

	// Elimina el archivo
	if (remove("ft_putchar_fd.txt") != 0)
	{
		perror("Error al eliminar el archivo");
		return (EXIT_FAILURE);
	}

	/////////////////////////////////////

	// Test ft_putstr_fd
	print_test_header("ft_putstr_fd");

	int		fd_ft_putstr_fd;
	char	*str_ft_putstr_fd;
	char	buffer_putstr_fd[256]; // Buffer para leer el contenido del archivo

	// Abre o crea un archivo llamado "ft_putstr_fd.txt"
	// en modo de escritura (O_WRONLY)
	// y con la bandera O_CREAT que crea el archivo si no existe.
	fd_ft_putstr_fd = open("ft_putstr_fd.txt", O_WRONLY | O_CREAT, 0644);
	if (fd_ft_putstr_fd == -1)
	{
		perror("Error al abrir el archivo");
		return (EXIT_FAILURE);
	}

	// Cadena que queremos escribir en el archivo
	str_ft_putstr_fd = "Hello, world!";

	// Llama a la función para escribir la cadena en el archivo
	ft_putstr_fd(str_ft_putstr_fd, fd_ft_putstr_fd);

	// Cierra el archivo
	if (close(fd_ft_putstr_fd) == -1)
	{
		perror("Error al cerrar el archivo");
		return (EXIT_FAILURE);
	}

	// Vuelve a abrir el archivo en modo de lectura (O_RDONLY)
	fd_ft_putstr_fd = open("ft_putstr_fd.txt", O_RDONLY);
	if (fd_ft_putstr_fd == -1)
	{
		perror("Error al abrir el archivo para lectura");
		return (EXIT_FAILURE);
	}

	// Lee el contenido del archivo y colócalo en el buffer
	ssize_t bytes_read_ft_putstr_fd = read(fd_ft_putstr_fd, buffer_putstr_fd, sizeof(buffer_putstr_fd) - 1);
	if (bytes_read_ft_putstr_fd == -1)
	{
		perror("Error al leer el archivo");
		return (EXIT_FAILURE);
	}

	// Null-termina el buffer
	buffer_putstr_fd[bytes_read_ft_putstr_fd] = '\0';

	// Compara el contenido del archivo con el resultado esperado
	if (strcmp(buffer_putstr_fd, str_ft_putstr_fd) == 0)
	{
		print_test_title(ANSI_COLOR_CYAN, 1, "Correct string writing in the fd");
		printf(OK "\n");
	}
	else
	{
		print_test_title(ANSI_COLOR_CYAN, 1, "Correct string writing in the fd");
		printf(KO "\n");
	}

	// Cierra el archivo
	if (close(fd_ft_putstr_fd) == -1)
	{
		perror("Error al cerrar el archivo");
		return (EXIT_FAILURE);
	}

	// Elimina el archivo
	if (remove("ft_putstr_fd.txt") != 0)
	{
		perror("Error al eliminar el archivo");
		return (EXIT_FAILURE);
	}

	/////////////////////////////////////

	// Test ft_putendl_fd
	print_test_header("ft_putendl_fd");

	int		fd_ft_putendl_fd;
	char	*str_ft_putendl_fd;
	char	buffer_putendl_fd[256]; // Buffer para leer el contenido del archivo

	// Abre o crea un archivo llamado "ft_putendl_fd.txt"
	// en modo de escritura (O_WRONLY)
	// y con la bandera O_CREAT que crea el archivo si no existe.
	fd_ft_putendl_fd = open("ft_putendl_fd.txt", O_WRONLY | O_CREAT, 0644);
	if (fd_ft_putendl_fd == -1)
	{
		perror("Error al abrir el archivo");
		return (EXIT_FAILURE);
	}

	// Cadena que queremos escribir en el archivo
	str_ft_putendl_fd = "Hello, world!";

	// Llama a la función para escribir la cadena seguida de un salto de línea en el archivo
	ft_putendl_fd(str_ft_putendl_fd, fd_ft_putendl_fd);

	// Cierra el archivo
	if (close(fd_ft_putendl_fd) == -1)
	{
		perror("Error al cerrar el archivo");
		return (EXIT_FAILURE);
	}

	// Vuelve a abrir el archivo en modo de lectura (O_RDONLY)
	fd_ft_putendl_fd = open("ft_putendl_fd.txt", O_RDONLY);
	if (fd_ft_putendl_fd == -1)
	{
		perror("Error al abrir el archivo para lectura");
		return (EXIT_FAILURE);
	}

	// Lee el contenido del archivo y colócalo en el buffer
	ssize_t bytes_read_ft_putendl_fd = read(fd_ft_putendl_fd, buffer_putendl_fd, sizeof(buffer_putendl_fd) - 1);
	if (bytes_read_ft_putendl_fd == -1)
	{
		perror("Error al leer el archivo");
		return (EXIT_FAILURE);
	}

	// Null-termina el buffer
	buffer_putendl_fd[bytes_read_ft_putendl_fd] = '\0';

	// Compara el contenido del archivo con el resultado esperado
	if (strcmp(buffer_putendl_fd, "Hello, world!\n") == 0)
	{
		print_test_title(ANSI_COLOR_CYAN, 1, "Correct string writing with newline in the fd");
		printf(OK "\n");
	}
	else
	{
		print_test_title(ANSI_COLOR_CYAN, 1, "Correct string writing with newline in the fd");
		printf(KO "\n");
	}

	// Cierra el archivo
	if (close(fd_ft_putendl_fd) == -1)
	{
		perror("Error al cerrar el archivo");
		return (EXIT_FAILURE);
	}

	// Elimina el archivo
	if (remove("ft_putendl_fd.txt") != 0)
	{
		perror("Error al eliminar el archivo");
		return (EXIT_FAILURE);
	}

	/////////////////////////////////////

	// Test ft_putnbr_fd
	print_test_header("ft_putnbr_fd");

	int		fd_ft_putnbr_fd;
	int		numbers_putnbr_fd[] = {12345, -12345, 0, -2147483648};
	char	buffer_putnbr_fd[256]; // Buffer para leer el contenido del archivo

	for (int i = 0; i < sizeof(numbers_putnbr_fd) / sizeof(numbers_putnbr_fd[0]); i++)
	{
		// Abre o crea un archivo llamado "ft_putnbr_fd.txt"
		// en modo de escritura (O_WRONLY)
		// y con la bandera O_CREAT que crea el archivo si no existe.
		fd_ft_putnbr_fd = open("ft_putnbr_fd.txt", O_WRONLY | O_CREAT, 0644);
		if (fd_ft_putnbr_fd == -1)
		{
			perror("Error al abrir el archivo");
			return (EXIT_FAILURE);
		}

		// Llama a la función para escribir el número en el archivo
		ft_putnbr_fd(numbers_putnbr_fd[i], fd_ft_putnbr_fd);

		// Cierra el archivo
		if (close(fd_ft_putnbr_fd) == -1)
		{
			perror("Error al cerrar el archivo");
			return (EXIT_FAILURE);
		}

		// Vuelve a abrir el archivo en modo de lectura (O_RDONLY)
		fd_ft_putnbr_fd = open("ft_putnbr_fd.txt", O_RDONLY);
		if (fd_ft_putnbr_fd == -1)
		{
			perror("Error al abrir el archivo para lectura");
			return (EXIT_FAILURE);
		}

		// Lee el contenido del archivo y colócalo en el buffer
		ssize_t bytes_read_ft_putnbr_fd = read(fd_ft_putnbr_fd, buffer_putnbr_fd, sizeof(buffer_putnbr_fd) - 1);
		if (bytes_read_ft_putnbr_fd == -1)
		{
			perror("Error al leer el archivo");
			return (EXIT_FAILURE);
		}

		// Null-termina el buffer
		buffer_putnbr_fd[bytes_read_ft_putnbr_fd] = '\0';

		// Compara el contenido del archivo con el resultado esperado
		if (strcmp(buffer_putnbr_fd, ft_itoa(numbers_putnbr_fd[i])) == 0)
		{
			print_test_title(ANSI_COLOR_CYAN, i + 1, "Correct number %d writing in the fd", numbers_putnbr_fd[i]);
			printf(OK "\n");
		}
		else
		{
			print_test_title(ANSI_COLOR_CYAN, i + 1, "Correct number %d writing in the fd", numbers_putnbr_fd[i]);
			printf(KO "\n");
		}

		// Cierra el archivo
		if (close(fd_ft_putnbr_fd) == -1)
		{
			perror("Error al cerrar el archivo");
			return (EXIT_FAILURE);
		}

		// Elimina el archivo
		if (remove("ft_putnbr_fd.txt") != 0)
		{
			perror("Error al eliminar el archivo");
			return (EXIT_FAILURE);
		}
	}

	/////////////////////////////////////
	return 0;
}

 */


//Funciones adicionales//
static void	ft_del_node_content(void *content)
{
	if (content != NULL)
		free(content);
}

//Funciones adicionales ft_lstiter_bonus//
// Define the function pointer type for the function to apply to each node content
typedef void (*t_func_ptr)(void *);

// Example function to be applied to each node content
void	ft_print_content(void *content)
{
	if (content != NULL)
		printf("%s\n", (char *)content);
}

//Funciones adicionales ft_lstmap_bonus//
// Function to double the content of each node
void *ft_double_content(void *content)
{
	char *original_value = (char *)content;
	char *doubled_value = ft_strjoin(original_value, original_value); // Join the string with itself to double its content
	return doubled_value;
}

///////////////////////////////////
//			PARTE BONUS			//
/////////////////////////////////

// cc main.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_strjoin.c ft_strlen.c

int main()
{
	// Test ft_lstnew
	print_test_header("ft_lstnew");

	// Test 1: Create a new node with null content
	print_test_title(ANSI_COLOR_CYAN, 1, "Create a new node with null content");
	t_list *ft_lstnew_result1 = ft_lstnew(NULL);
	printf("%s\n", (ft_lstnew_result1 != NULL && ft_lstnew_result1->content == NULL && ft_lstnew_result1->next == NULL) ? OK : KO);

	// Test 2: Create a new node with non-null content
	print_test_title(ANSI_COLOR_CYAN, 2, "Create a new node with non-null content");
	char *content_test2 = "Test";
	t_list *ft_lstnew_result2 = ft_lstnew(content_test2);
	printf("%s\n", (ft_lstnew_result2 != NULL && ft_lstnew_result2->content != NULL && ft_lstnew_result2->next == NULL && strcmp(ft_lstnew_result2->content, content_test2) == 0) ? OK : KO);

	// Test 3: Check the connection to the next node
	print_test_title(ANSI_COLOR_CYAN, 3, "Check the connection to the next node");
	t_list *node1_test3 = ft_lstnew("Node 1");
	t_list *node2_test3 = ft_lstnew("Node 2");
	node1_test3->next = node2_test3;
	printf("%s\n", (node1_test3->next == node2_test3) ? OK : KO);

	// Test 4: Check the connection to the next node when content is null
	print_test_title(ANSI_COLOR_CYAN, 4, "Check the connection to the next node when content is null");
	t_list *node1_test4 = ft_lstnew(NULL);
	t_list *node2_test4 = ft_lstnew(NULL);
	node1_test4->next = node2_test4;
	printf("%s\n", (node1_test4->next == node2_test4) ? OK : KO);

	/////////////////////////////////////

	// Test ft_lstadd_front
	print_test_header("ft_lstadd_front");

	// Test 1: Add a node to an empty list
	print_test_title(ANSI_COLOR_CYAN, 1, "Add a node to an empty list");
	t_list *lst_test1 = NULL;
	t_list *new_node_test1 = ft_lstnew("Node 1");
	ft_lstadd_front(&lst_test1, new_node_test1);
	printf("%s\n", (lst_test1 == new_node_test1) ? OK : KO);

	// Test 2: Add a node to a non-empty list
	print_test_title(ANSI_COLOR_CYAN, 2, "Add a node to a non-empty list");
	t_list *lst_test2 = ft_lstnew("Node 1");
	t_list *new_node_test2 = ft_lstnew("Node 2");
	ft_lstadd_front(&lst_test2, new_node_test2);
	printf("%s\n", (lst_test2 == new_node_test2 && lst_test2->next != NULL && lst_test2->next->content != NULL) ? OK : KO);

	// Test 3: Add a node with null content to a non-empty list
	print_test_title(ANSI_COLOR_CYAN, 3, "Add a node with null content to a non-empty list");
	t_list *lst3 = ft_lstnew("node1");
	t_list *new3 = ft_lstnew(NULL); // Crear un nuevo nodo con contenido nulo
	ft_lstadd_front(&lst3, new3);
	printf("%s\n", (lst3 == new3 && lst3->content == NULL && lst3->next != NULL) ? OK : KO);

	/////////////////////////////////////

	// Test ft_lstsize
	print_test_header("ft_lstsize");

	// Test 1: Count nodes in an empty list
	print_test_title(ANSI_COLOR_CYAN, 1, "Count nodes in an empty list");
	t_list *ft_lstsize_lst1 = NULL;
	int ft_lstsize_result1 = ft_lstsize(ft_lstsize_lst1);
	printf("%s\n", (ft_lstsize_result1 == 0) ? OK : KO);

	// Test 2: Count nodes in a list with one node
	print_test_title(ANSI_COLOR_CYAN, 2, "Count nodes in a list with one node");
	t_list *ft_lstsize_lst2 = ft_lstnew("node1");
	int ft_lstsize_result2 = ft_lstsize(ft_lstsize_lst2);
	printf("%s\n", (ft_lstsize_result2 == 1) ? OK : KO);

	// Test 3: Count nodes in a list with multiple nodes
	print_test_title(ANSI_COLOR_CYAN, 3, "Count nodes in a list with multiple nodes");
	t_list *ft_lstsize_lst3 = ft_lstnew("node1");
	ft_lstadd_front(&ft_lstsize_lst3, ft_lstnew("node2"));
	ft_lstadd_front(&ft_lstsize_lst3, ft_lstnew("node3"));
	int ft_lstsize_result3 = ft_lstsize(ft_lstsize_lst3);
	printf("%s\n", (ft_lstsize_result3 == 3) ? OK : KO);

	/////////////////////////////////////

	// Test ft_lstlast
	print_test_header("ft_lstlast");

	// Test 1: Get last node from an empty list
	print_test_title(ANSI_COLOR_CYAN, 1, "Get last node from an empty list");
	t_list *ft_lstlast_lst1 = NULL;
	t_list *ft_lstlast_result1 = ft_lstlast(ft_lstlast_lst1);
	printf("%s\n", (ft_lstlast_result1 == NULL) ? OK : KO);

	// Test 2: Get last node from a list with one node
	print_test_title(ANSI_COLOR_CYAN, 2, "Get last node from a list with one node");
	t_list *ft_lstlast_lst2 = ft_lstnew("node1");
	t_list *ft_lstlast_result2 = ft_lstlast(ft_lstlast_lst2);
	printf("%s\n", (ft_lstlast_result2 == ft_lstlast_lst2) ? OK : KO);

	// Test 3: Get last node from a list with multiple nodes
	print_test_title(ANSI_COLOR_CYAN, 3, "Get last node from a list with multiple nodes");
	t_list *ft_lstlast_lst3 = ft_lstnew("node1");
	ft_lstadd_front(&ft_lstlast_lst3, ft_lstnew("node2"));
	ft_lstadd_front(&ft_lstlast_lst3, ft_lstnew("node3"));
	t_list *ft_lstlast_result3 = ft_lstlast(ft_lstlast_lst3);
	printf("%s\n", (ft_lstlast_result3->content == "node1") ? OK : KO);

	/////////////////////////////////////

	// Test ft_lstadd_back
	print_test_header("ft_lstadd_back");

	// Test 1: Add a node to the end of an empty list
	print_test_title(ANSI_COLOR_CYAN, 1, "Add a node to the end of an empty list");
	t_list *ft_lstadd_back_lst1 = NULL;
	t_list *new_node1 = ft_lstnew("node1");
	ft_lstadd_back(&ft_lstadd_back_lst1, new_node1);
	printf("%s\n", (ft_lstadd_back_lst1 == new_node1) ? OK : KO);

	// Test 2: Add a node to the end of a list with one node
	print_test_title(ANSI_COLOR_CYAN, 2, "Add a node to the end of a list with one node");
	t_list *ft_lstadd_back_lst2 = ft_lstnew("node1");
	t_list *new_node2 = ft_lstnew("node2");
	ft_lstadd_back(&ft_lstadd_back_lst2, new_node2);
	printf("%s\n", (ft_lstadd_back_lst2->next == new_node2) ? OK : KO);

	// Test 3: Add a node to the end of a list with multiple nodes
	print_test_title(ANSI_COLOR_CYAN, 3, "Add a node to the end of a list with multiple nodes");
	t_list *ft_lstadd_back_lst3 = ft_lstnew("node1");
	ft_lstadd_back(&ft_lstadd_back_lst3, ft_lstnew("node2"));
	ft_lstadd_back(&ft_lstadd_back_lst3, ft_lstnew("node3"));
	t_list *new_node3 = ft_lstnew("node4");
	ft_lstadd_back(&ft_lstadd_back_lst3, new_node3);
	t_list *last_node = ft_lstlast(ft_lstadd_back_lst3);
	printf("%s\n", (last_node == new_node3) ? OK : KO);

	/////////////////////////////////////

	// Test ft_lstdelone
	print_test_header("ft_lstdelone");

	// Test 1: Delete a node with content "Hello"
	print_test_title(ANSI_COLOR_CYAN, 1, "Delete a node with content 'Hello'");
	t_list *lst_delone_test1 = ft_lstnew(strdup("Hello"));
	ft_lstdelone(lst_delone_test1, &ft_del_node_content);
	lst_delone_test1 = NULL; // Set the pointer to NULL after deleting the node
	printf("%s\n", (lst_delone_test1 == NULL) ? OK : KO);

	// Test 2: Delete a node with content "World"
	print_test_title(ANSI_COLOR_CYAN, 2, "Delete a node with content 'World'");
	t_list *lst_delone_test2 = ft_lstnew(strdup("World"));
	ft_lstdelone(lst_delone_test2, &ft_del_node_content);
	lst_delone_test2 = NULL; // Set the pointer to NULL after deleting the node
	printf("%s\n", (lst_delone_test2 == NULL) ? OK : KO);

	// Test 3: Delete a NULL node
	print_test_title(ANSI_COLOR_CYAN, 3, "Delete a NULL node");
	t_list *lst_delone_test3 = NULL;
	ft_lstdelone(lst_delone_test3, &ft_del_node_content);
	printf("%s\n", (lst_delone_test3 == NULL) ? OK : KO);

	/////////////////////////////////////

	// Test ft_lstclear
	print_test_header("ft_lstclear");

	// Test 1: Clear a list with multiple nodes
	print_test_title(ANSI_COLOR_CYAN, 1, "Clear a list with multiple nodes");
	t_list *lst_clear_test1 = ft_lstnew(strdup("Node 1"));
	ft_lstadd_back(&lst_clear_test1, ft_lstnew(strdup("Node 2")));
	ft_lstadd_back(&lst_clear_test1, ft_lstnew(strdup("Node 3")));
	ft_lstadd_back(&lst_clear_test1, ft_lstnew(strdup("Node 4")));
	ft_lstclear(&lst_clear_test1, &ft_del_node_content);
	printf("%s\n", (lst_clear_test1 == NULL) ? OK : KO);

	// Test 2: Clear an empty list
	print_test_title(ANSI_COLOR_CYAN, 2, "Clear an empty list");
	t_list *lst_clear_test2 = NULL;
	ft_lstclear(&lst_clear_test2, &ft_del_node_content);
	printf("%s\n", (lst_clear_test2 == NULL) ? OK : KO);

	/////////////////////////////////////

	// Test ft_lstiter
	print_test_header("ft_lstiter");

	// Test 1: Iterate through a list and print each node content
	print_test_title(ANSI_COLOR_CYAN, 1, "Iterate through a list and print each node content");
	t_list *lst_iter_test1 = ft_lstnew(strdup("Node 1"));
	ft_lstadd_back(&lst_iter_test1, ft_lstnew(strdup("Node 2")));
	ft_lstadd_back(&lst_iter_test1, ft_lstnew(strdup("Node 3")));
	ft_lstadd_back(&lst_iter_test1, ft_lstnew(strdup("Node 4")));
	printf("Expected output:\n");
	ft_lstiter(lst_iter_test1, &ft_print_content);
	printf("%s\n", OK);

	// Test 2: Iterate through an empty list
	print_test_title(ANSI_COLOR_CYAN, 2, "Iterate through an empty list");
	t_list *lst_iter_test2 = NULL;
	printf("Expected output: <No output>\n");
	ft_lstiter(lst_iter_test2, &ft_print_content);
	printf("%s\n", OK);

	/////////////////////////////////////

	// Test ft_lstmap
	print_test_header("ft_lstmap");

	// Test 1: Map each node content to double its value
	print_test_title(ANSI_COLOR_CYAN, 1, "Map each node content to double its value");
	t_list *lst_map_test1 = ft_lstnew(strdup("Node 1"));
	ft_lstadd_back(&lst_map_test1, ft_lstnew(strdup("Node 2")));
	ft_lstadd_back(&lst_map_test1, ft_lstnew(strdup("Node 3")));
	ft_lstadd_back(&lst_map_test1, ft_lstnew(strdup("Node 4")));

	t_list *mapped_list = ft_lstmap(lst_map_test1, &ft_double_content, &ft_del_node_content);
	t_list *current = mapped_list;
	int success = 1;
	char *expected_values[] = {"Node 1Node 1", "Node 2Node 2", "Node 3Node 3", "Node 4Node 4"};
	int i = 0;
	while (current)
	{
		char *value = (char *)current->content;
		printf("%s\n", value); // Print the content of each node
		if (strcmp(value, expected_values[i++]) != 0)
		{
			success = 0;
			break;
		}
		current = current->next;
	}
	printf("Expected output: %s\n", success ? OK : KO);

	// Test 2: Map an empty list
	print_test_title(ANSI_COLOR_CYAN, 2, "Map an empty list");
	t_list *lst_map_test2 = NULL;
	t_list *mapped_list_empty = ft_lstmap(lst_map_test2, &ft_double_content, &ft_del_node_content);
	printf("Expected output: %s\n", (mapped_list_empty == NULL) ? OK : KO);




}