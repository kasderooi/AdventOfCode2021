#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int		array[10][10];
int		width = 10;
int		height = 10;
char	esc = 27;
int		flashes;

void	add( int y, int x);

void	line_to_array( std::string line, int y ) {
	for ( int x = 0; x < width; x++ ) {
		array[y][x] = line[x] - '0';
	}
}

void	do_neighbours( int y, int x ) {
	if ( y - 1 >= 0 && x - 1 >= 0 )
		add( y - 1, x - 1 );
	if ( y - 1 >= 0 )
		add( y - 1, x );
	if ( y - 1 >= 0 && x + 1 < width )
		add( y - 1, x + 1 );
	if ( x - 1 >= 0 )
		add( y, x - 1 );
	if ( x + 1 < width )
		add( y, x + 1 );
	if ( y + 1 < height && x - 1 >= 0 )
		add( y + 1, x - 1 );
	if ( y + 1 < height )
		add( y + 1, x );
	if ( y + 1 < height && x + 1 < width )
		add( y + 1, x + 1 );
}

void	flash( int y, int x ) {
	array[y][x] = -1;
	do_neighbours( y, x );
}

void	add( int y, int x ) {
	if ( array[y][x] == 9 )
		flash( y, x );
	else if ( array[y][x] != -1 )
		array[y][x]++;
}

void	do_step( void ) {
	flashes = 0;
	for ( int y = 0; y < height; y++ ) {
		for ( int x = 0; x < width; x++ ) {
			add( y, x );
		}
	}
	for ( int y = 0; y < height; y++ ) {
		for ( int x = 0; x < width; x++ ) {
			if ( array[y][x] == -1 ) {
				array[y][x] = 0;
				flashes++;
			}
		}
	}
}

void	print_array( void ) {
	for ( int y = 0; y < height; y++ ) {
		for ( int x = 0; x < width; x++ ) {
			if ( array[y][x] == 0 )
				std::cout << esc << "[1m" << array[y][x] << esc << "[0m";
			else
				std::cout << array[y][x];
		}
		std::cout << std::endl;
	}
}

void	repeat_steps_to_end( void ) {
	int i = 0;
	print_array();
	while ( flashes < 100 ) {
		do_step();
		std::cout << "\nAfter step " << ++i << " and " << flashes << " flashes:" << std::endl;
		print_array();
	}
}

int	main( void ) {
	std::ifstream	input;
	std::string		line;
	int line_count = 0;
	
	input.open( "input.txt" );
	if ( input.is_open() ) {
		while ( getline( input, line ) )
			line_to_array( line, line_count++ );
	} else
		return 1;
	repeat_steps_to_end();
	input.close();
	return 0;
}
