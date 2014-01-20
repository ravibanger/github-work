//cl /EHsc /I D:\Project\boost_1_53_0\boost_1_53_0\ transform_iterator.cpp
#include <iostream>
#include <functional>
#include <boost/iterator/transform_iterator.hpp>
#include <boost/iterator/counting_iterator.hpp>
#include <boost/iterator/permutation_iterator.hpp>
#include <boost/functional.hpp>

template< typename T >
struct square
{
    T operator() (const T& x)  const { return x * x; }
    typedef T result_type;
};



int main()
{

	int x[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int y[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	const int N = sizeof(x)/sizeof(int);

	typedef square <int>  Function;

    //Example 1///////////////////////////////
	typedef boost::counting_iterator<int>                       count_iterator;
	typedef boost::transform_iterator<Function, count_iterator> square_transform_count_iterator;
	count_iterator count_i_begin(0), count_i_end(N);
	square_transform_count_iterator square_transform_begin(count_i_begin, Function());
	square_transform_count_iterator square_transform_end  (count_i_end,   Function());

	std::cout << "\n\nSquaring with counting iterator:" << std::endl;
	while (square_transform_begin != square_transform_end)
	  std::cout << *square_transform_begin++ << " ";
	std::cout << std::endl;

	//Example 2///////////////////////////////
	typedef boost::transform_iterator<Function, int *> square_transform_raw_iterator;
	{
		square_transform_raw_iterator square_raw_begin(x, Function());
		square_transform_raw_iterator square_raw_end(x+N, Function());
		std::cout << "\n\nSquaring with raw input buffer:" << std::endl;
		while (square_raw_begin != square_raw_end)
		  std::cout << *square_raw_begin++ << " " ;
		std::cout << std::endl;

		std::cout << "Checking whether input buffer is modified.\n Input Buffer x is:" << std::endl;
		for(int index=0; index<N; index++)
		  std::cout << x[index] << " " ;
		std::cout << std::endl;
	}

	//Example 3///////////////////////////////
	typedef boost::transform_iterator<Function, square_transform_raw_iterator> square_transform_transform_iterator;
	{
		square_transform_raw_iterator square_raw_begin(x, Function());
		square_transform_raw_iterator square_raw_end(x+N, Function());
		square_transform_transform_iterator square_transform_begin(square_raw_begin, Function());
		square_transform_transform_iterator square_transform_end  (square_raw_end,   Function());

		std::cout << "\nExample 3\nSquare and Square of the raw input buffer:" << std::endl;
		while (square_transform_begin != square_transform_end)
		  std::cout << *square_transform_begin++ << " " ;
		std::cout << std::endl;

		std::cout << "Checking whether input buffer is modified.\n Input Buffer x is:" << std::endl;
		for(int index=0; index<N; index++)
		  std::cout << x[index] << " " ;
		std::cout << std::endl;
	}

	typedef boost::permutation_iterator<square_transform_raw_iterator, count_iterator> permutation_iterator;
	//Example 4///////////////////////////////
    {
		square_transform_raw_iterator square_raw_begin(x, Function());
		square_transform_raw_iterator square_raw_end(x+N, Function());

		permutation_iterator perm_begin(square_raw_begin, count_i_begin);
		permutation_iterator perm_end  (square_raw_end, count_i_end);

		std::cout << "\nUsing Permutation Iterator with transform and counting Iterator:" << std::endl;
		while (perm_begin != perm_end)
		  std::cout << *perm_begin++ << " ";
		std::cout << std::endl;
	}

    //Example 5///////////////////////////////
    {
		typedef boost::permutation_iterator<int *, count_iterator> permute_iterator;
		permute_iterator perm_begin(x, count_i_begin);
		permute_iterator perm_end  (x+N, count_i_end);
        //First modify
		*perm_begin = 10;

		std::cout << "\nUsing Permutation Iterator with Simple buffer:" << std::endl;
		while (perm_begin != perm_end)
		  std::cout << *perm_begin++ << " ";
		std::cout << std::endl;
	}

    //Example 5///////////////////////////////
    {
		typedef boost::permutation_iterator<int *, count_iterator> permute_iterator;
		typedef boost::transform_iterator<Function, permute_iterator> permute_transform_iterator;
		permute_iterator perm_begin(x, count_i_begin);
		permute_iterator perm_end  (x+N, count_i_end);

		permute_transform_iterator perm_transform_begin(perm_begin, Function());
		permute_transform_iterator perm_transform_end  (perm_end, Function());
		//First modify
	}

	return 0;
}
