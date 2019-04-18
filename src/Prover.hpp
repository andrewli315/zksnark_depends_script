#include "r1cs_system.hpp"
#include <libff/common/default_types/ec_pp.hpp>
#include <libsnark/common/default_types/r1cs_gg_ppzksnark_pp.hpp>
#include <libsnark/zk_proof_systems/ppzksnark/r1cs_gg_ppzksnark/r1cs_gg_ppzksnark.hpp>

using namespace std;

using namespace libsnark;
template<typename FieldT>
class Prover{
	public:
		/*  Construct a Prover for zksnark.
		 	Prover can return primary input and proof for
			verifier verify the proof and check the zk proof.
		 */
		Prover<FieldT>();
		Prover<FieldT>(size_t constraint_size, size_t field_size, bool isBinary);
		Prover<FieldT>(size_t constraint_size, size_t field_size);
		// for online_verification
		r1cs_gg_ppzksnark_processed_verification_key<FieldT>
			get_pvk();
		// for verifier verification
		r1cs_gg_ppzksnark_verification_key<FieldT> get_vk();
		r1cs_gg_ppzksnark_primary_input<FieldT> get_primary_input();
		r1cs_gg_ppzksnark_proof<FieldT> get_proof();
	private:
		r1cs_gg_ppzksnark_keypair<FieldT> *keypair;
        r1cs_gg_ppzksnark_verification_key<FieldT> vk;
        r1cs_gg_ppzksnark_proving_key<FieldT> pk;
		r1cs_gg_ppzksnark_proof<FieldT> proof;
		r1cs_system<libff::Fr<FieldT>> system;
		r1cs_gg_ppzksnark_processed_verification_key<FieldT> pvk;
		//function
		void generate_keypair();
		void generate_proof();

};


