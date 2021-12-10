#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>

void split_to_int( std::vector<int> *init_list, std::string line, char c ) {
	int buf = 0;

	for ( int i = 0; line[i]; i++ ) {
		if ( line[i] != c ) {
			buf *= 10;
			buf += line[i] - 48;
		} else if ( i != 0 && line[i + 1] != c ) {
			(*init_list).push_back( buf );
			buf = 0;
		}
	}
	(*init_list).push_back( buf );
}

int	main( void ) {
	std::ifstream	input;
	std::string		line;
	std::vector<int> init_list;
	std::vector<int>::iterator ret;
	int		buf1,buf2;
	
	input.open( "input.txt" );
	if ( input.is_open() ) {
		getline( input, line );
		split_to_int( &init_list, line, ',' );
	} else
		return (1);
	sort( init_list.begin(), init_list.end() );
	buf2 = INT_MAX;
	for ( std::vector<int>::iterator itt = init_list.begin(); itt < init_list.end(); ++itt ) {
		buf1 = 0;
		for ( std::vector<int>::iterator it = init_list.begin(); it < init_list.end(); ++it ) 
			buf1 += abs((*itt) - (*it));
		if (buf1 <= buf2){
			buf2 = buf1;
			ret = itt;
		} else
			break ;
	}
	std::cout << buf2 << std::endl;
	std::cout << (*ret) << std::endl;
	input.close();
	return (0);
}
