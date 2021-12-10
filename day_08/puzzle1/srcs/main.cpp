#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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

int	main( void ) {
	std::ifstream	input;
	std::string		line;
	std::vector<std::string> init_list;
	std::vector<std::string> buf_list;
	std::vector<std::string> bigdata_list;
	std::vector<std::string> smalldata_list;
	int				buf, count = 0;
	
	input.open( "input.txt" );
	if ( input.is_open() ) {
		while ( getline( input, line ) )
			init_list.push_back(line);
	} else
		return (1);
	for ( unsigned long i = 0; i < init_list.size(); i++ ) {
		split( &buf_list, init_list[i], '|' );
		split( &bigdata_list, buf_list[0], ' ' );
		split( &smalldata_list, buf_list[1], ' ' );
		buf_list.erase( buf_list.begin(), buf_list.end() );
	}
	for ( unsigned long i = 0; i < smalldata_list.size(); i++ ) {
		buf = smalldata_list[i].length();
		if ( ( buf >= 2 && buf <= 4 ) || buf == 7 )
			count++;
	}
	std::cout << count << std::endl;
	input.close();
	return (0);
}
