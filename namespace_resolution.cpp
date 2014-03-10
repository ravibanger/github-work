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


}}}

namespace bolt { namespace cl {

    enum code_path_enums{
		SERIAL = 0,
		CL_GPU,
		CL_CPU,
		CL_HLM,
		TBB
	};
	struct control {
		code_path_enums code_path;
		bolt::cl::execution_path<> exec_path;
	};

	template<typename DerivedPolicy>
	const DerivedPolicy &derived_cast(const execution_path<DerivedPolicy> &x)
	{
	  return static_cast<const DerivedPolicy&>(x);
	}

	template <typename DerivedPolicy>
	const DerivedPolicy & take_path(bolt::cl::control &exec_path)
	{

		if(exec_path.code_path == bolt::cl::SERIAL)
			return bolt::cl::serial::path;
		if(exec_path.code_path == bolt::cl::CL_GPU)
			return bolt::cl::cpu::path;
		if(exec_path.code_path == bolt::cl::CL_CPU)
			return bolt::cl::gpu::path;
		if(exec_path.code_path == bolt::cl::CL_HLM)
			return bolt::cl::hsa::path;
	}

	int function ( bolt::cl::control &exec_path)
	{

		//bolt::cl::execution_path<bolt::cl::cpu::path_t> dummy;
		//selected_path(exec_path);
		if(exec_path.code_path == bolt::cl::SERIAL)
		{
			bolt::cl::serial::path_t path;
			function(path);
		}
		std::cout << "Execution Path Unknown\n" ;
		return 0;
	}
}}


int main()
{

	{
		bolt::cl::control path;
		path.code_path = bolt::cl::SERIAL;

    	bolt::cl::function(path);

    }
    {
		//bolt::cl::execution_path<bolt::cl::cpu::path_t> exec_path;
    	//function(exec_path);
   	}
    {
		//bolt::cl::execution_path<bolt::cl::serial::path_t> exec_path;
    	//function(exec_path);
    }

	return 0;
}
