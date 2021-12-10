#ifndef MAP_HPP
#define MAP_HPP

#include "Coordinates.hpp"

class Map {

	private:

		int 	_x;
		int 	_y;
		int**	_map;

	public:

	Map( void );
	~Map( void );
	Map( const Map& original );

	Map& operator=( const Map& original );

	int get_x( void );
	int get_y( void );
	void set_max( Coordinates *coordinate );
	void generate_map ( void );
	void set_point( int x, int y );
	int get_point( int x, int y );

};

#endif
