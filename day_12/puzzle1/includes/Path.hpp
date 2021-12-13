#ifndef PATH_HPP
#define PATH_HPP

#include <vector>
#include <string>

#define	ENDCAP -1
#define	SMALL 0
#define BIG 1

class Path {

	private:

	int					_size;
	char*				_key;
	std::vector<char*>	_path;

	public:

	Path( int size, char* key ) : _size(size), _key(key), _path() {};
	~Path( void ) {};

	char* get_key( void ) { return _key; };

	int	search_for_path( const char* path ) {
		for ( std::vector<char*>::iterator it = _path.begin(); it < _path.end(); it++ )
			if ( !strcmp( path, *it ) )
				return 1;
		return 0;
	}

	void add_path( char* path ) { _path.push_back( path ); };

};

#endif
