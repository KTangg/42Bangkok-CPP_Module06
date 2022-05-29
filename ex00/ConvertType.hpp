#ifndef __CONVERTTYPE_HPP__
# define __CONVERTTYPE_HPP__

# include <iostream>
# include <climits>
# include <string>
# include <cstdlib>
# include <iomanip>

# define EPSILON 1

enum type_enum
{
	char_type,
	int_type,
	float_type,
	double_type
};

class ConvertType
{
	public:
		// Standard Constructor
		ConvertType(std::string literal);
		// Copy Class Constructor
		ConvertType(ConvertType const &src);
		// Class Deconstructor
		virtual	~ConvertType(void);

		// Assign operator overload
		ConvertType	&operator=(ConvertType const &rhs);

		// Function member part
		void	printAll(void) const;
		static int	findType(std::string &literal);

	private:
		// Default Class Constructor
		ConvertType(void);
		// Attributes
		int			_type;
		std::string	_literal;

		void	_printCharType(void) const;
		void	_printIntType(void) const;
		void	_printFloatType(void) const;
		void	_printDoubleType(void) const;
		static void	_printChar(char c);
		static void	_printInt(int i);
		static void	_printFloat(float f);
		static void	_printDouble(double d);
};

#endif // **************************************************** __CONVERTTYPE_HPP__ //
