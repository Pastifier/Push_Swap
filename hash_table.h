#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include "stack.h"

typedef struct s_hash_table_entry {
	int		value;
	bool	occupied;
	size_t	hash;
}	t_entry;
#endif // !HASH_TABLE_H
