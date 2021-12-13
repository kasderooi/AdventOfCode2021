#include <iostream>
#include <fstream>
#include <string>
#include "Path.hpp"

char** split( std::string line ) {
	char*	ret[2];
	int		i = 0;
	int		j = 0;

	while ( line[i] && line[i] != '-' )
		i++;
	ret[0] = new char[i];
	i = 0;
	while ( line[i] && line[i] != '-' ) {
		ret[0][i] = line[i];
		i++;
	}
	j = ++i;
	while ( line[i] )
		i++;
	ret[0] = new char[i - j];
	i = 0;
	while ( line[j] ) {
		ret[1][i] = line[j];
		i++;
		j++;
	}
}

void	parse( std::vector<std::string> init_list, std::vector<Path> buf_list ) {
	char	**buf;

	for ( std::vector<std::string>::iterator it = init_list.begin(); init_list.end(); it++ ) {
		buf = split( *it );
		
	}
}

void	init_list( std::vector<Path> *buf_list ) {
	char* start = new char[6]();
	start[0] = 's';
	start[1] = 't';
	start[2] = 'a';
	start[3] = 'r';
	start[4] = 't';
	Path	start_elem( ENDCAP, start );
	(*buf_list).push_back( start_elem );
}

int	main( void ) {
	std::ifstream	input;
	std::string		line;
	std::vector<std::string> init_list;
	std::vector<Path> buf_list;
	int				buf, count = 0;
	
	input.open( "input.txt" );
	if ( input.is_open() ) {
		while ( getline( input, line ) )
			init_list.push_back( line );
	} else
		return (1);
	init_list( &buf_list );

	std::cout << count << std::endl;
	input.close();
	return (0);
}
