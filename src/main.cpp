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
	Prover<default_r1cs_gg_ppzksnark_pp> *prover = new Prover<default_r1cs_gg_ppzksnark_pp>(1000,100);
    r1cs_gg_ppzksnark_verification_key<default_r1cs_gg_ppzksnark_pp> vk = prover->get_vk();
    r1cs_gg_ppzksnark_primary_input<default_r1cs_gg_ppzksnark_pp> primary_input = prover->get_primary_input();
    r1cs_gg_ppzksnark_proof<default_r1cs_gg_ppzksnark_pp>proof = prover->get_proof();
    Verifier<default_r1cs_gg_ppzksnark_pp> verifier(vk, primary_input, proof);
    
    /* 
    Verifier<default_r1cs_gg_ppzksnark_pp> verifier;
    verifier.set_vk(prover.get_vk());
    verifier.set_primary_input(prover.get_primary_input());
    verifier.set_proof(prover.get_proof());
    */

//    bool ret = true;      
    bool ret = verifier.verify();
    if( ret == true)
    {
        cout << "Verify Success" << endl;
    }
    else
    {
        cout << "Verify Fail" << endl;
    }

    delete prover;
    return 0;
}
