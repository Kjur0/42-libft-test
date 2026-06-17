/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:16:02 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/17 15:46:29 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>

# define SETUP_TEST int	g_testn = 0;\
	int	test
# define TEST_PRINT(cond, print, expected, real) printf("> TEST %d\n", ++g_testn);\
	if (cond)\
	printf("\x1B[92m✓ TEST PASSED\x1B[0m\n");\
	else\
	{\
		printf("\x1B[91m⚠ TEST FAILED\x1B[0m\n");\
		printf(print, expected, real);\
	}
# define TEST(cond) printf("> TEST %d\n", ++g_testn);\
	if (cond)\
	printf("\x1B[92m✓ TEST PASSED\x1B[0m\n");\
	else\
	{\
		printf("\x1B[91m⚠ TEST FAILED\x1B[0m\n");\
	}
# define TEST_FINAL(cond) return (cond);
# define INIT_TESTS(name) int	tests_passed;\
	tests_passed = 0;\
	printf("-=-=-TESTING \x1B[95m%s\x1B[0m-=-=-\n\n", name);
# define TEST_CASE tests_passed += test
# define TESTS_RESULT 	if (tests_passed == g_testn)\
	printf("\n\x1B[92m✓ ALL %d TESTS PASSED\x1B[0m\n\n", tests_passed);\
	else if (tests_passed == 0)\
	printf("\n\x1B[91m⚠ ALL %d TESTS FAILED\x1B[0m\n\n", g_testn);\
	else\
	printf("\n\x1B[93m %d/%d TESTS PASSED\x1B[0m\n\n", tests_passed, g_testn);\
	return (g_testn - tests_passed);

#endif
