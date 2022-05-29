#include "ConvertType.hpp"

// Default Class Constructor
ConvertType::ConvertType(void)
{
}

// Standard Class Constructor
ConvertType::ConvertType(std::string literal)
{
	_type = ConvertType::findType(literal);
	_literal = literal;
}

// Copy Class Constructor
ConvertType::ConvertType(ConvertType const &src)
{
	*this = src;
}

// Class Deconstructor
ConvertType::~ConvertType(void)
{
}

// Assign Operator Overload
ConvertType	&ConvertType::operator=(ConvertType const &rhs)
{
	// Make your Assignment here
	_type = rhs._type;
	_literal = rhs._literal;
	return (*this);
}

void	ConvertType::printAll(void) const
{
	switch (_type)
	{
		case (char_type) :
			_printCharType();
			break ;
		case (int_type) :
			_printIntType();
			break ;
		case (float_type) :
			_printFloatType();
			break ;
		case (double_type) :
			_printDoubleType();
			break ;
	}
}

int	ConvertType::findType(std::string &literal)
{
	if (literal.length() == 1)
	{
		if (literal[0] >= '0' && literal[0] <= '9')
		{
			return (int_type);
		}
		else
		{
			return (char_type);
		}
	}
	else if (literal == "-inf" || literal == "+inf" || literal == "nan")
	{
		return (double_type);
	}
	else if (literal[literal.length() - 1] == 'f')
	{
		return (float_type);
	}
	else if (literal.find('.') != std::string::npos)
	{
		return (double_type);
	}
	else
	{
		return (int_type);
	}
}

void	ConvertType::_printCharType(void) const
{
	char	c = _literal[0];

	_printChar(c);
	_printInt(static_cast<int> (c));
	_printFloat(static_cast<float> (c));
	_printDouble(static_cast<double> (c));
}

void	ConvertType::_printIntType(void) const
{
	int	i = atoi(_literal.c_str());

	if (i >= 0 && i <= 255)
	{
		_printChar(static_cast<char> (i));
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
	}
	_printInt(i);
	double check = static_cast<double> (i) - static_cast<float> (i);
	if (check >= EPSILON || check <= (EPSILON) * -1)
	{
		std::cout << "float: impossible" << std::endl;
	}
	else
	{
		_printFloat(static_cast<float> (i));
	}
	_printDouble(static_cast<double> (i));
}

void	ConvertType::_printFloatType(void) const
{
	float	f = atof(_literal.c_str());

	if (f >= 0 && f <= 255)
	{
		_printChar(static_cast<char> (f));
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
	}
	if (f >= INT_MIN && f <= INT_MAX)
	{
		_printInt(static_cast<int> (f));
	}
	else
	{
		std::cout << "int: impossible" << std::endl;
	}
	_printFloat(f);
	_printDouble(static_cast<double> (f));
}

void	ConvertType::_printDoubleType(void) const
{
	double	d = atof(_literal.c_str());

	if (d >= 0 && d <= 255)
	{
		_printChar(static_cast<char> (d));
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
	}
	if (d >= INT_MIN && d <= INT_MAX)
	{
		_printInt(static_cast<int> (d));
	}
	else
	{
		std::cout << "int: impossible" << std::endl;
	}
	double check = d - static_cast<float> (d);
	if (check >= EPSILON || check <= (EPSILON) * -1)
	{
		std::cout << "float: impossible" << std::endl;
	}
	else
	{
		_printFloat(static_cast<float> (d));
	}
	_printDouble(d);
}

void	ConvertType::_printChar(char c)
{
	if (isprint(c))
	{
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else
	{
		std::cout << "char: Non displayable" << std::endl;
	}
}

void	ConvertType::_printInt(int i)
{
	std::cout << "int: " << i << std::endl;
}

void	ConvertType::_printFloat(float f)
{
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
}

void	ConvertType::_printDouble(double d)
{
	std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}
