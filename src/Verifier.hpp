#include <libff/common/default_types/ec_pp.hpp>
#include <libsnark/common/default_types/r1cs_gg_ppzksnark_pp.hpp>
#include <libsnark/zk_proof_systems/ppzksnark/r1cs_gg_ppzksnark/r1cs_gg_ppzksnark.hpp>

using namespace std;
using namespace libsnark;

template<typename FieldT>
class Verifier{
	public:
		Verifier();
		Verifier(r1cs_gg_ppzksnark_verification_key<FieldT> vk,
				r1cs_gg_ppzksnark_primary_input<FieldT> primary_input,
				r1cs_gg_ppzksnark_proof<FieldT> proof
				);
		void set_vk(r1cs_gg_ppzksnark_verification_key<FieldT> vk);
		void set_primary_input(r1cs_gg_ppzksnark_primary_input<FieldT> primary_input);
		void set_proof(r1cs_gg_ppzksnark_proof<FieldT> proof);
		bool verify();
	private:
		r1cs_gg_ppzksnark_verification_key<FieldT> vk;
		r1cs_gg_ppzksnark_primary_input<FieldT> primary_input;
		r1cs_gg_ppzksnark_proof<FieldT> proof;

};


