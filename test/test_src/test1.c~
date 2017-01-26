#include "tinytest.h"
#include "malloc.h"

void	add_free_block_to_list(t_block *block);
void	add_before(t_block *list, t_block *new);
void	add_after(t_block *list, t_block *new);
void	free_page(t_page *page);

void	reset_struct()
{
	g_main_struct = NULL;
}

void	test_init_main_struct(void)
{
	init_main_struct();
	ASSERT_EQUALS(1, (
		g_main_struct->init &&
		!g_main_struct->page &&
		!g_main_struct->free_block));
	reset_struct();
}

void	test_get_malloc_type(void)
{
	init_main_struct();
	ASSERT_EQUALS(TINY, get_malloc_type(TINY_SIZE));
	ASSERT_EQUALS(TINY, get_malloc_type(1));
	ASSERT_EQUALS(SMALL, get_malloc_type(TINY_SIZE + 1));
	ASSERT_EQUALS(SMALL, get_malloc_type(SMALL_SIZE));
	ASSERT_EQUALS(LARGE, get_malloc_type(SMALL_SIZE + 1));
	ASSERT_EQUALS(0, get_malloc_type(0));
	reset_struct();
}

void	test_get_free_block_in_list(void)
{
	char *s;

	init_main_struct();
	ASSERT_EQUALS(0, get_free_block_in_list(20));
	s = malloc(20);
	ASSERT_EQUALS(0, get_free_block_in_list(20));
	free(s);
	ASSERT_EQUALS(1, get_free_block_in_list(20) ? 1 : 0);
	ASSERT_EQUALS(0, get_free_block_in_list(20));
	reset_struct();
}

void	test_check_adress(void)
{
	char 	*s;
	int		adress;

	init_main_struct();
	ASSERT_EQUALS(0, check_adress(&adress));
	s = (char *)malloc(20);
	ASSERT_EQUALS(1, check_adress(s));
	s = (char *)realloc(s, 1025);
	ASSERT_EQUALS(1, check_adress(s));
	free(s);
	ASSERT_EQUALS(0, check_adress(s));
	ASSERT_EQUALS(0, check_adress(0));
	reset_struct();
}

void	test_defragment(void)
{
	char	*s1, *s2, *s3;

	init_main_struct();
	s1 = (char *)malloc(10);
	s2 = (char *)malloc(20);
	s3 = (char *)malloc(30);
	//	Un seul block free, donc pas de defragmentation a effectué
	free(s1);
	ASSERT_EQUALS(10, g_main_struct->free_block->size);
	ASSERT_EQUALS(0, g_main_struct->free_block->free_next ? 1 : 0);
	ASSERT_EQUALS(0, g_main_struct->free_block->free_prev ? 1 : 0);
	// Deux block free mais non contigus, donc pas de defragmentation
	free(s3);
	ASSERT_EQUALS(10, g_main_struct->free_block->size);
	ASSERT_EQUALS(30, g_main_struct->free_block->free_next->size);
	// Trois blocks free contigus, defrag doit fusionner les trois
	free(s2);
	ASSERT_EQUALS((10 + 20 + 30 + (sizeof(t_block) * 2)),
		g_main_struct->free_block->size);
	ASSERT_EQUALS(0, g_main_struct->free_block->free_next ? 1 : 0);
	ASSERT_EQUALS(0, g_main_struct->free_block->free_prev ? 1 : 0);
	reset_struct();
}

