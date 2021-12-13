#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define	SMALL 0
#define BIG 1

void split( std::string line, std::vector<char**>	*all ) {
	char**	ret1 = new char*[2];
	char**	ret2 = new char*[2];
	int		i = 0;
	int		j = 0;

	while ( line[i] && line[i] != '-' )
		i++;
	ret1[0] = new char[i];
	ret2[1] = new char[i];
	i = 0;
	while ( line[i] && line[i] != '-' ) {
		ret1[0][i] = line[i];
		ret2[1][i] = line[i];
		i++;
	}
	j = ++i;
	while ( line[i] )
		i++;
	ret1[1] = new char[i - j];
	ret2[0] = new char[i - j];
	i = 0;
	while ( line[j] ) {
		ret1[1][i] = line[j];
		ret2[0][i] = line[j];
		i++;
		j++;
	}
	all->push_back( ret1 );
	all->push_back( ret2 );
}

int		get_size( char* str ) {
	if ( str[0] >= 'a' && str[0] <= 'z' )
		return SMALL;
	return BIG;
}

int	in_list( std::vector<char*>	all, char* key ) {
	for ( std::vector<char*>::iterator it = all.begin(); it < all.end(); it++ ) {
		if ( !strcmp( key, *it ) ) {
			return 1;
		}
	}
	return 0;
}

std::vector<char**>	parse( std::vector<std::string> init_list ) {
	std::vector<char**>	all;

	for ( std::vector<std::string>::iterator it = init_list.begin(); it < init_list.end(); it++ )
		split( *it, &all );
	return all;
}

int	walk_options( std::vector<char**> all, std::vector<char*> path ) {\
	std::vector<char**>::iterator it = all.begin();
	char*		bufstr = path.back();
	int ret = 0;

	if ( !strcmp( bufstr, "end" ) ) {
		return 1;
	}
	if ( strcmp( bufstr, "start" ) )  {
		for ( std::vector<char**>::iterator it2 = all.begin(); it2 < all.end(); it2++ ) {
			if ( !strcmp( path.at( path.size() - 2 ) , (*it2)[0] ) && !strcmp( bufstr, (*it2)[1] ) ) {
				all.erase(it2);
				break ;
			}
		}
	}
	while ( it < all.end() ) {
		if ( !strcmp( bufstr, (*it)[0] ) && strcmp( (*it)[1], "start" ) && !( in_list( path, (*it)[1] ) && get_size( (*it)[1]) == SMALL ) ) {
			path.push_back( (*it)[1] );
			ret += walk_options( all, path );
			path.pop_back();
			it++;
		} else
			it++;
	}
	return ret;
}

int	main( void ) {
	std::ifstream	input;
	std::string		line;
	std::vector<char**>	all;
	std::vector<char*>	path;
	std::vector<std::string> init_list;
	
	input.open( "input.txt" );
	if ( input.is_open() ) {
		while ( getline( input, line ) )
			init_list.push_back( line );
	} else
		return (1);
	all = parse( init_list );
	path.push_back( (char*)"start" );
	std::cout << walk_options( all, path ) << std::endl;
	input.close();
	return (0);
}
