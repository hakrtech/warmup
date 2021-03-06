/* chapter 10 exercise 09 program to use replace strings function continuously
 * vasanth 28 february 2018
 */

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int string_length(char s[])
{
	int i = 0;

	while (s[i] != '\0') {
		++i;
	}
	assert(s[i] == '\0');

	return i;
}

int string_find(char s[], char f[])
{
	char c;
	int i, j, pos = -1;

	// loop s[ 0 .. !'\0' ] to find f[ 0 .. !'\0' ]
	i = 0;
	j = 0;
	c = f[j];
	while (s[i] != '\0') {
		if (s[i] == c) {
			int k;
			k = i;
			j = 0;
			while ((s[k] == f[j]) && (f[j] != '\0')) {
				++k;
				++j;
			}
			if (f[j] == '\0') {
				pos = i;
				break;
			}
		}
		++i;
	}

	return pos;
}

bool string_remove(char s[], int pos, int len)
{
	int i, j, s_len;
	bool is_removed = false;

	s_len = string_length(s);
	assert(s_len > 0);
	assert((0 <= pos) && (pos < s_len));
	assert((0 < len) && (len <= s_len));

	// loop s[ 0 .. s_len-1 ] removed s [ pos .. pos+len-1 ] 
	for (i = pos, j = pos+len; j <= s_len-1; ++i, ++j) {
		assert((0 <= i) && (i < s_len));
		s[i] = s[j];
	}
	if (j > s_len) {
		return is_removed;
	}
	assert(j == s_len);
	s[i] = '\0';
	is_removed = true;

	return is_removed;
}

bool string_insert(char s[], int pos, char ins[])
{
	int i, j, s_len, ins_len;
	bool is_inserted = false;

	s_len = string_length(s);
	ins_len = string_length(ins);
	assert((0 <= pos) && (pos < s_len));

	// string shift
	i = s_len - 1;
	j = (s_len+ins_len) - 1;
	s[s_len+ins_len] = '\0';

	while (i >= pos) {
		s[j] = s[i];
		--i;
		--j;
	}
	assert(i < pos);

	// string insert
	i = 0;
	j = pos;
	while ( i <= ins_len-1) {
		s[j] = ins[i];
		++i;
		++j;
	}
	if (i == ins_len) {
		is_inserted = true;
	}

	return is_inserted;
}

bool string_replace(char s[], char rmv[], char ins[])
{
	int pos, rmv_len;
	bool is_removed = false, is_inserted = false, is_replaced = false;

	pos = string_find(s, rmv);
	if (pos == -1) {
		return is_replaced;
	}

	rmv_len = string_length(rmv);
	is_removed = string_remove(s, pos, rmv_len);
	if (is_removed) {
		is_inserted = string_insert(s, pos, ins);
		if (is_inserted) {
			is_replaced = true;
		} else {
			printf("check string insert\n");
		}
	} else {
		printf("check string remove\n");
	}

	return is_replaced;
}

int main(void)
{
	char a[] = "The nature is beautiful god. Don't pollute and destroy. Nature will angry, destroy everything.";
	char b[] = " ";
	char c[] = "_";
	bool is_replaced = false;

	printf("continuous string replace>\n");
	printf("strings>\nsource a [ %s ]\nremove b [ %s ]\ninsert c [ %s ]\n", a, b, c);

	do {
		is_replaced = string_replace(a, b, c);
	} while (is_replaced == true);

	printf("replaced source strings a [ %s ]\n", a);

	return 0;
}

