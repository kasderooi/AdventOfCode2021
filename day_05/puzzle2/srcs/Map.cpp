#include "Map.hpp"

Map::Map( void ) : _x( 0 ), _y( 0 ), _map( NULL ) {
	return ;
}

Map::~Map( void ) {
	if ( _map != NULL ) {
		for ( int i = 0; i <= _x; i++ )
			delete _map[i];
		delete _map;
	}
	return ;
}

Map::Map( const Map& original ) {
	*this = original;
	return ;
}

Map& Map::operator=( const Map& original ) {
	if ( _map != NULL ) {
		for ( int i = 0; i <= _x; i++ )
			delete _map[i];
		delete _map;
	}
	if (this != &original){
		_x = original._x;
		_y = original._y;
		if ( original._map != NULL )
			generate_map();
		for ( int i = 0; i <= _x; i++ )
			for ( int j = 0; j <= _y; j++ )
				_map[i][j] = original._map[i][j];
	}
	return *this;
}

int	Map::get_x( void ) {
	return this->_x;
}

int	Map::get_y( void ) {
	return this->_y;
}

void Map::set_max( Coordinates *coordinate ) {
	if ( coordinate->get_start()[0] > this->_x )
		this->_x = coordinate->get_start()[0];
	if ( coordinate->get_end()[0] > this->_x )
		this->_x = coordinate->get_end()[0];
	if ( coordinate->get_start()[1] > this->_y )
		this->_y = coordinate->get_start()[1];
	if ( coordinate->get_end()[1] > this->_y )
		this->_y = coordinate->get_end()[1];
}

void Map::generate_map( void ) {
	_map = new int*[_x];
	for ( int i = 0; i <= _x; i++ )
		_map[i] = new int[_y];
	for ( int i = 0; i <= _x; i++ )
		for ( int j = 0; j <= _y; j++ )
			_map[i][j] = 0;
}

int Map::get_point( int x, int y ) {
	return _map[x][y];
}

void Map::set_point( int x, int y ) {
	_map[x][y]++;
}
