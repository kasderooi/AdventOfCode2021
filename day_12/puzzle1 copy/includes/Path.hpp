#ifndef PATH_HPP
#define PATH_HPP

#include <iostream>
#include <vector>
#include <string>

#define	START -2
#define	ENDCAP -1
#define	SMALL 0
#define BIG 1

struct Id {
	int					pathId;
	// std::vector<int>	history;
};

int		get_size( char* str );

class Path {

	private:

	int					_size;
	char*				_key;
	std::vector<Path*>	_path;
	std::vector<Path*>	_history;

	public:

	Path( char* key ) : _key( key ) {
		_size = ::get_size( key );
	};
	~Path( void ) {};
	
	char* get_key( void ) { return _key; };
	int get_size( void ) { return _size; };

	int	in_list( char* key ) {
		for ( std::vector<Path*>::iterator it = _path.begin(); it < _path.end(); it++ ) {
			if ( !strcmp( key, (*it)->get_key() ) ) {
				return 1;
			}
		}
		return 0;
	}

	std::vector<Path*>	get_history( void ) {
		return _history;
	}
	void	add_history( Path* element ) {
		_history.push_back( element );
	}
	void	copy_history( void ) {
		for ( std::vector<Path*>::iterator it = _history.begin(); it < _history.end(); it++ ) {
			(*it)->_history = this->_history;
		}
	}

	Path*	get_path( char* key ) {
		for ( std::vector<Path*>::iterator it = _history.begin(); it < _history.end(); it++ ) {
			if ( !strcmp( key, (*it)->get_key() ) ) {
				return *it;
			}
		}
		return NULL;
	}

	void	add_path( char* key1, char* key2 ) {
		Path* buf;
		if ( !strcmp( key1, _key ) ) {
			buf = get_path( key2 );
			if ( !strcmp( buf ) )
				buf->_path.push_back( this );
			if ( !buf )
				return;
			this->_path.push_back( buf );
			return;
		}
		if ( !strcmp( key2, _key ) ) {
			buf = get_path( key1 );
			buf->_path.push_back( this );
			if ( !buf )
				return;
			this->_path.push_back( buf );
			return;
		}
		for ( std::vector<Path*>::iterator it = _path.begin(); it < _path.end(); it++ ) {
			if ( !strcmp( key1, (*it)->get_key() ) || !strcmp( key2, (*it)->get_key() ) ) {
				(*it)->add_path( key1, key2 );
				return ;
			}
		}
	}

	int	find_path( Path* prev ) {
		int ret = 0;
	
		if ( !strcmp( _key, "end" ) ) {
			// std::cout << _key << "--------------end" << std::endl;
			return 1;
		}
		for ( std::vector<Path*>::iterator it = _path.begin(); it < _path.end(); it++ ) {
			std::cout << _key << "\t" << _path.size() << "\t" << (*it)->get_key() << std::endl;
			if ( (*it)->get_size() != START )
				ret += (*it)->find_path( this );
		}
		if ( _path.size() == 0 ) {
			if ( prev->get_size() == SMALL ) {
				// std::cout << _key << "--------------small" << std::endl;
				return -1;
			}
			if ( prev->get_size() == BIG ) {
				// std::cout << _key << "--------------big" << std::endl;
				return 0;
			}
		}
		// std::cout << _key << "\t" << ret << std::endl;
		return ret;
	}

	// int	find_path( Path* prev, Path* side_path ) {
	// 	static int i = 0;
	// 	int ret = 0;

	// 	i++;
	// 	if ( !strcmp( _key, "end" ) )
	// 		return 1;
	// 	if ( _path.size() == 0 ) {
	// 		if ( prev->get_size() == SMALL )
	// 			return 0;
	// 	} else {
	// 		for ( std::vector<Path*>::iterator it = _path.begin(); it < _path.end(); it++ ) {
	// 			if ( (*it) != side_path )	
	// 				ret += (*it)->find_path( this, side_path );
	// 		}
	// 	}
	// 	if ( prev->get_size() == BIG && prev != side_path ) {
	// 		ret += prev->find_path( this, this );
	// 	}
	// 	std::cout << prev->get_key() << "\t" << _key << "\t" << ret << std::endl;
	// 	return ret;
	// }
};

int		get_size( char* str ) {
	if ( !strcmp( str, "end" ) )
		return ENDCAP;
	if ( str[0] >= 'a' && str[0] <= 'z' )
		return SMALL;
	return BIG;
}

#endif
