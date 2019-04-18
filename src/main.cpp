#include <libff/common/default_types/ec_pp.hpp>
#include <libsnark/common/default_types/r1cs_gg_ppzksnark_pp.hpp>
#include <libsnark/zk_proof_systems/ppzksnark/r1cs_gg_ppzksnark/r1cs_gg_ppzksnark.hpp>
#include "r1cs_system.hpp"
#include "Prover.cpp"
#include "Verifier.cpp"
using namespace libsnark;
using namespace std;

int main()
{
    printf("This is a zksnark test\n");
	default_r1cs_gg_ppzksnark_pp::init_public_params();
	Prover<default_r1cs_gg_ppzksnark_pp> prover(1000,100);
    cout << "Verify" << endl;
//    r1cs_gg_ppzksnark_verification_key<default_r1cs_gg_ppzksnark_pp> vk = prover.get_vk();
    cout << "Verify" << endl;
    Verifier<default_r1cs_gg_ppzksnark_pp> verifier(prover.get_vk(),prover.get_primary_input(),prover.get_proof());
    //verifier.set_vk((prover.get_vk());
    //verifier.set_primary_input(prover.get_primary_input());
    //verifier.set_proof(prover.get_proof());
    bool ret = verifier.verify();
    if( ret == true)
    {
        cout << "Verify Success" << endl;
    }
    else
    {
        cout << "Verify Fail" << endl;
    }

    return 0;
}
