#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define len 12

void most_common_bits( std::vector<std::string> data, int *mc_bits, int line_count ) {
	for ( int i = 0; i < len; i++ )
		mc_bits[i] = 0;
	for ( std::vector<std::string>::iterator it = data.begin(); it < data.end(); it++ )
		for ( int i = 0; i < len; i++ )
			mc_bits[i] = mc_bits[i] + (*it)[i] - 48;
	for ( int i = 0; i < len; i++ ) 
		mc_bits[i] = round( (double)mc_bits[i] / (double)line_count );
}

int	str_to_binary( std::string str ) {
	int ret = 0;

	for ( int i = 0; i < len; i++ ) {
		ret = ret << 1;
		if (str[i] - 48 == 1)
			ret++;
	}
	return ret;
}

int rating( std::vector<std::string> data_in, int flip ) {
	std::vector<std::string> data_buf;
	int mc_bits[len];
	int	line_count;

	for ( int i = 0; i < len; i++ ){
		line_count = data_in.size();
		most_common_bits( data_in, mc_bits, line_count );
		for ( std::vector<std::string>::iterator it = data_in.begin(); it < data_in.end(); it++ )
			if ( mc_bits[i] && (*it)[i] - 48 == flip )
				data_buf.push_back( *it );
			else if ( mc_bits[i] && (*it)[i] - 48 == flip )
				data_buf.push_back( *it );
			else if ( !mc_bits[i] && (*it)[i] - 48 == -flip + 1 )
				data_buf.push_back( *it );
		if (!data_buf.size())
			break ;
		data_in = data_buf;
		data_buf.clear();
	}
	return str_to_binary( data_in[0] );
}

int	main( void ) {
	std::ifstream	input;
	std::string		line;
	std::vector<std::string> data;

	input.open( "input.txt" );
	if ( input.is_open() )
		while ( getline( input, line ) )
			data.push_back( line );
	else
		return (1);
	input.close();
	std::cout << rating( data, 0 ) * rating( data, 1 ) << std::endl;
	return (0);
}
