#include <libff/common/default_types/ec_pp.hpp>
#include <libsnark/common/default_types/r1cs_gg_ppzksnark_pp.hpp>
#include <libsnark/zk_proof_systems/ppzksnark/r1cs_gg_ppzksnark/r1cs_gg_ppzksnark.hpp>
#include "r1cs_system.hpp"
#include "Prover.cpp"
using namespace libsnark;
using namespace std;

int main()
{
    printf("This is a zksnark test\n");
	default_r1cs_gg_ppzksnark_pp::init_public_params();
	Prover<default_r1cs_gg_ppzksnark_pp> prover(500,100);
	

    return 0;
}