void	test_add_before(void)
{
	char	*s1, *s2, *s3;
	int		i = 0;

	init_main_struct();
	s1 = (char *)malloc(10);
	s2 = (char *)malloc(20);
	s3 = (char *)malloc(30);
	free(s1);
	ASSERT_EQUALS(10, g_main_struct->free_block->size);
	ASSERT_EQUALS(0, g_main_struct->free_block->free_next ? 1 : 0);
	ASSERT_EQUALS(0, g_main_struct->free_block->free_prev ? 1 : 0);
	add_before(g_main_struct->free_block, ((void *)s2 - sizeof(t_block)));
	ASSERT_EQUALS(20, g_main_struct->free_block->size);
	ASSERT_EQUALS(1, g_main_struct->free_block->free_next ? 1 : 0);
	ASSERT_EQUALS(0, g_main_struct->free_block->free_prev ? 1 : 0);
	add_before(g_main_struct->free_block, ((void *)s3 - sizeof(t_block)));
	ASSERT_EQUALS(30, g_main_struct->free_block->size);
	ASSERT_EQUALS(1, g_main_struct->free_block->free_next ? 1 : 0);
	ASSERT_EQUALS(0, g_main_struct->free_block->free_prev ? 1 : 0);
	while (g_main_struct->free_block && ++i)
		g_main_struct->free_block = g_main_struct->free_block->free_next;
	ASSERT_EQUALS(3, i);
	reset_struct();
}

void	test_add_after(void)
{
	char	*s1, *s2, *s3;
	int		i = 0;

	init_main_struct();
	s1 = (char *)malloc(10);
	s2 = (char *)malloc(20);
	s3 = (char *)malloc(30);
	free(s1);
	ASSERT_EQUALS(10, g_main_struct->free_block->size);
	ASSERT_EQUALS(0, g_main_struct->free_block->free_next ? 1 : 0);
	ASSERT_EQUALS(0, g_main_struct->free_block->free_prev ? 1 : 0);
	add_after(g_main_struct->free_block, ((void *)s2 - sizeof(t_block)));
	ASSERT_EQUALS(10, g_main_struct->free_block->size);
	ASSERT_EQUALS(1, g_main_struct->free_block->free_next ? 1 : 0);
	ASSERT_EQUALS(20, g_main_struct->free_block->free_next->size);
	ASSERT_EQUALS(0, g_main_struct->free_block->free_prev ? 1 : 0);
	add_after(g_main_struct->free_block->free_next, ((void *)s3 - sizeof(t_block)));
	ASSERT_EQUALS(10, g_main_struct->free_block->size);
	ASSERT_EQUALS(1, g_main_struct->free_block->free_next->free_next ? 1 : 0);
	ASSERT_EQUALS(30, g_main_struct->free_block->free_next->free_next->size);
	ASSERT_EQUALS(0, g_main_struct->free_block->free_prev ? 1 : 0);
	while (g_main_struct->free_block && ++i)
		g_main_struct->free_block = g_main_struct->free_block->free_next;
	ASSERT_EQUALS(3, i);
	reset_struct();
}

void	test_add_free_block_to_list(void)
{
	char	*s1, *s2, *s3;

	init_main_struct();
	s1 = (char *)malloc(10);
	s2 = (char *)malloc(20);
	s3 = (char *)malloc(30);
	free(s2);
	add_free_block_to_list(((void *)s1 - sizeof(t_block)));
	ASSERT_EQUALS(10, g_main_struct->free_block->size);
	add_free_block_to_list(((void *)s3 - sizeof(t_block)));
	ASSERT_EQUALS(10, g_main_struct->free_block->size);
	ASSERT_EQUALS(20, g_main_struct->free_block->free_next->size);
	ASSERT_EQUALS(30, g_main_struct->free_block->free_next->free_next->size);
	reset_struct();
}

void	test_free_page(void)
{
	int i = 0;

	init_main_struct();
	while (i++ < 100)
		malloc(128);
	malloc(1024);
	free_page(g_main_struct->page);
	ASSERT_EQUALS(1, (g_main_struct->page->type == TINY));
	malloc(1024);
	ASSERT_EQUALS(1, (g_main_struct->page->type == SMALL));
	reset_struct();
}

/* test runner */
int main()
{
	RUN(test_init_main_struct);
	RUN(test_get_malloc_type);
	RUN(test_get_free_block_in_list);
	RUN(test_check_adress);
	RUN(test_defragment);
	RUN(test_add_before);
	RUN(test_add_after);
	RUN(test_add_free_block_to_list);
	RUN(test_free_page);
	// system("./test.py");
	return TEST_REPORT();
}
