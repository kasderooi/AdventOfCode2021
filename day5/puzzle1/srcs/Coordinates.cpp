#include "Coordinates.hpp"
#include <iostream> 

Coordinates::Coordinates( void ) {
	this->set_start( 0, 0 );
	this->set_end( 0, 0 );
	return ;
}

Coordinates::Coordinates( std::string line ) {
	this->set_start( 0, 0 );
	this->set_end( 0, 0 );
	set_coordinates( line );
	return ;
}

Coordinates::~Coordinates( void ) {
	return ;
}

Coordinates::Coordinates( const Coordinates& original ) {
	*this = original;
	return ;
}

Coordinates& Coordinates::operator=( const Coordinates& original ) {
	if (this != &original){
		_start[0] = original._start[0];
		_start[1] = original._start[1];
		_end[0] = original._end[0];
		_end[1] = original._end[1];
	}
	return *this;
}

void Coordinates::set_start( int x, int y ) {
	_start[0] = x;
	_start[1] = y;
}

void Coordinates::set_end( int x, int y ) {
	_end[0] = x;
	_end[1] = y;
}

int* Coordinates::get_start( void ) {
	return this->_start;
}

int* Coordinates::get_end( void ) {
	return this->_end;
}

void Coordinates::set_coordinates( std::string line ) {
	int i = 0;
	int c = 0;

	while ( c < 2 ) {
		while ( line[i] >= '0' && line[i] <= '9') {
			_start[c] *= 10;
			_start[c] += line[i] - 48;
			i++;
		}
		while ( line[i] < '0' || line[i] > '9' )
			i++;
		c++;
	}
	c = 0;
	while ( c < 2 ) {
		while ( line[i] >= '0' && line[i] <= '9') {
			_end[c] *= 10;
			_end[c] += line[i] - 48;
			i++;
		}
		while ( line[i] < '0' || line[i] > '9' )
			i++;
		c++;
	}
}
