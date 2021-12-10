#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void split_to_int( std::vector<int> *draw, std::string line, char c ) {
	int buf = 0;

	for ( int i = 0; line[i]; i++ ) {
		if ( line[i] != c ) {
			buf *= 10;
			buf += line[i] - 48;
		} else if ( i != 0 && line[i + 1] != c ) {
			(*draw).push_back( buf );
			buf = 0;
		}
	}
	(*draw).push_back( buf );
}

int check_rows( std::vector<int> shadow, int board_index ) {
	int	check;
	int pos;

	for ( int row_index = 0; row_index < 5; row_index++ ) {
		check = 0;
		pos = ( board_index * 25 ) + ( row_index * 5 );
		for ( int column_index = 0; column_index < 5 ; column_index++ )
			if ( shadow[pos + column_index] )
				check++;
		if ( check == 5 )
			return 1;	
	}
	return 0;
}

int check_columns( std::vector<int> shadow, int board_index ) {
	int	check;
	int pos;

	for ( int column_index = 0; column_index < 5; column_index++ ) {
		check = 0;
		pos = ( board_index * 25 ) + column_index;
		for ( int row_index = 0; row_index < 5 ; row_index++ ) {
			if ( shadow[pos + (row_index * 5)] )
				check++;
			if ( check == 5 )
				return 1;	
		}
	}
	return 0;
}

int do_result( std::vector<int> board, std::vector<int> shadow, int nbr ) {
	int	ret = 0;

	for ( int i = 0; i < 25; i++ ) {
		if ( !shadow[ i + (nbr * 25) ] )
			ret += board[ i + (nbr * 25) ];
	}
	return ret;
}

void check_nbr( std::vector<int> draw, std::vector<int> boards, int line_count ) {
	std::vector<int> shadow( boards.size(), 0 );
	int				board_count = line_count / 5;

	for ( std::vector<int>::iterator it = draw.begin(); it < draw.end(); it++ ){
		for ( int board_index = 0; board_index < board_count; board_index++ )
			for ( int place_index = 0; place_index < 25; place_index++ )
				if ( *it == boards[(25 * board_index) + place_index])
					shadow[(25 * board_index) + place_index] = 1;
		for ( int i = 0; i < board_count; i++ ) {
			if ( check_rows( shadow, i ) || check_columns( shadow, i ) ) {
				std::cout << do_result( boards, shadow, i ) * (*it) << std::endl;
				return ;
			}
		}
	}
}

int	main( void ) {
	std::ifstream	input;
	std::string		line;
	std::vector<int> draw;
	std::vector<int> boards;
	int		line_count = 0;
	
	input.open( "input.txt" );
	if ( input.is_open() ) {
		getline( input, line );
		split_to_int( &draw, line, ',' );
		while ( getline( input, line ) )
			if ( line.length() ) {
				line_count++;
				split_to_int( &boards, line, ' ' );
			}
	} else
		return (1);
	check_nbr( draw, boards, line_count );
	input.close();
	return (0);
}
