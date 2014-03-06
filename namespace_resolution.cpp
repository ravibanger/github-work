#include <iostream>


namespace bolt { namespace cl {
	template <typename DerivedPath>
	struct execution_path {	};
} }



namespace bolt { namespace cl { namespace gpu {
	struct path_t : bolt::cl::execution_path<path_t>{};
    static const path_t path;

    template <typename TakenPath>
	int function ( bolt::cl::execution_path<TakenPath> &exec_path)
	{
		std::cout << "Execution Path OpenCL GPU\n" ;
		return 0;
	}

    template <typename TakenPath1, typename TakenPath2>
	int function ( bolt::cl::execution_path<TakenPath1> &exec_path1, bolt::cl::execution_path<TakenPath2> &exec_path2)
	{
		std::cout << "Execution Path OpenCL GPU\n" ;
		return 0;
	}
}}}



namespace bolt { namespace cl { namespace cpu {
	struct path_t : bolt::cl::execution_path<path_t>{};
	static const path_t path;

    template <typename TakenPath>
	int function ( bolt::cl::execution_path<TakenPath> &exec_path)
	{
		std::cout << "Execution Path OpenCL CPU\n" ;
		return 0;
	}

    template <typename TakenPath1, typename TakenPath2>
	int function ( bolt::cl::execution_path<TakenPath1> &exec_path1, bolt::cl::execution_path<TakenPath2> &exec_path2)
	{
		std::cout << "Execution Path OpenCL CPU\n" ;
		return 0;
	}
}}}


namespace bolt { namespace cl { namespace hlm {
	struct path_t : bolt::cl::execution_path<path_t>{};
	static const path_t path;

    template <typename TakenPath>
	int function ( bolt::cl::execution_path<TakenPath> &exec_path)
	{
		std::cout << "Execution Path OpenCL HLM\n" ;
		return 0;
	}

    template <typename TakenPath1, typename TakenPath2>
	int function ( bolt::cl::execution_path<TakenPath1> &exec_path1, bolt::cl::execution_path<TakenPath2> &exec_path2)
	{
		std::cout << "Execution Path OpenCL HLM\n" ;
		return 0;
	}
}}}


namespace bolt { namespace cl {namespace serial {
	struct path_t: bolt::cl::execution_path<path_t>{};
	static const path_t path;

    template <typename TakenPath>
	int function ( bolt::cl::execution_path<TakenPath> &exec_path)
	{
		std::cout << "Execution Path Serial CPU\n";
		return 0;
	}

    template <typename TakenPath1, typename TakenPath2>
	int function ( bolt::cl::execution_path<TakenPath1> &exec_path1, bolt::cl::execution_path<TakenPath2> &exec_path2)
	{
		std::cout << "Execution Path Serial CPU\n" ;
		return 0;
	}
}}}


namespace bolt { namespace cl { namespace btbb {
struct path_t: bolt::cl::execution_path<path_t>{};
	static const path_t path;

    template <typename TakenPath>
	int function ( bolt::cl::execution_path<TakenPath> &exec_path)
	{
		std::cout << "Execution Path TBB CPU\n" ;
		return 0;
	}

    template <typename TakenPath1, typename TakenPath2>
	int function ( bolt::cl::execution_path<TakenPath1> &exec_path1, bolt::cl::execution_path<TakenPath2> &exec_path2)
	{
		std::cout << "Execution Path TBB\n" ;
		return 0;
	}
}}}

namespace bolt { namespace cl {

    template <typename TakenPath>
	int function ( bolt::cl::execution_path<TakenPath> &exec_path)
	{
		function(exec_path);
		std::cout << "Execution Path Unknown\n" ;
		return 0;
	}
}}


int main()
{

	{
		bolt::cl::execution_path<bolt::cl::cpu::path_t> exec_path1;
    	bolt::cl::execution_path<bolt::cl::gpu::path_t> exec_path;
    	function(exec_path);
    	function(exec_path, exec_path1);
    }
    {
		bolt::cl::execution_path<bolt::cl::cpu::path_t> exec_path;
    	function(exec_path);
   	}
    {
		bolt::cl::execution_path<bolt::cl::serial::path_t> exec_path;
    	function(exec_path);
    }

	return 0;
}



