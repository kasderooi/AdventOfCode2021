#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

/* 
( ) = 3
[ ] = 57
{ } = 1197
< > = 25137
*/

int	calculate_incorrect( char* buf, char c, int points ) {
	if ( buf[0] == c )
		buf[0] = 0;
	else if ( buf[0] != 0 )
		return points;
	return 0;
}

int	check_line( std::string line ) {
	int len = line.length();
	int j = 0;
	int ret = 0;
	char* buf = new char[len];
	
	memset( buf, 0, len );
	for ( int i = 0; i < len; i++ ) {
		if ( line[i] == '(' || line[i] == '[' || line[i] == '{' || line[i] == '<' ) {
			buf[j++] = line[i];
		} else {
			switch ( line[i] ) {
				case ')' : 	ret += calculate_incorrect( &buf[--j], '(', 3 );
							break;
				case ']' :	ret += calculate_incorrect( &buf[--j], '[', 57 );
							break;
				case '}' :	ret += calculate_incorrect( &buf[--j], '{', 1197 );
							break;
				case '>' :	ret += calculate_incorrect( &buf[--j], '<', 25137 );
							break;
			}
		}
	}
	delete[] buf;
	return ret;
}

void	resolve_end( char* buf, char c ) {
	if ( buf[0] == c )
		buf[0] = 0;
}

unsigned long	complete_line( std::string line ) {
	int len = line.length();
	int j = 0;
	unsigned long ret = 0;
	char* buf = new char[len];
	
	for ( int i = 0; i < len; i++ )
		buf[i] = 0;
	for ( int i = 0; i < len; i++ ) {
		if ( line[i] == '(' || line[i] == '[' || line[i] == '{' || line[i] == '<' ) {
			buf[j] = line[i];
			j++;
		} else {
			switch ( line[i] ) {
				case ')' : 	resolve_end( &buf[--j], '(' );
							break;
				case ']' :	resolve_end( &buf[--j], '[' );
							break;
				case '}' :	resolve_end( &buf[--j], '{' );
							break;
				case '>' :	resolve_end( &buf[--j], '<' );
							break;
			}
		}
	}
	len = strlen( buf );
	for ( int i = len; i >= 0; i-- ) {
		ret *= 5;
		ret += buf[i] == '(' ? 1 : 0;
		ret += buf[i] == '[' ? 2 : 0;
		ret += buf[i] == '{' ? 3 : 0;
		ret += buf[i] == '<' ? 4 : 0;
	}
	delete[] buf;
	return ret;
}

int	main( void ) {
	std::ifstream	input;
	std::string		line;
	std::vector<std::string> init_list;
	std::vector<unsigned long> ret;
	
	input.open( "input.txt" );
	if ( input.is_open() ) {
		while ( getline( input, line ) )
			init_list.push_back(line);
	} else
		return (1);
	for ( std::vector<std::string>::iterator it = init_list.begin(); it < init_list.end(); it++ )
		if ( check_line( *it ) ) {
			init_list.erase( it );
			it--;
		}
	for ( std::vector<std::string>::iterator it = init_list.begin(); it < init_list.end(); it++ )
		ret.push_back( complete_line( *it ) );
	sort( ret.begin(), ret.end() );
	std::cout << ret.at(ret.size() / 2) << std::endl;
	input.close();
	return (0);
}
