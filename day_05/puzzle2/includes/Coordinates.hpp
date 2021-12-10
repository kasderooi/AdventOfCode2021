#ifndef COORDINATES_HPP
#define COORDINATES_HPP

#include <string>

class Coordinates {

	private:

		int		_start[2];
		int		_end[2];

	public:

		Coordinates( void );
		Coordinates( std::string line );
		~Coordinates( void );
		Coordinates( const Coordinates& original );

		Coordinates& operator=( const Coordinates& original );

		void set_start( int x, int y );
		void set_end( int x, int y );

		int *get_start( void );
		int *get_end( void );

		void set_coordinates( std::string line );
};

#endif
