#include "testlib.h"

int main()
{
	char matrix[5][10] = {\
		"1211111111",\
		"3000000001",\
		"1000000001",\
		"1000000001",\
		"1111111111"\
		};
	
	char **g_maps = get_map(open("map.ber", O_RDONLY));
	printf("%s", g_maps);

	// int rows_count = sizeof(matrix) / sizeof(*matrix);
	// int colum_count = sizeof(*matrix);

	// for(int x = 0; x < rows_count; x++){
	// 	for(int y = 0; y < colum_count; y++){
	// 		write(1, &matrix[x][y], 1);
	// 	}
	// 	write(1, "\n", 1);
	// }

	// ft_print_matrix((char **)(matrix));


	return 0;
}