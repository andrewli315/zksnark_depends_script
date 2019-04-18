#include "Prover.hpp"
#include "r1cs_system.hpp"
#include <cstdlib>
#include <ctime>

using namespace std;
template<typename FieldT>
Prover<FieldT>::Prover()
{
	/*  if user does not assign the constraint system parameters,
		Generating the value by random.
	*/
	this.system = generate_system_with_field<libff::Fr<FieldT>>(1000,500);
	generate_keypair();
    //generate_proof();
}
template<typename FieldT>
Prover<FieldT>::Prover(const size_t constraint_size, const size_t field_size, bool isBinary)
{
	
	if( isBinary == false)
		this->system = generate_system_with_field<libff::Fr<FieldT>>(constraint_size, field_size);
	else
		this->system = generate_system_with_binary<libff::Fr<FieldT>>(constraint_size,field_size);
	generate_keypair();
    //generate_proof();
}
template<typename FieldT>
Prover<FieldT>::Prover(const size_t constraint_size, const size_t field_size)
{
	
	r1cs_system<libff::Fr<FieldT>> sys = generate_system_with_field<libff::Fr<FieldT>>(constraint_size, field_size);
	// generate keypair and proof with r1cs_system 	
	this->system = std::move(sys);
    generate_keypair();
//    generate_proof();


}
template<typename FieldT>
void Prover<FieldT>::generate_keypair()
{
	r1cs_gg_ppzksnark_keypair<FieldT> kp = r1cs_gg_ppzksnark_generator<FieldT>( this->system.constraint_system );
	
    r1cs_gg_ppzksnark_proof<FieldT> proof = r1cs_gg_ppzksnark_prover<FieldT>(kp.pk,this->system.primary_input, this->system.auxiliary_input);
    this->vk = std::move(kp.vk);
    this->pk = std::move(kp.pk);
    this->pvk = std::move(r1cs_gg_ppzksnark_verifier_process_vk(kp.vk));
    this->proof = std::move(proof);
    this->keypair = &kp;
}
template<typename FieldT>
void Prover<FieldT>::generate_proof()
{
	cout << "\n\n\nProof Generation\n\n\n";
    libff::print_header("R1CS GG-PPZKSNARK Prover");
	r1cs_gg_ppzksnark_proof<FieldT> pf = r1cs_gg_ppzksnark_prover<FieldT>(this->pk, this->system.primary_input, this->system.auxiliary_input);
    this->proof = std::move(pf);
    

}

template<typename FieldT>
r1cs_gg_ppzksnark_processed_verification_key<FieldT> Prover<FieldT>::get_pvk()
{
	return this->pvk;
}
template<typename FieldT>
r1cs_gg_ppzksnark_verification_key<FieldT> Prover<FieldT>::get_vk()
{
	return this->vk;
}
template<typename FieldT>
r1cs_gg_ppzksnark_primary_input<FieldT> Prover<FieldT>:: get_primary_input()
{
	return this->system.primary_input;
}

template<typename FieldT>
r1cs_gg_ppzksnark_proof<FieldT> Prover<FieldT>::get_proof()
{
	return this->proof;
}

