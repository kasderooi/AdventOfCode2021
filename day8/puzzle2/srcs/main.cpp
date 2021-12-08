#include <iostream>
#include <fstream>
#include "Sorted.hpp"

/*
8 = abcdefg	7
0 = acfgeb	6
6 = acdefg	6
9 = abcdfg	6
2 = acdeg	5
3 = acdfg	5
5 = abdfg	5
4 = bdcf	4
7 = acf		3
1 = cf		2
*/

void split( std::vector<std::string> *init_list, std::string line, char c ) {
	int start = 0;
	int i = 0;

	while ( line[start] && line[start] == c )
		start++;
	i = start;
	while ( line[i] && line[i] != c )
		i++;
	if ( i - start > 0)
		(*init_list).push_back( line.substr( start, i - start ) );
	if ( line[i] != 0 )
		split( init_list, &line[i], c );
}

int solve_one_line( std::string init ) {
	std::vector<std::string> buf_list;
	std::vector<std::string> bigdata_list;
	std::vector<std::string> smalldata_list;
	split( &buf_list, init, '|' );
	split( &bigdata_list, buf_list[0], ' ' );
	split( &smalldata_list, buf_list[1], ' ' );
	Sorted          solution( bigdata_list );
	int				ret = 0;
	
	for ( unsigned long i = 0; i < smalldata_list.size() ; i++ )
		for ( int j = 0; j < 10; j++ )
			if ( !compare_all( solution.get_number(j), smalldata_list[i] ) ) {
				ret *= 10;
				ret += j;
			}
	return ret;
}

int	main( void ) {
	std::ifstream	input;
	std::string		line;
	std::vector<std::string> init_list;
	unsigned long ret = 0;
	
	input.open( "input.txt" );
	if ( input.is_open() ) {
		while ( getline( input, line ) )
			init_list.push_back(line);
	} else
		return (1);
	for ( unsigned int i = 0; i < init_list.size(); i++ ){
		ret += solve_one_line( init_list[i] );
	}
	std::cout <<  ret << std::endl;
	input.close();
	return (0);
}
