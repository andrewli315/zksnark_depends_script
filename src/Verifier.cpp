#include "Verifier.hpp"

using namespace std;
template<typename FieldT>
Verifier<FieldT>::Verifier()
{
}

template<typename FieldT>
Verifier<FieldT>::Verifier(r1cs_gg_ppzksnark_verification_key<FieldT> vk,
		r1cs_gg_ppzksnark_primary_input<FieldT> primary_input,
		r1cs_gg_ppzksnark_proof<FieldT> proof)
{
	this->proof = std::move(proof);
	this->primary_input = std::move(primary_input);
	this->vk = std::move(vk);
}
template<typename FieldT>
void Verifier<FieldT>::set_vk(r1cs_gg_ppzksnark_verification_key<FieldT> vk)
{
	this->vk = std::move(vk);
}
template<typename FieldT>
void Verifier<FieldT>::set_primary_input(r1cs_gg_ppzksnark_primary_input<FieldT> primary_input)
{
	this->primary_input = std::move(primary_input);
}

template<typename FieldT>
void Verifier<FieldT>::set_proof(r1cs_gg_ppzksnark_proof<FieldT> proof)
{
	this->proof = std::move(proof);
}

template<typename FieldT>
bool Verifier<FieldT>::verify()
{
    libff::print_header("R1CS GG-ppzkSNARK Online Verifier");
    cout << this->primary_input << endl;
	const bool ret = r1cs_gg_ppzksnark_verifier_weak_IC<FieldT>( this->vk, this->primary_input, this->proof);
	return ret ? true:false;
}

