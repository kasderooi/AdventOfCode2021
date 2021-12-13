#include <iostream>
#include <fstream>
#include <string>
#include "Path.hpp"

char** split( std::string line ) {
	char**	ret = new char*[2];
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
	ret[1] = new char[i - j];
	i = 0;
	while ( line[j] ) {
		ret[1][i] = line[j];
		i++;
		j++;
	}
	return ret;
}

int	in_list( std::vector<char*>	all, char* key ) {
	for ( std::vector<char*>::iterator it = all.begin(); it < all.end(); it++ ) {
		if ( !strcmp( key, *it ) ) {
			return 1;
		}
	}
	return 0;
}

std::vector<char*>	parse( std::vector<std::string> init_list ) {
	std::vector<char*>	all;
	char	**buf;

	for ( std::vector<std::string>::iterator it = init_list.begin(); it < init_list.end(); it++ ) {
		buf = split( *it );
		if ( !in_list( all, buf[0] ) )
			all.push_back(buf[0]);
		if ( !in_list( all, buf[1] ) )
			all.push_back(buf[1]);
	}
	return all;
}

void	init_du_jour( std::vector<std::string> init_list, Path* start ) {
	std::vector<char*> all = parse ( init_list );
	char	**buf;

	for ( std::vector<char*>::iterator it = all.begin(); it < all.end(); it++ ) {
		if ( strcmp( "start", *it ) )
			start->add_history( new Path( *it ) );
	}
	start->copy_history();
	for ( std::vector<std::string>::iterator it = init_list.begin(); it < init_list.end(); it++ ) {
		buf = split( *it );
		start->add_path( buf[0], buf[1] );
	}

}

int	main( void ) {
	std::ifstream	input;
	std::string		line;
	std::vector<char*>	all;
	std::vector<std::string> init_list;
	Path			start( (char*)"start" );
	
	input.open( "input.txt" );
	if ( input.is_open() ) {
		while ( getline( input, line ) )
			init_list.push_back( line );
	} else
		return (1);
	init_du_jour( init_list, &start );
	std::cout << start.find_path( &start ) << std::endl;
	input.close();
	return (0);
}
